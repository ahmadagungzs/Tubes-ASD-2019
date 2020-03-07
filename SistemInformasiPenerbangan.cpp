// IDENTITAS DIRI
// Nama Kelompok 		: Boejangan 
// Kelas				: ASD RA
// Nama Anggota 		: 
// 						1. Abrar Dewa Pratama 
//						2. Ahmad Agung Zefi Syahputra
// 						3. Muhammad Rafi Farhan
// Asisten Pembimbing	: Liga Septian

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct tElmtList *address;
typedef struct tElmtList {
  string b,c;  //Allocation
  string a;
  string f,g,h,i;//Allocation2
  int e;
  string d;
  string j,k,l,m;//allocation
  address Prev;
  address next;
} ElmtList;
struct List {
  address First;
  address Last;
};
  #define a(P) (P)->a
  #define b(P) (P)->b
  #define c(P) (P)->c
  #define d(P) (P)->d
  #define e(P) (P)->e
  #define f(P) (P)->f
  #define g(P) (P)->g
  #define h(P) (P)->h
  #define i(P) (P)->i
  #define j(P) (P)->j
  #define k(P) (P)->k
  #define l(P) (P)->l
  #define m(P) (P)->m
  #define Prev(P) (P)->Prev
  #define Next(P) (P)->next
  #define First(L) ((L).First)
  #define Last(L) ((L).Last)
  #define Nil NULL
  struct penerbangan{
    string jenisP,kelasP,jam,keterangan;
    int kodeP;
  };
  struct maskapai{
    string kodeM;
    string Makanan;
    string bagasi;
  };
  struct kota{
    string Bandara,kelas;
    string kapasitas;
    string kodeKota;
  };
address AllocationMaskapai(string x,string y,string z) { //fungsi alokasi
  address NewElmt;
  NewElmt = (ElmtList*) new (ElmtList);
  NewElmt->a = x;
  NewElmt->b = y;
  NewElmt->c = z;
  NewElmt->next = NULL;
  return NewElmt;
  }
address AllocationPenerbangan(string  x,int  y,string z,string a, string b,string c) { //fungsi alokasi
  address NewElmt;
  NewElmt = (ElmtList*) new (ElmtList);
  NewElmt->d = x;
  NewElmt->e = y;
  NewElmt->f = z;
  NewElmt->g = a;
  NewElmt->h = b;
  NewElmt->i = c;
  NewElmt->next = NULL;
  return NewElmt;
  }
address AllocationKota(string x,string y,string z,string a) { //fungsi alokasi
  address NewElmt;
  NewElmt = (ElmtList*) new (ElmtList);
  NewElmt->j = x;
  NewElmt->k = y;
  NewElmt->l = z;
  NewElmt->m = a;
  NewElmt->next = NULL;
  return NewElmt;
  }
