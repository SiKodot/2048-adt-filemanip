#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include "game.h"

typedef struct 
{
    char username[50];
    int highscore;
}HighScoreEntry;

extern HighScoreEntry Entry;

void saveHighScore(const char *username, int highscore);
void loadHighScore(Game2048 *game);

#endif