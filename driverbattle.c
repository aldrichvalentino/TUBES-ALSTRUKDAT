//main battle

#include "battle.h"
#include "mesinkata.h"
#include <stdio.h>

int main (){
    //kamus
    Kata np;
    PLAYER P;
    ENEMY E;
    TE T;
    int menang;
    Stack S;


    //algoritma
    printf("Enter your name : ");InputUser(&np);
    CreateEmptyPlayer(&P,np);

    LoadEnemy(&T);

    PSTR(P) = 1000;
    PDEF(P) = 1000;
    InitBattle(&P,T,&menang);

    return 0;
}
