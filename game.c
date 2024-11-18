#include "game.h"
#include <stdio.h>
#include <string.h>

int papan[6][6];

void resetPapan(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            papan[i][j] = 0; // Menginisialisasi papan dengan 0
        }
    }
}

void menampilkanPapan(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", papan[i][j]); // Menampilkan isi papan
        }
        printf("\n"); // Baris baru setelah setiap baris papan
    }
}