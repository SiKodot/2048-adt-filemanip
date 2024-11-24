#include "menu.h"
#include <conio.h> // Untuk _getch()
#include <stdlib.h> // Untuk system("cls")
#include <stdio.h>
#include "game.h" // lanjut ke game

void showMenu() { 
    int selected = 0; // Indeks pilihan yang dipilih

    while (1) { // Loop untuk menampilkan menu
        system("cls"); // Bersihkan layar

        // Menampilkan menu dengan pilihan yang dipilih

        printf("     ____    ____   __           _       ___        ___        _       __________          \n");
        printf("    |  __|  |   _| |  |         / \\     |   \\      /   |      / \\     |___    ___|         \n");
        printf("    | |__   |  |_  |  |        /   \\    | |\\ \\    / /| |     /   \\        |  |            \n");    
        printf("    |__  |  |   _| |  |       / /\\  \\   | | \\ \\  / / | |    / /_\\ \\       |  |            \n");
        printf("     _|  |  |  |_  |  |___   /  ___  \\  | |  \\ \\/ /  | |   /  ___  \\      |  |            \n");
        printf("    |____|  |____| |______| /__/   \\__\\ |_|   \\__/   |_|  /__/   \\__\\     |__|            \n\n\n");
        printf("      _____          _       __________       _        ____     __    _______          \n");
        printf("     |  __ \\        / \\     |___    ___|     / \\      |    \\   |  |  |  _____|         \n");
        printf("     | |  | |      /   \\        |  |        /   \\     |  |\\ \\  |  |  | |  ___          \n");
        printf("     | |  | |     / /_\\ \\       |  |       / /_\\ \\    |  | \\ \\ |  |  | | |_  |         \n");
        printf("     | |__| |    /  ___  \\      |  |      /  ___  \\   |  |  \\ \\|  |  | |___| |         \n");
        printf("     |_____/    /__/   \\__\\     |__|     /__/   \\__\\  |__|   \\____|  |_______|         \n\n\n");
        printf("                 _______      _________        ____       _______                    \n");
        printf("                /_____  \\    |  _____  |      / __ |     |  ___  |                         \n");
        printf("                     /  /    | |     | |     / /__||__   | |___| |                \n");
        printf("                    /  /     | |     | |    /__     __|  |  ___  |                        \n");
        printf("                 __/  /__    | |_____| |       |   |     | |___| |                    \n");
        printf("                |________|   |_________|       |___|     |_______|                                        \n");
        
        printf("Main menu:\n");
        


        // Menggunakan if untuk menentukan tampilan pilihan yang dipilih
        if (selected == 0) {
            printf("-> 1. Start Game\n");
        } else {
            printf("   1. Start Game\n");
        }

        if (selected == 1) {
            printf("-> 2. Leaderboard Highscore\n");
        } else {
            printf("   2. Leaderboard Highscore\n");
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

        char q = _getch(); // Input user memilih apa

        // Navigasi menu dengan tombol atas dan bawah
        if (q == 'w' && selected > 0) {
            selected--; // Pindah ke atas
        } else if (q == 's' && selected < 3) {
            selected++; // Pindah ke bawah
        } else if (q == '\r') { // Jika Enter ditekan
            break; // Keluar dari loop
        }
    }

    // Menangani pilihan yang dipilih
    switch (selected) {
        case 0: // Start Game
            system("cls"); // Tampilkan papan
            gameMain();
            break;
        case 1: // Leaderboard
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