bool IsEmpty(List L) {
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return (First(L) == NULL && Last(L) == NULL);
}
/****************** PEMBUATAN LIST KOSONG ******************/
void createList(List *L) {
    First(*L) = NULL;
}
/****************** ISI AWAL ******************/
void InsertFirstMaskapai(List *L, string kodeM,string Makanan,string bagasi){
    address NewElmt;
    NewElmt = AllocationMaskapai( kodeM, Makanan, bagasi);


    if(NewElmt != NULL){
        NewElmt->next = (*L).First;
        (*L).First = NewElmt;
    }
}
void InsertFirstPenerbangan(List *L,string kodeM, int kodeP,string kodeKota,string kelasP,string jam,string keterangan){
    address NewElmt;
    NewElmt = AllocationPenerbangan( kodeM,kodeP, kodeKota, kelasP, jam, keterangan);

    if(NewElmt != NULL){
        NewElmt->next = (*L).First;
        (*L).First = NewElmt;
    }
}
void InsertFirstKota(List *L, string kodeKota,string Bandara,string kelas,string kapasitas){
    address NewElmt;
    NewElmt = AllocationKota( kodeKota, Bandara, kelas, kapasitas);

    if(NewElmt != NULL){
        NewElmt->next = (*L).First;
        (*L).First = NewElmt;
    }
}
/****************** TAMBAH DATA ******************/
void InsertAfterMaskapai(address *PredElmt, string kodeM,string Makanan,string bagasi){
      address NewElmt;
      NewElmt = AllocationMaskapai(kodeM, Makanan, bagasi);

      if(NewElmt != NULL){
          NewElmt->next =   (*PredElmt)->next;
          (*PredElmt)->next = NewElmt;
      }
}
void InsertAfterPenerbangan(address *PredElmt,string kodeM,int kodeP,string kodeKota,string kelasP,string jam,string keterangan){
    address NewElmt;
    NewElmt = AllocationPenerbangan(kodeM,kodeP,kodeKota, kelasP, jam, keterangan);

    if(NewElmt != NULL){
        NewElmt->next = (*PredElmt)->next;
        (*PredElmt)->next = NewElmt;
    }
}
void InsertAfterKota(address *PredElmt, string kodeKota,string Bandara,string kelas,string kapasitas){
    address NewElmt;
    NewElmt = AllocationKota( kodeKota, Bandara, kelas, kapasitas);

    if(NewElmt != NULL){
        NewElmt->next = (*PredElmt)->next;
        (*PredElmt)->next = NewElmt;
    }
}
void InsertLastMaskapai(List *L, string kodeM,string Makanan,string bagasi){
    if(IsEmpty(*L)){
        InsertFirstMaskapai(&(*L),  kodeM, Makanan, bagasi);
    } else {
        address temp;
        temp = (*L).First;
        while (temp->next != NULL){
            temp = temp->next;
        }
        InsertAfterMaskapai(&temp, kodeM, Makanan, bagasi);
    }
}
void InsertLastPenerbangan(List *L, string kodeM, int kodeP,string kodeKota,string kelasP,string jam,string keterangan){
    if(IsEmpty(*L)){
        InsertFirstPenerbangan(&(*L), kodeM,kodeP,kodeKota,kelasP, jam, keterangan);
    } else {
        address temp;
        temp = (*L).First;
        while (temp->next != NULL){
            temp = temp->next;
        }
        InsertAfterPenerbangan(&temp,  kodeM,kodeP,kodeKota,kelasP, jam, keterangan);
    }
}void InsertLastKota(List *L,  string kodeKota,string Bandara,string kelas,string kapasitas){
    if(IsEmpty(*L)){
        InsertFirstKota(&(*L),   kodeKota, Bandara,kelas, kapasitas);
    } else {
        address temp;
        temp = (*L).First;
        while (temp->next != NULL){
            temp = temp->next;
        }
        InsertAfterKota(&temp, kodeKota, Bandara,kelas, kapasitas);
    }
}
void pilih(){
  cout<<endl;
  cout<<"######################### MASUKKAN PILIHAN ###########################"<<endl;
  cout<<"a.Maskapai "<<endl;
  cout<<"b.Penerbangan"<<endl;
  cout<<"c.Kota"<<endl;
  cout<<"d.Back"<<endl;
}
void menu(){
  cout<<"Pilihan Menu"<<endl;
  cout<<"1.Tampilkan Data Penerbangan"<<endl;
  cout<<"2.Tambah Data Penerbangan"<<endl;
  cout<<"3.Update Data Penerbangan"<<endl;
  cout<<"4.Hapus Data"<<endl;
  cout<<"5.Cari Data Penerbangan"<<endl;
  cout<<"6.Keluar"<<endl;
}
void integer(){
  cout<<endl;
  cout<<"################ MASUKKAN PILIHAN Kode Pendebangan atau bukan ################"<<endl;
  cout<<"1.Kode Penerbangan "<<endl;
  cout<<"2.Bukan Kode Penerbangan"<<endl;

}
void PENERBANGAN(){
  cout<<"1.Kode Maskapai"<<endl;
  cout<<"2.Kode Penerbangan"<<endl;
  cout<<"3.Kode Kota"<<endl;
  cout<<"4.Kelas Penerbangan"<<endl;
  cout<<"5.Jam Keberangkatan"<<endl;
  cout<<"6.Keterangan"<<endl;
}
void KOTA(){
  cout<<endl;
  cout<<"######################### MASUKKAN PILIHAN YANG INGIN DI UPDATE ###########################"<<endl;
  cout<<"1.Kode Kota"<<endl;
  cout<<"2.Nama Bandara"<<endl;
  cout<<"3.Kapasitas Parkir Pesawat"<<endl;
  cout<<"4.Status Bandara"<<endl;
}
void subpilih(char x, List *Aviation,List *Flight,List * City);
void case1(char x, List *Aviation, List *Flight, List * City);
address SearchIntFlight( List *Flight, int X){
		address P = First(*Flight);
 	
 	while (P != Nil){
 		if (  e(P)==X){
 			return P;
 		}
 		P = Next(P);
 	}
 	return NULL;
}

