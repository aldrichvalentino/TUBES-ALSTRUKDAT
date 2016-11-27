#include <stdio.h>
#include "narasi.h"
#include "mesinkata.h"
#include "player.h"

void NarasiOpening(Kata *Nama)
{
	//Kamus
	char C;
	
	//Algoritma
	printf("%s\n","Ahoyyy Captain!");
	printf("%s\n","What should we call you??");
	printf("%s\n","Insert Name Here: (max.16 character)");
	InputUser(Nama);
	while (Nama->Length > 16)
        {
            printf("Nama harus dibawah 16 Huruf\n");
            InputUser(Nama);
        }
	printf("%s","Congratulations Captain ");
	PrintKata(*Nama);
	printf("\n");
	printf("%s\n","Kamu baru saja mendapatkan informasi harta karun baru!");
	printf("%s\n","Harta karun tersebut berada dan tersembunyi di Samudra Bermuda, Samudra penuh misteri yang dihindari setiap penjelajah.");
	printf("%s\n","Yaitu harta Sang Bright Souls!!!");
	printf("%s\n","Dia dikenal sebagai Souls paling 'BRIGHT'.");
	printf("%s\n","Cahaya itu berasal dari hartanya yang menumpuk selalu memantulkan cahaya benderang baik disiang maupun malam hari.");
	printf("%s","Dalam perjalannya Captain ");
	PrintKata(*Nama); 
	printf("%s\n"," harus mengarungi puluhan lautan untuk menemukan dikediaman Sang Bright Souls.");
	printf("%s\n","HATI-HATI!!! Karena ditiap lautan ada 'Souls' lain yaitu monster22 kerabat dari Sang Bright Souls untuk melindungi hartanya.");
	printf("%s\n","SOOOO.. Let's begin the journey");
	printf("\n");
	printf("%s\n", "Press enter to continue");
	
	do 
		scanf("%c", &C);
	while (C != '\n');
	
}

void NarasiClosing(Kata Nama) {
	printf("%s\n","I have never expect that you will get finish this journey.");
	printf("%s","Sekarang kau adalah orang terkaya diseluruh negeri, Captain ");
	PrintKata(Nama);
	printf("%s\n", "!!!");
	printf("%s\n","Semoga kamu bisa menggunakan harta itu secara bijak tidak seperti Sang Bright Souls");
}

void NarasiContinue(Kata Nama) {
	printf("%s","Selamat datang kembali Captain ");
	PrintKata(Nama);
	printf("%s\n","!!!");
	printf("%s\n","Kami kira Captain sudah siap kembali untuk melanjutkan petualangan mencari harta Bright Souls");
	printf("%s\n","Semoga berhasil!!");
}

void NarasiBoss () {
	printf("%s\n","Lihatlah Captain!!");
	printf("%s\n","Setelah melewati perjalanan yang cukup panjang, sekarang kamu telah menemukan pulau kediaman Sang Bright Souls");
	printf("%s\n","Diujung sana telah tampak tujuan utamamu, segunung harta yang sangat terang!");
	printf("%s\n","Namun sebelumnya kamu harus mengalah BOSS dulu tentunya.");
	printf("%s\n","Yapp benar sekali! BOSS tidak lain adalah Sang Bright Souls!!!");
	printf("%s\n","Kami doakan segala kebaikkan padamu Captain!!");
}

void NarasiLaut(int X) {
	switch (X) {
		case 1 : NarasiLaut1(); break; 
		case 2 : NarasiLaut2(); break;
		case 3 : NarasiLaut3(); break;
		case 4 : NarasiLaut4(); break;
		case 5 : NarasiLaut5(); break;
		case 6 : NarasiLaut6(); break;
		case 7 : NarasiLaut7(); break;
		case 8 : NarasiLaut8(); break;
		case 9 : NarasiLaut9(); break;
		case 10 : NarasiLaut10(); break;
	}
}

