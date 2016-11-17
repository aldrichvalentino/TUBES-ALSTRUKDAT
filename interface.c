#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "matriks.h"
#include "point.h"
#include "jam.h"
#include <string.h>

int main (){
    //KAMUS
    Kata pilihan,Nama,NG,SG,LG,EXIT;
    MATRIKS M1,M2,M3,M4,M5,M6;
    boolean NamaDone;
    FILE *FPlayer;
    int i;


    //ALGORITMA
    CreateKata("NEW GAME",&NG);
    CreateKata("START GAME",&SG);
    CreateKata("LOAD GAME",&LG);
    CreateKata("EXIT",&EXIT);

    NamaDone = false;

    printf("Welcome to brightsouls guyz\n");
    printf("Pilih satu plz jgn banyak2\n");
    printf("NEW GAME\n");
    printf("START GAME\n");
    printf("LOAD GAME\n");
    printf("EXIT\n");
    printf("masukkan salah satu perintah diatas : \n");
    InputUser(&pilihan);

    while (!IsKataSama(pilihan,SG) && !IsKataSama(pilihan,NG) && !IsKataSama(pilihan,LG) && !IsKataSama(pilihan,EXIT))
    {
        printf("salah\n");
        InputUser(&pilihan);
    }
    if (IsKataSama(pilihan,NG))
    {
        CreateUser(FPlayer);
        //BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
        //M6 = GenerateMAP(M1);
        //TulisMATRIKS(M6);
        printf("\n");
    }
    else if (IsKataSama(pilihan,SG))
    {
        if (!NamaDone)
        {
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
        }
        //BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
        //TulisMATRIKS(M1);
        //TulisMATRIKS(M1);
        printf("\n");
    }
    else if (IsKataSama(pilihan,LG))
    {

    }
    else if (IsKataSama(pilihan,EXIT))
    {

    }
    return 0;
}

void CreateUser(FILE *F)
/* prosedur untuk membuat user baru, PENGECEKANNYA MASIH SALAH GATAU HRS GIMANA */
{
    boolean sama;
    char c[256];
    char line[256];
    int i;
    printf("Masukkan Nama User :\n");
    scanf("%s",c);
    sama = true;
    if (F != NULL)
    {
        F = fopen("listplayer.txt", "r");
        while (sama)
        {
            while (fgets(line,sizeof(line),F))
            {
                if (!strcmp(line,c))
                {
                    printf("Nama User telah digunakan, silahkan pilih nama lain\n");
                    sama = true;
                }
                else
                {
                    sama = false;
                }
            }
            scanf("%s",c);
        }
    }
    while (strlen(c) > 16)
    {
        if (strlen(c) > 16)
        {
            printf("Nama User harus dibawah 16 Huruf\n");
        }
        scanf("%s",c);
    }
    fclose(F);
    if (F == NULL)
    {
        F = fopen("listplayer.txt", "w");
    }
    else
    {
        F = fopen("listplayer.txt", "a");
    }
    fprintf(F,"%s",c);
    fprintf(F,"\n");
    fclose(F);
}
