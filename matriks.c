//Nama : Aldrich Valentino Halim
//NIM  : 13515081
//Nama File : matriks.c
//ADT Tubes matriks
//Deskripsi : ADT Matriks

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
    WayOut(*M,0) = MakePOINT(-1,-1);
    WayOut(*M,1) = MakePOINT(-1,-1);
    WayOut(*M,2) = MakePOINT(-1,-1);
    WayOut(*M,3) = MakePOINT(-1,-1);
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
    return ((i >= BrsMin) && (i <= BrsMax) && (j >= KolMin) && (j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terkecil M */
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M){
/* Mengirimkan indeks baris terbesar M */
    return (GetFirstIdxBrs(M) + NBrsEff(M) - 1);
}
indeks GetLastIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terbesar M */
    return (GetFirstIdxKol(M) + NKolEff(M) - 1);
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return ((i >= GetFirstIdxBrs(M)) && (i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M)) && (j <= GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i){
/* Mengirimkan elemen M(i,i) */
    return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
    indeks i,j;
    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for (i=GetFirstIdxBrs(MIn);i<=GetLastIdxBrs(MIn);++i)
        for (j=GetFirstIdxKol(MIn);j<=GetLastIdxKol(MIn);++j)
            Elmt(*MHsl,i,j)=Elmt(MIn,i,j);
    SearchWayOut(MHsl);
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS *M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
{
    indeks i,j;
    MakeMATRIKS(NB,NK,M);
    for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);++i)
        for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);++j)
            scanf("%d",&Elmt(*M,i,j));
}
void TulisMATRIKS (MATRIKS M){
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
*/
    //kamus
    indeks i,j;

    //algoritma
    for (i=GetFirstIdxBrs(M); i<=GetLastIdxBrs(M); i++){
        for (j=GetFirstIdxKol(M); j<=GetLastIdxKol(M); j++){
            printf("%c ",Elmt(M,i,j));
        }
        if (i != GetLastIdxBrs(M)){
          printf("\n");
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
    //kamus
    indeks i,j;
    boolean found;

   //algoritma
   if ((GetLastIdxBrs(M1) == GetLastIdxBrs(M2)) && (GetLastIdxKol(M1) == GetLastIdxKol(M2))) {
      found = true;
      i = GetFirstIdxBrs(M1);
      while ((found) && (i < GetLastIdxBrs(M1))){
         j = GetFirstIdxKol(M1);
         while ((found) && (j < GetLastIdxKol(M1))){
              if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
                found = false;
              }
              j += 1;
            }
         i += 1;
        }
        return found;
   } else {
        return false;
    }
}
boolean NEQ (MATRIKS M1, MATRIKS M2) {
/* Mengirimkan true jika M1 tidak sama dengan M2 */
    return (!EQ(M1,M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2){
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
    return ((NBrsEff(M1) == NBrsEff (M2)) && (NKolEff (M1) == NKolEff (M2)));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
/* Mengirimkan banyaknya elemen M */
    return (NBrsEff(M)*NKolEff(M));

}

/* ********** Matriks dan Point ********** */
ElType Elmt2(MATRIKS M,POINT P)
/* Mengakses matriks dengan point, mengeluarkan elemen di M pada posisi P */
{
    return (Elmt(M,Absis(P),Ordinat(P)));
}
void SetElmt(MATRIKS *M,POINT P,ElType X)
/* I.S. M terdefinisi, P indeks yang valid, X sembarang */
/* F.S. Elemen M pada posisi P adalah X */
{
    Elmt(*M,Absis(P),Ordinat(P)) = X;
}
void GenerateRandomPOINT(MATRIKS M,POINT *P)
/* I.S. M terdefinisi, P sembarang */
/* F.S. P merupakan indeks valid (bukan pinggiran) */
{
    indeks i,j;
    i = RandomIndeks(GetFirstIdxBrs(M)+1,GetLastIdxBrs(M)-1);
    j = RandomIndeks(GetFirstIdxKol(M)+1,GetLastIdxKol(M)-1);
    Absis(*P) = i;
    Ordinat(*P) = j;
}

void SearchWayOut (MATRIKS *M)
/* mencari jalan keluar matriks, yaitu di tepi matriks yg merupakan '-' */
{
    //kamus
    int i,j;

    //algoritma
    for(i = BrsMin; i <= GetLastIdxBrs(*M); i++){ //sisi kiri
        if(Elmt(*M,i,1) == '-'){
            WayOut(*M,0) = MakePOINT(i,1);
        }
    }
    for(i = BrsMin; i <= GetLastIdxBrs(*M); i++){ //sisi kanan
        if(Elmt(*M,i,GetLastIdxKol(*M)) == '-'){
            WayOut(*M,2) = MakePOINT(i,GetLastIdxKol(*M));
        }
    }
    for(j = KolMin; j <= GetLastIdxKol(*M); j++){ //sisi atas
        if(Elmt(*M,1,j) == '-'){
            WayOut(*M,1) = MakePOINT(1,j);
        }
    }
    for(j = KolMin; j <= GetLastIdxKol(*M); j++){ //sisi bawah
        if(Elmt(*M,GetLastIdxBrs(*M),j) == '-'){
            WayOut(*M,3) = MakePOINT(GetLastIdxBrs(*M),j);
        }
    }
}

/* ********** Operasi random ********** */
indeks RandomIndeks(indeks i,indeks j)
/* mengeluarkan indeks random dari i sampai j inklusif */
/* Asumsi : i dan j sama jenisnya (baris atau kolom) i<=j */
{
    return (rand(j-i+1)%+i);
}
void GenerateRandomMatriks(MATRIKS *M)
/* I.S. M sembarang */
/* F.S. M merupakan matriks dengan ukuran NBrsxNKol dan semua pinggiran adalah '#' dan sisanya antara '-' atau '#' */
/* Matriks didapat dari hasil generate secara random */
{
    POINT P;
    indeks i,j;
    for (i=GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);++i)
        for (j=GetFirstIdxKol(*M);j<=GetLastIdxKol(*M);++j)
            Elmt(*M,i,j) = '#';
    int k,l,m=(NBrsEff(*M)*NKolEff(*M))*3/2;
    GenerateRandomPOINT(*M,&P);
    SetAvail(M,P);
    for (l=0;l<m;++l)
    {
        int dir = rand()%4;
        switch (dir)
        {
            case 0 : Ordinat(P) = Ordinat(P)-1;break;
            case 1 : Absis(P) = Absis(P)-1;break;
            case 2 : Ordinat(P) = Ordinat(P)+1;break;
            case 3 : Absis(P) = Absis(P)+1;break;
        }
        if (Absis(P)==GetLastIdxBrs(*M)) --Absis(P);
        if (Absis(P)==GetFirstIdxBrs(*M)) ++Absis(P);
        if (Ordinat(P)==GetFirstIdxKol(*M)) ++Ordinat(P);
        if (Ordinat(P)==GetLastIdxKol(*M)) --Ordinat(P);
        SetElmt(M,P,'-');
    }
}
