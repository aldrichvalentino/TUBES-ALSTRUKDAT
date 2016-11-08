/*
NIM         : 13515021
Nama        : Dewita Sonya Tarabunga
Nama File   : listlinier.c
Tanggal     : 18 Oktober 2016
Topik       : ADT List Linier
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList (List L)
/* Mengirim true jika list kosong */
{
    return (FirstL(L)==Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyList (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    FirstL(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addressL AlokasiList (infotypeL X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressL P = (addressL) malloc(sizeof(ElmtList));
    if (P!=Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
void DealokasiList (addressL *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
addressL SearchList (List L, infotypeL X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressL P = FirstL(L);
    boolean found = false;
    while ((P!=Nil)&&(!found))
        if (Info(P)==X) found = true;
        else P = Next(P);
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstList (List *L, infotypeL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressL P = AlokasiList(X);
    if (P!=Nil)
    {
        Next(P) = FirstL(*L);
        FirstL(*L) = P;
    }
}
void InsVLastList (List *L, infotypeL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressL P = AlokasiList(X);
    if (P!=Nil)
    {
        if (IsEmptyList(*L)) InsVFirstList(L,X);
        else
        {
            addressL temp = FirstL(*L);
            while (Next(temp)!=Nil) temp = Next(temp);
            Next(P) = Nil;
            Next(temp) = P;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstList (List *L, infotypeL *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    *X = Info(FirstL(*L));
    addressL P = FirstL(*L);
    FirstL(*L) = Next(FirstL(*L));
    DealokasiList(&P);
}
void DelVLastList (List *L, infotypeL *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressL P1 = FirstL(*L);
    addressL P2 = Nil;
    while (Next(P1)!=Nil)
    {
        P2 = P1;
        P1 = Next(P1);
    }
    *X = Info(P1);
    if (P1==FirstL(*L)) FirstL(*L) = Nil;
    else Next(P2) = Nil;
    DealokasiList(&P1);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstList (List *L, addressL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = FirstL(*L);
    FirstL(*L) = P;
}
void InsertAfterList (List *L, addressL P, addressL Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
void InsertLastList (List *L, addressL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmptyList(*L)) InsertFirstList(L,P);
    else
    {
        addressL P2 = FirstL(*L);
        while (Next(P2)!=Nil) P2 = Next(P2);
        Next(P2) = P;
        Next(P) = Nil;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstList (List *L, addressL *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = FirstL(*L);
    FirstL(*L) = Next(FirstL(*L));
}
void DelPList (List *L, infotypeL X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    addressL P = SearchList(*L,X);
    if (P==FirstL(*L)) DelFirstList(L,&P);
    else if (P!=Nil)
    {
        addressL temp = FirstL(*L);
        while (Next(temp)!=P) temp = Next(temp);
        Next(temp) = Next(P);
        DealokasiList(&P);
    }
}
void DelLastList (List *L, addressL *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    if (Next(FirstL(*L))==Nil) DelFirstList(L,P);
    else
    {
        addressL temp = FirstL(*L);
        while (Next(Next(temp))!=Nil) temp = Next(temp);
        *P = Next(temp);
        Next(temp) = Nil;
    }
}
void DelAfterList (List *L, addressL *Pdel, addressL Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintList (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    printf("[");
    addressL P = FirstL(L);
    while (P!=Nil)
    {
        if (P!=FirstL(L)) printf(",");
        printf("%d",Info(P));
        P = Next(P);
    }
    printf("]");
}
int NbElmtList (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    addressL P = FirstL(L);
    while (P!=Nil)
    {
        ++count;
        P = Next(P);
    }
    return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotypeL MaxList (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
    addressL P = Next(FirstL(L));
    infotypeL maks = Info(FirstL(L));
    while (P!=Nil)
    {
        if (Info(P)>maks) maks = Info(P);
        P = Next(P);
    }
    return maks;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    if (IsEmptyList(*L1)) FirstL(*L3) = FirstL(*L2);
    else
    {
        FirstL(*L3) = FirstL(*L1);
        addressL P = FirstL(*L1);
        while (Next(P)!=Nil) P = Next(P);
        Next(P) = FirstL(*L2);
    }
    FirstL(*L1) = Nil;
    FirstL(*L2) = Nil;
}
