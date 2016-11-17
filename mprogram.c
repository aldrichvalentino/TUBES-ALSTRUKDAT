/* File : mprogram.c */

#include "map.h"
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

boolean NamaDone = false;

void Interface()
/* Nampilin interface awal */
{
    printf("Welcome to brightsouls guyz\n");
    printf("Pilih satu plz jgn banyak2\n");
    printf("NEW GAME\n");
    printf("START GAME\n");
    printf("LOAD GAME\n");
    printf("EXIT\n");
    printf("masukkan salah satu perintah diatas : \n");
}

boolean IsCommandValidAwal(Kata K)
/* Mengelurkan true jika K adalah command valid sebelum mulai game */
{
    Kata NG,SG,LG,EXIT;
    CreateKata("NEW GAME",&NG);
    CreateKata("START GAME",&SG);
    CreateKata("LOAD GAME",&LG);
    CreateKata("EXIT",&EXIT);
    return ((IsKataSama(K,NG))||(IsKataSama(K,SG))||(IsKataSama(K,LG))||(IsKataSama(K,EXIT)));
}

boolean IsCommandValidGame(Kata K)
/* Mengeluarkan true jika K adalah command valid sesudah mulai game */
{
    Kata GL,GU,GR,GD,SKILL,SAVE,LOAD,EXIT;
	CreateKata("GL",&GL);
	CreateKata("GU",&GU);
	CreateKata("GD",&GD);
	CreateKata("GR",&GR);
	CreateKata("SKILL",&SKILL);
	CreateKata("SAVE",&SAVE);
	CreateKata("LOAD",&LOAD);
	CreateKata("EXIT",&EXIT);
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
        if (!IsCommandValidGame(*command)) printf("Input tidak terdefinisi\n");
    } while (!IsCommandValidGame(*command));
}

void ProcessCommand(Kata pilihan,boolean *done)
/* I.S. command merupakan instruksi yang valid */
/* Proses sudah dilakukan, done bernilai true jika start game atau exit */
{
    Kata Nama,NG,SG,LG;
    CreateKata("NEW GAME",&NG);
    CreateKata("START GAME",&SG);
    CreateKata("LOAD GAME",&LG);
    if (IsKataSama(pilihan,NG))
    {
        /*
        printf("Masukkan Nama User :\n");
        InputUser(&Nama);
        while (Nama.Length > 16)
        {
            printf("Nama harus dibawah 16 Huruf\n");
            InputUser(&Nama);
        }
        NamaDone = true;
        FPlayer = fopen("listplayer.txt", "a");
        for (i = 0; i < Nama.Length; i++)
        {
            fprintf(FPlayer,"%c",Nama.TabKata[i]);
        }
        fprintf(FPlayer," | ");
        JAM J = MakeJAM(0,0,0);
        fprintf(FPlayer,"%02d:%02d:%02d",Hour(J),Minute(J),Second(J));
        fprintf(FPlayer,"\n");
        fclose(FPlayer);

        //BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
        //M6 = GenerateMAP(M1);
        //TulisMATRIKS(M6);
        printf("\n");
        */
    }
    else if (IsKataSama(pilihan,SG))
    {
        if (!NamaDone)
        {
            /*
            printf("Masukkan Nama User terlebih dahulu :\n");
            InputUser(&Nama);
            while (Nama.Length > 16)
            {
                printf("Nama harus dibawah 16 Huruf\n");
                InputUser(&Nama);
            }
            FPlayer = fopen("listplayer.txt", "a");
            for (i = 0; i < Nama.Length; i++)
            {
                fprintf(FPlayer,"%c",Nama.TabKata[i]);
            }
            fprintf(FPlayer," | ");
            JAM J = MakeJAM(0,0,0);
            fprintf(FPlayer,"%02d:%02d:%02d",Hour(J),Minute(J),Second(J));
            fprintf(FPlayer,"\n");
            fclose(FPlayer);
            NamaDone = true;
            */
        }
        //BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
        //TulisMATRIKS(M1);
        //TulisMATRIKS(M1);
        printf("\n");
    }
    else if (IsKataSama(pilihan,LG))
    {

    }
}

void InitAll(PLAYER *P,TE *T)
{
    InitAllMap(20,20,10);
    InitPosPlayer(P,&Mat(ElMini(CMap,CMiniMap)));
    LoadEnemy(T);
}

int main()
{
    srand((unsigned)time(NULL));
    Kata input,SG,EXIT,Aku;
    Kata GL,GU,GR,GD,SKILL,SAVE,LOAD;
    TE T;
    PLAYER P;
    CreateKata("Aku",&Aku);
    CreateEmptyPlayer(&P,Aku);
    InitAll(&P,&T);
    PrintMap();
	CreateKata("GL",&GL);
	CreateKata("GU",&GU);
	CreateKata("GD",&GD);
	CreateKata("GR",&GR);
	CreateKata("SKILL",&SKILL);
    CreateKata("Start Game",&SG);
    CreateKata("EXIT",&EXIT);
    do
    {
        BacaCommandGame(&input);
        if (IsKataSama(input,GL)) Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),0,T);
        else if (IsKataSama(input,GU)) Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),1,T);
        else if (IsKataSama(input,GR)) Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),2,T);
        else if (IsKataSama(input,GD)) Jalan(&P,&Mat(ElMini(CMap,CMiniMap)),3,T);
        PrintMap();
    } while (!IsKataSama(input,EXIT));
    /*
    boolean done = false;
    do
    {
        do
        {
            Interface();
            BacaCommandAwal(&input);
        } while (!done);
        if (IsKataSama(input,SG))
        {
            InitAll(&P,&T);
        }
    } while (!done);
    */
    return 0;
}
