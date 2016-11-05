/**** cara compile : gcc -o menemy.exe menemy.c enemy.c mesinkata.c mesinkar.c ****/


#include <stdio.h>
#include "enemy.h"
int main(){
	
	ENEMY E;
	TE T;

	LoadEnemy(&T);
	PrintKata(EName(T.Tab[1]));
	printf("\n");
	printf("STR : %d\n", ESTR(T.Tab[1]));
	PrintKata(EName(T.Tab[2]));
	printf("\n");
	printf("HP : %d\n", EHP(T.Tab[2]));
}
