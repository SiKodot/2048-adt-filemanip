// game.h
#ifndef GAME_H
#define GAME_H

#include<stdbool.h>

void gameMain();
void resetPapan();
void menampilkanPapan(); // Deklarasi fungsi
void geserMerge();
void addrandom();
void geserAtas();
void geserBawah();
void geserKiri();
void geserKanan();
void mergeAtas();
void mergeBawah();
void mergeKiri();
void mergeKanan();
bool gameOver();

#endif // GAME_H
/*
void scanWASD();
void geserBlok();
void menampilkanPapan();

*/