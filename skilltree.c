#include "listrek.h"
#include "boolean.h"
#include "skilltree.h"
#include <stdlib.h>
#include <stdio.h>


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
/* *** Traversal *** */
void PrintPreorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        printf("%d",Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
        printf(")");
    }
}
void PrintInorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        PrintInorder(Left(P));
        printf("%d",Akar(P));
        PrintInorder(Right(P));
        printf(")");
    }
}
void PrintPostorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d",Akar(P));
        printf(")");
    }
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
                case 8 : printf(COLOR_GREEN     "PIRATES HAT(1)"     COLOR_RESET "\n");break;
                case 4 : printf(COLOR_GREEN     "CAPTAINS BLOOD(2)"     COLOR_RESET "\n");break;
                case 12 : printf(COLOR_GREEN    "CAPTAINS SENSE(3)"     COLOR_RESET "\n");break;
                case 2 : printf(COLOR_GREEN     "BLOODY HOOK(4)"     COLOR_RESET "\n");break;
                case 6 : printf(COLOR_GREEN     "TOXIC ATTACK(5)"     COLOR_RESET "\n");break;
                case 10 : printf(COLOR_GREEN    "PIRATES EYES(6)"     COLOR_RESET "\n");break;
                case 14 : printf(COLOR_GREEN    "DEFENSIVE STANCE(7)"     COLOR_RESET "\n");break;
                case 1 : printf(COLOR_GREEN     "SACRED SWORD(8)"     COLOR_RESET "\n");break;
                case 3 : printf(COLOR_GREEN     "WAVE STRIKE(9)"     COLOR_RESET "\n");break;
                case 5 : printf(COLOR_GREEN     "BACKSTAB(10)"     COLOR_RESET "\n");break;
                case 7 : printf(COLOR_GREEN     "CAPTAINS RAGE(11)"     COLOR_RESET "\n");break;
                case 9 : printf(COLOR_GREEN     "SUPERIOR BLOCK(12)"     COLOR_RESET "\n");break;
                case 11 : printf(COLOR_GREEN    "WATER FORM(13)"     COLOR_RESET "\n");break;
                case 13 : printf(COLOR_GREEN    "SALTY SKIN(14)"     COLOR_RESET "\n");break;
                case 15 : printf(COLOR_GREEN    "ICE SHIELD(15)"     COLOR_RESET "\n");break;
            }
        }
        else
        {
            switch (Akar(P)){
                case 8 : printf("PIRATES HAT(1)\n");;break;
                case 4 : printf("CAPTAINS BLOOD(2)\n");break;
                case 12 : printf("CAPTAINS SENSE(3)\n");break;
                case 2 : printf("BLOODY HOOK(4)\n");break;
                case 6 : printf("TOXIC ATTACK(5)\n");break;
                case 10 : printf("PIRATES EYES(6)\n");break;
                case 14 : printf("DEFENSIVE STANCE(7)\n");break;
                case 1 : printf("SACRED SWORD(8)\n");break;
                case 3 : printf("WAVE STRIKE(9)\n");break;
                case 5 : printf("BACKSTAB(10)\n");break;
                case 7 : printf("CAPTAINS RAGE(11)\n");break;
                case 9 : printf("SUPERIOR BLOCK(12)\n");break;
                case 11 : printf("SPELL ARMOR(13)\n");break;
                case 13 : printf("HARD SKIN(14)\n");break;
                case 15 : printf("ICE SHIELD(15)\n");break;
            }
        }
        PrintTree1(Left(P),h,inc+1);
        PrintTree1(Right(P),h,inc+1);
    }
}

void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    PrintTree1(P,h,0);
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


