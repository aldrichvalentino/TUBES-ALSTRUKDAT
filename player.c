/* File: player.c */
#include <stdio.h>
#include "player.h"
#include "matriks.h"
#include "boolean.h"
#include "mesinkata.h"
#include "point.h"
#include "battle.h"
#include "map.h"
#include <stdlib.h>
#define cplayer 'P'
#define cmedicine 50

void clrscr()
{
	system("@cls||clear");
}

void CreateEmptyPlayer(PLAYER *P, Kata X)
/* Membuat Player dengan nama X, exp = 0,
   HP = STR = DEF = 100, skill = tree kosong */
{
	PName(*P) = X;
	PHP(*P) = 100;
	PSTR(*P) = 100;
	PDEF(*P) = 100;
	PEXP(*P) = 0;
	PLevel(*P) = 1;
	Posisi(*P) = MakePOINT(-1,-1);
	//MakeTree(A,L,R,PSkill(*P));
}

void DarahNaik(PLAYER *P)
/* I.S. Player terdefinisi */
/* F.S. HP player ditambah cmedicine */
{
	PHP(*P)+=cmedicine;
}

void SwitchPos(PLAYER *P,MATRIKS *M, POINT Po)
/* I.S. Pemain akan pindah map, M matriks setelah pindah dan Po adalah titiknya */
/* F.S. Pemain sudah berada di Po dan matriks sudah ada cplayer */
{
    SetElmt(&Mat(ElMini(CMap,CMiniMap)),Posisi(*P),'-');
    Posisi(*P) = Po;
    SetElmt(M,Po,cplayer);
}

void Jalan(PLAYER *P, MATRIKS *M, int dir,TE T)
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: posisi player bisa berubah/nggak, matriks bisa jadi gaada playernya,diisi '-'*/
{
    POINT po;
    char C;
    boolean win;
	switch (dir){
		case 0 : po = PrevY(Posisi(*P)) ; break;
		case 1 : po = PrevX(Posisi(*P)) ; break;
		case 2 : po = NextY(Posisi(*P)) ; break;
		case 3 : po = NextX(Posisi(*P)) ; break;
	}
	if (!IsIdxEff2(*M,po)) SwitchMap(P,dir);
	else
    {
        C = Elmt2(*M,po);
        switch (C)
        {
            case 'M' : SwitchPos(P,M,po); DarahNaik(P); break;
            case 'E' : InitBattle(P,&win,T); if (win) SwitchPos(P,M,po); break;
            case '-' : SwitchPos(P,M,po); break;
            case '#' : break;
        }
    }
}

void InitPosPlayer(PLAYER *P,MATRIKS *M)
/* I.S. game dimulai */
/* F.S. Posisi player sudah ditentukan */
{
    POINT Po;
    do
        GenerateRandomPOINT(*M,&Po);
    while (Elmt2(*M,Po)!='-');
    Posisi(*P) = Po;
    SetElmt(M,Po,cplayer);
}
