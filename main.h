#ifndef MAIN_H
#define MAIN_H

typedef struct {
    char username [50];
    int papan[4][4];
    int kosong[16][2]; //array untuk menyimpan posisi papan yang kosong
    int score;
    int highscore;
    int arah;

}Game2048;

extern Game2048 game;

typedef struct 
{
    char username[50];
    int highscore;
}HighScoreEntry;

extern HighScoreEntry Entry;

#endif
