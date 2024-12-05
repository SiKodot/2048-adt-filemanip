#include "game.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

Game2048 game;

#define HIGHSCORE_FILE "highscore.txt"

void menampilkanPapan() 
{
    for (int i = 0; i < 4; i++) 
    {
        // Menampilkan garis horizontal atas
        if (i == 0) 
        {
            printf("+------+------+------+------+\n");
        }

        for (int j = 0; j < 4; j++)
        {
            printf("| %4d ", game.papan[i][j]); // Menampilkan isi papan dengan batas
        }
        printf("|\n"); // Menutup baris dengan batas vertikal

        // Menampilkan garis horizontal bawah
        printf("+------+------+------+------+\n");
    }
}

void addrandom ()
{
    srand((unsigned)time(NULL));// untuk memastikan hasil angka acak dari rand() bervariasi setiap eksekusi program dengan menggunakan waktu sebagai seed

    int count = 0; //variabel untuk penomoran 
    
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if (game.papan[i][j] == 0) 
            {
                game.kosong[count][0] = i; //menyimpan baris yang kosong
                game.kosong[count][1] = j; //menyimpan kolom yang kosong
                count ++;
            } 
        }
    }
    if (count == 0) 
    {
        return; //keluar dari prosedur jika tidak ada array yang kosong
    }

    //pilih posisi array kosong secara acak
    int pilihan = rand() % count;
    int baris = game.kosong[pilihan][0];
    int kolom = game.kosong[pilihan][1];

    //tambahkan array kosong yang terpilih dengan angka 2 (90%) atau 4 (10%)
    game.papan[baris][kolom] = (rand() % 100 < 90 ? 2 : 4);

}

int inputgeser() {
    /* Deskripsi: 
       Mengambil input dari pengguna untuk menentukan arah geser ubin.
       Input dapat berupa 'w', 'a', 's', 'd' untuk arah atas, kiri, bawah, dan kanan, serta 'q' untuk kembali ke main menu. 
       Nantinya nilai yang didapat dari fungsi ini akan dimasukkan kedalam adt game.arah
       I.S: Tidak ada input yang diterima. game.arah kosong atau belum berubah
       F.S: Game.arah mendapatkan nilai 1 untuk atas atau 2 untuk bawah atau 3 untuk kiri
       atau 4 untuk kanan atau -1 untuk kembali ke main menu
    */

    int p = _getch(); // Mengambil input dari pengguna
    while (1) { // Loop untuk menunggu input yang valid
        if (p == 'w' || p == 72) // Jika input adalah 'w' atau arrow key atas
        { 
            return 1; // Mengembalikan 1 untuk geser atas
        }
        else if (p == 's' || p == 80) // Jika input adalah 's' atau arrow key bawah
        { 
            return 2; // Mengembalikan 2 untuk geser bawah
        }
        else if (p == 'a' || p == 75) // Jika input adalah 'a' atau arrow key kiri
        { 
            return 3; // Mengembalikan 3 untuk geser kiri
        }
        else if (p == 'd' || p == 77) // Jika input adalah 'd' atau arrow key kanan
        { 
            return 4; // Mengembalikan 4 untuk geser kanan
        }
        else if (p == 'q') // Jika input adalah 'q'
        {
            return -1; // Mengembalikan -1 untuk keluar ke main menu
        }
        else // Jika input tidak valid
        {
            p = _getch(); // Ambil input lagi
        }
    }
}

void geserAtas()
{
    /* Deskripsi: 
            Prosedur ini berfungsi untuk menggeser seluruh angka yang ada pada papan permainan ke arah atas. 
            Pergeseran dilakukan dengan memeriksa setiap kolom dan baris pada papan, kemudian apabila terdapat ubin kosong
            di atas baris angka tersebut, nilai dari ubin akan dipindahkan ke atas, dan ubin saat ini akan bernilai kosong. 
            Proses ini terus dilakukan hingga tidak ada lagi ubin kosong di antara angka-angka yang tersisa. 
       I.S: Seluruh angka yang ada di dalam papan permainan masih belum tergeser ke barisan ubin yang paling atas.
       F.S: Seluruh angka yang ada di dalam papan permainan sudah tergeser ke barisan ubin yang paling paling atas. 
    */
    for (int j = 0; j < 4; j++) // Loop untuk setiap kolom
    { 
        for (int i = 1; i < 4; i++) // Mulai dari baris kedua
        { 
            if (game.papan[i][j] != 0) // Jika ada angka
            { 
                int k = i;
                while (k > 0 && game.papan[k - 1][j] == 0) // Selama ada sel kosong di atas
                { 
                    game.papan[k - 1][j] = game.papan[k][j]; // Geser angka ke atas
                    game.papan[k][j] = 0; // Setel sel saat ini menjadi kosong
                    k--; // Pindah ke baris atas
                }
            }
        }
    }
}