/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
    }
}
int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeOneElmt(P))
    {
        return 1;
    }
    else
    {
        if (IsUnerLeft(P))
        {
            return (NbDaun(Left(P)));
        }
        else if (IsUnerRight(P))
        {
            return (NbDaun(Right(P)));
        }
        else if (IsBiner(P))
        {
            return (NbDaun(Left(P)) + NbDaun(Right(P)));
        }
    }
}
boolean IsSkewLeft (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else
    {
        if (Right(P) != Nil)
        {
            return false;
        }
        else
        {
            return (IsSkewLeft(Left(P)));
        }
    }

}
boolean IsSkewRight (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else
    {
        if (Left(P) != Nil)
        {
            return false;
        }
        else
        {
            return (IsSkewRight(Right(P)));
        }
    }

}
int Level (BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
{
    if (Akar(P) == X)
    {
        return 1;
    }
    else
    {
        if (SearchTree(Left(P),X))
        {
            return 1 + (Level(Left(P),X));
        }
        else
        {
            return 1 + (Level(Right(P),X));
        }
    }
}
int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        if (Tinggi(Left(P)) > Tinggi(Right(P)))
        {
            return (1 + Tinggi(Left(P)));
        }
        else
            return (1 + Tinggi(Right(P)));
        }
}
/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    if (IsTreeEmpty(*P))
    {
        *P = AlokNode(X);
    }
    else
    {
        AddDaunTerkiri(&Left(*P),X);
    }
}
void AddDaunTerkanan (BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    if (IsTreeEmpty(*P))
    {
        *P = AlokNode(X);
    }
    else
    {
        AddDaunTerkanan(&Left(*P),X);
    }
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
    if (IsTreeOneElmt(*P))
    {
        if (Akar(*P) == X)
        {
            if (Kiri)
            {
                Left(*P) = AlokNode(Y);
            }
            else
            {
                Right(*P) = AlokNode(Y);
            }
        }
    }
    else
    {
        if (SearchTree(Left(*P),X))
        {
            AddDaun(&Left(*P),X,Y,Kiri);
        }
        else
        {
            AddDaun(&Right(*P),X,Y,Kiri);
        }
    }
}
void DelDaunTerkiri (BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
    addrNode N;
    if (IsTreeOneElmt(*P))
    {
        *X = Akar(*P);
        N = *P;
        *P = Nil;
        DealokNode(N);
    }
    else
    {
        if (IsUnerRight(*P))
        {
            DelDaunTerkiri(&Right(*P),X);
        }
        else
        {
            DelDaunTerkiri(&Left(*P),X);
        }
    }
}
void DelDaun (BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
    addrNode N;
    if (IsTreeOneElmt(*P))
    {
        if (Akar(*P) == X)
        {
             N = *P;
            *P = Nil;
            DealokNode(N);
        }
    }
    else
    {
        if (IsUnerRight(*P))
        {
            DelDaun(&Right(*P),X);
        }
        else if (IsUnerLeft(*P))
        {
            DelDaun(&Left(*P),X);
        }
        else if (IsBiner(*P))
        {
            DelDaun(&Left(*P),X);
            DelDaun(&Right(*P),X);
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

void AmbilSkill(BinTree *P)
// Prosedur untuk ngambil skill
{
    char pilih;
    int x;
    int skill;
    BinTree T;
    printf("Pilih nomor skill yang ingin diambil :\n");
    scanf("%d",&skill);
    if (SkillToInt(skill) <= 15 && SkillToInt(skill) >= 1)
    {
        if (!IsSudah(*P,SkillToInt(x)))
        {
            T = Parent(*P,SkillToInt(skill));
            if (IsSudah(*P,Akar(T)))
            {
                Sudah(SearchBST(*P,SkillToInt(skill))) = true;
            }
            else
            {
                printf("Skill sebelumnya harus diambil terlebih dahulu, pengambilan skill gagal\n");
            }
        }
        else
        {
            printf("Skill tersebut sudah diambil, pengambilan skill gagal\n");
        }
    }
    else
    {
        printf("Input nomor skill salah, pengambilan skill gagal\n");
    }
}

/* Command ini digunakan untuk menampilkan skill yang sudah diambil, dan
memilih skill baru yang akan diambil. Skill hanya mempengaruhi status pemain.
Mekanisme dan tampilan skill dibebaskan, namun harus berbentuk pohon */
