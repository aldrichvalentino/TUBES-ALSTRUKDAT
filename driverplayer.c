/* namafile: driverplayer.c */
/* cara compile : gcc -o driver.exe driver.c matriks.c player.c point.c mesinkata.c mesinkar.c*/
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "matriks.h"
#include "boolean.h"
#include "mesinkata.h"
#include "point.h"

int main(){
	/* KAMUS */
	PLAYER P1;
	Kata name;
	char C;
	int i = 0;
	
	/* ALGORITMA */
	clrscr();
	printf("Masukkan nama player: ");
	name.Length=0;
	do
	{
		scanf("%c", &C);
		if (C!='\n')
		{
			name.TabKata[i]=C;
			name.Length++;
			i++;
		}
	}
	while (C!='\n');
	CreateEmptyPlayer(&P1, name);
	//SwitchPos
	//Jalan
	PrintGame(P1);
	PHP(P1)=75;
	printf("HP: %d, MaxHP : %d, STR : %d, DEF : %d, EXP : %d, Level : %d\n", PHP(P1), MaxHP(P1), PSTR(P1), PDEF(P1), PEXP(P1), PLevel(P1));
	printf("Darah Naik: \n");
	DarahNaik(&P1);
	printf("HP: %d, MaxHP : %d, STR : %d, DEF : %d, EXP : %d, Level : %d\n", PHP(P1), MaxHP(P1), PSTR(P1), PDEF(P1), PEXP(P1), PLevel(P1));
	printf("PrintCLoop('*',5) : ");
	PrintCLoop('*',5);
	printf("\n");
	printf("Digit(1234) : %d\n", digit(1234) );
	
	return 0;
}
	