void tampil(List *Aviation,List *Flight,List * City){
  address temp1= Aviation->First,temp2= Flight->First,temp3= City->First;
  char lanjut,toPilih,toMenu;
  penerbangan A[999];
  int i = 1;
  while(temp1!=NULL && temp2!=NULL && temp3!=NULL ){
    cout<<'#'<<i<<endl;
    cout<<"Kode Penerbangan  : "<<temp2->d<<"  "<<temp2->e<<endl;
    cout<<"Kelas Penerbangan : "<<temp2->g<<endl;
    cout<<"Jam Keberangkatan : "<<temp2->h<<endl;
    cout<<"Keterangan        : "<<temp2->i<<endl;
    temp2 = temp2->next;
    i++;
  }
  do {
    cout<<"Lanjutkan?(y/t) : "<<endl;
    cin>>lanjut;
    if(lanjut=='y'){
      system("cls");
      pilih();
      cin>>toPilih;
      subpilih(toPilih,&(*Aviation),&(*Flight),&(* City));

    }
    else if(lanjut=='t'){
      system("cls");
      menu();
      cin>>toMenu;
      if(toMenu!='6'){
        case1(toMenu,&(*Aviation),&(*Flight),&(* City));
      }
      else{
        exit(0);
      }
    }
    else{
      cout<<"salah input "<<endl<<"masukkan lagi : ";
      cin>>lanjut;
    }
  } while(true);
}

void tampilCari(address *P,address *Q,address *R,List *Aviation,List *Flight,List * City){
  cout<<"MASKAPAI"<<endl<<endl;
  char lanjut,toPilih,toMenu;






        cout<<"Kode Maskapai             : "<<(*Q)->a<<endl;
        cout<<"Ketersediaan Makanan      : "<<(*Q)->b<<endl;
        cout<<"Berat Bagasi              : "<<(*Q)->c<<endl<<endl;
        cout<<"PENERBANGAN"<<endl<<endl;
        cout<<"Kode Penerbangan          : "<<(*P)->e<<endl;
        cout<<"Kelas Penerbangan         : "<<(*P)->g<<endl;
        cout<<"Jam Keberangkatan         : "<<(*P)->h<<endl;
        cout<<"Keterangan                : "<<(*P)->i<<endl<<endl;
        cout<<"KOTA"<<endl<<endl;

        
          cout<<"Kode Kota                 : "<<(*R)->j<<endl;
          cout<<"Nama Bandara              : "<<(*R)->k<<endl;
          cout<<"Kapasitas Parkir Pesawat  : "<<(*R)->m<<endl;
          cout<<"Status Bandara            : "<<(*R)->l<<endl;
        
          
        
    

    do {
      cout<<"Lanjutkan?(y/t) : "<<endl;
      cin>>lanjut;
      if(lanjut=='y'){
        system("cls");
        pilih();
        cin>>toPilih;
        subpilih(toPilih,&(*Aviation),&(*Flight),&(* City));

      }
      else if(lanjut=='t'){
        system("cls");
        menu();
        cin>>toMenu;
        if(toMenu!='6'){
          case1(toMenu,&(*Aviation),&(*Flight),&(* City));
        }
        else{
          exit(0);
        }
      }
      else{
        cout<<"salah input "<<endl<<"masukkan lagi : ";
        cin>>lanjut;
      }
    } while(true);
}



