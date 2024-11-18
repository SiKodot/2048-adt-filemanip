#include "game.h"
#include <stdio.h>
#include <string.h>

int papan[3][3];

void resetPapan() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            papan[i][j] = 0; // Menginisialisasi papan dengan 0
        }
    }
}

void menampilkanPapan() {
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", papan[i][j]); // Menampilkan isi papan
        }
        printf("\n"); // Baris baru setelah setiap baris papan
    }
}