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
        printf("                |________|   |_________|       |___|     |_______|                                        \n");
        
        printf("Main menu:\n");
        printf("1. start game\n");
        printf("2. highscore\n");
        printf("3. how to play\n");
        printf("4. exit\n\n");
        printf("Masukkan pilihan anda\n");
}

void howtoplay(){
    /* Deskripsi: 
       Prosedur ini menampilkan instruksi permainan 2048 kepada pemain, menjelaskan cara bermain, aturan, dan kondisi kemenangan serta kekalahan. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan instruksi permainan di konsol, termasuk penjelasan tentang papan, ubin, cara menggeser ubin, munculnya ubin baru, kondisi kemenangan, dan kekalahan.
    */
        printf("Papan   : Game 2048 dimainkan di papan berukuran 4x4.\n");
        printf("Ubin    : Setiap ubin memiliki nilai yang merupakan kelipatan dua, seperti 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, dan 2048.\n");
        printf("Geser Ubin: Anda dapat menggeser ubin ke atas, bawah, kiri, atau kanan. Ubin yang memiliki angka yang sama akan bergabung menjadi satu ubin dengan nilai yang dijumlahkan.\n");
        printf("Munculnya Ubin Baru: Setiap kali Anda melakukan gerakan, ubin baru dengan nilai 2 atau 4 akan muncul di papan.\n");
        printf("Kemenangan  : Anda menang jika Anda berhasil menggabungkan ubin menjadi 2048.\n");
        printf("Kekalahan   : Permainan berakhir jika tidak ada lagi gerakan yang mungkin dilakukan dan papan sudah penuh.\n\n\n");
        printf("Tekan apapun untuk kembali\n");
}

void printforinputuser(){
    /* Deskripsi: 
       Prosedur ini menampilkan pesan kepada pengguna untuk memasukkan nama pengguna sebelum memulai permainan. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan pesan yang meminta pengguna untuk memasukkan nama pengguna dan memberikan instruksi tentang cara menyelesaikan input.
    */
        printf("Masukkan nama pengguna\n");
        printf("Jika sudah selesai tekan enter dan pastikan nama sesuai\n");
}

void printforinputgeser(){
    /* Deskripsi: 
       Prosedur ini menampilkan instruksi kepada pengguna tentang cara menggeser blok dalam permainan, serta memberikan opsi untuk keluar dari permainan. 
       i.s : 
       Layar tidak menampilkan apa apa
       f.s : 
       Menampilkan pesan yang menjelaskan kontrol untuk 
       menggeser blok dan cara keluar dari permainan.
    */

    printf("Gunakan W/A/S/D untuk menggeser blok. Tekan Q untuk keluar.\n");
}

void displayPapan(Game2048 permainan, DataHighScore dhs) {
    /* Deskripsi :
       Prosedur ini berfungsi untuk menampilkan informasi ketika 
       permainan sedang berlangsung mencakup nama pengguna 
       saat ini, skor saat ini, skor tertinggi yang pernah di capai 
       beserta nama pengguna yang mencapainya, serta instruksi 
       kontrol permainan.
       I.S : Data permainan (Game2048) yang berisi informasi nama 
       pengguna dan skor saat ini sudah tersedia, data skor tertinggi 
       (DataHighScore) yeng berisi informasi skor tertinggi dan 
       nama pengguna pemilik skor tersebut sudah tersedia tetapi 
       belum di tampilkan di layar.
       F.S : Informasi nama pengguna, skor saat ini, nama dan skor 
       tertinggi, dan petunjuk penggunaan berhasil ditampilkan ke layar.
    */
    printf("Nama Pengguna: %s\n", permainan.username);
    printf("Score: %d\n", permainan.score);
    printf("High Score: %d (%s)\n", dhs.highscore, dhs.username);
}

void displayGameOver(Game2048 permainan, DataHighScore *dhs) { 
    /* Deskripsi: 
       Prosedur ini menampilkan pesan "Game Over" beserta skor akhir dari permainan. Jika skor akhir lebih tinggi dari skor tertinggi 
       yang tersimpan, maka skor tertinggi akan diperbarui.
       i.s : 
       permainan adalah data Game2048 yang berisi informasi permainan, termasuk skor akhir. 
       dhs adalah data DataHighScore yang menyimpan informasi tentang skor tertinggi.
       f.s : 
       Menampilkan pesan "Game Over" dan skor akhir. Jika skor akhir 
       lebih tinggi dari skor tertinggi, maka skor tertinggi akan 
       diperbarui dan ditampilkan.
    */

    printf("Game Over! Skor akhir: %d\n", permainan.score); // Menampilkan pesan "Game Over" dan skor akhir permainan
    if (permainan.score > dhs->highscore) { // Membandingkan skor akhir dengan skor tertinggi yang tersimpan
        dhs->highscore = permainan.score;   // Mengupdate skor tertinggi dengan skor akhir jika lebih tinggi
        printf("Selamat! High Score baru: %d\n", dhs->highscore); // Menampilkan pesan bahwa ada skor tertinggi baru
    }
}

void displaywin(Game2048 permainan, DataHighScore *dhs){
    /* Deskripsi: 
       Prosedur ini menampilkan pesan kemenangan kepada pemain, termasuk nama pengguna dan skor akhir. Jika skor akhir 
       lebih tinggi dari skor tertinggi yang tersimpan, maka skor tertinggi akan diperbarui.
       i.s : 
       permainan adalah data Game2048 yang berisi informasi permainan, termasuk skor akhir. 
       dhs adalah data DataHighScore yang menyimpan informasi tentang skor tertinggi.
       f.s : 
       Menampilkan pesan kemenangan, nama pengguna, dan skor akhir. 
       Jika skor akhir lebih tinggi dari skor tertinggi, maka skor tertinggi akan diperbarui dan ditampilkan.
    */

    printf("You Win! %s\n", permainan.username); // Menampilkan pesan kemenangan dan nama pengguna
    printf("Skor akhir: %d\n", permainan.score); // Menampilkan skor akhir permainan
    if (permainan.score > dhs->highscore) { // Membandingkan skor akhir dengan skor tertinggi yang tersimpan
        dhs->highscore = permainan.score;   // Mengupdate skor tertinggi dengan skor akhir jika lebih tinggi
        printf("Selamat! High Score baru: %d\n", dhs->highscore); // Menampilkan pesan bahwa ada skor tertinggi baru
    }
}