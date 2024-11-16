#include "menu.h" // Menggunakan header yang benar atau deklarasi
#include <conio.h> // Untuk _getch()
#include <stdlib.h> //untuk system("cls")
#include <stdio.h>

void showMenu() { // Ubah nama fungsi menjadi showMenu
    printf("1. start game\n");
    printf("2. load game\n");
    printf("3. how to play\n");
    printf("4. exit\n");


    char a =_getch(); //input user memilih apa 
    system("cls"); //clear terminal


    switch (a) {
        case '1': //start game
                system("cls"); // Bersihkan layar
            break;
        case '2': //load game
            system("cls"); // Bersihkan layar
            break;
        case '3': //how to play
            system("cls");
            printf("Papan   : Game 2048 dimainkan di papan berukuran 4x4.\n");
            printf("Ubin    : Setiap ubin memiliki nilai yang merupakan kelipatan dua, seperti 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, dan 2048.\n");
            printf("Geser Ubin: Anda dapat menggeser ubin ke atas, bawah, kiri, atau kanan. Ubin yang memiliki angka yang sama akan bergabung menjadi satu ubin dengan nilai yang dijumlahkan.\n");
            printf("Munculnya Ubin Baru: Setiap kali Anda melakukan gerakan, ubin baru dengan nilai 2 atau 4 akan muncul di papan.\n");
            printf("Kemenangan  : Anda menang jika Anda berhasil menggabungkan ubin menjadi 2048.\n");
            printf("Kekalahan   : Permainan berakhir jika tidak ada lagi gerakan yang mungkin dilakukan dan papan sudah penuh.\n\n\n");
            printf("tekan apapun untuk kembali");
            getch();
            system("cls"); // Bersihkan layar
            printGreeting();
            showMenu();
            break;
        case '4': //exit
            system("cls"); // Bersihkan layar
            break;
        default: //jika tidak valid
            printf("Pilihan tidak valid\n"); // Menangani pilihan yang tidak valid
            break;
    }
}



