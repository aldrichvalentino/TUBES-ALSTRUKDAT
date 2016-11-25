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

extern int ronde;

/* *************** Primitif *************** */
void PrintBorder ();
/* buat border panjang gitu deh */

void PrintGuard ();
/* untuk print guard */

void PrintPlayer ( PLAYER P );
/* I.S. : Player terdefinisi */
/* F.S. : menampilkan status player di layar */

void PrintEnemy ( ENEMY E , infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4 );
/* menampilkan status enemy */

void HideTwoMoves (char i1, char i2, char i3, char i4, char *o1, char *o2, char *o3, char *o4);
/* merandom move yang dihide */

void InitBattle (PLAYER *P, TE T, boolean *result);
/* I.S. : player dan tabel enemy terdefinisi
          akan mencatat seluruh keadaan sebelum battle dimulai
          akan memanggil fungsi battle UI dan dialog box sebanyak 10 kali atau hingga musuh kalah
   F.S. : player menang atau kalah, enemy kalah atau kabur,
*/

void InputUserMoves (Queue *PlayerMoves);
/* Prosedur untuk menampilkan battle */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : enemy dikalahkan atau tidak, HP berkurang, exp bertambah atau berkurang */
/*        result akan terisi true apabila menang, false bila kalah */
/* setelah selesai dan exp bertambah, program caller harus mengecek exp, lalu menambahkan level jika sudah cukup */

void BattleProccess (PLAYER *P, char MP, ENEMY *E, infotypeQ ME);
/* I.S. : player, enemy, dan player moves dan enemy moves terdefinisi
   F.S. : Permainan selesai dengan HP player dan enemey berkurang, seluruh move sudah dieksekusi
*/

void BattleUI (PLAYER P, ENEMY E, infotypeQ M1, infotypeQ M2, infotypeQ M3, infotypeQ M4, int round );
/* Prosedur untuk menampilkan battle */
/* I.S. : Seluruh peta, player, enemy terdefinisi */
/* F.S. : enemy dikalahkan atau tidak, HP berkurang, exp bertambah atau berkurang */
/*        result akan terisi true apabila menang, false bila kalah */
/* setelah selesai dan exp bertambah, program caller harus mengecek exp, lalu menambahkan level jika sudah cukup */

int Damage(int Attack, int Defense);
/* fungsi menghitung damage yang dihasilkan */

#endif
