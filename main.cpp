#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;
typedef struct node *simpul;
struct node
{
  char Isi;
  simpul Kanan;
} ;

void Sisip_Depan(simpul &CL, char elemen);
void Sisip_Belakang(simpul &CL, char elemen);
void Sisip_Tengah(simpul &CL, char elemen1, char elemen2);
void Hapus_Depan(simpul &CL);
void Hapus_Belakang(simpul &CL);
void Hapus_Tengah(simpul &CL, char elemen);
void Cetak(simpul CL);

main()
{
  char huruf, huruf2;
  simpul CL = NULL;  
  int i;
  cout<<"\t\t==OPERASI PADA CIRCULAR SINGLE LINKED LIST==\n\n";
  cout<<"Penyisipan Simpul Di Depan\n\n";
  for(i=1; i<=4; i++)
  {
    cout<<"Masukkan Huruf :"; cin>>huruf;
    Sisip_Depan(CL, huruf);
  }
  Cetak(CL);
  cout<<"\nPenyisipan Simpul Di Belakang \n\n";
  for(i=1; i<=4; i++)
  {
    cout<<"Masukkan Huruf :"; cin>>huruf;
    Sisip_Belakang(CL, huruf);
  }
  Cetak(CL);

  cout<<"\nMasukkan Huruf     :"; cin>>huruf;
  cout<<"Disisip Setelah Huruf :"; cin>>huruf2;
  cout<<huruf<<" Disisip Setelah "<<huruf2<<endl;
  Sisip_Tengah(CL, huruf, huruf2);
  Cetak(CL);

  cout<<"\nSetelah Hapus Simpul Belakang \n";
  Hapus_Belakang(CL);
  Cetak(CL);

  cout<<"\nMasukkan Huruf Tengah Yang Akan Dihapus :"; cin>>huruf;
  Hapus_Tengah(CL,huruf);
  Cetak(CL);
  getchar();
}

void Sisip_Depan(simpul &CL, char elemen)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen;
  baru->Kanan = baru;
  if(CL == NULL)
    CL=baru;
  else
  {
    bantu = CL;
    while(bantu->Kanan != CL) bantu=bantu->Kanan;
    baru->Kanan = CL;
    bantu->Kanan = baru;
    CL = baru;
  }
}

void Sisip_Tengah(simpul &CL, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen1;
  baru->Kanan = baru;
  if(CL == NULL)
    cout<<"List Kosong ............."<<endl;
  else
  {
    bantu = CL;
    while(bantu->Isi != elemen2) bantu=bantu->Kanan;
    baru->Kanan = bantu->Kanan;
    bantu->Kanan = baru;
  }
}

void Sisip_Belakang(simpul &CL, char elemen)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen;
  baru->Kanan = baru;
  if(CL == NULL)
    CL=baru;
  else
  {
    bantu = CL;
    while(bantu->Kanan != CL) bantu=bantu->Kanan;
    baru->Kanan = CL;
    bantu->Kanan = baru;
  }
}

void Cetak(simpul CL)
{
  simpul bantu;
  if(CL==NULL)
    cout<<"Linked List Kosong ......."<<endl;
  else
  {
    bantu = CL;
    cout<<"Isi Linked List : ";
    while (bantu->Kanan != CL)
    {
      cout<<bantu->Isi<<"-->";
      bantu=bantu->Kanan;
    }
    cout<<bantu->Isi;
  }
}

void Hapus_Depan(simpul &CL)
{
  simpul bantu, Hapus;
  if(CL == NULL)
    cout<<"Linked List Kosong .......";
  else
  {
    bantu = CL;
    while(bantu->Kanan != CL) bantu=bantu->Kanan;
    Hapus = CL;
    CL = CL->Kanan;
    bantu->Kanan = CL;
    Hapus->Kanan = Hapus;
    free(Hapus);
  }
}

void Hapus_Belakang(simpul &CL)
{
  simpul hapus, bantu;
  if(CL==NULL)
    cout<<"Linked List Kosong ........";
  else
  {
    bantu = CL;
    while(bantu->Kanan->Kanan != CL) bantu=bantu->Kanan;
    hapus = bantu->Kanan;
    bantu->Kanan = CL;
    hapus->Kanan = hapus;
    free(hapus);
  }
}

void Hapus_Tengah(simpul &CL, char elemen)
{
  simpul hapus, bantu;
  if(CL == NULL)
    cout<<"Linked List Kosong .......";
  else
  {
    bantu = CL;
    while(bantu->Kanan->Isi != elemen) bantu=bantu->Kanan;
    hapus = bantu->Kanan;
    bantu->Kanan = hapus->Kanan;
    hapus->Kanan = hapus;
    free(hapus);
  }
}
