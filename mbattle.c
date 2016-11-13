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
    boolean menang = false;
    Stack S;


    //algoritma
    printf("Enter your name : ");InputUser(&np);
    CreateEmptyPlayer(&P,np);

    LoadEnemy(&T);

    InitBattle(&P,T,&menang);

    return 0;
}
