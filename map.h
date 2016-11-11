/* File : map.h */
/* Definisi peta pada game */
/* Menggunakan representasi graph sebagai map besar
    dan setiap node mempunyai matriks yang bersesuaian
    sebagai map kecil */

#ifndef MAP_H
#define MAP_H

#include "boolean.h"
#include "graph.h"
#include "matriks.h"
#include "enemy.h"

#define MaxNode 10
#define MaxEnemy 10 /* Max musuh pada satu minimap */

typedef struct {
    ENEMY EMap[MaxEnemy+1]; /* Menyatakan musuh apa saja yang terdapat pada map */
    POINT pos[MaxEnemy+1]; /* Menyatakan posisi dari musuh di TE */
    int Neff;
} TEMap; /*Data musuh dan posisi masing-masing dalam bentuk tabel */
typedef struct {
    MATRIKS mat; /* bentuk map */
    TEMap enem;
} MiniMap;
typedef struct {
    Graph gr; /* Representasi map besar yang menghubungkan map-map kecil */
    MiniMap m[MaxNode+1]; /* Representasi bentuk dari tiap node pada graph */
    int node; /* Jumlah node */
} Map;

/* Graph dengan infotypeG adalah int menyatakan minimap apa saja yang terhubung */

/* Daftar Selektor */
#define NeffM(T) (T).Neff
#define Pos(T,i) ((T).pos)[(i)]
#define EMap(T,i) ((T).EMap)[(i)]
#define Mat(M) (M).mat
#define ElmtMat(M,i,j) ((M).mat)[(i)][(j)]
#define LEn(M) (M).enem
#define Node(M) (M).node
#define Gr(M) (M).gr
#define ElMini(M,i) ((M).m)[(i)]
#define Mini(M) (M).m

/* ********** Make Empty ********** */
void CreateEmptyTEMap(TEMap *T);
/* I.S. T sembarang */
/* F.S. neff(T) = 0, T tidak berisi informasi apapun */
void MakeEmptyMiniMap(MiniMap *M,int NB, int NK);
/* I.S. M sembarang */
/* F.S. M merupakan minimap dengan ukuran NBxNK dan tanpa musuh dan tanpa medicine */
void CreateEmptyMap(Map *M);
/* I.S. M sembarang */
/* F.S. M kosong, jumlah node 0, graph dan minimap kosong */

/* ********** Pencarian ********** */
int SearchPos1(TEMap T,POINT P);
/* Mengeluarkan indeks di tabel T dimana P tersimpan, mengeluarkan 0 jika tidak ada di map */
ENEMY SearchPos2(TEMap T,POINT P);
/* mengeluarkan enemy yang terletak pada posisi P, mengeluarkan Undefined jika tidak ada enemy */

/* ********** Predikat ********** */
boolean IsEmptyTEMap(TEMap T);
/* Mengeluarkan true jika T kosong */
boolean IsFullTEMap(TEMap T);
/* Mengeluarkan true jika T penuh */
boolean IsOccupied(MiniMap M, POINT P);
/* Mengeluarkan true jika terdapat musuh di P */

/* ********** Operasi random ********** */
void GenerateRandomWayOut(MATRIKS *M,List L);
/* I.S. M merupakan bentuk minimap yang belum terdapat jalan keluar, L terdefinsi merupakan list
    minimap yang adjacent dengan matriks M */
/* F.S. M sudah terdapat jalur keluar masuk */

/* ********** Insialisasi Map ********** */
void InitMap(MiniMap *M,int NB ,int NK,List L);
/* I.S. M sembarang, NB dan NK valid */
/* F.S. M terbentuk merupakan map berukuran NBxNK */
/* Terbentuk dengan generate secara random */
void InitAllMap(Map *M,int NB,int NK,int n);
/* I.S. M sembarang */
/* F.S. Seluruh bagian map sudah terdefinisi dengan n node dan masing-masing
    matriks berukuran NBxNK */
/* Proses dengan genrate random */

#endif // MAP_H
