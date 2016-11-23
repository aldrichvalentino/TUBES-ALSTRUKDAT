/* File : fileeksternal.c */

#include "fileeksternal.h"
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

