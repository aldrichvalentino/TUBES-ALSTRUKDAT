/* File : map.c */

#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CreateEmptyTEMap(TEMap *T)
/* I.S. T sembarang */
/* F.S. neff(T) = 0, T tidak berisi informasi apapun */
{
    NeffM(*T) = 0;
}
void MakeEmptyMiniMap(MiniMap *M,int NB, int NK)
/* I.S. M sembarang */
/* F.S. M merupakan minimap dengan ukuran NBxNK dan tanpa musuh dan tanpa medicine */
{
    CreateEmptyTEMap(&LEn(*M));
    MakeMATRIKS(NB,NK,&Mat(*M));
}
void CreateEmptyMap(Map *M)
/* I.S. M sembarang */
/* F.S. M kosong, jumlah node 0, graph dan minimap kosong */
{
    Node(*M) = 0;
}

/* ********** Pencarian ********** */
int SearchPos1(TEMap T,POINT P)
/* Mengeluarkan indeks di tabel T dimana P tersimpan, mengeluarkan 0 jika tidak ada di map */
{
    Pos(T,0) = P;
    int i = NeffM(T);
    while (NEQPoint(Pos(T,i),P))
        --i;
    return i;
}
ENEMY SearchPos2(TEMap T,POINT P)
/* mengeluarkan enemy yang terletak pada posisi P, mengeluarkan Undefined jika tidak ada enemy */
{
    int i = SearchPos1(T,P);
    if (i==0) return EnemUndef();
    else return EMap(T,i);
}

/* ********** Predikat ********** */
boolean IsEmptyTEMap(TEMap T)
/* Mengeluarkan true jika T kosong */
{
    return (NeffM(T)==0);
}
boolean IsFullTEMap(TEMap T)
/* Mengeluarkan true jika T penuh */
{
    return (NeffM(T)==MaxEnemy);
}
boolean IsOccupied(MiniMap M, POINT P)
/* Mengeluarkan true jika terdapat musuh di P */
{
    return (SearchPos1(LEn(M),P));
}

/* ********** Operasi random ********** */
void GenerateRandomWayOut(MATRIKS *M,List L)
/* I.S. M merupakan bentuk minimap yang belum terdapat jalan keluar, L terdefinsi merupakan list
    minimap yang adjacent dengan matriks M */
/* F.S. M sudah terdapat jalur keluar masuk */
{
    POINT temp;
    addressL P = FirstL(L);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (Elmt2(*M,temp)!='-');
        while (Ordinat(temp)>GetFirstIdxKol(*M))
        {
            temp = PrevY(temp);
            SetElmt(M,temp,'-');
        }
    }
    P = Next(P);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (Elmt2(*M,temp)!='-');
        while (Absis(temp)>GetFirstIdxBrs(*M))
        {
            temp = PrevX(temp);
            SetElmt(M,temp,'-');
        }
    }
    P = Next(P);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (Elmt2(*M,temp)!='-');
        while (Ordinat(temp)<GetLastIdxKol(*M))
        {
            temp = NextY(temp);
            SetElmt(M,temp,'-');
        }
    }
    P = Next(P);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (Elmt2(*M,temp)!='-');
        while (Absis(temp)<GetLastIdxBrs(*M))
        {
            temp = NextX(temp);
            SetElmt(M,temp,'-');
        }
    }
}

/* ********** Insialisasi Map ********** */
void InitMap(MiniMap *M,int NB ,int NK,List L)
/* I.S. M sembarang, NB dan NK valid , L terdefinisi adalah list of adjacent node*/
/* F.S. M terbentuk merupakan map berukuran NBxNK */
/* Terbentuk dengan generate secara random */
{
    CreateEmptyTEMap(&LEn(*M));
    MakeMATRIKS(NB,NK,&Mat(*M));
    GenerateRandomMatriks(&Mat(*M));
    GenerateRandomWayOut(&Mat(*M),L);
}
void InitAllMap(Map *M,int NB,int NK,int n)
/* I.S. M sembarang */
/* F.S. Seluruh bagian map sudah terdefinisi dengan n node dan masing-masing
    matriks berukuran NBxNK */
/* Proses dengan genrate random */
{
    GenerateRandomGraph(&Gr(*M),n);
    int i;
    addressG P = FirstG(Gr(*M));
    for (i=1;i<=n;++i)
    {
        InitMap(&ElMini(*M,i),NB,NK,Info(P));
        P = Next(P);
    }
    Node(*M) = n;
}

int main()
{
    srand((unsigned)time(NULL));
    MATRIKS M;
    MakeMATRIKS(20,20,&M);
    for (int i=1;i<=10;++i)
    {
        GenerateRandomMatriks(&M);
        TulisMATRIKS(M);
        printf("\n%d\n",i);
    }
    return 0;
}
