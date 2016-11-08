/* File: player.c */
#include <stdio.h>
#include "player.h"
#include "matriks.h"
#include "boolean.h"
#include "mesinkata.h"
#include "point.h"
#define cplayer 'P'
#define cmedicine 50
void CreateEmptyPlayer(PLAYER *P, Kata X)
/* Membuat Player dengan nama X, exp = 0,
   HP = STR = DEF = 100, skill = tree kosong */
{
	PName(*P) = X;
	PHP(*P) = 100;
	PSTR(*P) = 100;
	PDEF(*P) = 100;
	PEXP(*P) = 0;
	PosisiX(*P) = -1;
	PosisiY(*P) = -1;
	//MakeTree(A,L,R,PSkill(*P));
}

void InitiatePos(PLAYER *P,MATRIKS *M, int dir)
/* (analisis kasus di caller)
 I.S: Posisi player tdk terdefinisi (-1,-1) atau di WayOut map awal tergantung dir,
 matriks tidak ada player, dir 0: mau player muncul di kiri map baru, 1(up), 2(right), 3(down)
 F.S: Posisi player di salah satu WayOut map baru, matriks jadi ada playernya.
 */
{
	POINT Pos;
	SearchWayOut(M);
	switch (dir){
		case 0: Pos = WayOut(*M,0); break;
		case 1: Pos = WayOut(*M,1); break;
		case 2: Pos = WayOut(*M,2); break;
		case 3: Pos = WayOut(*M,3); break;
	}
	(*P).POS = Pos;
	Elmt(*M,Absis(Pos),Ordinat(Pos)) = cplayer;
}
void Jalan(PLAYER *P, MATRIKS *M,int dir, char *C, POINT *po)
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: pos Player berubah, matriks jadi gaada playernya (diisi '-'), output 
  char C apa yang diinjek: M,E,#,-, po menyimpan posisi sebelum jalan. */
{
	*po=(*P).POS;
	switch (dir){
		case 0 : PosisiY(*P)=Ordinat((*P).POS)-1; break;
		case 1 : PosisiX(*P)=Absis((*P).POS)-1; break;
		case 2 : PosisiY(*P)=Ordinat((*P).POS)+1; break;
		case 3 : PosisiX(*P)=Absis((*P).POS)+1; break;
	}
	*C = Elmt(*M, PosisiX(*P),PosisiY(*P));
	Elmt(*M, Absis(*po),Ordinat(*po))='-';
}
void BacaCommand (PLAYER *P, MATRIKS *M, char *mode) //parameter lain menyusul
/*	(looping di caller)
	I.S: menerima input keyboard GL GU GR GD SKILL SAVE LOAD EXIT
	F.S: output char mode F: salah command,S: save, L: load, K: skill, E: exit, G*/
{
	Kata GL,GU,GR,GD,SKILL,SAVE,LOAD,EXIT;
	GL.TabKata[0]='G'; GL.TabKata[1]='L'; GL.Length=2;
	GU.TabKata[0]='G'; GU.TabKata[1]='U'; GU.Length=2;
	GR.TabKata[0]='G'; GR.TabKata[1]='R'; GR.Length=2;
	GD.TabKata[0]='G'; GD.TabKata[1]='D'; GD.Length=2;
	SKILL.TabKata[0]='S'; SKILL.TabKata[1]='K';	SKILL.TabKata[2]='I'; SKILL.TabKata[3]='L';	SKILL.TabKata[4]='L'; SKILL.Length = 5;
	SAVE.TabKata[0]='S'; SAVE.TabKata[1]='A'; SAVE.TabKata[2]='V'; SAVE.TabKata[3]='E'; SAVE.Length = 4;
	LOAD.TabKata[0]='L'; LOAD.TabKata[1]='O'; LOAD.TabKata[2]='A'; LOAD.TabKata[3]='D'; LOAD.Length = 4;
	EXIT.TabKata[0]='E'; EXIT.TabKata[1]='X'; EXIT.TabKata[2]='I'; EXIT.TabKata[3]='T'; EXIT.Length = 4;
	
	POINT PrecPos;
	char C;
	Kata command;
	InputUser(&command);
	SearchWayOut(M);
	if (IsKataSama(command,GL)){
		Jalan(P,M,0,&C,&PrecPos);
		if (EQPoint(PrecPos,WayOut(*M,0))){
			InitiatePos(P,M,2);	//dari left map awal muncul di right map baru,mustinya M diisi map baru
		}*mode = 'G';
	} else if (IsKataSama(command,GU)){
		Jalan(P,M,1,&C,&PrecPos);
		if (EQPoint(PrecPos,WayOut(*M,1))){
			InitiatePos(P,M,3);//dari atas map awal muncul dibawah map baru,mustinya M diisi map baru
		}*mode = 'G';
	} else if (IsKataSama(command,GR)){
		Jalan(P,M,2,&C,&PrecPos);
		if (EQPoint(PrecPos,WayOut(*M,2))){
			InitiatePos(P,M,0);//dari kanan map awal muncul dikiri map baru,mustinya M diisi map baru
		}*mode = 'G';
	} else if (IsKataSama(command,GD)){
		Jalan(P,M,3,&C,&PrecPos);
		if (EQPoint(PrecPos,WayOut(*M,3))){
			InitiatePos(P,M,1);//dari bawah map awal muncul di atas map baru,mustinya M diisi map baru
		}*mode = 'G';
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
	
	if (*mode=='G')
	{
		switch (C){
		case'-' : Elmt(*M,PosisiX(*P),PosisiY(*P)) = cplayer; break;
		case'M' : Elmt(*M,PosisiX(*P),PosisiY(*P)) = cplayer; PHP(*P)+=cmedicine; break;
		case'#' : 
			(*P).POS = PrecPos;
			Elmt(*M,PosisiX(*P),PosisiY(*P)) = '#';
			Elmt(*M,Absis(PrecPos),Ordinat(PrecPos)) = cplayer;
			break;
		case'E' : //masukkan prosedur battle disini
			/*if (menang)
			{
				Elmt(*M,PosisiX(*P),PosisiY(*P)) = cplayer;
			}
			else*/
			{
				(*P).POS = PrecPos;
				Elmt(*M,PosisiX(*P),PosisiY(*P)) = '-';
				Elmt(*M,Absis(PrecPos),Ordinat(PrecPos)) = cplayer;
			}
			break;	
		}
	}
}
