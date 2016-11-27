/* File : mprogram.c */
/*
gcc -o mprogram mprogram.c jam.c narasi.c fileeksternal.c matriks.c battle.c stack.c queue.c enemy.c player.c point.c map.c graph.c gambar.c listlinier.c mesinkata.c mesinkar.c -lm
*/
#include "gambar.h"
#include "map.h"
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "jam.h"
#include "fileeksternal.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

boolean NamaDone = false,ready=false;
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
    PrintCoolBS();
    PrintBorder();
    PrintCLoop(' ',20); printf("NEW GAME\n");
    PrintCLoop(' ',20); printf("START GAME\n");
    PrintCLoop(' ',20); printf("LOAD GAME\n");
    PrintCLoop(' ',20); printf("EXIT\n");
    PrintBorder();
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
        PrintCLoop(' ',20); printf("Masukkan salah satu perintah diatas : ");
        InputUser(command);
        if (!IsCommandValidAwal(*command))
        {
			PrintCLoop(' ',20);
			printf("Input tidak terdefinisi\n");
		}
    } while (!IsCommandValidAwal(*command));
}

void BacaCommandGame(Kata *command)
/* I.S. Masuk ke game */
/* F.S. sudah ada command yang valid */
{
    do
    {
        InputUser(command);
        if ((!IsCommandValidGame(*command))&&((*command).Length!=0))
        {
			printf("Input tidak terdefinisi\n");
		}
    } while (!IsCommandValidGame(*command));
}

void InitAll()
{
    InitAllMap(20,20,MaxNode);
    InitPosPlayer(&P,&Mat(ElMini(CMap,CMiniMap)));
    LoadEnemy(&T);
    StartRecord(&JamGame,&sec);
}

void ProcessCommand(Kata pilihan)
/* I.S. command merupakan instruksi yang valid */
/* Proses sudah dilakukan, done bernilai true jika start game atau exit */
{
    if (IsKataSama(pilihan,NG))
    {
        Kata player;
        NarasiOpening(&player);
        CreateEmptyPlayer(&P,player);
        NamaDone = true;
    }
    else if (IsKataSama(pilihan,SG))
    {
        if (!NamaDone)
        {
			PrintCLoop(' ',20);
            printf("Anda belum memasukkan username anda\n");
            ProcessCommand(NG);
        }
        if (!ready) InitAll();
    }
    else if (IsKataSama(pilihan,LG))
    {
        if (!NamaDone)
        {
            printf("Anda belum memasukkan username anda\n");
            ProcessCommand(NG);
        }
        ready = LoadGame(&P,&JamGame);
        LoadEnemy(&T);
    }
    else if (IsKataSama(pilihan,GL))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),0,T);
        PrintGame(P);
    }
    else if (IsKataSama(pilihan,GU))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),1,T);
        PrintGame(P);
    }
    else if (IsKataSama(pilihan,GR))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),2,T);
        PrintGame(P);
    }
    else if (IsKataSama(pilihan,GD))
    {
        Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),3,T);
        PrintGame(P);
    }
    else if (IsKataSama(pilihan,SAVE))
    {
        Record(&JamGame,sec);
        SaveGame(P,JamGame);
    }
    else if (IsKataSama(pilihan,SKILL))
    {

    }
    else if (IsKataSama(pilihan,EXIT))
    {
        CreateEmptyGraph(&Gr(CMap));
        Node(CMap) = 0;
        ready = false;
    }
}

int main()
{
    char c;
    srand((unsigned)time(NULL));
    Kata input;
    SetAllKata();
    clrscr();
    printf("Make sure your window is on full-screen mode.\n");	
    printf("Press enter to continue.");
    do
    {
	scanf("%c",&c);
    }
    while (c!='\n');
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
            PrintGame(P);
            do
            {
                BacaCommandGame(&input);
                ProcessCommand(input);
            } while (!IsKataSama(input,EXIT));
           CreateKata("",&input);
        }
    } while (!IsKataSama(input,EXIT));
    clrscr();
    return 0;
}
