/* File : queue.c */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

/* ********* Prototype ********* */
int NBElmtQ (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
    int ret;
    if ((Head(Q)==Nil)&&(Tail(Q)==Nil))
    {
        ret = 0;
    }
    else
    {
        ret = Tail(Q) - Head(Q) + 1;
        if (ret <= 0)
        {
            ret = ret + MaxElQ(Q);
        }
    }
    return ret;
}

boolean IsEmptyQ (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
    return ((Head(Q) == Nil) && (Tail(Q) == Nil));
}
boolean IsFullQ (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
    return (NBElmtQ(Q) == MaxElQ(Q));
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi,Membuat sebuah Q kosong */
{
    (*Q).T = (infotype *) malloc ((Max + 1) * sizeof(infotype));
    if ((*Q).T == NULL)
    {
        MaxElQ(*Q) = Nil;
    }
    else
    {
        MaxElQ(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}
/* *** Destruktor *** */
void DeAlokasiQ (Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
    MaxElQ(*Q) = Nil;
    free((*Q).T);
}
/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
{
    if (IsEmptyQ(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoHead(*Q) = X;
    }
    else
    {
        if (Tail(*Q) == MaxElQ(*Q))
        {
            Tail(*Q) = 1;
        }
        else
        {
            Tail(*Q)++;
        }
        InfoTail(*Q) = X;
    }

}

void DelQ (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{
    Queue Qt;
    Qt = *Q;
    infotype y;
    y = InfoHead(Qt);
    *X = y;
    if (NBElmtQ(Qt) == 1)
    {
        Head(Qt) = Nil;
        Tail(Qt) = Nil;
    }
    else
    {
        if (Head(Qt) == MaxElQ(Qt))
        {
            Head(Qt) = 1;
        }
        else
        {
            Head(Qt)++;
        }
    }
    *Q = Qt;
}

void PrintQueue(Queue Q)
/* I.S. Q sembarang */
/* Isi queue dicetak ke layar */
/* mendelete elemen sampai habis dan menuliskan semuanya ke layar */
{
    char c;
    while (!IsEmptyQ(Q))
    {
        DelQ(&Q,&c);
        printf("%c",c);
    }
}

