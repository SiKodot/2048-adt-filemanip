#include "ukuran.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Untuk _getch()
#include "game.h" // lanjut ke game

void menampilkanPapan(int size);

// Fungsi untuk menampilkan ilustrasi papan
void ilustrasi(int size) {
        for (int j = 0; j < size; j++) { // Ganti i dengan j untuk menghindari shadowing
        printf("+-----"); // Menampilkan garis batas horizontal
    }
    printf("+\n");

    // Menampilkan isi papan
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("|     "); // Menampilkan sel kosong
        }
        printf("|\n"); // Menutup baris

        // Menampilkan batas horizontal setelah setiap baris
        for (int j = 0; j < size; j++) { // Ganti i dengan j untuk menghindari shadowing
            printf("+-----"); // Menampilkan garis batas horizontal
        }
        printf("+\n");
    }
}

void menu_ukuran() {
    int selected = 0;
    char input;

    while (1) { // Loop untuk navigasi menu
        // Menampilkan pilihan ukuran dengan penanda untuk yang dipilih
        printf("Pilih ukuran kotak:\n");
        for (int i = 0; i < 3; i++) {
            if (i == selected) {
                printf("-> %dx%d <-\n", i + 4, i + 4); // Menandai ukuran yang dipilih
            } else {
                printf("   %dx%d\n", i + 4, i + 4); // Menampilkan ukuran lainnya
            }
        }
        // Menampilkan ilustrasi papan sesuai pilihan saat ini
        ilustrasi(selected + 4); // Menampilkan papan dengan ukuran yang dipilih
        input = _getch(); // Input user memilih apa
        system("cls"); // Membersihkan layar untuk menampilkan menu lagi

        // Navigasi menu dengan tombol atas dan bawah
        if (input == 'w' && selected > 0) {
            selected--; // Pindah ke atas
        } else if (input == 's' && selected < 2) {
            selected++; // Pindah ke bawah
        } else if (input == '\r') {
            break; // Keluar dari loop jika Enter ditekan
        }
    }

    // Tunggu input sebelum keluar
    menampilkanPapan(int size);

}