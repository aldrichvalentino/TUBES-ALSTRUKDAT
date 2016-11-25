/* File: player.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT JAM */

#ifndef PLAYER_H
#define PLAYER_H

#include "boolean.h"
#include "mesinkata.h"
#include "point.h"
#include "enemy.h"
#include "matriks.h"

//#include "tree.h"
/* *** Definisi TYPE PLAYER *** */
typedef struct {
	Kata NAME;
	int HP;
	int MaxHP;
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
#define MaxHP(P) (P).MaxHP
#define PSTR(P) (P).STR
#define PDEF(P) (P).DEF
#define PEXP(P) (P).EXP
#define PLevel(P) (P).LEVEL
#define Posisi(P) (P).POS
#define PosisiX(P) (P).POS.X
#define PosisiY(P) (P).POS.Y
// #define PSkill(P) (P).SKILL


void clrscr();

void CreateEmptyPlayer(PLAYER *P, Kata X);
/* Membuat Player dengan nama X, exp = 0 */

void DarahNaik(PLAYER *P);

void SwitchPos(PLAYER *P,MATRIKS *M, POINT Po);
/* I.S. Pemain akan pindah map, M matriks setelah pindah dan Po adalah titiknya */
/* F.S. Pemain sudah berada di Po dan matriks sudah ada cplayer */

void Jalan(PLAYER *P, MATRIKS *M, int dir,TE T);
//I.S: di matriks ada player, input dir 0(left),1(up),2(right),3(down).
/*F.S: posisi player bisa berubah/nggak, matriks bisa jadi gaada playernya,diisi '-'*/

void InitPosPlayer(PLAYER *P,MATRIKS *M);
/* I.S. game dimulai */
/* F.S. Posisi player sudah ditentukan */

void PrintGame(PLAYER P);
void PrintCLoop(char c, int x);
int digit(int X);
#endif

