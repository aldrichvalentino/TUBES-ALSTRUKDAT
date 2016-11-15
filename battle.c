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
    char me1,me2,me3,me4,mp1,mp2,mp3,mp4;
    Queue PlayerMoves;

    /* inisiasi enemy */
    CreateEmptyStack(&S); //untuk set move nya
    RandomStack(&S,10);   //dirandom 1 - 10
    round = 1;           //inisiasi ronde
    CreateEnemy(&E,T,5); //BLOM DIRANDOM!! MUSUHNYA UDH SIAP

    /* dialog box */
    BattleUI(*P,E,'#','#','#','#',round);
    PrintKata(EName(E)); printf(" has appeared!\n");
    printf("What will you do?\n");
    InputUserMoves(&PlayerMoves);
    PrintBorder();

    /* akan diulan 10 ronde */
    while ((round <= 10) && (EHP(E) > 0)){
        PopStack(&S,&i);      //ambil 1
        //mengambil move dari queue
            DelQueue(&EAksi(E)[i],&me1);
            DelQueue(&EAksi(E)[i],&me2);
            DelQueue(&EAksi(E)[i],&me3);
            DelQueue(&EAksi(E)[i],&me4);

        /* pertarungan dimulai */
        BattleUI(*P,E,me1,me2,me3,me4,round);
        DelQueue(&PlayerMoves,&mp1);
        DelQueue(&PlayerMoves,&mp2);
        DelQueue(&PlayerMoves,&mp3);
        DelQueue(&PlayerMoves,&mp4);
        printf("Inserted Commands : %c %c %c %c \n",mp1,mp2,mp3,mp4);

        BattleProccess(P,mp1,&E,me1);
        BattleProccess(P,mp2,&E,me2);
        BattleProccess(P,mp3,&E,me3);
        BattleProccess(P,mp4,&E,me4);

        ++round;

        if(PHP(*P) > 0 && EHP(E) > 0 && round <= 10){        //player masih punya HP
            BattleUI(*P,E,'#','#','#','#',round);       //Nanti yang disamarkan 2 aja
            InputUserMoves(&PlayerMoves);
            PrintBorder();
        }
    }

    /* akhiran */
    PrintBorder();
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

void InputUserMoves (Queue *PlayerMoves)
/* Prosedur untuk menampilkan battle */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : enemy dikalahkan atau tidak, HP berkurang, exp bertambah atau berkurang */
/*        result akan terisi true apabila menang, false bila kalah */
/* setelah selesai dan exp bertambah, program caller harus mengecek exp, lalu menambahkan level jika sudah cukup */
{
    /* Kamus */
    char c;

    /*Insert Command*/
    printf("Please insert 4 commands : ");
    CreateEmptyQueue(PlayerMoves,4);
    while(!IsFullQueue(*PlayerMoves)){
        scanf("%c",&c);
        if(c == 'A' || c == 'F' || c == 'B'){   //Memasukan input A F B
            AddQueue(PlayerMoves,c);
        } else
        if(c == 'E'){                           //Mendelete E
            DelQueue(PlayerMoves,&c);
        }
    }
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
        printf(" received damage from the flank!\n");
        PHP(*P) -= 10; //nanti harus diatur sesuai level
    } else
    if(MP == 'F' && ME == 'A'){
        PrintKata(EName(*E));
        printf(" attacked! You received damage!\n");
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
        printf(" received damage!\n");
        EHP(*E) -= 25; //nanti harus diatur sesuai level
    } else
    if(MP == 'A' && ME == 'A'){
        PrintKata(PName(*P));
        printf(" attacked! ");
        PrintKata(EName(*E));
        printf(" received damage!\n");
        EHP(*E) -= 25; //nanti harus diatur sesuai level

        PrintKata(EName(*E));
        printf(" attacked! You received damage!\n");
        PHP(*P) -= 10; //nanti harus diatur sesuai level
    }
    else
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
