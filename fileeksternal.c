/* File : fileeksternal.c */

#include "fileeksternal.h"
#include "map.h"
#include "narasi.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void CreateUser(Kata K)
/* I.S. sembarang */
/* F.S. K berisi nama user jika proses berhasil */
{
    boolean sama;
    char c[256];
    char line[256];
    int i;
    for (i=0;i<K.Length;++i) c[i] = K.TabKata[i];
    c[K.Length] = '\n';
    c[K.Length+1] = 0;
    FILE *F = fopen("listplayer.txt", "r");
    sama = false;
    while ((fgets(line,sizeof(line),F)!=NULL)&&(!sama)) 
	{
		printf("%s-%s-",c,line);
		sama = !strcmp(line,c);
	}
    fclose(F);
    if (!sama)
    {
        F = fopen("listplayer.txt", "a");
        fputs(c,F);
        fclose(F);
    }
}

boolean IsFileExist(char *c)
/* Mengeluarkan true jika file bernama c ada */
{
	return (access(c,F_OK)!=-1);    
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
    K = ConvertToTxt(K);

    if (IsFileExist(K.TabKata))
    {
    	char c[100];
	do
        {
            PrintCLoop(' ',20); printf("Anda sudah pernah menyimpan game. Apakah anda ingin melanjutkan?(y/n)\n");
	    PrintCLoop(' ',20);
            scanf("%s",c);
            if (!strcmp(c,"n")) 
	    {
		printf("Command : ");
		return;
	    }
        } while (strcmp(c,"y"));
    }
    FILE *F = fopen(K.TabKata,"w");
    //print jam
    char jam[10];
    ConvertJamToString(J,jam);
    fputs(jam,F);
    //print player
    fprintf(F,"\n%d %d %d %d %d %d\n",PHP(P),MaxHP(P),PSTR(P),PDEF(P),PEXP(P),PLevel(P));
    fprintf(F,"%d %d\n%d\n",PosisiX(P),PosisiY(P),CMiniMap);
    //print map
    //print matriks
    MATRIKS M;
    int i,j,m;
    for (m=1;m<=MaxNode;++m)
    {
        M = Mat(ElMini(CMap,m));
        for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);++i)
        {
            for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);++j)
            {
                fprintf(F,"%c ",Elmt(M,i,j));
            }
            fprintf(F,"\n");
        }
        fprintf(F,"\n");
        fprintf(F,"%d\n",NeffM(LEn(ElMini(CMap,m))));
        if (!IsEmptyTEMap(LEn(ElMini(CMap,m))))
        {
            Kata K;
            int nef = NeffM(LEn(ElMini(CMap,m)));
            int i=1;
            while (i<=nef)
            {
                K = EName(EMap(LEn(ElMini(CMap,m)),i));
                K.TabKata[K.Length] = 0;
                fputs(K.TabKata,F);
                fprintf(F," %d %d\n",Absis(Pos(LEn(ElMini(CMap,m)),i)),Ordinat(Pos(LEn(ElMini(CMap,m)),i)));
                ++i;
            }
        }
    }
    //print skill
    int a[16];
    for (i = 2; i <= 15; i++)
    {
        if (Sudah(SearchBST(PSkill(P),SkillToInt(i))) == true)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }
    for (i = 2; i <= 15 ; i++)
    {
        fprintf(F,"%d ", a[i]);
    }
    fprintf(F,"\n");
    //print graph
    Graph G = Gr(CMap);
    addressG PG = FirstG(G);
    while (PG!=Nil)
    {
        addressL PL = FirstL(Info(PG));
        while (PL!=Nil)
        {
            fprintf(F,"%d ",Info(PL));
            PL = Next(PL);
        }
        fprintf(F,"\n");
        PG = Next(PG);
    }
    fprintf(F,"-1");
    printf("Save berhasil!\nCommand: ");
    fclose(F);
}

