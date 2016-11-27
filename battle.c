//ADT untuk BATTLE
//Jadi isinya semua interface buat battle
//Tanggal 5 November 2016

/****** compile : gcc -o battle mbattle.c player.c enemy.c battle.c mesinkata.c stack.c queue.c mesinkar.c point.c matriks.c map.c narasi.c listlinier.c graph.c skilltree.c -lm *****/

#include "color.h"
#include "boolean.h"
#include "player.h"
#include "gambar.h"
#include "enemy.h"
#include "battle.h"
#include "mesinkata.h"
#include "map.h"
#include "skilltree.h"
#include "narasi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* *************** Primitif untuk Printing *************** */
void PrintBorder ()
/* buat ngeprint border panjang */
{
    printf(COLOR_MAGENTA"------------------------------------------------------------------------------------------------------\n"COLOR_RESET);
}

void PrintGuard ()
/* buat pring guard */
{
    printf(COLOR_CYAN" | "COLOR_RESET);
}

void PrintPlayer ( PLAYER P )
/* I.S. : Player terdefinisi */
/* F.S. : menampilkan status player di layar */
{
    //kamus
    int i;

    PrintKata(P.NAME); //nama
    i = 15 - PName(P).Length;
	PrintCLoop(' ', i);
    PrintGuard();

    printf("LVL : %d",P.LEVEL); //level
    i = 4 - digit(PLevel(P));
	PrintCLoop(' ', i);
    PrintGuard();

	if(PHP(P) < 0){
		printf("HP : 0");
	} else {
		printf("HP : %d",P.HP); //HP
	}
    i = 4 - digit(PHP(P));
	PrintCLoop(' ', i);
	printf(" "); //karena "H""P" hanya 2 huruf jadi ditambah 1 spasi biar sama panjang
    PrintGuard();

    printf("STR : %d",P.STR); //Strength
    i = 4 - digit(PSTR(P));
	PrintCLoop(' ', i);
    PrintGuard();

    printf("DEF : %d",P.DEF); //Defense
    i = 4 - digit(PDEF(P));
	PrintCLoop(' ', i);
    PrintGuard();
}

void PrintEnemy ( ENEMY E , infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4 )
/* I.S. : Enemy tidak kosong, sudah diload dari file eksternal */
         /* M1 dan M2 adalah move enemy */
/* F.S. : Menampilkan nama, HP, dan 2 command dari enemy */
{
    /* kamus */
    int i;

    /* algoritma */
    PrintKata(E.NAME);
    i = 15 - EName(E).Length;
	PrintCLoop(' ', i);
    PrintGuard();

	if(EHP(E) < 0){
		printf("HP : 0");
	} else {
		printf("HP : %d",E.HP);
	}
    i = 4 - digit(EHP(E));
	PrintCLoop(' ', i);
	printf(" ");
    PrintGuard();

    printf("Command : %c ",M1);
    printf("%c ",M2);
    printf("%c ",M3);
    printf("%c ",M4);

    printf("  ");
    PrintGuard();
    printf("\n");
}

void BattleUIinput (PLAYER P, ENEMY E, infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4, int round, Queue *PlayerMoves)
/* Prosedur untuk menampilkan battle saat input pengguna */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : Seluruh input pengguna disimpan dalam queue */
{
	/* print player */
    PrintBorder();
    PrintPlayer(P);
    printf("Round %d",round); //Round
    PrintGuard(); printf("\n"); PrintBorder();
    PrintEnemy(E,M1,M2,M3,M4); PrintBorder();

    /* input pengguna */
    PrintKata(EName(E)); printf(" Attacked!\n");
    printf("Please input your command\n"); PrintBorder();

    /* Kamus */
    char c;

    /*Insert Command*/
    CreateEmptyQueue(PlayerMoves,4);

    while(!IsFullQueue(*PlayerMoves)){
		printf("Inserted Commands : "); PrintQueue(*PlayerMoves); printf("\n");
		PrintBorder();
		printf("Command (A / F / B) : ");
        scanf("%c",&c);
        if(c == 'A' || c == 'F' || c == 'B'){   //Memasukan input A F B
            AddQueue(PlayerMoves,c);
        } else
        if(c == 'E'){                           //Mendelete E
            CreateEmptyQueue(PlayerMoves,4);
        }
        PrintBorder();
        clrscr();
        /* print player */
		PrintBorder();
		PrintPlayer(P);
		printf("Round %d",round); //Round
		PrintGuard(); printf("\n"); PrintBorder();
		PrintEnemy(E,M1,M2,M3,M4); PrintBorder();

		/* input pengguna */
		PrintKata(EName(E)); printf(" Attacked!\n");
		printf("Please input your command\n");
		PrintBorder();
    }
}