void geserBawah()
{
    /* Deskripsi: 
            Prosedur ini berfungsi untuk menggeser seluruh angka yang ada pada papan permainan ke arah bawah. 
            Pergeseran dilakukan dengan memeriksa setiap kolom dan baris pada papan, kemudian apabila terdapat ubin kosong
            di bawah baris angka tersebut, nilai dari ubin akan dipindahkan ke bawah, dan ubin saat ini akan bernilai kosong. 
            Proses ini terus dilakukan hingga tidak ada lagi ubin kosong di antara angka-angka yang tersisa.
       I.S: Seluruh angka yang ada di dalam papan permainan masih belum tergeser ke barisan ubin yang paling bawah.
       F.S: Seluruh angka yang ada di dalam papan permainan sudah tergeser ke barisan ubin yang paling paling bawah. 
    */
    for (int j = 0; j < 4; j++) // Loop untuk setiap kolom
    { 
        for (int i = 2; i >= 0; i--) // Mulai dari baris ketiga ke atas
        { 
            if (game.papan[i][j] != 0) // Jika ada angka
            { 
                int k = i;
                while (k < 3 && game.papan[k + 1][j] == 0) // Selama ada sel kosong di bawah
                { 
                    game.papan[k + 1][j] = game.papan[k][j]; // Geser angka ke bawah
                    game.papan[k][j] = 0; // Setel sel saat ini menjadi kosong
                    k++; // Pindah ke baris bawah
                }
            }
        }
    }
}

void geserKiri()// Kiri
{
    /* Deskripsi: 
            Prosedur ini berfungsi untuk menggeser seluruh angka yang ada pada papan permainan ke arah kiri. 
            Pergeseran dilakukan dengan memeriksa setiap kolom dan baris pada papan, kemudian apabila terdapat ubin kosong 
            di samping kiri baris angka tersebut, nilai dari ubin akan dipindahkan ke kiri, dan ubin saat ini akan bernilai kosong. 
            Proses ini terus dilakukan hingga tidak ada lagi ubin kosong di antara angka-angka yang tersisa.
       I.S: Seluruh angka yang ada di dalam papan permainan masih belum tergeser ke kolom ubin yang paling kiri.
       F.S: Seluruh angka yang ada di dalam papan permainan sudah tergeser ke kolom ubin yang paling paling kiri. 
    */
    for (int i = 0; i < 4; i++) // Loop untuk setiap baris
    { 
        for (int j = 1; j < 4; j++) // Mulai dari kolom kedua
        { 
            if (game.papan[i][j] != 0) // Jika ada angka
            { 
                int k = j;
                while (k > 0 && game.papan[i][k - 1] == 0) // Selama ada sel kosong di kiri
                { 
                    game.papan[i][k - 1] = game.papan[i][k]; // Geser angka ke kiri
                    game.papan[i][k] = 0;// Setel sel saat ini menjadi kosong
                    k--; // Pindah ke kolom kiri
                }
            }
        }
    }
}


void geserKanan()
{
    /* Deskripsi: 
            Prosedur ini berfungsi untuk menggeser seluruh angka yang ada pada papan permainan ke arah kanan. 
            Pergeseran dilakukan dengan memeriksa setiap kolom dan baris pada papan, kemudian apabila terdapat ubin kosong 
            di samping kanan baris angka tersebut, nilai dari ubin akan dipindahkan ke kanan, dan ubin saat ini akan bernilai kosong. 
            Proses ini terus dilakukan hingga tidak ada lagi ubin kosong di antara angka-angka yang tersisa.
       I.S: Seluruh angka yang ada di dalam papan permainan masih belum tergeser ke kolom ubin yang paling kanan.
       F.S: Seluruh angka yang ada di dalam papan permainan sudah tergeser ke kolom ubin yang paling paling kanan. 
    */
    for (int i = 0; i < 4; i++) // Loop untuk setiap baris
    { 
        for (int j = 2; j >= 0; j--) // Mulai dari kolom ketiga ke kiri
        { 
            if (game.papan[i][j] != 0) // Jika ada angka
            { 
                int k = j;
                while (k < 3 && game.papan[i][k + 1] == 0) // Selama ada sel kosong di kanan
                { 
                    game.papan[i][k + 1] = game.papan[i][k]; // Geser angka ke kanan
                    game.papan[i][k] = 0; // Setel sel saat ini menjadi kosong
                    k++; // Pindah ke kolom kanan
                }
            }
        }
    }
}

void mergeAtas()
{
    
    for (int j = 0; j < 4; j++) // Loop untuk setiap kolom
    { 
        for (int i = 0; i < 3; i++) // Loop untuk baris dari atas ke bawah
        { 
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i + 1][j]) // Jika angka sama
            { 
                game.papan[i][j] *= 2; // Gabungkan angka
                game.score += game.papan[i][j];
                game.papan[i + 1][j] = 0; // Setel sel di bawah menjadi kosong
            }
        }
    }
}

