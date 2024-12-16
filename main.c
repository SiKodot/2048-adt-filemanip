#include "display.h"
#include "game.h"//ADT
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //untuk addrandom
#include <conio.h> // untuk getch

int main() {
    
    DataHighScore dhs;

    while (1){
        system("cls");
        mainmenu(); // menampilkan main menu
        
        int input;

        int a =_getch(); //input user memilih apa 
        switch (a) {
            case '1': //start game
                system("cls"); // Bersihkan layar

                if (ifinitiation()){// Jika permainan baru dimulai dan isi papan 0 semua, maka menambahkan dua angka acak di awal permainan
                    printforinputuser(); //menampilkan cara memasukkan username ke data game
                    inputusername(&game); //modul untuk memasukkan input user ke dalam game
                    // Tambahkan 2 angka acal di awal permainan
                    addrandom(); 
                    addrandom(); 
                }
            
                while (1) { 
                
                    loadHighScore(&dhs); //mengakses file highscore 
                    displayPapan(game, dhs); //berisi nama, score, nama dari highscore, dan highscore
                    printforinputgeser(); //menampilkan panduan menggeser ubin
                    if (game.score>dhs.highscore){ //jika game2048.score lebih besar dari data highscore
                        saveHighScore(&game, &dhs); // maka score pemain akan disimpan kedalam datahighscore
                    }
                    menampilkanPapan(); // Menampilkan papan dan grid

                    if (win()){ //jika saat modul win dijalankan dan true/win (salah satu balok mencapai 2048) maka akan dijalankan
                        displaywin(game); //menampilkan you win dan score terakhir
                        int c = _getch();
                        while (c != '1') { // Jika pengguna menekan '1', akan keluar dari permainan
                            c = _getch();
                            if (c == '1') return 0; // keluar permainan
                        }
                        // Jika tidak, tetap di dalam loop dan tunggu input lebih lanjut
                    }
                    // Periksa jika game over
                    if (gameOver()) { //jika modul menjadi true (tidak ada yg bisa digerakkan lagi dan tidak ada balok yg 0) maka akan dijalankan
                        displayGameOver(game); //menampilkan game over dan score terakhir
                        int c = _getch();
                        while (c != '1') { // Jika pengguna menekan '1', akan keluar dari permainan
                            c = _getch();
                            if (c == '1') return 0; // keluar permainan
                        }
                        // Jika tidak, tetap di dalam loop dan tunggu input lebih lanjut
                    }

                    // Panggil fungsi geserMerge untuk menangani input untuk menggeser
                    game.arah=inputgeser(); //menyimpan hasil function inputgeser kedalam data game2048.arah
                    
                    switch (game.arah) {
                        case 1: // Geser atas
                            geserAtas();
                            mergeAtas();
                            geserAtas();
                            break;
                        case 2: // Geser bawah
                            geserBawah();
                            mergeBawah();
                            geserBawah();
                            break;
                        case 3: // Geser kiri
                            geserKiri();
                            mergeKiri();
                            geserKiri();
                            break;
                        case 4: // Geser kanan
                            geserKanan();
                            mergeKanan();
                            geserKanan();
                            break;
                        case -1:
                            input = -1;
                            break;

                        default:
                            break; // Tidak ada aksi jika arah tidak valid
                    }

                    if (input == -1) { //kembali ke menu utama
                        input = 0;
                        break;
                    }
                    
                    if (game.score>dhs.highscore){//jika game2048.score lebih besar dari data highscore
                        saveHighScore(&game, &dhs); // maka score pemain akan disimpan kedalam datahighscore
                    }
                    // Tambahkan angka acak baru setelah pergerakan
                    addrandom();
                    system("cls");
                }
                break;


            case '2': //Highscore
                system("cls"); // Bersihkan layar
                loadHighScore(&dhs); //mengakses file highscore 
                displayPapan(game, dhs); //berisi nama, score, nama dari highscore, dan highscore
                getch(); //pengguna harus menginput apapun untuk kembali ke main menu
                break;


            case '3': //how to play
                system("cls");
                howtoplay(); // menampilkan cara bermain 
                getch();// tekan apa saja untuk kembali ke main menu
                system("cls");
                break;


            case '4': //exit/keluar dari permainan
                system("cls"); // Bersihkan layar
                exit(0);
                break;
        }
    }
}