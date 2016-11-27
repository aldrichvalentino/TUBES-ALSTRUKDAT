#ifndef _SKILTREE_H_
#define _SKILTREE_H_

/* Modul lain yang digunakan : */
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "color.h"


#define Nil NULL /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
typedef int infotype; /* type infotype sesuai pada modul listrek */
typedef struct tNode *addrNode;
typedef struct tNode {
	infotype info;
	addrNode left;
	addrNode right;
	boolean sudah;
} Node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;

/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Sudah(P) (P)->sudah

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R, int i);
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
/* Manajemen Memory */
addrNode AlokNode (infotype X);
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokNode (addrNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt (BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */

void PrintTree1(BinTree P, int h, int inc);
// Prosedur antara untuk PrintSkillTree

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

BinTree SearchBST (BinTree P, infotype X);
// Mendapatkan pohon yang memiliki akar bernilai X

boolean IsSudah(BinTree P, infotype X);
// Mengecek apakah skill sudah diambil atau belum

void SaveSkillTree(BinTree P, FILE *F);
/* Untuk menyimpan Tree ke file eksternal */

void CreateNewSkillTree(BinTree *P);
// Membuat skill tree baru untuk player

int SkillToInt(int skill);
// Mengubah biar jadi BST kalo di proses di fungsi

void AmbilSkill(BinTree *P);
// Prosedur untuk mengambil skill

#endif
