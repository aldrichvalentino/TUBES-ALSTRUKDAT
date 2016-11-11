/* File : graph.c */

#include "graph.h"
#include "listlinier.h"
#include "point.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

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
    int i,j;
    for (i=0;i<n;++i)
    {
        CreateEmptyList(&L);
        for (j=0;j<4;++j) InsVLastList(&L,NodeUndef);
        InsVLastGraph(G,L);
    }
}

/*** JUMLAH ELEMEN ***/
int NbElmtGraph(Graph G)
/* mengeluarkan jumlah node pada graph G */
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

void GenerateRandomGraph(Graph *G,int n)
/* I.S. G sembarang */
/* F.S. G adalah connected graph dengan n node */
/* G didapat melalui hasil generate secara random */
{
    CreateEmptyGraph(G);
    ResetGraph(G,n);
    POINT p[n+1];
    p[1] = MakePOINT(0,0);
    int k,m;
    for(k=2;k<=n;++k)
    {
        POINT P = p[k-1];
        int dir = (rand()%4);
        switch (dir)
        {
            case 0 : p[k] = PrevX(P); break;
            case 1 : p[k] = NextY(P); break;
            case 2 : p[k] = NextX(P); break;
            case 3 : p[k] = PrevY(P); break;
        }
    }
    addressG PG = FirstG(*G);
    addressL PL;
    List L;
    for (k=1;k<=n;++k)
    {
        L = Info(PG);
        PL = FirstL(L);
        for (m=1;m<=n;++m)
        {
            if (EQPoint(p[m],PrevX(p[k]))) Info(PL) = m;
            else if (EQPoint(p[m],NextY(p[k]))) Info(Next(PL)) = m;
            else if (EQPoint(p[m],NextX(p[k]))) Info(Next(Next(PL))) = m;
            else if (EQPoint(p[m],PrevY(p[k]))) Info(Next(Next(Next(PL)))) = m;
        }
        PG = Next(PG);
    }
}