void BattleUIoutput (PLAYER *P, ENEMY *E, infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4, Queue PlayerMoves, int round, int movenum, int calc)
/* untuk mengeprint seluruh proses battle setelah input
 * I.S. : semua player, enemy, dan move nya terdefinisi
 * F.S. : diprint hasil dari battle
 */
{
	int i; char aksi, buang;
	Queue Temp = PlayerMoves;
	if(calc == 1)
	{
		/* print header */
		PrintBorder();
		PrintPlayer(*P);
		printf("Round %d",round); //Round
		PrintGuard(); printf("\n"); PrintBorder();
		switch (movenum) {
			case 1 :
			{
				PrintKata(EName(*E));
				i = 15 - EName(*E).Length;
				PrintCLoop(' ', i);
				PrintGuard();

				if (EHP(*E)>=0) printf("HP : %d",EHP(*E));
				else printf("HP : 0");
				i = 4 - digit(EHP(*E));
				PrintCLoop(' ', i);
				printf(" ");
				PrintGuard();

				printf("Command : >%c ",M1);
				printf("%c ",M2);
				printf("%c ",M3);
				printf("%c ",M4);
				break;
			}
			case 2 :
			{
				PrintKata(EName(*E));
				i = 15 - EName(*E).Length;
				PrintCLoop(' ', i);
				PrintGuard();

				if (EHP(*E)>=0) printf("HP : %d",EHP(*E));
				else printf("HP : 0");
				i = 4 - digit(EHP(*E));
				PrintCLoop(' ', i);
				printf(" ");
				PrintGuard();

				printf("Command : %c ",M1);
				printf(">%c ",M2);
				printf("%c ",M3);
				printf("%c ",M4);
				break;
			}
			case 3 :
			{
				PrintKata(EName(*E));
				i = 15 - EName(*E).Length;
				PrintCLoop(' ', i);
				PrintGuard();

				if (EHP(*E)>=0) printf("HP : %d",EHP(*E));
				else printf("HP : 0");
				i = 4 - digit(EHP(*E));
				PrintCLoop(' ', i);
				printf(" ");
				PrintGuard();

				printf("Command : %c ",M1);
				printf("%c ",M2);
				printf(">%c ",M3);
				printf("%c ",M4);
				break;
			}
			case 4 :
			{
				PrintKata(EName(*E));
				i = 15 - EName(*E).Length;
				PrintCLoop(' ', i);
				PrintGuard();

				if (EHP(*E)>=0) printf("HP : %d",EHP(*E));
				else printf("HP : 0");
				i = 4 - digit(EHP(*E));
				PrintCLoop(' ', i);
				printf(" ");
				PrintGuard();

				printf("Command : %c ",M1);
				printf("%c ",M2);
				printf("%c ",M3);
				printf(">%c ",M4);
				break;
			}
		}

		printf("\n");
		PrintBorder();
		PrintKata(EName(*E)); printf(" Attacked!\n");

		/* dialog box */
		switch (movenum) {
			case 1 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc); break; }
			case 2 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M2,calc); break; }
			case 3 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M2,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M3,calc); break; }
			case 4 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M2,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M3,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M4,calc); break; }
		}

		PrintBorder();
		printf("Inserted Commands : ");
		switch (movenum) {
			case 1 :
			{ DelQueue(&Temp,&aksi); printf(">%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi); break; }
			case 2 :
			{ DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf(">%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi); break; }
			case 3 :
			{ DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf(">%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi); break; }
			case 4 :
			{ DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf("%c ",aksi);
			  DelQueue(&Temp,&aksi); printf(">%c ",aksi); break; }
		} printf("\n");
		PrintBorder();
	}
	else
	{
	switch (movenum) {
			case 1 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc); break; }
			case 2 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M2,calc); break; }
			case 3 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M2,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M3,calc); break; }
			case 4 :
			{ DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M1,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M2,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M3,calc);
			  DelQueue(&PlayerMoves,&aksi); BattleProccess(P,aksi,E,M4,calc); break; }
		}
	}
}

