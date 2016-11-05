/* File: player.c */
#include "player.h"

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

