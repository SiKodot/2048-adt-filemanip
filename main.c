#include "display.h"
#include "game.h"//ADT
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //untuk addrandom
#include <conio.h> // untuk getch


int main() {
    
    DataHighScore dhs;

    while (1){

        mainmenu(); // menampilkan main menu
        
        int input;

        int a =_getch(); //input user memilih apa 
        switch (a) {
            case '1': //start game
                system("cls"); // Bersihkan layar

                if (ifinitiation()){// Jika permainan baru dimulai dan isi papan 0 semua, maka menambahkan dua angka acak di awal permainan
                printforinputuser();
                inputusername(&game);
                addrandom();
                addrandom();
                }
            
                while (true) { //definisi true jika menang atau kalah akan berubah jadi false dan akan break atau selesai
                loadHighScore(&dhs);
                displayPapan(game, dhs);
                printforinputgeser();
                if (game.score>dhs.highscore){
                    saveHighScore(&game, &dhs);
                }
                // Tampilkan papan
                menampilkanPapan();

                if (win()){ //jika saat modul win dijalankan dan true (salah satu balok mencapai 2048) maka akan dijalankan
                    displaywin(game, &dhs); //menampilkan you win dan score terakhir
                    exit(0);
                    break; //loop selesai dan permainan berakhir
                }
                
                // Periksa jika game over
                if (gameOver()) { //jika modul menjadi true (tidak ada yg bisa digerakkan lagi dan tidak ada balok yg 0) maka akan dijalankan
                    displayGameOver(game, &dhs); //menampilkan game over dan score terakhir
                    exit(0);
                    break; // Keluar dari loop jika permainan sudah berakhir
                }

                // Panggil fungsi geserMerge untuk menangani input
                game.arah=inputgeser();
                
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

                if (input == -1) {
                    input = 0;
                    break;
                }
                
                if (game.score>dhs.highscore){
                    saveHighScore(&game, &dhs);
                }
                // Tambahkan angka acak baru setelah pergerakan
                addrandom();
                }
                break;


            case '2': //Highscore
                system("cls"); // Bersihkan layar
                loadHighScore(&dhs);
                displayPapan(game, dhs);
                break;


            case '3': //how to play
                system("cls");
                howtoplay();
                getch();// tekan apa saja untuk kembali ke main
                system("cls");
                break;


            case '4': //exit
                system("cls"); // Bersihkan layar
                exit(0);
                break;
            }
        }
    }