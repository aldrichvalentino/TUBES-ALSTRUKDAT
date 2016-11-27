//ADT untuk BATTLE
//Jadi isinya semua interface buat battle
//Tanggal : 5 November 2016

#ifndef BATTLE_H
#define BATTLE_H

#include "boolean.h"
#include "mesinkata.h"
#include "player.h"
#include "enemy.h"
#include "map.h"
#include "skilltree.h"

/* *************** Primitif untuk Printing *************** */
void PrintBorder ();
/* buat ngeprint border panjang */

void PrintGuard ();
/* buat pring guard */

void PrintPlayer ( PLAYER P );
/* I.S. : Player terdefinisi */
/* F.S. : menampilkan status player di layar */

void PrintEnemy ( ENEMY E , infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4 );
/* I.S. : Enemy tidak kosong, sudah diload dari file eksternal */
         /* M1 dan M2 adalah move enemy */
/* F.S. : Menampilkan nama, HP, dan 2 command dari enemy */

void BattleUIinput (PLAYER P, ENEMY E, infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4, int round, Queue *PlayerMoves);
/* Prosedur untuk menampilkan battle saat input pengguna */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : Seluruh input pengguna disimpan dalam queue */

void BattleUIoutput (PLAYER *P, ENEMY *E, infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4, Queue PlayerMoves, int round, int movenum, int calc);
/* untuk mengeprint seluruh proses battle setelah input
 * I.S. : semua player, enemy, dan move nya terdefinisi
 * F.S. : diprint hasil dari battle
 */

void HideTwoMoves (char i1, char i2, char i3, char i4, char *o1, char *o2, char *o3, char *o4);
/* menrandom apa yg dihide */

/* **************** Primitif untuk Kalkulasi **************************/
void BattleProccess (PLAYER *P, char MP, ENEMY *E, infotypeQ ME, int calc);
/* I.S. : player, enemy, dan player moves dan enemy moves terdefinisi
   F.S. : Permainan selesai dengan HP player dan enemey berkurang, seluruh move sudah dieksekusi
   * calu = calculation 0 berarti tidak mengeprint hasil kalkulasi
*/

int Damage (int Attack, int Defense);
/* menghitung damage yang dihasilkan */
/* Attack adalah str dari penyerang */
/* Defense adalah def dari yang diserang */

void LevelUp (PLAYER *P);
/* menghitung skema naik level */
/* I.S. : sudah selesai battle, exp sudah bertambah */
/* F.S. : level naik */

/* ******************* Primitif untuk Memulai Battle ********************* */
void InitBattle (PLAYER *P, TE T, int *result);
/* I.S. : player dan tabel enemy terdefinisi
          akan mencatat seluruh keadaan sebelum battle dimulai
          akan memanggil fungsi battle UI dan dialog box sebanyak 10 kali atau hingga musuh kalah
          Status dari Player dan Enemy akan diupdate tiap ronde selesai
   F.S. : player menang atau kalah, enemy kalah atau kabur
   * 	  result 1 = menang
   * 	  result 2 = seri
   * 	  result 3 = kalah
*/

#endif
