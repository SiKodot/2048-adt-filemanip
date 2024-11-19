#include "game.h"
#include <stdio.h>
#include <string.h>

int papan[4][4];

void gameMain(){
    resetPapan();
    menampilkanPapan();
}

void resetPapan() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            papan[i][j] = 0; // Menginisialisasi papan dengan 0
        }
    }
}

void menampilkanPapan() {
    for (int i = 0; i < 4; i++) {
        // Menampilkan garis horizontal atas
        if (i == 0) {
            printf("+---+---+---+---+\n");
        }

        for (int j = 0; j < 4; j++) {
            printf("| %d ", papan[i][j]); // Menampilkan isi papan dengan batas
        }
        printf("|\n"); // Menutup baris dengan batas vertikal

        // Menampilkan garis horizontal bawah
        printf("+---+---+---+---+\n");
    }
}