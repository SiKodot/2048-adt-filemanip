#include <stdio.h>
#include "display.h"
#include "game.h"
#include "highscore.h"

void mainmenu(){
    /*
    Deskripsi:
    Prosedur ini menampilkan menu utama permainan, termasuk sambutan permainan dan pilihan yang tersedia untuk pemain.
    i.s: layar kosong
    f.s: Menampilkan menu utama permainan di konsol, termasuk pilihan untuk memulai permainan, melihat skor tertinggi, 
    cara bermain, dan keluar dari permainan.
    */
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
        printf("                |________|   |_________|       |___|     |_______|                                        \n\n\n\n");
        

    printf("     ==============================================================================\n");
    printf("                                   GAME 2048 MENU                                  \n");
    printf("     ==============================================================================\n");
    printf("                                   1 > Start Game                                  \n");
    printf("                                   2 > High Score                                  \n");
    printf("                                   3 > How to Play                                 \n");
    printf("                                   4 > Exit                                        \n\n");
    printf("     ==============================================================================\n");
    printf("                                Masukkan pilihan anda                                \n");
}


void howtoplay(){
    /* Deskripsi: 
       Prosedur ini menampilkan instruksi permainan 2048 kepada pemain, menjelaskan cara bermain, aturan, dan kondisi kemenangan serta kekalahan. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan instruksi permainan di konsol, termasuk penjelasan tentang papan, ubin, cara menggeser ubin, munculnya ubin baru, kondisi kemenangan, dan kekalahan.
    */
        // Header
    printf("================================================================\n");
    printf("                        HOW TO PLAY 2048                        \n");
    printf("================================================================\n");

    // Penjelasan tentang papan
    printf("|  [ Papan ]                                                   |\n");
    printf("|  Game 2048 dimainkan di papan berukuran 4x4.                 |\n");
    printf("|                                                              |\n");
    // Penjelasan tentang ubin
    printf("|  [ Ubin ]                                                    |\n");
    printf("|  Setiap ubin memiliki nilai kelipatan dua,                   |\n");
    printf("|  seperti 2, 4, 8, 16, 32, hingga 2048.                       |\n");
    printf("|                                                              |\n");
    // Penjelasan tentang cara menggeser ubin
    printf("|  [ Geser Ubin ]                                              |\n");
    printf("|  Anda dapat menggeser ubin ke atas, bawah, kiri, atau kanan. |\n");
    printf("|  Ubin dengan angka yang sama akan bergabung menjadi satu     |\n");
    printf("|  ubin dengan nilai yang dijumlahkan.                         |\n");
    printf("|                                                              |\n");
    // Penjelasan tentang munculnya ubin baru
    printf("| [ Munculnya Ubin Baru ]                                      |\n");
    printf("| Setelah setiap gerakan, ubin baru dengan nilai 2 atau 4      |\n");
    printf("| akan muncul secara acak di papan.                            |\n");
    printf("|                                                              |\n");
    // Penjelasan tentang kemenangan
    printf("| [ Kemenangan ]                                               |\n");
    printf("| Anda menang jika berhasil membuat ubin bernilai 2048.        |\n");
    printf("|                                                              |\n");
    // Penjelasan tentang kekalahan
    printf("| [ Kekalahan ]                                                |\n");
    printf("| Permainan berakhir jika papan penuh dan tidak ada            |\n");
    printf("| gerakan yang mungkin dilakukan.                              |\n");
    
    // Footer
    printf("================================================================\n");
    printf("               Tekan tombol apapun untuk kembali                \n");
    printf("================================================================\n");
}

void printforinputuser(){
    /* Deskripsi: 
       Prosedur ini menampilkan pesan kepada pengguna untuk memasukkan nama pengguna sebelum memulai permainan. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan pesan yang meminta pengguna untuk memasukkan nama pengguna dan memberikan instruksi tentang cara menyelesaikan input.
    */

    printf("================================================\n");
    printf("                MASUKKAN NAMA ANDA              \n");
    printf("================================================\n\n");
    printf("Instruksi:\n");
    printf("  1. Masukkan nama Anda (maksimal 10 karakter).\n");
    printf("  2. Pastikan nama yang dimasukkan sudah sesuai.\n");
    printf("  3. Tekan ENTER untuk menyelesaikan input.\n\n");
    printf("------------------------------------------------\n");
    printf("Silakan masukkan nama Anda: ");
}


void printforinputgeser(){
    /* Deskripsi: 
       Prosedur ini menampilkan instruksi kepada pengguna tentang cara menggeser blok dalam permainan, serta memberikan opsi untuk keluar dari permainan. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan pesan yang menjelaskan kontrol untuk menggeser blok dan cara keluar dari permainan.
    */

    printf("===================================\n");
    printf("PETUNJUK KONTROL:\n");
    printf("W/A/S/D : Geser Blok\n");
    printf("Q       : Keluar Permainan\n");
    printf("===================================\n");
}

void displayPapan(Game2048 permainan, DataHighScore dhs) {
    /* Deskripsi :
       Prosedur ini berfungsi untuk menampilkan informasi ketika 
       permainan sedang berlangsung mencakup nama pengguna 
       saat ini, skor saat ini, skor tertinggi yang pernah di capai 
       beserta nama pengguna yang mencapainya.
       I.S : Data permainan (Game2048) yang berisi informasi nama 
       pengguna dan skor saat ini sudah tersedia, data skor tertinggi 
       (DataHighScore) yeng berisi informasi skor tertinggi dan 
       nama pengguna pemilik skor tersebut sudah tersedia tetapi 
       belum di tampilkan di layar.
       F.S : Informasi nama pengguna, skor saat ini, nama dan skor 
       tertinggi, dan petunjuk penggunaan berhasil ditampilkan ke layar.
    */
    printf("+--------------------------------------+\n");
    printf("|              GAME 2048               |\n");
    printf("+--------------------------------------+\n");
    printf("+--------------------------------------+\n");
    printf("| Nama Pengguna : %-20s |\n", permainan.username);
    printf("| Score         : %-20d |\n", permainan.score);
    printf("| High Score    : %-6d by %-10s |\n", dhs.highscore, dhs.username);
    printf("+--------------------------------------+\n\n");
}

void displayGameOver(Game2048 permainan) { 
    /* Deskripsi: 
       Prosedur ini menampilkan pesan "Game Over" beserta skor akhir dari permainan.
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan pesan "Game Over" dan skor akhir.
    */

    printf("=======================================\n");
    printf("                GAME OVER              \n");
    printf("=======================================\n");
    printf("Game Over! Skor akhir: %d\n", permainan.score);
    printf("=======================================\n");
    printf("          Tekan 1 untuk keluar          \n");
}


void displaywin(Game2048 permainan){
    /* Deskripsi: 
       Prosedur ini menampilkan pesan kemenangan kepada pemain, termasuk nama pengguna dan skor akhir. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan pesan kemenangan, nama pengguna, dan skor akhir. 
    */
    printf("===================================\n");
    printf("        SELAMAT ANDA MENANG!       \n");
    printf("===================================\n");
    printf("Selamat %s!\n", permainan.username);
    printf("Skor akhir: %d\n", permainan.score);
    printf("===================================\n");
    printf("        Tekan 1 untuk keluar       \n");
}