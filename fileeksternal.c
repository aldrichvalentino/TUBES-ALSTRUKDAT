/* File : fileeksternal.c */

#include "fileeksternal.h"
#include "map.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CreateUser(Kata *K)
/* I.S. sembarang */
/* F.S. succeed bernilai true jika berhasil membuat user, selain itu false, K berisi nama user jika proses berhasil */
{
    boolean sama;
    char c[256];
    char line[256];
    int i;
    FILE *F = fopen("listplayer.txt", "r");
    printf("Masukkan Nama User :\n");
    fgets(c,sizeof(c),stdin);
    while (strlen(c) > 16)
    {
        if (strlen(c) > 16)
        {
            printf("Nama User harus dibawah 16 Huruf\n");
            printf("Masukkan Nama User :\n");
        }
        fgets(c,sizeof(c),stdin);
    }
    sama = false;
    while ((fgets(line,sizeof(line),F)!=NULL)&&(!sama)) sama = !strcmp(line,c);
    fclose(F);
    if (!sama)
    {
        F = fopen("listplayer.txt", "a");
        fputs(c,F);
        fclose(F);
    }
    CreateKata(c,K);
    --(*K).Length;
}

boolean IsFileExist(char *c)
/* Mengeluarkan true jika file bernama c ada */
{
    FILE *F = fopen(c,"r");
    boolean temp = (F!=NULL);
    fclose(F);
    return temp;
}

Kata ConvertToTxt(Kata K)
/* Menambah .txt dibelakang K */
{
    Kata T;
    char c;
    CopyKata(K,&T);
    T.TabKata[K.Length] = '.';
    T.TabKata[K.Length+1] = 't';
    T.TabKata[K.Length+2] = 'x';
    T.TabKata[K.Length+3] = 't';
    K.TabKata[K.Length+4] = 0;
    T.Length = K.Length+4;
    return T;
}

void SaveGame(PLAYER P,JAM J)
/* I.S. Permainan sudah dimainkan */
/* F.S. Data permainan sudah disimpan di (namaplayer).txt */
{
    Kata K = PName(P);
    Kata T = ConvertToTxt(K);
    char c;
    if (IsFileExist(T.TabKata))
    {
        while (c!='y')
        {
            printf("Anda sudah pernah menyimpan game. Apakah anda ingin melanjutkan?(y/n)\n");
            scanf("%c",&c);
            if (c=='n') return;
        }
    }
    FILE *F = fopen(T.TabKata,"w");
    //tulis di file eksternal
    fclose(F);
}

void LoadGame(PLAYER *P,JAM *J)
/* I.S. Nama player terdefinisi */
/* F.S. Data permainan sudah dipindah ke program */
{
    Kata K = PName(*P);
    Kata T = ConvertToTxt(K);
    if (!IsFileExist(T.TabKata)) printf("Anda belum pernah menyimpan permainan\n");
    else
    {
        FILE *F = fopen(T.TabKata,"r");
        //load
        fclose(F);
    }
}
