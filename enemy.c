/* File: enemy.c */
#include "enemy.h"
#include <stdio.h>
void PrintKata (Kata K)
/* mencetak Kata K tanpa karakter apapun diawal dan diakhir */
{
	int i =1;
	while (i<=K.Length)
	{
		printf("%c", K.TabKata[i]);
		i++;
	}
}

int KataToInt (Kata K)
{
	int val = 0;
	int i = 1;
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

void LoadEnemy(TE *T)
/* Membuka file eksternal dan menyimpan semua ke array of ENEMY */
{
	FILE * fin;
	int retval;
	char C;
	Kata X;
	int i,j,n;
	
	void AD()
	{
		i=1;
		X.Length=0;
		do
		{
			retval = fscanf(fin,"%C",&C);
			if ((C!=' ')&&(C!='\n'))
			{
				X.TabKata[i]=C;
				X.Length++;
				i++;
			}
			else if (C=='.')
			{
				break;
			}
		}
		while ((C!=' ')&&(C!='\n'));
	}

	j=1;
	fin = fopen("enemy.txt","r");
	for(n = 1;n<=2;n++)	//repeat n times
	{
		do	
	{	
		AD();
		EName((*T).Tab[j])=X;
		AD();
		EHP((*T).Tab[j])=KataToInt(X);
		AD();
		ESTR((*T).Tab[j])=KataToInt(X);
		AD();
		EDEF((*T).Tab[j])=KataToInt(X);
		AD();
		EEXP((*T).Tab[j])=KataToInt(X);
		j++;
	}
		while (C!='\n');
	}
	fclose(fin);
}
