/* File: player.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "mesinkata.h"
//#include "tree.h"
/* *** Definisi TYPE PLAYER *** */
typedef struct { 
	Kata NAME;
	int HP;
	int STR;
	int DEF;
	int EXP;
	// BinTree SKILL;
} PLAYER;

/* *** Notasi Akses: selektor PLAYER *** */
#define PName(P) (P).NAME
#define PHP(P) (P).HP
#define PSTR(P) (P).STR
#define PDEF(P) (P).DEF
#define PEXP(P) (P).EXP
// #define PSkill(P) (P).SKILL

void CreateEmptyPlayer(PLAYER *P, Kata X);
/* Membuat Player dengan nama X, exp = 0 */
#endif

