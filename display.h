#ifndef MENU_H
#define MENU_H
#include "game.h"
#include "highscore.h"

// Fungsi untuk menampilkan menu dan menangani input pengguna
void greeting();
void howtoplay();
void printforinputuser();
void displayPapan(Game2048 *permainan);
void displayGameOver(Game2048 *permainan);
void displaywin(Game2048 *permainan);

#endif // MENU_H