#include "skilltree.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "battle.h"

/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R, int i)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
    BinTree P;
	P = (addrNode) malloc (sizeof(Node));
	if (P != Nil)
	{
		Akar(P) = Akar;
		Left(P) = L;
		Right(P) = R;
		if (i == 1)
        {
            Sudah(P) = true;
        }
        else
        {
            Sudah(P) = false;
        }
    }
	return P;
}
void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
	*P = (addrNode) malloc (sizeof(Node));
	if (*P != Nil)
	{
		Akar(*P) = Akar;
		Left(*P) = L;
		Right(*P) = R;
		Sudah(*P) = false;
	}
}
/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addrNode P;
    P = (addrNode) malloc(sizeof(Node));
    if (P != Nil)
    {
        Akar(P) = X;
        Right(P) = Nil;
        Left(P) = Nil;
    }
    return P;
}
void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}
/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P == Nil);
}
boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (!IsTreeEmpty(P))
    {
        return (Right(P) == Nil && Left(P) == Nil);
    }
    else
    {
        return false;
    }
}
boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    return (Left(P) != Nil && Right(P) == Nil);
}
boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    return (Left(P) == Nil && Right(P) != Nil);
}
boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    return (Left(P) != Nil && Right(P) != Nil);
}

void PrintTree1(BinTree P, int h, int inc)
// UNTUK NGEPRINT TP INI BELUM JADI
{
    int i;
    if (!IsTreeEmpty(P))
    {
        for (i = 1;i <= h*inc;i++)
        {
            printf(" ");
        }
        if (Sudah(P))
        {
            switch (Akar(P)){
                case 8 : printf(COLOR_GREEN     "(1) PIRATES HAT [+5 STR, +5 DEF]"     COLOR_RESET "\n");break;
                case 4 : printf(COLOR_GREEN     "(2) CAPTAINS BLOOD [+10 STR, +5 DEF]"     COLOR_RESET "\n");break;
                case 12 : printf(COLOR_GREEN    "(3) CAPTAINS SENSE [+5 STR, +10 DEF]"     COLOR_RESET "\n");break;
                case 2 : printf(COLOR_GREEN     "(4) BLOODY HOOK [+20 STR, +5 DEF]"     COLOR_RESET "\n");break;
                case 6 : printf(COLOR_GREEN     "(5) TOXIC ATTACK [+15 STR, +10 DEF]"     COLOR_RESET "\n");break;
                case 10 : printf(COLOR_GREEN    "(6) PIRATES EYES [+10 STR, +15 DEF]"     COLOR_RESET "\n");break;
                case 14 : printf(COLOR_GREEN    "(7) DEFENSIVE STANCE [+5 STR, +20 DEF]"     COLOR_RESET "\n");break;
                case 1 : printf(COLOR_GREEN     "(8) SACRED SWORD [+40 STR, +5 DEF]"     COLOR_RESET "\n");break;
                case 3 : printf(COLOR_GREEN     "(9) WAVE STRIKE [+35 STR, +10 DEF]"     COLOR_RESET "\n");break;
                case 5 : printf(COLOR_GREEN     "(10) BACKSTAB [+30 STR, +15 DEF]"     COLOR_RESET "\n");break;
                case 7 : printf(COLOR_GREEN     "(11) CAPTAINS RAGE [+25 STR, +20 DEF]"     COLOR_RESET "\n");break;
                case 9 : printf(COLOR_GREEN     "(12) SUPERIOR BLOCK [+20 STR, +25 DEF]"     COLOR_RESET "\n");break;
                case 11 : printf(COLOR_GREEN    "(13) WATER FORM [+15 STR, +30 DEF]"     COLOR_RESET "\n");break;
                case 13 : printf(COLOR_GREEN    "(14) SALTY SKIN [+10 STR, +35 DEF]"     COLOR_RESET "\n");break;
                case 15 : printf(COLOR_GREEN    "(15) ICE SHIELD [+5 STR, +40 DEF]"     COLOR_RESET "\n");break;
            }
        }
        else
        {
            switch (Akar(P)){
                case 8 : printf("(1) PIRATES HAT [+5 STR, +5 DEF]\n");;break;
                case 4 : printf("(2) CAPTAINS BLOOD [+10 STR, +5 DEF]\n");break;
                case 12 : printf("(3) CAPTAINS SENSE [+5 STR, +10 DEF]\n");break;
                case 2 : printf("(4) BLOODY HOOK [+20 STR, +5 DEF]\n");break;
                case 6 : printf("(5) TOXIC ATTACK [+15 STR, +10 DEF]\n");break;
                case 10 : printf("(6) PIRATES EYES [+10 STR, +15 DEF]\n");break;
                case 14 : printf("(7) DEFENSIVE STANCE [+5 STR, +20 DEF]\n");break;
                case 1 : printf("(8) SACRED SWORD [+40 STR, +5 DEF]\n");break;
                case 3 : printf("(9) WAVE STRIKE [+35 STR, +10 DEF]\n");break;
                case 5 : printf("(10) BACKSTAB [+30 STR, +15 DEF]\n");break;
                case 7 : printf("(11) CAPTAINS RAGE [+25 STR, +20 DEF]\n");break;
                case 9 : printf("(12) SUPERIOR BLOCK [+20 STR, +25 DEF]\n");break;
                case 11 : printf("(13) WATER FORM [+15 STR, +30 DEF]\n");break;
                case 13 : printf("(14) SALTY SKIN [+10 STR, +35 DEF]\n");break;
                case 15 : printf("(15) ICE SHIELD [+5 STR, +40 DEF]\n");break;
            }
        }
        PrintTree1(Left(P),h,inc+1);
        PrintTree1(Right(P),h,inc+1);
    }
}


