//Nama : Aldrich Valentino Halim
//NIM  : 13515081
//Nama File : matriks.c
//ADT Tubes matriks
//Deskripsi : ADT Matriks

/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include "matriks.h"
#include "point.h"
#include "mesinkar.h"
#include <stdio.h>
#include <stdlib.h>

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

/* ********** Mencari jalan keluar MATRIKS ********** */
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

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
/* Melakukan assignment MHsl  MIn */
    //Kamus
    indeks i,j;
    //algoritma
    MakeMATRIKS(GetLastIdxBrs(MIn),GetLastIdxKol(MIn),MHsl);
    for (i=GetFirstIdxBrs(MIn); i<=GetLastIdxBrs(MIn); i++){
        for (j=GetFirstIdxKol(MIn); j<=GetLastIdxKol(MIn); j++){
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }
    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);
    SearchWayOut(MHsl);
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS *M1, int NB, int NK){
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
    //kamus
    indeks i,j ;
    char *fin;

    //algoritma
    MakeMATRIKS(NB,NK,M1);

    fin = malloc(10 * sizeof(char));
    fin = "peta.txt";
    START(fin);
    while(!EOP){
        for(i = 1; i <= NB; i++){
            for(j= 1; j <= NK; j++){
                Elmt(*M1,i,j) = CC;
                ADV();
                ADV();
            }
        }
    }

    SearchWayOut(M1);
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

void Transpose (MATRIKS * M){
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
    //kamus
    indeks i,j;
    MATRIKS Mbaru;

    //algoritma
    MakeMATRIKS(NKolEff(*M),NBrsEff(*M),&Mbaru);
    for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
        for (j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
            Elmt(Mbaru,j,i) = Elmt(*M,i,j);
        }
    }
    CopyMATRIKS(Mbaru,M);
}

void Rotate180 (MATRIKS * M){
//merotasi 180 derajat
    //kamus
    indeks i,j;
    MATRIKS Mbaru;

    //algoritma
    MakeMATRIKS(NBrsEff(*M),NKolEff(*M),&Mbaru);
    for (i=GetFirstIdxBrs(*M); i<=GetLastIdxBrs(*M); i++){
        for (j=GetFirstIdxKol(*M); j<=GetLastIdxKol(*M); j++){
            Elmt(Mbaru,GetLastIdxBrs(*M) - i + 1,GetLastIdxKol(*M) - j + 1) = Elmt(*M,i,j);
        }
    }
    CopyMATRIKS(Mbaru,M);
}

MATRIKS GenerateMAP (MATRIKS M)
//membuat sebuah map baru dari map asal dengan cara merotasi 180 derajat atau transpose
//MUNGKIN BISA JADI LAG GARA-GARA DIGENERATE RANDOM NUMBER TRUS DIPASTIIN GA 0
{
    //kamus
    MATRIKS New;
    int i;

    //algoritma
    do {
        srand((unsigned int)time(NULL));
        i = rand() % 3;
    } while (i == 0); //mencegah dapet 0

    CopyMATRIKS(M,&New);
    if (i == 1){ //transpose
        Transpose(&New);
    } else if (i == 2){
        Rotate180(&New);
    }
    return New;
}

