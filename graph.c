/* File : graph.c */

#include "graph.h"
#include "listlinier.h"

void MakeEmptyGraph(Graph *G)
/* I.S. G sembarang */
/* F.S. Terbentuk graph kosong */
{
    NeffG(*G) = 0;
}

IdxType GetFirstIdx(Graph G)
/* Mengeluarkan indeks minimum */
{
    return IdxMin;
}

IdxType GetLastIdx(Graph G)
/* Mengeluarkan indeks terakhir */
{
    return (IdxMax-IdxMin+1);
}

IdxType GetLastIdxEff(Graph G)
/* Mengeluarkan indeks terakhir yang efektif */
{
    return (NeffG(G)-IdxMin+1);
}

int MaxNbEl(Graph G)
/* mengeluarkan nilai maksimum yang dapat ditampung */
{
    return (IdxMax-IdxMin+1);
}

boolean IsEmptyG(Graph G)
/* mengeluarkan true jika graph G kosong */
{
    return (NeffG(G)==0);
}

boolean IsFullG(Graph G)
/* mengeluarkan true jika graph G penuh */
{
    return (NeffG(G)==MaxNbEl(G));
}

void SetFirst(Graph *G)
/* I.S. G sembarang, G tidak penuh */
/* F.S. Neff dari G bertambah satu dan first sudah dialokasi */
/* First dialokasi, jika alokasi gagal, maka IS=FS*/
{
    address P = Alokasi(0);
    if (P!=Nil)
    {
        ++NeffG(*G);
        FirstList(*G,GetLastIdxEff(*G)) = P;
    }
}

void ResetGraph(Graph *G, int n)
/* I.S. Graph G kosong, n <= MaxNbEL(G) */
/* F.S. Terbentuk Graph dengan neff = n namun kosong */
{
    int i;
    for (i = GetFirstIdx(*G);i<GetFirstIdx(*G)+n;++i)
    {
        FirstList(*G,i) = Nil;
    }
    NeffG(*G) = n;
}

int GoTo(Graph G, int now, int n)
/* berpindah ke graph lain yang adjacent dengan dia */
/* Jika n=1 pindah ke kiri
        n=2 pindah ke atas
        n=3 pindah ke kanan
        n=4 pindah ke bawah
*/
{
    address P = FirstList(G,now);
    int cnt = n;
    while (n>1)
    {
        P = Next(P);
        --n;
    }
}
