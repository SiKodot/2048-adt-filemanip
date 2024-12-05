// game.h
#ifndef GAME_H
#define GAME_H
#include<stdbool.h>

#include "highscore.h"

typedef struct {
    char username [50];
    int papan[4][4];
    int kosong[16][2]; //array untuk menyimpan posisi papan yang kosong
    int score;
    int arah;

}Game2048;

extern Game2048 game;

void menampilkanPapan(); // Deklarasi fungsi
int inputgeser();
void addrandom();
void geserAtas();
void geserBawah();
void geserKiri();
void geserKanan();
void tambahSkor(int nilai);
void mergeAtas();
void mergeBawah();
void mergeKiri();
void mergeKanan();

void inputusername(Game2048 *permainan);
bool gameOver();
bool win();
bool ifinitiation();
void saveHighScore(Game2048 *permainan, DataHighScore *Highscore);
void loadHighScore(DataHighScore *HighScore);

#endif // GAME_H