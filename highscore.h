#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#define HIGHSCORE_FILE "highscore.txt"
#include "game.h"

typedef struct {
    char username[50];
    int highscore;
}DataHighScore;

#endif