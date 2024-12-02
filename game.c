#include "game.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

Game2048 game;

#define HIGHSCORE_FILE "highscore.txt"

void menampilkanPapan() {
    for (int i = 0; i < 4; i++) {
        // Menampilkan garis horizontal atas
        if (i == 0) {
            printf("+------+------+------+------+\n");
        }

        for (int j = 0; j < 4; j++) {
            printf("| %4d ", game.papan[i][j]); // Menampilkan isi papan dengan batas
        }
        printf("|\n"); // Menutup baris dengan batas vertikal

        // Menampilkan garis horizontal bawah
        printf("+------+------+------+------+\n");
    }
}

void addrandom (){
     srand((unsigned)time(NULL));// untuk memastikan hasil angka acak dari rand() bervariasi setiap eksekusi program dengan menggunakan waktu sebagai seed

    int count = 0; //variabel untuk penomoran 
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (game.papan[i][j] == 0) {
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

int geserMerge(){
    int p =_getch();
    while (1){
    if (p == 'w' || p == 72) { //atas
        return 1;
    }
    else if (p == 's' || p == 80) { // bawah
       return 2;
    }
    else if (p == 'a' || p == 75) { //kiri
        return 3;
    }
    else if (p == 'd' || p == 77) { //kanan
        return 4;
    }
    else if (p=='q'){
        return -1;
    }
    else{
        p=_getch();
    }
}
}

void geserAtas()
{
        
    for (int j = 0; j < 4; j++) { // Loop untuk setiap kolom
        for (int i = 1; i < 4; i++) { // Mulai dari baris kedua
            if (game.papan[i][j] != 0) { // Jika ada angka
                int k = i;
                while (k > 0 && game.papan[k - 1][j] == 0) { // Selama ada sel kosong di atas
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
        
    for (int j = 0; j < 4; j++) { // Loop untuk setiap kolom
        for (int i = 2; i >= 0; i--) { // Mulai dari baris ketiga ke atas
            if (game.papan[i][j] != 0) { // Jika ada angka
                int k = i;
                while (k < 3 && game.papan[k + 1][j] == 0) { // Selama ada sel kosong di bawah
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
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 1; j < 4; j++) { // Mulai dari kolom kedua
            if (game.papan[i][j] != 0) { // Jika ada angka
                int k = j;
                while (k > 0 && game.papan[i][k - 1] == 0) { // Selama ada sel kosong di kiri
                    game.papan[i][k - 1] = game.papan[i][k]; // Geser angka ke kiri                        papan[i][k] = 0; // Setel sel saat ini menjadi kosong
                    game.papan[i][k] = 0;
                    k--; // Pindah ke kolom kiri
                }
            }
        }
    }
}


void geserKanan()
{
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 2; j >= 0; j--) { // Mulai dari kolom ketiga ke kiri
            if (game.papan[i][j] != 0) { // Jika ada angka
                int k = j;
                while (k < 3 && game.papan[i][k + 1] == 0) { // Selama ada sel kosong di kanan
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
    for (int j = 0; j < 4; j++){ // Loop untuk setiap kolom
        for (int i = 0; i < 3; i++) { // Loop untuk baris dari atas ke bawah
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i + 1][j]) { // Jika angka sama
                game.papan[i][j] *= 2; // Gabungkan angka
                game.papan[i + 1][j] = 0; // Setel sel di atas menjadi kosong
            }
        }
    }
}

void mergeBawah()
{
    for (int j = 0; j < 4; j++) { // Loop untuk setiap kolom
        for (int i = 3; i > 0; i--) { // Loop untuk baris dari bawah ke atas
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i - 1][j]) { // Jika angka sama
                game.papan[i][j] *= 2; // Gabungkan angka
                game.papan[i - 1][j] = 0; // Setel sel di atas menjadi kosong
            }
        }
    }
}

void mergeKiri()
{
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 0; j < 3; j++) { // Loop untuk kolom dari kiri ke kanan
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i][j + 1]) { // Jika angka sama
                game.papan[i][j] *= 2; // Gabungkan angka
                game.papan[i][j + 1] = 0; // Setel sel di kanan menjadi kosong
            }
        }
    }
}

void mergeKanan()
{
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 3; j > 0; j--) { // Loop untuk kolom dari kanan ke kiri
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i][j - 1]) { // Jika angka sama
                game.papan[i][j] *= 2; // Gabungkan angka
                game.papan[i][j - 1] = 0; // Setel sel di kiri menjadi kosong
            }
        }
    }
}

