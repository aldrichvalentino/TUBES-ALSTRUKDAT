#include "jam.h"
#include <stdio.h>

/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
    return ((H>=0)&&(H<24)&&(M>=0)&&(M<60)&&(S>=0)&&(S<60));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
    JAM j;
    Hour(j)=HH;
    Minute(j)=MM;
    Second(j)=SS;
    return j;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
{
    printf("%02d:%02d:%02d",Hour(J),Minute(J),Second(J));
}
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
    return 3600*Hour(J)+60*Minute(J)+Second(J);
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
    N=N%86400;
    return MakeJAM(N/3600,(N%3600)/60,N-N/3600-(N%3600)/60);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
    return ((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)==Second(J2)));
}
boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
    return (!JEQ(J1,J2));
}
boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
    if (Hour(J1)<Hour(J2)) return true;
    else if (Minute(J1)<Minute(J2)) return true;
    else if (Second(J1)<Second(J2)) return true;
    else return false;
}
boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
{
    return ((!JLT(J1,J2))&&(JNEQ(J1,J2)));
}
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
    JAM j;
    if (Second(J)<59) j=MakeJAM(Hour(J),Minute(J),Second(J)+1);
    else if (Minute(J)<59) j=MakeJAM(Hour(J),Minute(J)+1,0);
    else if (Hour(J)<23) j=MakeJAM(Hour(J)+1,0,0);
    else j=MakeJAM(0,0,0);
    return j;
}
JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
    int i;
    JAM j=J;
    for (i=0;i<N;++i) j=NextDetik(j);
    return j;
}
JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
    JAM j;
    if (Second(J)>0) j=MakeJAM(Hour(J),Minute(J),Second(J)-1);
    else if (Minute(J)>0) j=MakeJAM(Hour(J),Minute(J)-1,59);
    else if (Hour(J)>0) j=MakeJAM(Hour(J)-1,59,59);
    else j=MakeJAM(23,59,59);
    return j;
}
JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
{
    int i;
    JAM j=J;
    for (i=0;i<N;++i) j=PrevDetik(j);
    return j;
}
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
    return ((JAMToDetik(JAkh)-JAMToDetik(JAw)+86400)%86400);
}

/* ***************************************************************** */
/* KELOMPOK OPERASI RECORD JAM                                    */
/* ***************************************************************** */
void StartRecord(JAM *J,time_t *sec)
/* I.S. Sembarang
    F.S. Jam diset menjadi 00:00:00, sec mwnyimpan waktu yang akan menjadi acuan waktu*/
{
    *J = MakeJAM(0,0,0);
    *sec = time(NULL);
}
JAM Record(JAM J,time_t sec)
/* I.S. J dan sec terdefinisi, sec merupakan waktu acuan awal
    F.S. J diupdate sesuai dengan lama waktu yang telah terjadi sejak StartRecord*/
{
    time_t temp = time(NULL);
    temp -= sec;
    return DetikToJAM(temp);
}

int main()
{
    return 0;
}
