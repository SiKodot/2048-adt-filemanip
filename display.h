#ifndef MENU_H
#define MENU_H
#include "game.h"
#include "highscore.h"

// Fungsi untuk menampilkan menu dan menangani input pengguna
void mainmenu();
void howtoplay();
void printforinputuser();
void printforinputgeser();
void displayPapan(Game2048 permainan, DataHighScore dhs);
void displayGameOver(Game2048 permainan);
void displaywin(Game2048 permainan);
#endif // MENU_H