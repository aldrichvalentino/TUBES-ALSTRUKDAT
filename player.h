/* File: player.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "mesinkata.h"
#include "point.h"
#include "matriks.h"

//#include "tree.h"
/* *** Definisi TYPE PLAYER *** */
typedef struct {
	Kata NAME;
	int HP;
	int STR;
	int DEF;
	int EXP;
	POINT POS;
	// BinTree SKILL;
} PLAYER;

/* *** Notasi Akses: selektor PLAYER *** */
#define PName(P) (P).NAME
#define PHP(P) (P).HP
#define PSTR(P) (P).STR
#define PDEF(P) (P).DEF
#define PEXP(P) (P).EXP
#define Posisi(P) (P).POS
#define PosisiX(P) (P).POS.X
#define PosisiY(P) (P).POS.Y
// #define PSkill(P) (P).SKILL

void CreateEmptyPlayer(PLAYER *P, Kata X);
/* Membuat Player dengan nama X, exp = 0 */

void InitiatePos(PLAYER *P,MATRIKS *M, int dir);
/* (analisis kasus di caller)
 I.S: Posisi player tdk terdefinisi (-1,-1) atau di WayOut map awal tergantung dir,
 matriks tidak ada player, dir 0: mau player muncul di kiri map baru, 1(up), 2(right), 3(down)
 F.S: Posisi player di salah satu WayOut map baru, matriks jadi ada playernya.

 void Jalan(PLAYER *P, MATRIKS *M,int dir, char *C, POINT *po);
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: pos Player berubah, matriks jadi gaada playernya (diisi '-'), output
  char C apa yang diinjek: M,E,#,-, po menyimpan posisi sebelum jalan. */

void SwitchPos(PLAYER *P,MATRIKS *M, POINT Po);
/* I.S. Pemain akan pindah map, M matriks setelah pindah dan Po adalah titiknya */
/* F.S. Pemain sudah berada di Po dan matriks sudah ada cplayer */

void Jalan(PLAYER *P, MATRIKS *M,int dir, char *C, POINT *po);
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: pos Player berubah, matriks jadi gaada playernya (diisi '-'), output
  char C apa yang diinjek: M,E,#,-, po menyimpan posisi sebelum jalan. */

void BacaCommand (PLAYER *P, MATRIKS *M, char *mode); //parameter lain menyusul
/*	(looping di caller)
	I.S: menerima input keyboard GL GU GR GD SKILL SAVE LOAD EXIT
	F.S: output char mode F: salah command,S: save, L: load, K: skill, E: exit, G*/

#endif

