#include "game.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int papan[4][4];

void gameMain(){
    int A;
    resetPapan(); // Reset papan sekali di awal
    while (1) { // Loop tak terbatas untuk terus menerima input
        menampilkanPapan(); // Tampilkan papan saat ini
        addrandom(); // Tambahkan angka acak di papan
        menampilkanPapan(); // Tampilkan papan setelah menambahkan angka acak
        geser(&A); // Ambil input dari pengguna
        geserangka(A); // Geser angka berdasarkan input
    }

    return 0;
}

void resetPapan() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            papan[i][j] = 0; // Menginisialisasi papan dengan 0
        }
    }
    papan[0][3] = 2; // Menambahkan angka 2 di posisi tertentu
    papan[0][1] = 2;
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

void geser(int *arah){
    while (1) {

        char a =_getch();

        if (a == 'w' || a == 72) {
            *arah = 1;
        }
        else if (a == 's' || a == 80) {
            *arah = 2;
        }
        else if (a == 'a' || a == 75) {
            *arah = 3;
            break;
        }
        else if (a == 'd' || a == 77) {
            *arah = 4;
            break;
        }
        else{
            return;
        }
        
    }
}

void addrandom (){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (papan[i][j] == 0) {
                papan[i][j] = (rand() %100 <90) ? 2:4;
            }; // Menginisialisasi papan dengan 0
        }
    }
}

void geserangka(int arah) {
    if (arah == 3) { // Kiri
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j < 4; j++) { // Mulai dari kolom 1
                if (papan[i][j] != 0) { // Jika ada angka
                    int k = j;
                    while (k > 0 && papan[i][k - 1] == 0) { // Geser ke kiri
                        papan[i][k - 1] = papan[i][k];
                        papan[i][k] = 0;
                        k--;
                    }
                }
            }
        }
}
}