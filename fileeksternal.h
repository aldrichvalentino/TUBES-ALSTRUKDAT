/* File : fileeksternal.h */


#ifndef FILEEKSTERNAL_H
#define FILEEKSTERNAL_H

#include "boolean.h"
#include "player.h"
#include "jam.h"
#include "mesinkata.h"

void CreateUser(Kata *K);
/* I.S. sembarang */
/* F.S. succeed bernilai true jika berhasil membuat user, selain itu false, K berisi nama user jika proses berhasil */

boolean IsFileExist(char *c);
/* Mengeluarkan true jika file bernama c ada */

Kata ConvertToTxt(Kata K);
/* Menambah .txt dibelakang K */

void SaveGame(PLAYER P,JAM J);
/* I.S. Permainan sudah dimainkan */
/* F.S. Data permainan sudah disimpan di (namaplayer).txt */

boolean LoadGame(PLAYER *P,JAM *J);
/* I.S. Nama player terdefinisi */
/* F.S. Data permainan sudah dipindah ke program */

#endif // FILEEKSTERNAL_H