void subpilih(char x, List *Aviation,List *Flight,List * City){
  address temp1=(*Aviation).First,temp2=(*Flight).First,temp3=(*City).First;
  maskapai plane[999];
  penerbangan plane2[999];
  kota tujuan[999];
  char toMenu,toPilih;
  int i=6;
  do {
    if(x=='a'){
        cout<<"Kode Maskapai : ";
        cin>>plane[i].kodeM;
        cout<<"Makanan : ";
        cin>>plane[i].Makanan;
        cout<<"Berat Bagasi : ";
        cin>>plane[i].bagasi;

        InsertLastMaskapai(&(*Aviation),plane[i].kodeM,plane[i].Makanan,plane[i].bagasi);
        system("cls");
        pilih();
        cin>>toPilih;
        subpilih(toPilih,&(*Aviation),&(*Flight),&(* City));
        return;
    }
    else if(x== 'b'){
         cout<<"Kode Maskapai : ";
         cin>>plane[i].kodeM;
         cout<<"Kode Penerbangan : ";
         cin>>plane2[i].kodeP;
         cout<<"Kode Kota : ";
         cin>>tujuan[i].kodeKota;
         cout<<"Jenis Penerbangan : ";
         cin>>plane2[i].jenisP;
         cout<<"Kelas Penerbangan : ";
         cin>>plane2[i].kelasP;
         cout<<"Jam Penerbangan : ";
         cin>>plane2[i].jam;
         cout<<"Keterangan Penerbangan : ";
         cin>>plane2[i].keterangan;
         InsertLastPenerbangan(&(*Flight),plane[i].kodeM,plane2[i].kodeP,tujuan[i].kodeKota,plane2[i].kelasP,plane2[i].jam,plane2[i].keterangan);
         system("cls");
         pilih();
         cin>>toPilih;
         subpilih(toPilih,&(*Aviation),&(*Flight),&(* City));
         return;
    }
    else if(x=='c'){
        cout<<"Kode Kota : ";
        cin>>tujuan[i].kodeKota;
        cout<<"Nama Bandara : ";
        cin>>tujuan[i].Bandara;
        cout<<"Status Bandara : ";
        cin>>tujuan[i].kelas;
        cout<<"Kapasitas Parkir Pesawat Bandara : ";
        cin>>tujuan[i].kapasitas;
        InsertLastKota(&(*City),tujuan[i].kodeKota,tujuan[i].Bandara,tujuan[i].kelas,tujuan[i].kapasitas);
        system("cls");
        pilih();
        cin>>toPilih;
        subpilih(toPilih,&(*Aviation),&(*Flight),&(* City));i++;
        return;
    }
    else if(x=='d'){
        system("cls");
        menu();
        cin>>toMenu;
        case1(toMenu,&(*Aviation), &(*Flight),&(* City));
        return;
    }
    else{
      cout<<"salah input "<<endl<<"masukkan lagi : ";
      cin>>x;
    }
  } while(true);
}
void Update(List *Aviation, List *Flight, List * City,int X){
  address P=(*Flight).First;
  int kodeBaru;
  string maskapaii,food,bagage,kodePBaru,jenisPbaru,kelasPBaru,jamBaru,keteranganBaru,kodeKotaBaru,Namabaru,statusbaru,kapasitasbaru;
  while(P!=NULL){
    if(P->e==X){
      cout<<"Masukkan Data Yang baru "<<endl<<endl;
      cout<<"Kode Maskapai : ";
      cin>>maskapaii;
      cout<<"Makanan : "; 
      cin>>food;
      cout<<"Berat Bagasi : ";
      cin>>bagage;
      cout<<"Kode Penerbangan : ";
      cin>>kodeBaru;
      cout<<"Kode Kota : ";
      cin>>kodeKotaBaru;
      cout<<"Jenis Penerbangan : ";
      cin>>jenisPbaru;
      cout<<"Kelas Penerbangan : ";
      cin>>kelasPBaru;
      cout<<"Jam Penerbangan : ";
      cin>>jamBaru;
      cout<<"Keterangan Penerbangan : ";
      cin>>keteranganBaru;
      cout<<"Nama Bandara : ";
      cin>>Namabaru;
      cout<<"Status Bandara : ";
      cin>>statusbaru;
      cout<<"Kapasitas Parkir Pesawat Bandara : ";
      cin>>kapasitasbaru;
      break;
    }
    
    else{
      cout<<"kode tidak ditemukan ";
    }
  }
  P->a=maskapaii;
  P->b=food;
  P->c=bagage;
  P->d=maskapaii;
  P->e=kodeBaru;
  P->f=kodeKotaBaru;
  P->g=jenisPbaru;
  P->h=kelasPBaru;
  P->i=jamBaru;
  P->j=keteranganBaru;
  P->k=Namabaru;
  P->l=statusbaru;
  P->m=kapasitasbaru;


}


