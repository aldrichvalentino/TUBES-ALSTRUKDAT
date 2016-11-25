/* File : map.c */

#include "color.h"
#include "map.h"
#include "player.h"
#include "battle.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CMiniMap;
Map CMap;

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
POINT SearchWayIn(int M,int dir)
/* Mencari point jalan masuk jika player sebelumnya berada di CMap dan akan pergi ke MiniMap M */
/* Asumsi : CMap dan M adalah dua map yang saling adjacent pada CMap */
{
    POINT P;
    MATRIKS Mat = Mat(ElMini(CMap,M));
    switch (dir)
    {
        case 0 : P = MakePOINT(GetFirstIdxBrs(Mat)+1,GetLastIdxKol(Mat)); while (!IsAvail(Mat,P)) P = NextX(P); break;
        case 1 : P = MakePOINT(GetLastIdxBrs(Mat),GetFirstIdxKol(Mat)+1); while (!IsAvail(Mat,P)) P = NextY(P); break;
        case 2 : P = MakePOINT(GetFirstIdxBrs(Mat)+1,GetFirstIdxKol(Mat)); while (!IsAvail(Mat,P)) P = NextX(P); break;
        case 3 : P = MakePOINT(GetFirstIdxBrs(Mat),GetFirstIdxKol(Mat)+1); while (!IsAvail(Mat,P)) P = NextY(P); break;
    }
    return P;
}

/* ********** Penambahan/Pengurangan Elemen ********** */
void InsertLast(TEMap *T,ENEMY E,POINT P)
/* I.S. T tidak penuh, E terdefinisi */
/* F.S. E dimasukkan sebagai elemen terakhir dari T */
{
    if (!IsFullTEMap(*T))
    {
        ++NeffM(*T);
        EMap(*T,NeffM(*T)) = E;
        Pos(*T,NeffM(*T)) = P;
    }
}
void DeleteTEMap(TEMap *T,POINT P)
/* I.S. T terdefinisi, terdapat musuh di point P */
/* F.S. elemen musuh di poin p dihapus, sisanya digeser */
{
    --NeffM(*T);
    int i = SearchPos1(*T,P);
    int j,k=NeffM(*T);
    for (j=i;j<=k;++j)
    {
        EMap(*T,j) = EMap(*T,j+1);
        Pos(*T,j) = Pos(*T,j+1);
    }
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
/* I.S. Player pindah ke minimap lain */
/* F.S. Merandom kemunculan medicine dan letaknya, mungkin ada medicine mungkin tidak ada */
/* CMiniMap sudah diupdate ke tempat player berpindah*/
{
    int i = rand()%5;
    if (i==1)
    {
        MATRIKS M = Mat(ElMini(CMap,CMiniMap));
        POINT P;
        do
            GenerateRandomPOINT(M,&P);
        while (!IsAvail(M,P));
        SetElmt(&Mat(ElMini(CMap,CMiniMap)),P,'M');
        TulisPOINT(P);
    }
}
void RandomEnemy()
/* I.S. Player pindah ke minimap lain */
/* F.S. Merandom kemunculan enemy dan letaknya, mungkin ada enemy atau tidak */
/* CMiniMap sudah diupdate ke tempat player berpindah */
{
    int i = rand()%10;
    POINT P;
    MATRIKS M = Mat(ElMini(CMap,CMiniMap));
    if (i==1)
    {
        do
            GenerateRandomPOINT(M,&P);
        while (!IsAvail(M,P));
        SetElmt(&Mat(ElMini(CMap,CMiniMap)),P,'E');
        InsertLast(&LEn(ElMini(CMap,CMiniMap)),EnemUndef(),P);
        do
            GenerateRandomPOINT(M,&P);
        while (!IsAvail(Mat(ElMini(CMap,CMiniMap)),P));
        SetElmt(&Mat(ElMini(CMap,CMiniMap)),P,'E');
        InsertLast(&LEn(ElMini(CMap,CMiniMap)),EnemUndef(),P);
    }
    else if (2*i<10-NeffM(LEn(ElMini(CMap,CMiniMap))))
    {
        do
            GenerateRandomPOINT(M,&P);
        while (!IsAvail(M,P));
        SetElmt(&Mat(ElMini(CMap,CMiniMap)),P,'E');
        InsertLast(&LEn(ElMini(CMap,CMiniMap)),EnemUndef(),P);
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
    GenerateRandomGraph(&Gr(CMap),n);
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
void SwitchMap(PLAYER *P, int i)
/* I.S. i angka antara 0 sampai 3 inklusif */
/* Player berpindah map, kiri jika 0, atas jika 1, kanan jika 2, bawah jika 3 */
{
    infotypeG L = SearchGraph(Gr(CMap),CMiniMap);
    int j;
    addressL Padr = FirstL(L);
    for (j=0;j<i;++j) Padr = Next(Padr);
    POINT Po = SearchWayIn(Info(Padr),i);
    SwitchPos(P,&Mat(ElMini(CMap,Info(Padr))),Po);
    CMiniMap = Info(Padr);
    RandomMed();
    RandomEnemy();
}

/* ********** Penulisan Map ********** */
void PrintMap()
/* Menampilkan map yang sedang aktif di layar */
{
    MATRIKS M;
    indeks i,j;
    M = (Mat(ElMini(CMap,CMiniMap)));

    for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++)
    {
		PrintCLoop(' ',22);
        for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
            //1m=bold,black 30, red 31, green 32, brown 33, blue 34, magenta 35, cyan 36, lgrey 37
            switch (Elmt(M,i,j)){
				case 'P' : printf(COLOR_LGREEN "%c " COLOR_RESET, Elmt(M,i,j));break;
				case 'M' : printf(COLOR_WHITE "%c " COLOR_RESET, Elmt(M,i,j));break;
				case 'E' : printf(COLOR_LRED "%c " COLOR_RESET, Elmt(M,i,j));break;
				case '#' : printf(COLOR_CYAN "%c " COLOR_RESET, Elmt(M,i,j));break;
				case '-' : printf(COLOR_GREY "%c " COLOR_RESET, Elmt(M,i,j));break;
				default : printf("%c ",Elmt(M,i,j));break;
			}
        }
        printf("\n");
    }
}