boolean LoadGame(PLAYER *P,JAM *J)
/* I.S. Nama player terdefinisi */
/* F.S. Data permainan sudah dipindah ke program */
{
    Kata K = PName(*P);
    K = ConvertToTxt(K);
    if (!IsFileExist(K.TabKata))
    {
        char temp;
	PrintCLoop(' ',20);
	printf("Anda belum pernah menyimpan permainan\n");
	PrintCLoop(' ',20);
	printf("Press Enter to Continue\n");
	PrintCLoop(' ',20);
        do
	{
		scanf("%c",&temp);
	} while (temp!='\n');
        return false;
    }
    else
    {
        FILE *F = fopen(K.TabKata,"r");
        //load jam
        char jam[10];
        fgets(jam,sizeof(jam),F);
        ConvertStringToJam(J,jam);
        //load player
        fscanf(F,"%d %d %d %d %d %d",&PHP(*P),&MaxHP(*P),&PSTR(*P),&PDEF(*P),&PEXP(*P),&PLevel(*P));
        fscanf(F,"%d %d %d",&PosisiX(*P),&PosisiY(*P),&CMiniMap);
        //load map
        //load matriks
        MATRIKS M;
        int m,i,j;
        for (m=1;m<=MaxNode;++m)
        {
            MakeMATRIKS(20,20,&Mat(ElMini(CMap,m)));
            MATRIKS M;
            MakeMATRIKS(20,20,&M);
            for (i=GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);++i)
            {
                for (j=GetFirstIdxKol(M);j<=GetLastIdxKol(M);++j)
                {
                    fscanf(F," %c",&Elmt(Mat(ElMini(CMap,m)),i,j));
                }
            }
            fscanf(F,"%d",&NeffM(LEn(ElMini(CMap,m))));
            if (!IsEmptyTEMap(LEn(ElMini(CMap,m))))
            {
                int i = 1;
                int nef = NeffM(LEn(ElMini(CMap,m)));
                while (i<=nef)
                {
                    Kata K;
                    int j=0;
                    char temp;
                    fscanf(F," %c",&temp);
                    while (temp!=' ')
                    {
                        K.TabKata[j]=temp;
                        ++j;
                        temp = fgetc(F);
                    }
                    K.Length = j;
                    EName(EMap(LEn(ElMini(CMap,m)),i)) = K;
                    fscanf(F,"%d %d",&Absis(Pos(LEn(ElMini(CMap,m)),i)),&Ordinat(Pos(LEn(ElMini(CMap,m)),i)));
                    ++i;
                }
            }
        }
	//load skill
	int a[16];
    for (i = 2; i <= 15; i++)
    {
        fscanf(F,"%d",&a[i]);
    }
    BinTree T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15;

    T15 = Tree(15,Nil,Nil,a[15]);
    T14 = Tree(13,Nil,Nil,a[14]);
    T13 = Tree(11,Nil,Nil,a[13]);
    T12 = Tree(9,Nil,Nil,a[12]);
    T11 = Tree(7,Nil,Nil,a[11]);
    T10 = Tree(5,Nil,Nil,a[10]);
    T9 = Tree(3,Nil,Nil,a[9]);
    T8 = Tree(1,Nil,Nil,a[8]);

    T7 = Tree(14,T14,T15,a[7]);
    T6 = Tree(10,T12,T13,a[6]);
    T5 = Tree(6,T10,T11,a[5]);
    T4 = Tree(2,T8,T9,a[4]);

    T3 = Tree(12,T6,T7,a[3]);
    T2 = Tree(4,T4,T5,a[2]);

    MakeTree(8,T2,T3,&PSkill(*P));
    Sudah(PSkill(*P)) = true;
        //load graph
        CreateEmptyGraph(&Gr(CMap));
        addressG PG,PrecG=Nil;
        addressL PL,PrecL;
        List templist;
        int temp;
        fscanf(F,"%d",&temp);
        while (temp!=-1)
        {
            CreateEmptyList(&templist);
            PrecL = Nil;
            for (i=1;i<=4;++i)
            {
                PL = AlokasiList(temp);
                if (PrecL==Nil) FirstL(templist) = PL;
                else Next(PrecL) = PL;
                PrecL = PL;
                fscanf(F,"%d",&temp);
            }
            PG = AlokasiGraph(templist);
            if (PrecG==Nil) FirstG(Gr(CMap)) = PG;
            else Next(PrecG) = PG;
            PrecG = PG;
        }
        fclose(F);
	NarasiContinue(PName(*P));
	PrintCLoop(' ',20);
	printf("Press Enter to Continue\n");
	char c;
	do scanf("%c",&c); while (c!='\n');
        return true;
    }
}
