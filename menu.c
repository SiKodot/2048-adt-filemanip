#include "menu.h"
#include <conio.h> // Untuk _getch()
#include <stdlib.h> // Untuk system("cls")
#include <stdio.h>
#include "greeting.h" //selamat datang
#include "game.h" // lanjut ke game

void showMenu() { 
    int selected = 0; // Indeks pilihan yang dipilih
    char a;

    while (1) { // Loop untuk menampilkan menu
        system("cls"); // Bersihkan layar

        // Menampilkan menu dengan pilihan yang dipilih

        printGreeting();
        
        printf("Main menu:\n");
        


        // Menggunakan if untuk menentukan tampilan pilihan yang dipilih
        if (selected == 0) {
            printf("-> 1. Start Game\n");
        } else {
            printf("   1. Start Game\n");
        }

        if (selected == 1) {
            printf("-> 2. Load Game\n");
        } else {
            printf("   2. Load Game\n");
        }

        if (selected == 2) {
            printf("-> 3. How to Play\n");
        } else {
            printf("   3. How to Play\n");
        }

        if (selected == 3) {
            printf("-> 4. Exit\n");
        } else {
            printf("   4. Exit\n");
        }

        a = _getch(); // Input user memilih apa

        // Navigasi menu dengan tombol atas dan bawah
        if (a == 'w' && selected > 0) {
            selected--; // Pindah ke atas
        } else if (a == 's' && selected < 3) {
            selected++; // Pindah ke bawah
        } else if (a == '\r') { // Jika Enter ditekan
            break; // Keluar dari loop
        }
    }

    // Menangani pilihan yang dipilih
    switch (selected) {
        case 0: // Start Game
            system("cls"); // Tampilkan papan
            gameMain();
            break;
        case 1: // Load Game
            system("cls"); // Bersihkan layar
            break;
        case 2: // How to Play
            system("cls");
            printf("Papan   : Game 2048 dimainkan di papan berukuran 4x4.\n");
            printf("Ubin    : Setiap ubin memiliki nilai yang merupakan kelipatan dua, seperti 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, dan 2048.\n");
            printf("Geser Ubin: Anda dapat menggeser ubin ke atas, bawah, kiri, atau kanan. Ubin yang memiliki angka yang sama akan bergabung menjadi satu ubin dengan nilai yang dijumlahkan.\n");
            printf("Munculnya Ubin Baru: Setiap kali Anda melakukan gerakan, ubin baru dengan nilai 2 atau 4 akan muncul di papan.\n");
            printf("Kemenangan  : Anda menang jika Anda berhasil menggabungkan ubin menjadi 2048.\n");
            printf("Kekalahan   : Permainan berakhir jika tidak ada lagi gerakan yang mungkin dilakukan dan papan sudah penuh.\n\n\n");
            printf("Tekan apapun untuk kembali");
            getch();
            system("cls"); // Bersihkan layar
            printGreeting();
            showMenu();
            break;
        case 3: // Exit
            system("cls"); // Bersihkan layar
            exit(0);
        default: // Jika tidak valid
            printf("Pilihan tidak valid\n"); // Menangani pilihan yang tidak valid
            break;
    }
}