#include "main.h"
#include "display.h"
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


int main() {
    greeting();

    char a =_getch(); //input user memilih apa 
    switch (a) {
        case '1': //start game
            system("cls"); // Bersihkan layar
              // Inisialisasi skor dan papan
        // Tambahkan dua angka acak di awal permainan
        if (ifinitiation()){
            addrandom();
            addrandom();
        }
        
        while (true) {
        displayPapan(&game);
        // Tampilkan papan
        menampilkanPapan();

        if (win()){
            printf ("You win!\n");
            displayGameOver(&game);
            break;
        }
        
        // Periksa jika game over
        if (gameOver()) {
            printf("Game Over! Skor akhir: %d\n", game.score);
            displayGameOver(&game);
            break; // Keluar dari loop jika permainan sudah berakhir
        }

        // Panggil fungsi geserMerge untuk menangani input
        geserMerge();

        // Tambahkan angka acak baru setelah pergerakan
        addrandom();
    }
        
        break;



        case '2': //Highscore
            system("cls"); // Bersihkan layar
            break;



        case '3': //how to play
            system("cls");
            howtoplay();
            getch();// tekan apa saja untuk kembali ke main
            system("cls"); // Bersihkan layar
            main();
            break;



        case '4': //exit
            system("cls"); // Bersihkan layar
            exit(0);
            break;
}
}