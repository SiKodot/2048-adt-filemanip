#include <stdio.h>
#include "display.h"
#include "game.h"

void greeting(){
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
        printf("1. start game\n");
        printf("2. highscore\n");
        printf("3. how to play\n");
        printf("4. exit\n\n");
        printf("Masukkan pilihan anda\n");
}

void howtoplay(){
        printf("Papan   : Game 2048 dimainkan di papan berukuran 4x4.\n");
        printf("Ubin    : Setiap ubin memiliki nilai yang merupakan kelipatan dua, seperti 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, dan 2048.\n");
        printf("Geser Ubin: Anda dapat menggeser ubin ke atas, bawah, kiri, atau kanan. Ubin yang memiliki angka yang sama akan bergabung menjadi satu ubin dengan nilai yang dijumlahkan.\n");
        printf("Munculnya Ubin Baru: Setiap kali Anda melakukan gerakan, ubin baru dengan nilai 2 atau 4 akan muncul di papan.\n");
        printf("Kemenangan  : Anda menang jika Anda berhasil menggabungkan ubin menjadi 2048.\n");
        printf("Kekalahan   : Permainan berakhir jika tidak ada lagi gerakan yang mungkin dilakukan dan papan sudah penuh.\n\n\n");
        printf("Tekan apapun untuk kembali");
}

void printforinputuser(){
        printf("Masukkan nama pengguna\n");
        printf("Jika sudah selesai tekan enter dan pastikan nama sesuai\n");
}

void displayPapan(Game2048 permainan, DataHighScore dhs) {
    printf("Nama Pengguna: %s\n", permainan.username);
   printf("Score: %d\n", permainan.score);
   printf("High Score: %d (%s)\n", dhs.highscore, dhs.username);
   printf("Gunakan W/A/S/D untuk menggeser blok. Tekan Q untuk keluar.\n");
   // Di sini Anda bisa menambahkan kode untuk menampilkan papan permainan
}

// Fungsi untuk menampilkan pesan Game Over
void displayGameOver(Game2048 permainan, DataHighScore *dhs) { 
    printf("Game Over! Skor akhir: %d\n", permainan.score);
    if (permainan.score > dhs->highscore) { // Membandingkan skor dengan highscore
        dhs->highscore = permainan.score;   // Mengupdate highscore
        printf("Selamat! High Score baru: %d\n", dhs->highscore);
    }
}

void displaywin(Game2048 permainan, DataHighScore *dhs){
    printf("You Win! %s\n", permainan.username);
    printf("Skor akhir: %d\n", permainan.score);
    if (permainan.score > dhs->highscore) { // Membandingkan skor dengan highscore
        dhs->highscore = permainan.score;   // Mengupdate highscore
        printf("Selamat! High Score baru: %d\n", dhs->highscore);
    }
}