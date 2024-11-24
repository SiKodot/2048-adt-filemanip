#include "game.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>

int papan[4][4];
int score;

void gameMain(){
    int A;
    score=0;
    resetPapan(); // Reset papan sekali di awal
    while (1) { // Loop tak terbatas untuk terus menerima input
        system("cls");
        addrandom();
        printf("Score: %d\n", score);
        menampilkanPapan(); // Tampilkan papan saat ini
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
}

void menampilkanPapan() {
    for (int i = 0; i < 4; i++) {
        // Menampilkan garis horizontal atas
        if (i == 0) {
            printf("+------+------+------+------+\n");
        }

        for (int j = 0; j < 4; j++) {
            printf("| %4d ", papan[i][j]); // Menampilkan isi papan dengan batas
        }
        printf("|\n"); // Menutup baris dengan batas vertikal

        // Menampilkan garis horizontal bawah
        printf("+------+------+------+------+\n");
    }
}

void geser(int *arah){
    while (1) {

        char p =_getch();

        if (p == 'w' || p == 72) { //atas
            *arah = 1;
        }
        else if (p == 's' || p == 80) { // bawah
            *arah = 2;
        }
        else if (p == 'a' || p == 75) { //kiri
            *arah = 3;
            break;
        }
        else if (p == 'd' || p == 77) { //kanan
            *arah = 4;
            break;
        }
        else{
            return;
        }
        
    }
}

void addrandom (){
    //inisialisasi generator pengacak angka
    srand((unsigned)time(NULL));

    int kosong[16][2]; //array untuk menyimpan posisi papan yang kosong
    int count = 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (papan[i][j] == 0) {
                kosong[count][0] = i; //menyimpan baris yang kosong
                kosong[count][1] = j; //menyimpan kolom yang kosong
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
    int baris = kosong[pilihan][0];
    int kolom = kosong[pilihan][1];

    //tambahkan array kosong yang terpilih dengan angka 2 (90%) atau 4 (10%)
    papan[baris][kolom] = (rand() % 100 < 90 ? 2 : 4);

}

void geserangka(int arah) {

    if (arah == 1){//atas

    }

    if (arah == 2) { //bawah

    }

    if (arah == 4) {//kanan
        
    }
    
    if (arah == 3) { // Kiri
        for (int i = 0; i < 4; i++) { //loop baris
            for (int j = 1; j < 4; j++) { // loop kolom
                if (papan[i][j] != 0) { // Jika ada angka
                    int k = j; //maka posisi kolom atau j akan disimpan di var k
                    while (k > 0 && papan[i][k - 1] == 0) { //Selama k lebih besar dari 0 dan sel di kiri kosong
                        papan[i][k - 1] = papan[i][k]; //Geser angka ke kiri
                        papan[i][k] = 0; // Setel sel saat ini menjadi kosong
                        k--; //pindah ke kolom kiri
                    }
                }
            }
        }
    merge(arah); // Panggil fungsi merge setelah menggeser angka
    }
}

void merge(int arah){
if (arah=3){
    for (int i = 0; i < 4; i++) { // Loop untuk setiap baris
        for (int j = 0; j < 3; j++) { // Loop untuk kolom dari 0 hingga 2 (kolom 3 tidak perlu diperiksa)
            if (papan[i][j] != 0 && papan[i][j] == papan[i][j + 1]) { // Jika ada angka dan angka di sebelah kanan sama
                score += papan[i][j] * 2; // Tambahkan nilai yang digabungkan ke skor
                papan[i][j] *= 2; // Gabungkan angka dengan mengalikan dengan 2
                papan[i][j + 1] = 0; // Setel sel di sebelah kanan menjadi kosong
            }
        }
    }
    }
if (arah=4){
}
}