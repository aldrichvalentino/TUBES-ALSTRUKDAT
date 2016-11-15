/* File: player.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "mesinkata.h"
#include "matriks.h"
//#include "map.h"
#include "point.h"

//#include "tree.h"
/* *** Definisi TYPE PLAYER *** */
typedef struct {
	Kata NAME;
	int HP;
	int STR;
	int DEF;
	int EXP;
	int LEVEL;
	POINT POS;
	// BinTree SKILL;
} PLAYER;

/* *** Notasi Akses: selektor PLAYER *** */
#define PName(P) (P).NAME
#define PHP(P) (P).HP
#define PSTR(P) (P).STR
#define PDEF(P) (P).DEF
#define PEXP(P) (P).EXP
#define PLevel(P) (P).LEVEL
#define PosisiX(P) (P).POS.X
#define PosisiY(P) (P).POS.Y
// #define PSkill(P) (P).SKILL

void clrscr();
void CreateEmptyPlayer(PLAYER *P, Kata X);
/* Membuat Player dengan nama X, exp = 0, level = 1 */
void DarahNaik(PLAYER *P);
/* I.S. Player terdefinisi */
/* F.S. HP player ditambah cmedicine */
void SwitchPos(PLAYER *P,MATRIKS *M, POINT Po);
/* I.S. Pemain akan pindah map, M matriks setelah pindah dan Po adalah titiknya */
/* F.S. Pemain sudah berada di Po dan matriks sudah ada cplayer */
void Jalan(PLAYER *P, MATRIKS *M, int dir);
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: posisi player bisa berubah/nggak, matriks bisa jadi gaada playernya,diisi '-'*/
void BacaCommand (PLAYER *P, MATRIKS *M, char *mode);
//parameter lain menyusul
/*	(looping di caller)
	I.S: menerima input keyboard GL GU GR GD SKILL SAVE LOAD EXIT
	F.S: output char mode F: salah command,S: save, L: load, K: skill, E: exit, G*/
#endif

