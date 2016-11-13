//ADT untuk BATTLE
//Jadi isinya semua interface buat battle
//Tanggal 5 November 2016

/****** compile : gcc mbattle.c player.c enemy.c battle.c mesinkata.c stack.c queue.c mesinkar.c -o battle *****/

#include "boolean.h"
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "mesinkata.h"
#include <stdio.h>

/* kamus global */
int ronde = 1;

/* *************** Primitif *************** */
void PrintBorder ()
/* buat ngeprint border panjang */
{
    printf("-----------------------------------------------------------------------------------------\n");
}

void PrintGuard ()
/* buat pring guard */
{
    printf(" | ");
}

void PrintPlayer ( PLAYER P )
/* I.S. : Player terdefinisi */
/* F.S. : menampilkan status player di layar */
{
    PrintKata(P.NAME); //nama
    PrintGuard();

    //blum print level pemain

    printf("HP : %d",P.HP); //HP
    PrintGuard();

    printf("STR : %d",P.STR); //Strength
    PrintGuard();

    printf("DEF : %d",P.DEF); //Defense
    PrintGuard();
}

void PrintEnemy ( ENEMY E , infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4 )
/* I.S. : Enemy tidak kosong, sudah diload dari file eksternal */
         /* M1 dan M2 adalah move enemy */
/* F.S. : Menampilkan nama, HP, dan 2 command dari enemy */
{
    /* kamus */
    char Aksi;
    Queue Q;
    int i;

    /* algoritma */
    PrintKata(E.NAME);
    PrintGuard();

    printf("HP : %d",E.HP);
    PrintGuard();

    printf("%c ",M1);
    printf("%c ",M2);
    printf("%c ",M3);
    printf("%c ",M4);

    PrintGuard();
    printf("\n");
}

void InitBattle (PLAYER *P, TE T, boolean *result)
/* I.S. : player dan tabel enemy terdefinisi
          akan mencatat seluruh keadaan sebelum battle dimulai
          akan memanggil fungsi battle UI dan dialog box sebanyak 10 kali atau hingga musuh kalah
          Status dari Player dan Enemy akan diupdate tiap ronde selesai
   F.S. : player menang atau kalah, enemy kalah atau kabur,
*/
{
    /* Kamus */
    ENEMY E;
    Stack S;
    int i, round;
    char move1,move2,move3,move4;
    Kata PlayerMoves;

    /* inisiasi enemy */
    CreateEmptyStack(&S); //untuk set move nya
    RandomStack(&S,10);   //dirandom 1 - 10
    round = 1;           //inisiasi ronde
    CreateEnemy(&E,T,1); //atau 2, nanti dibikin random

    /* akan diulan 10 ronde */
    while ((round <= 10) && (EHP(E) > 0)){
        PopStack(&S,&i);      //ambil 1
        //mengambil move dari queue
            DelQueue(&EAksi(E)[i],&move1);
            DelQueue(&EAksi(E)[i],&move2);
            DelQueue(&EAksi(E)[i],&move3);
            DelQueue(&EAksi(E)[i],&move4);

        /* Panggil Battle UI */
        if(PHP(*P) != 0){        //player masih punya HP
            BattleUI(*P,E,'#','#','#','#',round);
            InputUserMoves(E, &PlayerMoves);
            PrintBorder();

            /* pertarungan dimulai */
            BattleUI(*P,E,move1,move2,move3,move4,round);
            BattleProccess(P,PlayerMoves.TabKata[0],&E,move1);
            BattleProccess(P,PlayerMoves.TabKata[1],&E,move2);
            BattleProccess(P,PlayerMoves.TabKata[2],&E,move3);
            BattleProccess(P,PlayerMoves.TabKata[3],&E,move4);
            ++round;
        }
    }

    /* akhiran */
    if ((EHP(E) <= 0) || (round > 10)){
        *result = true;
        EDie(E) = true;
        printf("Congratulations! %s has been defeated!\n",EName(E));
    } else
    if (PHP(*P) == 0){
        *result = false;
        printf("You have lost!\n");
    }
    PrintBorder();
}

void InputUserMoves (ENEMY E, Kata *PlayerMoves)
/* Prosedur untuk menampilkan battle */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : enemy dikalahkan atau tidak, HP berkurang, exp bertambah atau berkurang */
/*        result akan terisi true apabila menang, false bila kalah */
/* setelah selesai dan exp bertambah, program caller harus mengecek exp, lalu menambahkan level jika sudah cukup */
{
    /* dialog box */
    PrintKata(EName(E)); printf(" has appeared!\n");
    printf("What will you do?\n");
    PrintBorder();

    /*Insert Command*/
    printf("Please insert 4 commands : ");
    InputUser(PlayerMoves);
}

void BattleProccess (PLAYER *P, char MP, ENEMY *E, infotypeQ ME)
/* I.S. : player, enemy, dan player moves dan enemy moves terdefinisi
   F.S. : Permainan selesai dengan HP player dan enemey berkurang, seluruh move sudah dieksekusi
*/
{
    if(MP == 'A' && ME == 'B'){
        PrintKata(PName(*P));
        printf(" attacked! but it's blocked!\n");
    } else
    if(MP == 'B' && ME == 'F'){
        PrintKata(PName(*P));
        printf(" is blocking the flank!\n");
    } else
    if(MP == 'F' && ME == 'A'){
        PrintKata(EName(*E));
        printf(" attacked! Flank failed! You received damage!\n");
        PHP(*P) -= 10; //nanti harus diatur sesuai level
    } else
    if(MP == 'A' && ME == 'F'){
        PrintKata(PName(*P));
        printf(" attacked! ");
        PrintKata(EName(*E));
        printf(" received damage!\n");
        EHP(*E) -= 25; //nanti harus diatur sesuai level
    } else
    if(MP == 'B' && ME == 'A'){
        PrintKata(PName(*P));
        printf(" blocked the attack!\n");
    } else
    if(MP == 'F' && ME == 'B'){
        PrintKata(PName(*P));
        printf(" flanked! ");
        PrintKata(EName(*E));
        printf(" received no damage!\n");
    } else
    {
        printf("Nothing happened!\n");
    }
}

void BattleUI (PLAYER P, ENEMY E, infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4, int round )
/* Prosedur untuk menampilkan battle */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : enemy dikalahkan atau tidak, HP berkurang, exp bertambah atau berkurang */
/*        result akan terisi true apabila menang, false bila kalah */
/* setelah selesai dan exp bertambah, program caller harus mengecek exp, lalu menambahkan level jika sudah cukup */
{
    /* print player */
    PrintBorder();
    PrintPlayer(P);
    printf("Round %d",round); //Round
    PrintGuard();
    printf("\n");
    PrintBorder();

    /* print enemy */
    PrintEnemy(E,M1,M2,M3,M4);
}