void mergeBawah()
{
    for (int j = 0; j < 4; j++) // Loop untuk setiap kolom
    { 
        for (int i = 3; i > 0; i--) // Loop untuk baris dari bawah ke atas
        { 
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i - 1][j]) // Jika angka sama
            { 
                game.papan[i][j] *= 2; // Gabungkan angka
                game.score += game.papan[i][j];
                game.papan[i - 1][j] = 0; // Setel sel di atas menjadi kosong
            }
        }
    }
}

void mergeKiri()
{
    for (int i = 0; i < 4; i++) // Loop untuk setiap baris
    { 
        for (int j = 0; j < 3; j++) // Loop untuk kolom dari kiri ke kanan
        { 
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i][j + 1]) // Jika angka sama
            { 
                game.papan[i][j] *= 2; // Gabungkan angka
                game.score += game.papan[i][j];
                game.papan[i][j + 1] = 0; // Setel sel di kanan menjadi kosong
            }
        }
    }
}

void mergeKanan()
{
    for (int i = 0; i < 4; i++) // Loop untuk setiap baris
    { 
        for (int j = 3; j > 0; j--) // Loop untuk kolom dari kanan ke kiri
        { 
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i][j - 1]) // Jika angka sama
            { 
                game.papan[i][j] *= 2; // Gabungkan angka
                game.score += game.papan[i][j];
                game.papan[i][j - 1] = 0; // Setel sel di kiri menjadi kosong
            }
        }
    }
}

bool gameOver() {
    /* Deskripsi: 
       Fungsi ini memeriksa apakah permainan telah berakhir. Permainan dianggap berakhir jika tidak ada sel kosong 
       dan tidak ada ubin yang dapat digabungkan dengan ubin di sebelah kanan atau di bawahnya. 
       Jika ada sel kosong atau ubin yang dapat digabungkan, permainan masih berlanjut.
       i.s : 
       game.papan adalah papan permainan yang merupakan array 2D berukuran 4x4 yang berisi nilai-nilai dari ubin permainan.
       f.s : 
       Mengembalikan true jika permainan telah berakhir (tidak ada langkah yang mungkin dilakukan).
       Mengembalikan false jika permainan masih dapat dilanjutkan (masih ada sel kosong atau ubin yang dapat digabungkan).
    */
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris pada papan
        for (int j = 0; j < 4; j++) { // Loop untuk setiap kolom pada baris
            // Jika ada sel kosong
            if (game.papan[i][j] == 0) {
                return false; // Masih ada sel kosong, permainan belum berakhir
            }
            // Jika ada ubin yang bisa digabungkan ke kanan
            if (j < 3 && game.papan[i][j] == game.papan[i][j + 1]) {
                return false; // Masih bisa digabungkan ke kanan
            }
            // Jika ada ubin yang bisa digabungkan ke bawah
            if (i < 3 && game.papan[i][j] == game.papan[i + 1][j]) {
                return false; // Masih bisa digabungkan ke bawah
            }
        }
    }

    return true; // Jika tidak ada yang bisa dilakukan, maka lose/gameover
}



bool win() {
    /* Deskripsi: 
       Fungsi ini memeriksa apakah ada ubin pada papan permainan yang telah mencapai nilai 2048. 
       Jika ada, fungsi ini mengembalikan nilai true, menandakan bahwa pemain telah menang. 
       Jika tidak, fungsi ini mengembalikan nilai false, menandakan permainan masih berlanjut.
       i.s : 
       game.papan adalah papan permainan yang merupakan array 2D berukuran 4x4 yang berisi nilai-nilai dari ubin permainan.
       f.s : 
       Mengembalikan true jika ada ubin dengan nilai 2048, menandakan pemain telah menang.
       Mengembalikan false jika tidak ada ubin dengan nilai 2048, menandakan permainan masih berlanjut.
    */
    for (int i = 0; i <= 3; i++) { // Loop untuk setiap baris pada papan
        for (int j = 0; j <= 3; j++) { // Loop untuk setiap kolom pada baris
            if (game.papan[i][j] == 2048) { // Cek apakah ubin saat ini adalah 2048
                return true; // Jika ada salah satu ubin yang mencapai 2048, kembalikan true
            }
        }
    }
    return false; // Jika tidak ada ubin yang mencapai 2048, kembalikan false
}

