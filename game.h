// game.h
#ifndef GAME_H
#define GAME_H
#include<stdbool.h>

typedef struct {
    char username [50];
    int papan[4][4];
    int kosong[16][2]; //array untuk menyimpan posisi papan yang kosong
    int score;
    int highscore;
    int arah;

}Game2048;

extern Game2048 game;

void gameMain();
void resetPapan();
void menampilkanPapan(); // Deklarasi fungsi
int geserMerge();
void addrandom();
void geserAtas();
void geserBawah();
void geserKiri();
void geserKanan();
void mergeAtas();
void mergeBawah();
void mergeKiri();
void mergeKanan();
void inputusername(Game2048 *game);
bool gameOver();
bool win();
bool ifinitiation();

#endif // GAME_H