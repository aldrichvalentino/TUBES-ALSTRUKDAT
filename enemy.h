/* File: enemy.h */

#ifndef ENEMY_H
#define ENEMY_H

#include "boolean.h"
#include "mesinkata.h"
#include "stack.h"

/* *** Definisi TYPE ENEMY *** */
typedef struct { 
	Kata NAME;
	int HP;
	int STR;
	int DEF;
	int EXP;
	Stack AKSI;
} ENEMY;

typedef struct { 
	ENEMY Tab[10];
} TE;	
/* *** Notasi Akses: selektor ENEMY *** */
#define EName(E) (E).NAME
#define EHP(E) (E).HP
#define ESTR(E) (E).STR
#define EDEF(E) (E).DEF
#define EEXP(E) (E).EXP
#define EAksi(E) (E).AKSI

void PrintKata (Kata K);
/* mencetak Kata K tanpa karakter apapun diawal dan diakhir */
int KataToInt (Kata K);
/* mengubah kata menadi integer */
void LoadEnemy(TE *T);
/* Membuka file eksternal dan menyimpan semua ke array of ENEMY */
#endif
