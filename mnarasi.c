#include <stdio.h>
#include "narasi.h"

int main () {
	//Kamus
	Kata Nama;
	
	//Algoritma
	NarasiOpening(&Nama);
	NarasiClosing(Nama);
	NarasiContinue(Nama); 
	NarasiBoss (); 
	NarasiLaut(1);
	NarasiLaut(2);
	NarasiLaut(3);
	NarasiLaut(4);
	NarasiLaut(5);
	NarasiLaut(6);
	NarasiLaut(7);
	NarasiLaut(8);
	NarasiLaut(9);
	NarasiLaut(10); 
	NarasiKetemuMonster (); 
	NarasiMenangLawanMonster (); 
	NarasiKetemuEnergi (); 
	NarasiKekuranganEnergi ();
	return 0;
}