address SearchStringAviation ( List *Aviation, string X){
 /* Mencari apakah ada elemen list dengan Info(P)=X */
 /* Jika ada, mengirimkan address elemen tersebut. */
 /* Jika tidak ada, mengirimkan Nil */
 	address P = First(*Aviation);
 	
 	while (P != Nil){
 		if (  a(P)==X){
 			return P;
 		}
 		P = Next(P);
 	}
 	return NULL;
 }
 address SearchStringCity ( List *City, string X){
 /* Mencari apakah ada elemen list dengan Info(P)=X */
 /* Jika ada, mengirimkan address elemen tersebut. */
 /* Jika tidak ada, mengirimkan Nil */
 	address P = First(*City);
 	
 	while (P != Nil){
 		if (  j(P)==X){
 			return P;
 		}
 		P = Next(P);
 	}
 	return NULL;
 }


void Deallocation(address P ){


          delete(P);
}
void DelFirst ( List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
	*P = First(*L);
	First(*L) = Next(*P);
	Prev(First(*L)) = NULL;
	Deallocation(*P);
}
void DelLast (List *L, address *P){
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
	*P = Last(*L);
	Last(*L) = Prev(*P);
	Next(Last(*L)) = NULL;
	Prev(*P) = NULL;
	Deallocation(*P);
}
void DelAfter (List *L, address *Pdel, address Prec){
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	Prev(Next(*Pdel)) = Prec;
	Prev(*Pdel) = NULL;
	Next(*Pdel)= NULL;
	Deallocation(*Pdel);
}
void DelP(List *Flight,int angka){
  address P;
  address g=First(*Flight);
  P=SearchIntFlight (&(*Flight) ,angka);
  address prec=Prev(P);
if(P!=NULL){
  if(Next(g)==NULL&&Prev(g)==NULL){
    First(*Flight)=NULL;
  }
  else if(P==First(*Flight)){
    DelFirst(&(*Flight),&P);
  }
  else if(P==Last(*Flight)){
    DelLast(&(*Flight),&P);
  }
  else{
    DelAfter(&(*Flight),&P,prec);
  }
}
}

