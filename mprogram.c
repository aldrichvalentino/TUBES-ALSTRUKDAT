/* File : mprogram.c */

#include "map.h"
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "jam.h"
#include "fileeksternal.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

boolean NamaDone = false;
JAM JamGame;
time_t sec;
Kata NG,SG,LG,EXIT,GU,GL,GD,GR,SAVE,LOAD,SKILL;
PLAYER P;
TE T;

void SetAllKata()
/* Mempersiapkan semua kata */
{
    CreateKata("NEW GAME",&NG);
    CreateKata("START GAME",&SG);
    CreateKata("LOAD GAME",&LG);
    CreateKata("EXIT",&EXIT);
    CreateKata("GU",&GU);
    CreateKata("GL",&GL);
    CreateKata("GD",&GD);
    CreateKata("GR",&GR);
    CreateKata("SAVE",&SAVE);
    CreateKata("SKILL",&SKILL);
}

void Interface()
/* Nampilin interface awal */
{
    clrscr();
    printf("Welcome to brightsouls guyz\n");
    printf("Pilih satu plz jgn banyak2\n");
    printf("NEW GAME\n");
    printf("START GAME\n");
    printf("LOAD GAME\n");
    printf("EXIT\n");
    printf("Masukkan salah satu perintah diatas : \n");
}

boolean IsCommandValidAwal(Kata K)
/* Mengelurkan true jika K adalah command valid sebelum mulai game */
{
    return ((IsKataSama(K,NG))||(IsKataSama(K,SG))||(IsKataSama(K,LG))||(IsKataSama(K,EXIT)));
}

boolean IsCommandValidGame(Kata K)
/* Mengeluarkan true jika K adalah command valid sesudah mulai game */
{
	return ((IsKataSama(K,GL))||(IsKataSama(K,GU))||(IsKataSama(K,GD))||(IsKataSama(K,GR))||(IsKataSama(K,SKILL))||(IsKataSama(K,SAVE))
            ||(IsKataSama(K,LOAD))||(IsKataSama(K,EXIT)));
}

void BacaCommandAwal(Kata *command)
/* I.S. Masuk ke game */
/* F.S. sudah ada command yang valid */
{
    do
    {
        InputUser(command);
        if (!IsCommandValidAwal(*command)) printf("Input tidak terdefinisi\n");
    } while (!IsCommandValidAwal(*command));
}

void BacaCommandGame(Kata *command)
/* I.S. Masuk ke game */
/* F.S. sudah ada command yang valid */
{
    do
    {
        InputUser(command);
        if ((!IsCommandValidGame(*command))&&((*command).Length!=0)) printf("Input tidak terdefinisi\n");
    } while (!IsCommandValidGame(*command));
}

void ProcessCommand(Kata pilihan)
/* I.S. command merupakan instruksi yang valid */
/* Proses sudah dilakukan, done bernilai true jika start game atau exit */
{
    if (IsKataSama(pilihan,NG))
    {
        Kata player;
        CreateUser(&player);
        CreateEmptyPlayer(&P,player);
        NamaDone = true;
    }
    else if (IsKataSama(pilihan,SG))
    {
        if (!NamaDone)
        {
            printf("Anda belum memasukkan username anda\n");
            ProcessCommand(NG);
        }
    }
    else if (IsKataSama(pilihan,LG))
    {

    }
    else if (IsKataSama(pilihan,GL))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),0,T);
        PrintMap();
    }
    else if (IsKataSama(pilihan,GU))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),1,T);
        PrintMap();
    }
    else if (IsKataSama(pilihan,GR))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),2,T);
        PrintMap();
    }
    else if (IsKataSama(pilihan,GD))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),3,T);
        PrintMap();
    }
    else if (IsKataSama(pilihan,SAVE))
    {

    }
    else if (IsKataSama(pilihan,SKILL))
    {

    }
}

void InitAll()
{
    InitAllMap(20,20,10);
    InitPosPlayer(&P,&Mat(ElMini(CMap,CMiniMap)));
    LoadEnemy(&T);
    StartRecord(&JamGame,&sec);
}

int main()
{
    srand((unsigned)time(NULL));
    Kata input;
    SetAllKata();
    do
    {
        do
        {
            Interface();
            BacaCommandAwal(&input);
            ProcessCommand(input);
        } while ((!IsKataSama(input,SG))&&(!IsKataSama(input,EXIT)));
        if (IsKataSama(input,SG))
        {
            InitAll();
            PrintMap();
            do
            {
                BacaCommandGame(&input);
                ProcessCommand(input);
            } while (!IsKataSama(input,EXIT));
            CreateKata("",&input);
        }
    } while (!IsKataSama(input,EXIT));
    return 0;
}
