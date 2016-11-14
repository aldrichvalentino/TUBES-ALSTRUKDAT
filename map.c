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
POINT SearchWayIn(int M)
/* Mencari point jalan masuk jika player sebelumnya berada di CMap dan akan pergi ke MiniMap M */
/* Asumsi : CMap dan M adalah dua map yang saling adjacent pada CMap */
{
    int i = SearchInfoGraph(SearchGraph(Gr(CMap),CMiniMap),M);
    POINT P;
    MATRIKS Mat = Mat(ElMini(CMap,M));
    switch (i)
    {
        case 1 : P = MakePOINT(GetFirstIdxKol(Mat)+1,GetFirstIdxBrs(Mat)); while (!IsAvail(Mat,P)) P = NextX(P); break;
        case 2 : P = MakePOINT(GetFirstIdxKol(Mat),GetFirstIdxBrs(Mat)+1); while (!IsAvail(Mat,P)) P = NextY(P); break;
        case 3 : P = MakePOINT(GetFirstIdxBrs(Mat)+1,GetLastIdxKol(Mat)); while (!IsAvail(Mat,P)) P = NextX(P); break;
        case 4 : P = MakePOINT(GetLastIdxBrs(Mat),GetFirstIdxKol(Mat)+1); while (!IsAvail(Mat,P)) P = NextY(P); break;
    }
    return P;
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
/* Mengeluarkan true jika terdapat musuh atau medicine di P */
{
    return ((SearchPos1(LEn(M),P))||(Elmt2(M,P)=='M');
}
boolean IsAvail(MATRIKS M, POINT P)
/* Mengeluarkan true jika P dapat diisi dengan musuh atau medicine */
{
    return (Elmt2(M,P)=='-');
}

/* ********** Akses Elemen ********** */
void SetAvail(MATRIKS *M, POINT P)
/* I.S. Point P bukan '-' */
/* F.S. POINT P berisi nilai '-' (available) */
{
    SetElmt(M,P,'-');
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
        while (!IsAvail(*M,temp));
        while (Ordinat(temp)>GetFirstIdxKol(*M))
        {
            temp = PrevY(temp);
            SetAvail(M,temp);
        }
    }
    P = Next(P);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (!IsAvail(*M,temp));
        while (Absis(temp)>GetFirstIdxBrs(*M))
        {
            temp = PrevX(temp);
            SetAvail(M,temp);
        }
    }
    P = Next(P);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (!IsAvail(*M,temp));
        while (Ordinat(temp)<GetLastIdxKol(*M))
        {
            temp = NextY(temp);
            SetAvail(M,temp);
        }
    }
    P = Next(P);
    if (Info(P)!=NodeUndef)
    {
        do
            GenerateRandomPOINT(*M,&temp);
        while (!IsAvail(*M,temp));
        while (Absis(temp)<GetLastIdxBrs(*M))
        {
            temp = NextX(temp);
            SetAvail(M,temp);
        }
    }
}
void RandomMed()
/* Player pindah ke minimap lain, merandom kemunculan medicine dan letaknya */
/* mungkin ada medicine mungkin tidak ada */
/* CMiniMap sudah diupdate ke tempat player berpindah*/
{
    int i = rand()%10;
    if (!i)
    {
        MATRIKS M = Mat(ElMini(CMap,CMiniMap));
        POINT P;
        do
            GenerateRandomPOINT(M,&P);
        while (!IsAvail(M,P));
        SetElmt(&(Mat(ElMini(CMap,CMiniMap))),P,'M');
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
void InitAllMap(int NB,int NK,int n)
/* I.S. CMap sembarang */
/* F.S. Seluruh bagian map sudah terdefinisi dengan n node dan masing-masing
    matriks berukuran NBxNK, CMiniMap berisi n */
/* Proses dengan genrate random */
{
    GenerateRandomGraph(&Gr(CMap)),n);
    int i;
    addressG P = FirstG(Gr(CMap));
    for (i=1;i<=n;++i)
    {
        InitMap(&ElMini(CMap,i),NB,NK,Info(P));
        P = Next(P);
    }
    Node(CMap) = n;
    CMiniMap = n;
}
