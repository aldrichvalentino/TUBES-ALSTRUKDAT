/* File: enemy.h */

#ifndef ENEMY_H
#define ENEMY_H

#include "boolean.h"
#include "mesinkata.h"
#include "queue.h"
#include "stack.h"

/* *** Definisi TYPE ENEMY *** */
#define IdxMinAksi 1
#define IdxMaxAksi 10
#define IdxUndefAksi -999
typedef struct {
	Kata NAME;
	int HP;
	int STR;
	int DEF;
	int EXP;
	Queue AKSI[IdxMaxAksi+1];
	boolean Die;
} ENEMY;

#define IdxMinTE 1
#define IdxMaxTE 10
#define IdxUndefTE -999
typedef struct {
	ENEMY Tab[IdxMaxTE+1];
	int Neff;
} TE;
/* *** Notasi Akses: selektor ENEMY *** */
#define EName(E) (E).NAME
#define EHP(E) (E).HP
#define ESTR(E) (E).STR
#define EDEF(E) (E).DEF
#define EEXP(E) (E).EXP
#define EAksi(E) (E).AKSI
#define EDie(E) (E).Die
#define NeffT(E) (E).Neff
#define InfoT(T,i) ((T).Tab)[(i)]

void LoadEnemy(TE *T);
/* I.S. Sembarang, file eksternal berisi data enemy tersedia */
/* F.S. Semua data sudah dipindahkan ke program */
/* Membuka file eksternal dan menyimpan semua ke array of ENEMY */

void CreateEnemy(ENEMY *E,TE T,int i);
/* I.S. T terdefinsi, E sembarang, i<IdxMaxTE */
/* F.S. E berisi data musuh yang terdapat pada tabel T pada indeks i */

void RandomStack(Stack *S,int n);
/* I.S. S sembarang */
/* F.S. S berisi angka permutasi random dari 1 sampai n */

void LostHP(ENEMY *E,int lost);
/* I.S. EDie(E) = False(E belum mati) */
/* F.S. HP musuh berkurang sebanyak lost, EDie(E) = true jika HP-Lost=0 */


#endif