bool ifinitiation() {
    /* Deskripsi: 
       Fungsi ini memeriksa apakah papan permainan masih dalam keadaan kosong (belum ada angka sama sekali). 
       Jika semua sel pada papan kosong, fungsi ini mengembalikan true, 
       menandakan bahwa permainan dapat dimulai dengan menambahkan dua blok. 
       Jika ada setidaknya satu sel yang berisi angka, fungsi ini mengembalikan false, menandakan bahwa permainan sudah dimulai.
       i.s : 
       game.papan adalah papan permainan yang merupakan array 2D berukuran 4x4 yang berisi nilai-nilai dari ubin permainan, 
       yang dapat berupa 0 (kosong) atau angka positif.
       f.s : 
       Mengembalikan true jika semua sel pada papan kosong, menandakan bahwa permainan dapat dimulai.
       Mengembalikan false jika ada setidaknya satu sel yang berisi angka, menandakan bahwa permainan sudah dimulai.
    */
    for (int i = 0; i <= 3; i++) { // Loop untuk setiap baris pada papan
        for (int j = 0; j <= 3; j++) { // Loop untuk setiap kolom pada baris
            if (game.papan[i][j] != 0) { // Cek apakah sel saat ini tidak kosong
                return false; // Jika ada sel yang berisi angka, kembalikan false
            }
        }
    }
    return true; // Jika semua sel kosong, kembalikan true
}

void inputusername(Game2048 *permainan) {
    /* Deskripsi: 
       Prosedur ini digunakan untuk membaca input nama pengguna dari standar input (stdin) dan menyimpannya dalam atribut 
       `username` dari data `Game2048`. Fungsi ini juga menghapus karakter newline yang mungkin ditambahkan 
       saat pengguna menekan tombol Enter.
       i.s : 
       data Game2048.username tak terdefinisi
       f.s : 
       Setelah fungsi ini dijalankan, `permainan->username` berisi nama pengguna yang dimasukkan oleh pengguna, 
       tanpa karakter newline di akhir.
    */
    fgets(permainan->username, sizeof(permainan->username), stdin); 
    // Menggunakan fgets untuk membaca input dari pengguna. 
    // Input disimpan dalam permainan->username. sizeof(permainan->username) 
    // memastikan bahwa kita tidak membaca lebih banyak karakter 
    // daripada yang bisa ditampung oleh array.

    // Menghapus newline
    permainan->username[strcspn(permainan->username, "\n")] = '\0'; 
    // Menggunakan strcspn untuk menemukan dan mengganti newline 
    // dengan karakter null (\0), yang menandakan akhir dari string. 
    // Ini menghilangkan newline yang ditambahkan oleh fgets 
    // ketika pengguna menekan Enter.
}

// Fungsi untuk menyimpan high score ke file
void saveHighScore(Game2048 *permainan, DataHighScore *Highscore) 
{
    FILE *file = fopen(HIGHSCORE_FILE, "w");

    strcpy(Highscore->username, permainan->username);
    Highscore->highscore = permainan->score;

    if (file != NULL) 
    {
        fwrite(&*Highscore, sizeof(DataHighScore), 1, file);
    } else {
        printf("Error: Unable to open high score file for writing.\n");
    }

    fclose(file);
}

// Fungsi untuk memuat high score dari file
void loadHighScore(DataHighScore *HighScore) { 
/*  Deskripsi: 
    Prosedur ini memuat skor tertinggi dari file HIGHSCORE_FILE dan menyimpannya dalam struktur DataHighScore. 
    Jika file tidak dapat dibuka, maka skor tertinggi akan diatur ke nilai default yaitu 0.
    i.s : 
    HIGHSCORE_FILE adalah nama file yang berisi skor tertinggi. DataHighScore adalah data yang berisi informasi tentang skor tertinggi.
    f.s : 
    Struktur DataHighScore telah diisi dengan skor tertinggi dari file dan akan dibaca. Jika file tidak dapat dibuka, maka skor tertinggi akan diatur ke nilai default. */

FILE *file = fopen(HIGHSCORE_FILE, "rb"); // Membuka file HIGHSCORE_FILE
// Jika file tidak dapat dibuka, maka file akan bernilai NULL

if (file != NULL) { // Jika file ada
    fread(&*HighScore, sizeof(DataHighScore),1,file); // Membaca skor tertinggi dari file dan menyimpannya dalam data DataHighScore
} else { // Jika file tidak dapat dibuka
    printf("Error: Unable to open high score file for reading. Starting with default values.\n"); // Mencetak pesan error
    strcpy(HighScore->username, "Player"); // Mengatur nama pengguna ke default yaitu "Player"
    HighScore->highscore = 0; // Mengatur skor tertinggi ke nilai default 0
    // fwrite(&*HighScore, sizeof(DataHighScore), 1, file); // Baris ini tidak dapat dijalankan karena file tidak dapat dibuka
    // Sebaiknya, buat file baru dan tulis skor tertinggi ke dalamnya
    fwrite(&*HighScore, sizeof(DataHighScore), 1, file); // Menulis skor tertinggi ke dalam file
    }
    fclose(file); // Menutup file
}