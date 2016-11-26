#ifndef _SKILTREE_H_
#define _SKILTREE_H_

/* Modul lain yang digunakan : */
#include "listrek.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "color.h"

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
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
boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

/* *** Traversal *** */
void PrintPreorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
void PrintInorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
void PrintPostorder (BinTree P);
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
void PrintTree1(BinTree P, int h, int inc);
void PrintTree (BinTree P, int h);
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/

/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */
int NbDaun (BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
boolean IsSkewLeft (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight (BinTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
int Level (BinTree P, infotype X);
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
int Tinggi (BinTree P);
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaunTerkanan (BinTree *P, infotype X);
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
void DelDaunTerkiri (BinTree *P, infotype *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun tevoid CreateSkillTree(BinTree *P);rkiri yang dihapus */
void DelDaun (BinTree *P, infotype X);
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */

BinTree SearchBST (BinTree P, infotype X);
// Mendapatkan pohon yang memiliki akar bernilai X

boolean IsSudah(BinTree P, infotype X);
// Mengecek apakah skill sudah diambil atau belum

void SaveSkillTree(BinTree P, FILE *F);

void CreateNewSkillTree(BinTree *P);
// Membuat skill tree baru untuk player

int SkillToInt(int skill);
// Mengubah biar jadi BST kalo di proses di fungsi

void AmbilSkill(BinTree *P);
// Prosedur untuk ngambil skill

#endif