/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
    if (IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        if (Akar(P) == X)
        {
            return true;
        }
        else
        {
            return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
        }
    }
}

BinTree SearchBST (BinTree P, infotype X)
// Mendapatkan pohon yang memiliki akar bernilai X
{
    if (IsTreeEmpty(P))
    {
        return Nil;
    }
    else
    {
        if (Akar(P) == X)
        {
            return P;
        }
        else
        {
            if (X > Akar(P))
            {
                return SearchBST(Right(P), X);
            }
            else
            {
                return SearchBST(Left(P),X);
            }
        }
    }
}

boolean IsSudah(BinTree P, infotype X)
// Mengecek apakah skill sudah diambil atau belum
{
    if (IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        if (Akar(P) == X)
        {
            return Sudah(P);
        }
        else
        {
            if (X > Akar(P))
            {
                return IsSudah(Right(P), X);
            }
            else
            {
                return IsSudah(Left(P),X);
            }
        }
    }
}


void SaveSkillTree(BinTree P, FILE *F)
{
    int a[16];
    int i;
    for (i = 2; i <= 15; i++)
    {
        if (Sudah(SearchBST(P,SkillToInt(i))) == true)
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 0;
        }
    }
    F = fopen("skill.txt","w");
    for (i = 2; i <= 15 ; i++)
    {
        fprintf(F,"%d ", a[i]);
    }
    fclose(F);

}

