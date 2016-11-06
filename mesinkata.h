/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 50
#define BLANK1 ' '
#define BLANK2 '\n'

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char *namafile);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void InputUser(Kata *K);
/* I.S. Sembarang */
/* F.S. menginput masukan kata dari user dan menyimpannya di K */

void PrintKata (Kata K);
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */

int KataToInt (Kata K);
/* Kata K berisi integer dalam bentuk kata, mengkonversinya ke int */

char KataToChar (Kata K);
/* K.Length = 1 , mengeluarkan konversi K ke char */

boolean IsKataSama (Kata K1, Kata K2);
/* Mengeluarkan true jika K1 sama dengan K2 */

void CreateKata(char c[],Kata *K);
/* I.S. string c[] terdefinisi, K sembarang */
/* F.S. Megkonversi bentuk string ke Kata K */

void CopyKata(Kata K1,Kata *K2);
/* I.S. K1 terdefinsi, K2 sembarang */
/* F.S. K2 merupakan copyan dari K1, berisi sama dengan K1 */

#endif
