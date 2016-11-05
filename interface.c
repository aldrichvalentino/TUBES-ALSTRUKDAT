
#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"
#include "mesinkar.h"
#include "matriks.h"
#include "point.h"


int main (){
    //KAMUS
    Kata pilihan,Nama,NG,SG,LG,EXIT;
    MATRIKS M1,M2,M3,M4,M5,M6;
    boolean NamaDone;


    //ALGORITMA
    NG.TabKata[0] = 'N';
    NG.TabKata[1] = 'E';
    NG.TabKata[2] = 'W';
    NG.TabKata[3] = ' ';
    NG.TabKata[4] = 'G';
    NG.TabKata[5] = 'A';
    NG.TabKata[6] = 'M';
    NG.TabKata[7] = 'E';
    NG.Length = 8;

    SG.TabKata[0] = 'S';
    SG.TabKata[1] = 'T';
    SG.TabKata[2] = 'A';
    SG.TabKata[3] = 'R';
    SG.TabKata[4] = 'T';
    SG.TabKata[5] = ' ';
    SG.TabKata[6] = 'G';
    SG.TabKata[7] = 'A';
    SG.TabKata[8] = 'M';
    SG.TabKata[9] = 'E';
    SG.Length = 10;

    LG.TabKata[0] = 'L';
    LG.TabKata[1] = 'O';
    LG.TabKata[2] = 'A';
    LG.TabKata[3] = 'D';
    LG.TabKata[4] = ' ';
    LG.TabKata[5] = 'G';
    LG.TabKata[6] = 'A';
    LG.TabKata[7] = 'M';
    LG.TabKata[8] = 'E';
    LG.Length = 9;

    EXIT.TabKata[0] = 'E';
    EXIT.TabKata[1] = 'X';
    EXIT.TabKata[2] = 'I';
    EXIT.TabKata[3] = 'T';
    EXIT.Length = 4;

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
        printf("Masukkan Nama User :\n");
        InputUser(&Nama);
        while (Nama.Length > 16)
        {
            printf("Nama harus dibawah 16 Huruf\n");
            InputUser(&Nama);
        }
        NamaDone = true;
        BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
        M6 = GenerateMAP(M1);
        TulisMATRIKS(M6);
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
        }
        BacaMATRIKS(&M1,&M2,&M3,&M4,&M5,20,20);
        TulisMATRIKS(M1);
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