void skorAtas() {
    for (int j = 0; j < 4; j++) { // Loop untuk setiap kolom
        for (int i = 0; i < 3; i++) { // Loop untuk baris dari atas ke bawah
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i + 1][j]) { // Jika angka sama
                game.score += game.papan[i][j] * 2; // Tambahkan skor
            }
        }
    }
}


void skorBawah() {
    for (int j = 0; j < 4; j++) { // Loop untuk setiap kolom
        for (int i = 3; i > 0; i--) { // Loop untuk baris dari bawah ke atas
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i - 1][j]) { // Jika angka sama
                game.score += game.papan[i][j] * 2; // Tambahkan skor
            }
        }
    }
}


void skorKiri() {
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 0; j < 3; j++) { // Loop untuk kolom dari kiri ke kanan
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i][j + 1]) { // Jika angka sama
                game.score += game.papan[i][j] * 2; // Tambahkan skor
            }
        }
    }
}


void skorKanan() {
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 3; j > 0; j--) { // Loop untuk kolom dari kanan ke kiri
            if (game.papan[i][j] != 0 && game.papan[i][j] == game.papan[i][j - 1]) { // Jika angka sama
                game.score += game.papan[i][j] * 2; // Tambahkan skor
            }
        }
    }
}


bool gameOver()
{
    // Cek apakah ada sel kosong
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            if (game.papan[i][j] == 0) {
                return false; // Masih ada sel kosong, permainan belum berakhir
            }
        }
    }

    for (int i=0; i<= 3; i++){
        for (int j=0;j<3; j++){
            if (game.papan[i][j] == game.papan[i][j+1]){
                return false;// jika balok sama dengan balok kanannya berarti masih lanjut
            }
        }
    }

    for (int i=1; i<=3; i++){
        for (int j=0;j<=3; j++){
            if (game.papan[i][j] == game.papan[i-1][j]){
                return false;// jika balok sama dengan balok bawah berarti masih lanjut
            }
        }
    }

    return true; //jika tidak ada yg terjalankan maka akan true yaitu gameover
}

bool win()
{
    for (int i=0; i<=3; i++){
        for (int j=0; j<=3; j++){
            if (game.papan[i][j]==2048){
            return true;//jika ada salah satu balok yang mencapai 2048 maka akan menang dan gameover
            }
        }
    }
    return false;//jika tidak ada balok yg 2048 false yaitu lanjut ke game lagi
}

bool ifinitiation()
{
    for (int i=0; i<=3; i++){
        for (int j=0; j<=3; j++){
            if (game.papan[i][j]!=0){
            return false;//jika belum ada angka sama sekali maka true yaitu menambahkan 2 blok
            }
        }
    }
    return true;//jika sudah ada yg berisi angka maka false yaitu melanjutkan game
}

void inputusername(Game2048 *permainan){
    fgets(permainan->username, sizeof(permainan->username), stdin);
    
    // Menghapus newline
    permainan->username[strcspn(permainan->username, "\n")] = '\0'; // Menggunakan strcspn untuk menemukan dan mengganti newline
    // strcspn mencari posisi karakter newline (\n) dalam string game->username. Jika ditemukan, kita menggantinya dengan karakter null (\0), yang menandakan akhir dari string. Ini menghilangkan newline yang ditambahkan oleh fgets ketika pengguna menekan Enter.
    //Menggunakan fgets untuk membaca input dari pengguna. Input disimpan dalam game->username. sizeof(game->username) memastikan bahwa kita tidak membaca lebih banyak karakter daripada yang bisa ditampung oleh array.
}

// Fungsi untuk menyimpan high score ke file
void saveHighScore(Game2048 *permainan, DataHighScore *Highscore) {

    FILE *file = fopen(HIGHSCORE_FILE, "w");

    strcpy(Highscore->username, permainan->username);
    Highscore->highscore = permainan->score;

    if (file != NULL) {
        fwrite(&*Highscore, sizeof(DataHighScore), 1, file);
    } else {
        printf("Error: Unable to open high score file for writing.\n");
    }

    fclose(file);
}

// Fungsi untuk memuat high score dari file
void loadHighScore(DataHighScore *HighScore) {
    FILE *file = fopen(HIGHSCORE_FILE, "rb");

    if (file != NULL) {
        fread(&*HighScore, sizeof(DataHighScore),1,file);
    } else {
        printf("Error: Unable to open high score file for reading. Starting with default values.\n");
        strcpy(HighScore->username, "Player"); // Default username
        HighScore->highscore = 0; // Default high score
        fwrite(&*HighScore, sizeof(DataHighScore), 1, file);
    }

    fclose(file);
}