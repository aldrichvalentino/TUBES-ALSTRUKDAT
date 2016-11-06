/* namafile: driver.c */
/* cara compile : gcc -o driver.exe driver.c matriks.c player.c point.c mesinkata.c mesinkar.c*/
#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "matriks.h"
#include "boolean.h"
#include "mesinkata.h"
#include "point.h"
#define cplayer 'P'

void clrscr()
{
	system("@cls||clear");
}

int main(){
	MATRIKS M1,M2,M3,M4,M5;
	Kata X; 
	PLAYER P1; 
	char menu;
	
	X.TabKata[0]='A';
	X.Length=1;
	CreateEmptyPlayer(&P1,X);
    BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);

	clrscr();
	InitiatePos(&P1,&M1,0);
	TulisMATRIKS(M1);
	printf("\n");
	do
	{
		menu = 'F';
		printf("Input Command: ");
		BacaCommand(&P1,&M1,&menu);
		if (menu =='G')
		{
			clrscr();
			TulisMATRIKS(M1); 
			printf("\n");
		}	
	}
	while (menu!='E');
return 0;
}