void HideTwoMoves (char i1, char i2, char i3, char i4, char *o1, char *o2, char *o3, char *o4)
/* menrandom apa yg dihide */
{
    //kamus
    int seed;

    //algoritma
    srand((unsigned int)time(NULL));
    seed = rand() % 6;
    switch (seed)
    {
        case 0 : *o1 = '#'; *o2 = '#'; *o3 = i3; *o4 = i4; break;
        case 1 : *o1 = '#'; *o2 = i2; *o3 = '#'; *o4 = i4; break;
        case 2 : *o1 = '#'; *o2 = i2; *o3 = i3; *o4 = '#'; break;
        case 3 : *o1 = i1; *o2 = '#'; *o3 = '#'; *o4 = i4; break;
        case 4 : *o1 = i1; *o2 = '#'; *o3 = i3; *o4 = '#'; break;
        case 5 : *o1 = i1; *o2 = i2; *o3 = '#'; *o4 = '#'; break;
    }
}

/* **************** Primitif untuk Kalkulasi **************************/
void BattleProccess (PLAYER *P, char MP, ENEMY *E, infotypeQ ME, int calc)
/* I.S. : player, enemy, dan player moves dan enemy moves terdefinisi
   F.S. : Permainan selesai dengan HP player dan enemey berkurang, seluruh move sudah dieksekusi
   * calu = calculation 0 berarti tidak mengeprint hasil kalkulasi
*/
{
	if(calc != 0){
		if(MP == 'A' && ME == 'B'){
			PrintKata(PName(*P));
			printf(" attacked! but it's blocked!\n");
		} else
		if(MP == 'B' && ME == 'F'){
			PrintKata(PName(*P));
			printf(" received damage from the flank! -%d HP\n",Damage(ESTR(*E),PDEF(*P))*3/2);
			PHP(*P) -= Damage(ESTR(*E),PDEF(*P))*3/2;
		} else
		if(MP == 'F' && ME == 'A'){
			PrintKata(EName(*E));
			printf(" attacked! You received damage! -%d HP\n",Damage(ESTR(*E),PDEF(*P)));
			PHP(*P) -= Damage(ESTR(*E),PDEF(*P));
		} else
		if(MP == 'A' && ME == 'F'){
			PrintKata(PName(*P));
			printf(" attacked! ");
			PrintKata(EName(*E));
			printf(" received damage! -%d HP\n",Damage(PSTR(*P),EDEF(*E)));
			EHP(*E) -= Damage(PSTR(*P),EDEF(*E));
		} else
		if(MP == 'B' && ME == 'A'){
			PrintKata(PName(*P));
			printf(" blocked the attack!\n");
		} else
		if(MP == 'F' && ME == 'B'){
			PrintKata(PName(*P));
			printf(" flanked! ");
			PrintKata(EName(*E));
			printf(" received damage! -%d HP\n",Damage(PSTR(*P),EDEF(*E))*3/2);
			EHP(*E) -= Damage(PSTR(*P),EDEF(*E)) * 3/2; //flank memberi lebih banyak damage
		} else
		if(MP == 'A' && ME == 'A'){
			PrintKata(PName(*P));
			printf(" attacked! ");
			PrintKata(EName(*E));
			printf(" received damage! -%d HP\n",Damage(PSTR(*P),EDEF(*E)));
			EHP(*E) -= Damage(PSTR(*P),EDEF(*E));

			PrintKata(EName(*E));
			printf(" attacked! You received damage! -%d HP\n",Damage(ESTR(*E),PDEF(*P)));
			PHP(*P) -= Damage(ESTR(*E),PDEF(*P));
		}else
		{
			printf("Nothing happened!\n");
		}
	}
	else
	{
		if(MP == 'B' && ME == 'F'){
			PHP(*P) -= Damage(ESTR(*E),PDEF(*P))*3/2;
		} else
		if(MP == 'F' && ME == 'A'){
			PHP(*P) -= Damage(ESTR(*E),PDEF(*P));
		} else
		if(MP == 'A' && ME == 'F'){
			EHP(*E) -= Damage(PSTR(*P),EDEF(*E));
		} else
		if(MP == 'F' && ME == 'B'){
			EHP(*E) -= Damage(PSTR(*P),EDEF(*E)) * 3/2; //flank memberi lebih banyak damage
		} else
		if(MP == 'A' && ME == 'A'){
			EHP(*E) -= Damage(PSTR(*P),EDEF(*E));
			PHP(*P) -= Damage(ESTR(*E),PDEF(*P));
		}
	}
}

