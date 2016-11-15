/* File: enemy.c */

#include "enemy.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* ********** Pembuatan Enemy ********** */
void CreateEnemUndef(ENEMY *E)
/* I.S. E sembarang */
/* F.S. E adalah musuh yang belum terdefinsi */
{
    CreateKata("Undefined",&EName(*E));
    EHP(*E) = Undef;
    ESTR(*E) = Undef;
    EEXP(*E) = Undef;
    EDEF(*E) = Undef;
    EDie(*E) = false;
    //CreateEmptyQueue(EAksi(*E));
}
void CreateEnemy(ENEMY *E,TE T,int i)
/* I.S. T terdefinsi, E sembarang, i<IdxMaxTE */
/* F.S. E berisi data musuh yang terdapat pada tabel T pada indeks i */
{
    //kamus
    int j;

    CopyKata(EName(InfoT(T,i)),&EName(*E));
    EHP(*E) = EHP(InfoT(T,i));
    ESTR(*E) = ESTR(InfoT(T,i));
    EDEF(*E) = EDEF(InfoT(T,i));
    EEXP(*E) = EEXP(InfoT(T,i));
    EDie(*E) = false;
    for(j = 1; j <= IdxMaxAksi; ++j){
        EAksi(*E)[j] = EAksi(InfoT(T,i))[j];
    }
}
ENEMY EnemUndef()
/* Mengeluarkan enemy Undefined */
{
    ENEMY E;
    CreateEnemUndef(&E);
    return E;
}

/* ********** File Eksternal ********** */
void LoadEnemy(TE *T)
/* I.S. Sembarang, file eksternal berisi data enemy tersedia, jumlah musuh <= MaxEl dari TE */
/* F.S. Semua data sudah dipindahkan ke program */
/* Membuka file eksternal dan menyimpan semua ke array of ENEMY */
{
    char c[10] = "enemy.txt";
    STARTKATA(c);
    ENEMY E;
    Queue Q;
    int i,j,k=IdxMinTE;
    while (!EndKata)
    {
        CopyKata(CKata,&EName(E));
        ADVKATA(); EHP(E) = KataToInt(CKata);
        ADVKATA(); ESTR(E) = KataToInt(CKata);
        ADVKATA(); EDEF(E) = KataToInt(CKata);
        ADVKATA(); EEXP(E) = KataToInt(CKata);
        for (i=IdxMinAksi;i<=IdxMaxAksi;++i)
        {
            CreateEmptyQueue(&Q,4);
            for (j=0;j<4;++j)
            {
                ADVKATA();
                AddQueue(&Q,KataToChar(CKata));
            }
            EAksi(E)[i] = Q;
        }
        InfoT(*T,k) = E;
        ++k;
        ADVKATA();
    }
    NeffT(*T) = k;
}

/* ********** Predikat ********** */
boolean IsSameEnemy(ENEMY E1,ENEMY E2)
/* Mengeluarkan true jika E1 adalah E2 adalah musuh yang sama */
{
    return IsKataSama(EName(E1),EName(E2));
}
boolean IsEnemyUndefined(ENEMY E)
/* Mengeluarkan true jika E undefined */
{
    return IsSameEnemy(E,EnemUndef());
}

void RandomStack(Stack *S,int n)
/* I.S. S sembarang */
/* F.S. S berisi angka permutasi random dari 1 sampai n */
{
    int i,j,k,l;
    int set[n],temp;
    long long modulo = 1;
    for (i = 2;i<=n;++i) modulo*=i;
    srand((unsigned)time(NULL));
    long long random = (rand()%modulo);
    for (i = 0;i<n;++i) set[i] = i+1;
    while (random>0)
    {
        for (i = 0;i<n;++i)
        {
            if (set[i+1]>set[i]) j = i;
        }
        for (i = j+1;i<n;++i)
        {
            if (set[i]>set[j]) l = i;
        }
        temp = set[j];
        set[j] = set[l];
        set[l] = temp;
        k = (9-j)/2;
        for (i = 0;i<k;++i)
        {
            temp = set[j+i+1];
            set[j+i+1] = set[9-i];
            set[9-i] = temp;
        }
        --random;
    }
    for (i = 0;i<n;++i) PushStack(S,set[i]);
}

void LostHP(ENEMY *E,int lost)
/* I.S. EDie(E) = False(E belum mati) */
/* F.S. HP musuh berkurang sebanyak lost, EDie(E) = true jika HP-Lost=0 */
{
    if (EHP(*E)-lost>0) EHP(*E)-=lost;
    else EDie(*E) = true;
}
