/* File: player.c */
#include <stdio.h>
#include "color.h"
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
            case 'E' : InitBattle(P,T,&win); if (win) SwitchPos(P,M,po); break;
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

void PrintGame(PLAYER P)
{
	clrscr();
	int i;
	PrintBorder();
	PrintKata(PName(P));
	i = 15 - PName(P).Length;
	PrintCLoop(' ', i);
	PrintGuard();
	
	printf("LVL : %d", PLevel(P));
	i = 4 - digit(PLevel(P));
	PrintCLoop(' ', i);
	PrintGuard();
	
	printf("HP : %d", PHP(P));
	i = 4 - digit(PHP(P));
	PrintCLoop(' ', i);
	printf(" "); //karena "H""P" hanya 2 huruf jadi ditambah 1 spasi biar sama panjang
	PrintGuard();
	
	printf("STR : %d", PSTR(P));
	i = 4 - digit(PSTR(P));
	PrintCLoop(' ', i);
	PrintGuard();
	
	printf("DEF : %d", PDEF(P));
	i = 4 - digit(PDEF(P));
	PrintCLoop(' ', i);
	PrintGuard();
	
	printf("EXP : %d", PEXP(P));
	i = 4 - digit(PEXP(P));
	PrintCLoop(' ', i);
	printf("\n");
	PrintBorder();
	
	PrintMap();
	PrintBorder();

	printf("<narasi baris 1>\n");
	printf("<narasi baris 2>\n");
	PrintBorder();

	printf("Command : ");
}

void PrintCLoop(char c, int x)
{
	int i = 1;
	while (i<=x)
	{
		printf("%c",c);
		i++;
	}
}

int digit(int X)
{
	if (X>=0 && X<=9)
	{
		return 1;
	}
	else
	{
		return 1+digit(X/10);
	}
}