int Damage (int Attack, int Defense)
/* menghitung damage yang dihasilkan */
/* Attack adalah str dari penyerang */
/* Defense adalah def dari yang diserang */
{
    /* kamus */
    int selisih = Attack - Defense;

    /* algoritma */
    if (selisih >= 0){   //Jika attack > defense
        return (int)(20 + 0.1*selisih);
    } else
    if (selisih < -100){  //Jika defense >>> attack
        return (5);
    } else {             //Jika defense > attack, -100 < selisih < -1
        return (int)(20 + 0.15*selisih);
    }
}

void LevelUp (PLAYER *P)
/* menghitung skema naik level */
/* I.S. : sudah selesai battle, exp sudah bertambah */
/* F.S. : level naik */
{
	//KAMUS
	int lvlawal = PLevel(*P);

	//algoritma
	if(PLevel(*P) == 1 && PEXP(*P) >= 100)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 100;
		MaxHP(*P) += 50;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	} else
	if(PLevel(*P) == 2 && PEXP(*P) >= 150)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 150;
		MaxHP(*P) += 50;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	} else
	if(PLevel(*P) == 3 && PEXP(*P) >= 200)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 200;
		MaxHP(*P) += 50;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	} else
	if(PLevel(*P) == 4 && PEXP(*P) >= 250)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 250;
		MaxHP(*P) += 50;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	} else
	if(PLevel(*P) == 5 && PEXP(*P) >= 300)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 300;
		MaxHP(*P) += 50;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	} else
	if(PLevel(*P) == 6 && PEXP(*P) >= 350)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 350;
		MaxHP(*P) += 50;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	} else
	if(PLevel(*P) == 7 && PEXP(*P) >= 400)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 400;
		MaxHP(*P) += 100;
		PSTR(*P) += 100;
		PDEF(*P) += 100;
	} else
	if(PLevel(*P) == 8 && PEXP(*P) >= 450)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 450;
		MaxHP(*P) += 100;
		PSTR(*P) += 100;
		PDEF(*P) += 100;
	} else
	if(PLevel(*P) == 9 && PEXP(*P) >= 500)
	{
		PLevel(*P) += 1;
		PEXP(*P) -= 500;
		MaxHP(*P) += 100;
		PSTR(*P) += 50;
		PDEF(*P) += 50;
	}

	if(PLevel(*P) > lvlawal) {
		printf("Congratulations! You are now level %d!\n",PLevel(*P));
		AmbilSkill(&PSkill(*P),&PSTR(*P),&PDEF(*P));
		PrintBorder();
	}
}

