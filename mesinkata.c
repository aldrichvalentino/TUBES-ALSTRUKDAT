/* File: mesinkata.c */
/* Implementasi Mesin Kata: Model Akuisisi Versi I */

#include "mesinkata.h"
#include <stdio.h>

boolean EndKata;
Kata CKata;

void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */
{
	while (((CC == BLANK1)||(CC == BLANK2)) && (CC != MARK))
	{
		ADV();
	}
}

void STARTKATA(char *namafile)
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	START(namafile);
	IgnoreBlank();
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		EndKata = false;
		SalinKata();
		IgnoreBlank();
	}
}

void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{
	IgnoreBlank();
	if (CC == MARK)
	{
		EndKata = true;
	}
	else
	{
		SalinKata();
	}
	IgnoreBlank();
}

void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
	int i = 0;

	for (;;)
	{
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC == MARK ) || (CC == BLANK1 ) || (CC == BLANK2))
		{
			break;
		}
		else
		{
			i++;
		}
	}
	if (i>NMax)
	{
		CKata.Length=NMax;
	}
	else
	{
		CKata.Length = i+1;
	}
}

void InputUser(Kata *K)
/* I.S. Sembarang */
/* F.S. menginput masukan kata dari user dan menyimpannya di K */
{
	char c;
	int i = 0;
	scanf("%c",&c);
	while (c != '\n')
	{
		(*K).TabKata[i] = c;
		++i;
		scanf("%c",&c);
	}
	(*K).Length = i;
}

void PrintKata (Kata K)
/* I.S. Kata K terdefinisi */
/* F.S. K tercetak di layar tanpa karakter tambahan di awal maupun di akhir */
{
	int i = 0;
	while (i<K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
}

int KataToInt (Kata K)
/* Kata K berisi integer dalam bentuk kata, mengkonversinya ke int */
{
	int val = 0;
	int i = 0;
	while (i<K.Length)
	{
		val = val * 10;
		switch (K.TabKata[i]){
			case '0' : val += 0; break;
			case '1' : val += 1; break;
			case '2' : val += 2; break;
			case '3' : val += 3; break;
			case '4' : val += 4; break;
			case '5' : val += 5; break;
			case '6' : val += 6; break;
			case '7' : val += 7; break;
			case '8' : val += 8; break;
			case '9' : val += 9; break;
		};
		i++;
	}
	return val;
}

char KataToChar (Kata K)
/* K.Length = 1 , mengeluarkan konversi K ke char */
{
    return (K.TabKata[0]);
}

boolean IsKataSama (Kata K1, Kata K2)
/* Mengeluarkan true jika K1 sama dengan K2 */
{
	int i;
	boolean found;
	found = false;

	if (K1.Length != K2.Length){
		return false;
	} else {
		i = 0;
		while ((!found)&&(i < K1.Length)){
			found = (K1.TabKata[i] == K2.TabKata[i]);
			i++;
		}
		return (K1.TabKata[i] == K2.TabKata[i]);
	}
}

void CreateKata(char c[],Kata *K)
/* I.S. string c[] terdefinisi, K sembarang */
/* F.S. Megkonversi bentuk string ke Kata K */
{
    int i = 0;
    while (c[i]!='\0')
    {
        (*K).TabKata[i] = c[i];
        ++i;
    }
    (*K).Length = i;
}

void CopyKata(Kata K1,Kata *K2)
/* I.S. K1 terdefinsi, K2 sembarang */
/* F.S. K2 merupakan copyan dari K1, berisi sama dengan K1 */
{
    (*K2).Length = K1.Length;
    int i,len = K1.Length;
    for (i = 0;i<len;++i)
    {
        (*K2).TabKata[i] = K1.TabKata[i];
    }
}