void LoadSkillTree(BinTree *P, FILE *F)
{
    int a[16];
    int i,x;
    F = fopen("skill.txt","r");
    for (i = 2; i <= 15; i++)
    {
        fscanf(F,"%d",&x);
        a[i] = x;
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

    MakeTree(8,T2,T3,P);
    Sudah(*P) = true;

    fclose(F);
}

void CreateNewSkillTree(BinTree *P)
// Membuat skill tree baru untuk player
{
    BinTree T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15;

    T15 = Tree(15,Nil,Nil,0);
    T14 = Tree(13,Nil,Nil,0);
    T13 = Tree(11,Nil,Nil,0);
    T12 = Tree(9,Nil,Nil,0);
    T11 = Tree(7,Nil,Nil,0);
    T10 = Tree(5,Nil,Nil,0);
    T9 = Tree(3,Nil,Nil,0);
    T8 = Tree(1,Nil,Nil,0);

    T7 = Tree(14,T14,T15,0);
    T6 = Tree(10,T12,T13,0);
    T5 = Tree(6,T10,T11,0);
    T4 = Tree(2,T8,T9,0);

    T3 = Tree(12,T6,T7,0);
    T2 = Tree(4,T4,T5,0);
    *P = Nil;
    MakeTree(8,T2,T3,P);
    Sudah(*P) = true;
}

void PrintSkillTree(BinTree P)
{
    PrintTree1(P,2,0);
}

int SkillToInt(int skill)
// Mengubah biar jadi BST kalo di proses di fungsi
{
    switch (skill){
        case 1 : return 8; break;
        case 2 : return 4; break;
        case 3 : return 12; break;
        case 4 : return 2; break;
        case 5 : return 6; break;
        case 6 : return 10; break;
        case 7 : return 14; break;
        case 8 : return 1; break;
        case 9 : return 3; break;
        case 10 : return 5; break;
        case 11 : return 7; break;
        case 12 : return 9; break;
        case 13 : return 11; break;
        case 14 : return 13; break;
        case 15 : return 15; break;
    }
}

addrNode Parent(BinTree P, infotype X)
{
    if (IsTreeEmpty(P))
    {
        return Nil;
    }
    else
    {
        if (Akar(Left(P)) == X || Akar(Right(P)) == X)
        {
            return P;
        }
        else
        {
            if (X > Akar(P))
            {
                return Parent(Right(P),X);
            }
            else
            {
                return Parent(Left(P),X);
            }
        }
    }
}

void AmbilSkill(BinTree *P, int *STR, int *DEF)
/* I.S. : Player terdefinisi, sudah naik level, STR adalah STR player, DEF adalah DEF player
 * F.S. : skill diambil, status bertambah
 */
{
    char pilih;
    boolean stop = false;
    int skill;
    BinTree T;
    PrintSkillTree(*P);
    printf("                                      PLAYER SKILL TREE\n");
    PrintBorder();
    printf("If you choose the upper path your STR will increase!\nIf you choose the lower path your DEF will increase!\n");
    printf("Pilih nomor skill yang ingin diambil :\n");
    scanf("%d",&skill);
    while (!stop)
    {
		if (skill >=16 || skill <= 0)
		{
			printf("Input tidak terdefinisi, ulangi input :\n");
			scanf("%d",&skill);
		}
		else
		{
				if ((!IsSudah(*P,SkillToInt(skill)))&&(skill!=1))
				{
					T = Parent(*P,SkillToInt(skill));
					if (IsSudah(*P,Akar(T)))
					{
						Sudah(SearchBST(*P,SkillToInt(skill))) = true;
						switch (skill){
							case 2 : *STR += 10; *DEF += 5; printf("STR bertambah 10, DEF bertambah 5\n"); break;
							case 3 : *STR += 5; *DEF += 10; printf("STR bertambah 5, DEF bertambah 10\n"); break;
							case 4 : *STR += 20; *DEF += 5; printf("STR bertambah 20, DEF bertambah 5\n"); break;
							case 5 : *STR += 15; *DEF += 10; printf("STR bertambah 15, DEF bertambah 10\n"); break;
							case 6 : *STR += 10; *DEF += 15; printf("STR bertambah 10, DEF bertambah 15\n"); break;
							case 7 : *STR += 5; *DEF += 20; printf("STR bertambah 5, DEF bertambah 20\n"); break;
							case 8 : *STR += 40; *DEF += 5; printf("STR bertambah 40, DEF bertambah 5\n"); break;
							case 9 : *STR += 35; *DEF += 10; printf("STR bertambah 35, DEF bertambah 10\n"); break;
							case 10 : *STR += 30; *DEF += 15; printf("STR bertambah 30, DEF bertambah 15\n"); break;
							case 11 : *STR += 25; *DEF += 20; printf("STR bertambah 25, DEF bertambah 20\n"); break;
							case 12 : *STR += 20; *DEF += 25; printf("STR bertambah 20, DEF bertambah 25\n"); break;
							case 13 : *STR += 15; *DEF += 30; printf("STR bertambah 15, DEF bertambah 30\n"); break;
							case 14 : *STR += 10; *DEF += 35; printf("STR bertambah 10, DEF bertambah 35\n"); break;
							case 15 : *STR += 5; *DEF += 40; printf("STR bertambah 5, DEF bertambah 40\n"); break;
						}
					stop = true;
					}
					else
					{
						printf("Skill sebelumnya harus diambil terlebih dahulu, pengambilan skill gagal\n");
						scanf("%d",&skill);
					}
				}
				else
				{
					printf("Skill tersebut sudah diambil, pengambilan skill gagal\n");
					scanf("%d",&skill);
				}
		}
	}
}

/* Command ini digunakan untuk menampilkan skill yang sudah diambil, dan
memilih skill baru yang akan diambil. Skill hanya mempengaruhi status pemain.
Mekanisme dan tampilan skill dibebaskan, namun harus berbentuk pohon */