/* ******************* Primitif untuk Memulai Battle ********************* */
void InitBattle (PLAYER *P, TE T, int *result)
/* I.S. : player dan tabel enemy terdefinisi
          akan mencatat seluruh keadaan sebelum battle dimulai
          akan memanggil fungsi battle UI dan dialog box sebanyak 10 kali atau hingga musuh kalah
          Status dari Player dan Enemy akan diupdate tiap ronde selesai
   F.S. : player menang atau kalah, enemy kalah atau kabur
   * 	  result 1 = menang
   * 	  result 2 = seri
   * 	  result 3 = kalah
*/
{
    /* Kamus */
    ENEMY E;
    Stack S;
    int i, round, movenum, PHPawal, EHPawal;
    char me1,me2,me3,me4,mp1,mp2,mp3,mp4,o1,o2,o3,o4,buang;
    Queue PlayerMoves;

    /* inisiasi enemy */
    CreateEmptyStack(&S); //untuk set move nya
    RandomStack(&S,10);   //dirandom 1 - 10
    round = 1;           //inisiasi ronde

    srand((unsigned int)time(NULL));
    int rnd;
    if(PLevel(*P) < 2){
        rnd = rand() % 3;
    } else if(PLevel(*P) < 4){
        rnd = rand() % 5;
    } else if(PLevel(*P) < 6){
        rnd = rand() % 7;
    } else if(PLevel(*P) < 8){
        rnd = rand() % 9;
    } else{
        rnd = rand() % 11;
    }
    if (rnd == 0) rnd += 1 ;
    if (IsEnemyUndefined(SearchPos2(LEn(ElMini(CMap,CMiniMap)),Posisi(*P)))) 
    {
	CreateEnemy(&E,T,rnd);
	EMap(LEn(ElMini(CMap,CMiniMap)),SearchPos1(LEn(ElMini(CMap,CMiniMap)),Posisi(*P))) = E;
    }
    else
    {
	rnd = 0;
	E = SearchPos2(LEn(ElMini(CMap,CMiniMap)),Posisi(*P));
    }

    if(rnd != 10)
    {

	//pertarungan
    do {
		PopStack(&S,&i);      //ambil 1
		//mengambil move dari queue
		DelQueue(&EAksi(E)[i],&me1);
		DelQueue(&EAksi(E)[i],&me2);
		DelQueue(&EAksi(E)[i],&me3);
		DelQueue(&EAksi(E)[i],&me4);
		HideTwoMoves(me1,me2,me3,me4,&o1,&o2,&o3,&o4);
		clrscr();

		BattleUIinput(*P,E,o1,o2,o3,o4,round,&PlayerMoves);

        movenum = 0;
        PHPawal = PHP(*P);
        EHPawal = EHP(E);
        while(movenum <= 4){
			BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,movenum,0);
			BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,movenum,1);
			if(PHP(*P) <= 0 || EHP(E) <= 0) break;
			scanf("%c",&buang);
			clrscr();
			movenum++;

			if(PHP(*P) > 0 && EHP(E) > 0){
				PHP(*P) = PHPawal;
				EHP(E) = EHPawal;
			}
		}
		PHP(*P) = PHPawal;
		EHP(E) = EHPawal;

		BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,4,0);

        ++round;
    } while ((round <= 10) && (EHP(E) > 0) && (PHP(*P) > 0));

    /* akhiran */
    if ((PHP(*P) > 0) || (round > 10)){
        EDie(E) = true;
        printf("Congratulations! ");PrintKata(EName(E));printf(" has been defeated!\n");
        if(EHP(E) <= 0){
			*result = 1;
            printf("You received %d experience!\n",EEXP(E));
            PEXP(*P) += EEXP(E);
        } else {
			*result = 2;
            PrintKata(EName(E));printf(" fled!\n");
        }
    } else
    if (PHP(*P) <= 0){
        *result = 3;
        printf("You have lost!\n");
    }
    LevelUp (P);

    PrintCLoop(' ',20);
    printf("Press enter to continue!\n");
    PrintCLoop(' ',20);
    do scanf("%c",&buang); while (buang!='\n');

    }
    else //lawan boss
    {

    NarasiBoss();
    PrintCLoop(' ',20);
    printf("Press enter to continue!\n");
    PrintCLoop(' ',20);
    do scanf("%c",&buang); while (buang!='\n');


    //pertarungan
    do {
    	PopStack(&S,&i);      //ambil 1
		//mengambil move dari queue
		DelQueue(&EAksi(E)[i],&me1);
		DelQueue(&EAksi(E)[i],&me2);
		DelQueue(&EAksi(E)[i],&me3);
		DelQueue(&EAksi(E)[i],&me4);
		HideTwoMoves(me1,me2,me3,me4,&o1,&o2,&o3,&o4);
		clrscr();

		BattleUIinput(*P,E,o1,o2,o3,o4,round,&PlayerMoves);

        movenum = 0;
        PHPawal = PHP(*P);
        EHPawal = EHP(E);
        while(movenum <= 4){
			BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,movenum,0);
			BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,movenum,1);
			if(PHP(*P) <= 0 || EHP(E) <= 0) break;
			scanf("%c",&buang);
			clrscr();
			movenum++;

			if(PHP(*P) > 0 && EHP(E) > 0){
				PHP(*P) = PHPawal;
				EHP(E) = EHPawal;
			}
		}
		PHP(*P) = PHPawal;
		EHP(E) = EHPawal;

		BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,4,0);

        ++round;
    } while ((round <= 10) && (EHP(E) > 0) && (PHP(*P) > 0));

    if(round > 10){
    int temp = EHP(E);
    CreateEnemy(&E,T,10);
    EHP(E) = temp;

    CreateEmptyStack(&S);
    RandomStack(&S,10);
    do {
    	PopStack(&S,&i);
		//mengambil move dari queue
		DelQueue(&EAksi(E)[i],&me1); printf("%c\n",me1);
		DelQueue(&EAksi(E)[i],&me2);printf("%c\n",me2);
		DelQueue(&EAksi(E)[i],&me3);printf("%c\n",me3);
		DelQueue(&EAksi(E)[i],&me4);printf("%c\n",me4);
		HideTwoMoves(me1,me2,me3,me4,&o1,&o2,&o3,&o4);
		clrscr();

		BattleUIinput(*P,E,o1,o2,o3,o4,round,&PlayerMoves);

        movenum = 0;
        PHPawal = PHP(*P);
        EHPawal = EHP(E);
        while(movenum <= 4){
			BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,movenum,0);
			BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,movenum,1);
			if(PHP(*P) <= 0 || EHP(E) <= 0) break;
			scanf("%c",&buang);
			clrscr();
			movenum++;

			if(PHP(*P) > 0 && EHP(E) > 0){
				PHP(*P) = PHPawal;
				EHP(E) = EHPawal;
			}
		}
		PHP(*P) = PHPawal;
		EHP(E) = EHPawal;

		BattleUIoutput(P,&E,me1,me2,me3,me4,PlayerMoves,round,4,0);

        ++round;
    } while ((round <= 20) && (EHP(E) > 0) && (PHP(*P) > 0));
	}

    /* akhiran final battle */
    if ((PHP(*P) > 0) || (round > 20)){
        EDie(E) = true;
        printf("Congratulations! ");PrintKata(EName(E));printf(" has been defeated!\n");
        if(EHP(E) <= 0){
			*result = 1;
            printf("You received %d experience!\n",EEXP(E));
            PEXP(*P) += EEXP(E);
            PrintWin();
            NarasiClosing(PName(*P));
    	    printf("Press enter to continue!\n");
    	    do scanf("%c",&buang); while (buang!='\n');
	    clrscr();
	    PrintCredits();
    	    //do scanf("%c",&buang); while (buang!='\n');
		exit(0);
        } else {
			*result = 2;
            PrintKata(EName(E));printf(" fled!\n");
        }
    } else
    if (PHP(*P) <= 0){
        *result = 3;
        printf("You have lost!\n");
    }
    LevelUp (P);

    printf("Press Enter to continue!\n");
    scanf("%c",&buang);

  }
}