void case1(char x, List *Aviation, List *Flight, List * City){
  char y;
  int cari,kPenerbangan, angka,update;
  string Pilih,hapus;
  address P,Q,R;
  switch(x){
    case '1':
        cout<<"Data Penerbangan"<<endl;
        tampil(&(*Aviation),&(*Flight),&(* City));
        break;
    case '2':
        cout<<"Tambah Data"<<endl;
        pilih();
        cin>>y;
        subpilih(y, &(*Aviation),&(*Flight),&(* City));
        break;
    case '3':
        cout<<"Masukkan Kode Penerbangan Data yang ingin di Update"<<endl;
        cin>>update;
        Update(&(*Aviation),&(*Flight),&(*City),update);
        break;
    case '4':
        cout<<"Hapus Data"<<endl<<endl;
        cout<<"Masukkan Kode Penerbangan dari data yang ingin dihapus"<<endl;
        cin>>angka;
        DelP(&(*Flight),angka);

        break;
    case '5':
        cout<<"Cari Data"<<endl;
        cout<<"Masukkan Kode Penerbangan "<<endl;
        cin>>cari;
        P=SearchIntFlight (&(*Flight) ,cari);
        Q=SearchStringAviation(&(*Aviation),P->d);
        R=SearchStringCity(&(*City),P->f);
        
            tampilCari(&P, &Q,&R,&(*Aviation),&(*Flight),&(*City));

        break;}
  }