void NarasiLaut10 () {
	printf("%s\n","Selamat Datang di 'Mirrored Waves Ocean' Captain!!");
	printf("%s\n","Laut ini memiliki kemampuan magis mendatangkan ombak yang kongruen dari kanan maupun kiri.");
	printf("%s\n","Bagaikan entah dengan apa ombak-ombak itu di 'Mirror'.");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut9 () {
	printf("%s\n","Selamat Datang di 'Pryvyt Sea' Captain!!");
	printf("%s\n","Laut ini dijadikan tempat makluk22 parasit tinggal Captain.");
	printf("%s\n","Parasit yang biasanya merusak kapal-kapal yang melintas.");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut8 () {
	printf("%s\n","Selamat Datang di 'Dread Ocean' Captain!!");
	printf("%s\n","Laut ini memiliki kemampuan magis menyebarkan rasa takut luar biasa.");
	printf("%s\n","Manusia biasanya hilang arah karena gila ketakutan di lautan ini.");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut7 () {
	printf("%s\n","Selamat Datang di 'Abyssal Bay' Captain!!");
	printf("%s\n","Laut ini merasa dimiliki oleh seluruh penghuninya. Rasa memiliki yang lebih dari sekedar rasa memiliki biasa.");
	printf("%s\n","Biasanya tidak ada yang selamat dari lautan ini, karena akan diculik dan para monster merasa 'memiliki' pengunjung tersebut.");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut6 () {
	printf("%s\n","Selamat Datang di 'Neglected Ocean' Captain!!");
	printf("%s\n","Nama laut ini berasal dari sejarah bahwa dahulu laut ini tidak dianggap .");
	printf("%s\n","Walaupun sekarang sudah dianggap, monster22 yang menaung di lautan ini sudah terlanjur memiliki dendam mendalam.");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut5 () {
	printf("%s\n","Selamat Datang di 'Red Sea' Captain!!");
	printf("%s\n","Diketahui bahwa laut ini berwarna merah berasal dari darah makhluk hidup yang menjadi santapan penghuni disini.");
	printf("%s\n","Monster22 yang menaung di lautan ini hobby memakan siapapun yang melintas");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut4 () {
	printf("%s\n","Selamat Datang di 'Boiling Gulf' Captain!!");
	printf("%s\n","Jangan pernah mencoba memegang air di laut ini");
	printf("%s\n","Siapapun yang terkena air laut ini akan langsung mati mendidih.");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut3 () {
	printf("%s\n","Selamat Datang di 'Overwhelming Waves' Captain!!");
	printf("%s\n","Laut ini telah disihir secara mistis sehingga arus-arusnya dapat secara misterius menggulung kapal22");
	printf("%s\n","Kendalikan kapal dengan baik Captain!!");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut2 () {
	printf("%s\n","Selamat Datang di 'Forbidden Depths' Captain!!");
	printf("%s\n","Diketahui bahwa laut ini dikatakan 'Terlarang' karena monster22 disini BENCI diganggu para pendatang");
	printf("%s\n","Cobalah melintas tanpa mengganggu monster disini sama sekali");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiLaut1 () {
	printf("%s\n","Selamat Datang di 'Bottomless Bay' Captain!!");
	printf("%s\n","Diketahui bahwa laut ini tidak memiliki dasar.");
	printf("%s\n","Monster22 yang menaung di lautan ini gemar menarik lawannya yang lengah ke lautan untuk tinggal bersama mereka.");
	printf("%s\n","Serta tentunya mereka tidak akan pernah kembali");
	printf("%s\n","Berhati-hatilah Captain!!!");
}

void NarasiKetemuEnergi () {
	printf("%s\n","Waaahh keberuntungan ada di pihakmu Captain!!");
	printf("%s\n","Kamu baru saja menemukan sebotol 'Medicine'.");
	printf("%s\n","Oleh karena itu, HP naik 50 HP.");
}

void NarasiKekuranganEnergi () {
	printf("%s\n","Ada masalah Captain!");
	printf("%s\n","Tampaknya energi telah berkurang banyak.");
	printf("%s\n","Captain butuh 'Medicine' tambahan segera!!");
}
