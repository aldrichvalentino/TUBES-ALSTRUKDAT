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
	while ((CC == BLANK) && (CC != MARK))
	{
		ADV();
	}
}

void STARTKATA()
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{
	START();
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
		if ((CC == MARK ) || (CC == BLANK ))
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
		CKata.Length = i;
	}
}

void InputUser(Kata *K)
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
/* mencetak Kata K tanpa karakter apapun diawal dan diakhir */
{
	int i = 0;
	while (i<K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
}

int KataToInt (Kata K)
{
	int val = 0;
	int i = 0;
	while (i<=K.Length)
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

boolean IsKataSama (Kata K1, Kata K2){
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
