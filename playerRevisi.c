/* File: player.c */
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#define cplayer 'P'
#define cmedicine 50


void clrscr()
{
	system("@cls||clear");
}
void CreateEmptyPlayer (PLAYER *P, Kata X)
//Membuat Player dengan nama X, exp = 0,
//HP = STR = DEF = 100, skill = tree kosong
{
	PName(*P) = X;
	PHP(*P) = 100;
	PSTR(*P) = 100;
	PDEF(*P) = 100;
	PEXP(*P) = 0;
	PLevel(*P) = 1;
	PosisiX(*P) = -1;
	PosisiY(*P) = -1;
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
    (*P).POS = Po;
    SetElmt(M,Po,cplayer);
}
void Jalan(PLAYER *P, MATRIKS *M, int dir)
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: posisi player bisa berubah/nggak, matriks bisa jadi gaada playernya,diisi '-'*/
{
	POINT po = (*P).POS;
	char C;
	switch (dir){
		case 0 : Ordinat(po)=Ordinat((*P).POS)-1; break;
		case 1 : Absis(po)=Absis((*P).POS)-1; break;
		case 2 : Ordinat(po)=Ordinat((*P).POS)+1; break;
		case 3 : Absis(po)=Absis((*P).POS)+1; break;
	}
	if (Ordinat(po) < GetFirstIdxKol(*M))
	{
		//SwitchMap(P,0);
	}
	else if (Ordinat(po) > GetLastIdxKol(*M))
	{
		//SwitchMap(P,2);
	}
	else if (Absis(po) < GetFirstIdxBrs(*M))
	{
		//SwitchMap(P,1);
	} 
	else if (Absis(po) > GetLastIdxBrs(*M))
	{
		//SwitchMap(P,3);
	}
	else
	{
		C = Elmt(*M, Ordinat(po),Absis(po));
		switch(C){
			case 'M' : 
				(*P).POS = po;
				Elmt(*M, PosisiX(*P), PosisiY(*P))='-';
				Elmt(*M, Absis(po), Ordinat(po))=cplayer;
				DarahNaik(P);
				break;
			case 'E' : 
				//panggil Battle();
				/* if menang then
				(*P).POS = po;
				Elmt(*M, PosisiX(*P), PosisiY(*P))='-';
				Elmt(*M, Absis(po), Ordinat(po))=cplayer;
				else do nothing
				*/ 
				break;
			case '-' :
				(*P).POS = po;
				Elmt(*M, PosisiX(*P), PosisiY(*P))='-';
				Elmt(*M, Absis(po), Ordinat(po))=cplayer;
				break;
			case '#' :
				//do nothing
				break;
		}
	}
}


void BacaCommand (PLAYER *P, MATRIKS *M, char *mode) //parameter lain menyusul
/*	(looping di caller)
	I.S: menerima input keyboard GL GU GR GD SKILL SAVE LOAD EXIT
	F.S: output char mode F: salah command,S: save, L: load, K: skill, E: exit, G*/
{
	Kata GL,GU,GR,GD,SKILL,SAVE,LOAD,EXIT;
	CreateKata("GL",&GL);
	CreateKata("GU",&GU);
	CreateKata("GD",&GD);
	CreateKata("GR",&GR);
	CreateKata("SKILL",&SKILL);
	CreateKata("SAVE",&SAVE);
	CreateKata("LOAD",&LOAD);
	CreateKata("EXIT",&EXIT);

	Kata command;
	InputUser(&command);
	
	if (IsKataSama(command,GL)){
		Jalan(P,M,0);
		*mode = 'G';
	} else if (IsKataSama(command,GU)){
		Jalan(P,M,1);
		*mode = 'G';
	} else if (IsKataSama(command,GR)){
		Jalan(P,M,2);
		*mode = 'G';
	} else if (IsKataSama(command,GD)){
		Jalan(P,M,3);
		*mode = 'G';
	} else if (IsKataSama(command,SKILL)){
		*mode = 'K';
		printf("ceritanya skill 1: A, skill 2: B\n");
	} else if (IsKataSama(command,SAVE)){
		*mode = 'S';
		printf("ceritanya save successful\n");
	} else if (IsKataSama(command,LOAD)){
		*mode = 'L';
		printf("ceritanya load successful\n");
	} else if (IsKataSama(command,EXIT)){
		*mode = 'E';
		printf("thanks for playing\n");
	} else 	{
		*mode ='F';
		printf("salah nih, case sensitive loh\n");
	}
}
