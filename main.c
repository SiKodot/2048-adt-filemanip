#include "main.h"
#include "display.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

Game2048 game;

int main() {
    greeting();

    char a =_getch(); //input user memilih apa 
    switch (a) {
        case '1': //start game
            system("cls"); // Bersihkan layar
            gameMain();
            break;
        case '2': //Highscore
            system("cls"); // Bersihkan layar
            break;
        case '3': //how to play
            system("cls");
            howtoplay();
            getch();// tekan apa saja untuk kembali ke main
            system("cls"); // Bersihkan layar
            greeting();
            break;
        case '4': //exit
            system("cls"); // Bersihkan layar
            exit(0);
            break;
        default: //jika tidak valid
            printf("Pilihan tidak valid\n"); // Menangani pilihan yang tidak valid
            break;
    }
}

void gameMain() {
    // Inisialisasi skor dan papan
    game.score = 0;
    if (game.score > game.highscore) {
        game.highscore = game.score;
    }
    resetPapan();

    // Tambahkan dua angka acak di awal permainan
    addrandom();
    addrandom();

    // Loop utama permainan
    while (1) {
        // Tampilkan papan
        menampilkanPapan();
        displayPapan(&game);
        
        // Periksa jika game over
        if (gameOver()) {
            displayGameOver(&game);
            break;
        }

        // Panggil fungsi geserMerge untuk menangani input
        geserMerge();

        // Tambahkan angka acak baru setelah pergerakan
        addrandom();
    }
}