void isiAwal(List *Aviation,List *Flight,List * City){
  maskapai plane[999];
  penerbangan plane2[999];
  kota tujuan[999];

    plane2[0].kodeP=123;
    plane[0].kodeM="GA";
    tujuan[0].kodeKota="CGK";
    plane2[0].kelasP="Ekonomi";
    plane2[0].jam="12.30";
    plane2[0].keterangan="onTime";
    InsertFirstPenerbangan(&(*Flight),plane[0].kodeM,plane2[0].kodeP,tujuan[0].kodeKota,plane2[0].kelasP,plane2[0].jam,plane2[0].keterangan);


    plane[0].kodeM="GA";
    plane[0].Makanan="Ada";
    plane[0].bagasi="20Kg";
    InsertFirstMaskapai(&(*Aviation),plane[0].kodeM,plane[0].Makanan,plane[0].bagasi);


    tujuan[0].kodeKota="CGK";
    tujuan[0].Bandara="SoekarnoHatta";
    tujuan[0].kelas="Internasional";
    tujuan[0].kapasitas="1000";
    InsertFirstKota(&(*City),tujuan[0].kodeKota,tujuan[0].Bandara,tujuan[0].kelas,tujuan[0].kapasitas);
    
    plane2[1].kodeP=234;
    plane[1].kodeM="GA";
    tujuan[1].kodeKota="CGK";
    plane2[1].kelasP="BISNIS";
    plane2[1].jam="13.30";
    plane2[1].keterangan="onTime";
    InsertLastPenerbangan(&(*Flight),plane[1].kodeM,plane2[1].kodeP,tujuan[1].kodeKota,plane2[1].kelasP,plane2[1].jam,plane2[1].keterangan);


    plane[1].kodeM="GA";
    plane[1].Makanan="Ada";
    plane[1].bagasi="20Kg";
    InsertLastMaskapai(&(*Aviation),plane[1].kodeM,plane[1].Makanan,plane[1].bagasi);


    tujuan[1].kodeKota="CGK";
    tujuan[1].Bandara="SoekarnoHatta";
    tujuan[1].kelas="Internasional";
    tujuan[1].kapasitas="1000";
    InsertLastKota(&(*City),tujuan[1].kodeKota,tujuan[1].Bandara,tujuan[1].kelas,tujuan[1].kapasitas);
    
    plane2[2].kodeP=345;
    plane[2].kodeM="GA";
    tujuan[2].kodeKota="CGK";
    plane2[2].kelasP="Ekonomi";
    plane2[2].jam="15.30";
    plane2[2].keterangan="onTime";
    InsertLastPenerbangan(&(*Flight),plane[2].kodeM,plane2[2].kodeP,tujuan[2].kodeKota,plane2[2].kelasP,plane2[2].jam,plane2[2].keterangan);


    plane[2].kodeM="GA";
    plane[2].Makanan="Ada";
    plane[2].bagasi="20Kg";
    InsertLastMaskapai(&(*Aviation),plane[2].kodeM,plane[2].Makanan,plane[2].bagasi);


    tujuan[2].kodeKota="CGK";
    tujuan[2].Bandara="SoekarnoHatta";
    tujuan[2].kelas="Internasional";
    tujuan[2].kapasitas="1000";
    InsertLastKota(&(*City),tujuan[2].kodeKota,tujuan[2].Bandara,tujuan[2].kelas,tujuan[2].kapasitas);
    
    
    plane2[3].kodeP=456;
    plane[3].kodeM="GA";
    tujuan[3].kodeKota="TKG";
    plane2[3].kelasP="Ekonomi";
    plane2[3].jam="14.30";
    plane2[3].keterangan="onTime";
    InsertLastPenerbangan(&(*Flight),plane[3].kodeM,plane2[3].kodeP,tujuan[3].kodeKota,plane2[3].kelasP,plane2[3].jam,plane2[3].keterangan);


    plane[3].kodeM="GA";
    plane[3].Makanan="Ada";
    plane[3].bagasi="20Kg";
    InsertLastMaskapai(&(*Aviation),plane[3].kodeM,plane[3].Makanan,plane[3].bagasi);


    tujuan[3].kodeKota="TKG";
    tujuan[3].Bandara="SoekarnoHatta";
    tujuan[3].kelas="Internasional";
    tujuan[3].kapasitas="1000";
    InsertLastKota(&(*City),tujuan[3].kodeKota,tujuan[3].Bandara,tujuan[3].kelas,tujuan[3].kapasitas);
    
    plane2[4].kodeP=567;
    plane[4].kodeM="GA";
    tujuan[4].kodeKota="PKU";
    plane2[4].kelasP="Ekonomi";
    plane2[4].jam="17.30";
    plane2[4].keterangan="onTime";
    InsertLastPenerbangan(&(*Flight),plane[4].kodeM,plane2[4].kodeP,tujuan[4].kodeKota,plane2[4].kelasP,plane2[4].jam,plane2[4].keterangan);


    plane[4].kodeM="GA";
    plane[4].Makanan="Ada";
    plane[4].bagasi="20Kg";
    InsertLastMaskapai(&(*Aviation),plane[4].kodeM,plane[4].Makanan,plane[4].bagasi);


    tujuan[4].kodeKota="PKU";
    tujuan[4].Bandara="SoekarnoHatta";
    tujuan[4].kelas="Internasional";
    tujuan[4].kapasitas="1000";
    InsertLastKota(&(*City),tujuan[4].kodeKota,tujuan[4].Bandara,tujuan[4].kelas,tujuan[4].kapasitas);
  }



 void pemanis(){
   cout<<"#####################################################################"<<endl;
   cout<<"                  SELAMAT DATANG DI BOEJANG TRAVEL                   "<<endl;
   cout<<"                      SILAHKAN MASUKIN DATA                          "<<endl;
   cout<<"#####################################################################"<<endl;
   system("pause");
 }

int main(){
  address temp;
  List data1,data2,data3;
  int tempHapus,i=0;
  char pilihMenu;
  createList(& data1);
  createList(& data2);
  createList(& data3);
  isiAwal(&data1,&data2,&data3);
  do {
    system("cls");
    pemanis();
    menu();
    cin>>pilihMenu;
    case1(pilihMenu,&data1,&data2,&data3);
  } while(pilihMenu != '6');
  cout << "Terima kasih telah menggunakan program ini." << endl;
  cout << "Have a nice day!";
  return 0;
}
