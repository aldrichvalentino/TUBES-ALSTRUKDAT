/* File : graph.h */
/* Definisi ADT Graph */
/* Menggunakan array of list */

#ifndef GRAPH_H
#define GRAPH_H

#include "boolean.h"
#include "listlinier.h"

/* Kamus umum */
#define IdxMax 10
#define IdxMin 1
#define IdxUndef -999

/* Definisi tipe graph */
typedef int IdxType; /* tipe indeks */
typedef struct
{
    List list[IdxMax+1]; /* memori tempat menyimpan elemen */
    int neff; /* nilai efektif tabel */
} Graph;

/* SELEKTOR */
#define NeffG(G) (G).neff
#define List(G,i) ((G).list)[i]
#define FirstList(G,i) ((G).list[i]).First

void MakeEmptyGraph(Graph *G);
/* I.S. G sembarang */
/* F.S. Terbentuk graph kosong */

IdxType GetFirstIdx(Graph G);
/* Mengeluarkan indeks minimum */

IdxType GetLastIdx(Graph G);
/* Mengeluarkan indeks terakhir */

IdxType GetLastIdxEff(Graph G);
/* Mengeluarkan indeks terakhir yang efektif */

int MaxNbEl(Graph G);
/* mengeluarkan nilai maksimum yang dapat ditampung */

boolean IsEmptyG(Graph G);
/* mengeluarkan true jika graph G kosong */

boolean IsFullG(Graph G);
/* mengeluarkan true jika graph G penuh */

void SetFirst(Graph *G);
/* I.S. G sembarang, G tidak penuh */
/* F.S. Neff dari G bertambah satu dan first sudah dialokasi */
/* First dialokasi, jika alokasi gagal, maka IS=FS*/

void ResetGraph(Graph *G, int n);
/* I.S. Graph G kosong, n <= MaxNbEL(G) */
/* F.S. Terbentuk Graph dengan neff = n namun kosong */

int GoTo(Graph G, int now, int n);
/* berpindah ke graph lain yang adjacent dengan dia */
/* Jika n=1 pindah ke kiri
        n=2 pindah ke atas
        n=3 pindah ke kanan
        n=4 pindah ke bawah
*/

#endif // GRAPH_H

