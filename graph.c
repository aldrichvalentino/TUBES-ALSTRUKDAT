/* File : graph.c */

#include "graph.h"
#include "listlinier.h"
#include <stdlib.h>

/****************** PEMBUATAN GRAPH KOSONG ******************/
void CreateEmptyGraph(Graph *G)
/* I.S. G sembarang */
/* F.S. Terbentuk graph kosong */
{
    FirstG(*G) = Nil;
}

/****************** TEST GRAPH KOSONG ******************/
boolean IsEmptyGraph(Graph G)
/* mengeluarkan true jika graph G kosong */
{
    return (FirstG(G)==Nil);
}

/****************** Manajemen Memori ******************/
addressG AlokasiGraph(infotypeG X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressG P = (addressG) malloc(sizeof(ElmtGraph));
    if (P!=Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
}
void DealokasiGraph(addressG *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    addressL PL = FirstL(Info(*P));
    addressL P2;
    while (PL!=Nil)
    {
        P2 = PL;
        PL = Next(PL);
        DealokasiList(&P2);
    }
    free(*P);
}

/*** PENAMBAHAN ELEMEN ***/
void InsVFirstGraph (Graph *G, infotypeG X)
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan list X jika alokasi berhasil */
{
    addressG P = AlokasiGraph(X);
    if (P!=Nil)
    {
        Next(P) = FirstG(*G);
        FirstG(*G) = P;
    }
}
void InsVLastGraph (Graph *G, infotypeG X)
/* I.S. G mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen graph di akhir: elemen terakhir yang baru */
/* merupakan list X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressG P = AlokasiGraph(X);
    if (P!=Nil)
    {
        if (IsEmptyGraph(*G)) InsVFirstGraph(G,X);
        else
        {
            addressG temp = FirstG(*G);
            while (Next(temp)!=Nil) temp = Next(temp);
            Next(P) = Nil;
            Next(temp) = P;
        }
    }
}
void ResetGraph(Graph *G, int n)
/* I.S. Graph G sembarang */
/* F.S. Terbentuk Graph dengan jumlah elemen n dengan semua info merupakan list kosong */
{
    CreateEmptyGraph(G);
    List L;
    CreateEmptyList(&L);
    int i;
    for (i=0;i<n;++i) InsVLastGraph(G,L);
}

/*** JUMLAH ELEMEN ***/
int NbElmtGraph(Graph G)
/* mengeluarkan jumlah elemen dari graph G */
{
    addressG P = FirstG(G);
    int count = 0;
    while (P!=Nil)
    {
        ++count;
        P = Next(P);
    }
    return count;
}

/*** PENCARIAN ELEMEN ***/
infotypeG SearchGraph(Graph G, int n)
/* NbElmtGraph(G) lebih besar dari n, mengeluarkan list yang merupakan info dari elemen ke n graph G */
{
    addressG P = FirstG(G);
    int i = 1;
    while (i<n)
    {
        P = Next(P);
        ++i;
    }
    return Info(P);
}
