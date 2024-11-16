#include "menu.h" // Menggunakan header yang benar

void showMenu() { // Ubah nama fungsi menjadi showMenu
    printf("1. start game\n");
    printf("2. load game\n");
    printf("3. how to play\n");
    printf("4. exit\n");

    int a;
    scanf("%d", &a);

    switch (a) {
        case 1:
            printf("lanjut\n");
            break;
        case 2:
            printf("slebew\n");
            break;
        case 3:
            printf("Papan Permainan: Game 2048 dimainkan di papan berukuran 4x4.\n");
            printf("Ubin (Tiles): Setiap ubin memiliki nilai yang merupakan kekuatan dua, seperti 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, dan 2048.\n");
            printf("Menggeser Ubin: Anda dapat menggeser ubin ke atas, bawah, kiri, atau kanan. Ubin yang memiliki angka yang sama akan bergabung menjadi satu ubin dengan nilai yang dijumlahkan.\n");
            printf("Munculnya Ubin Baru: Setiap kali Anda melakukan gerakan, ubin baru dengan nilai 2 atau 4 akan muncul di papan.\n");
            printf("Kemenangan: Anda menang jika Anda berhasil menggabungkan ubin menjadi 2048.\n");
            printf("Kekalahan: Permainan berakhir jika tidak ada lagi gerakan yang mungkin dilakukan dan papan sudah penuh.\n");
            getchar();
            getchar();
            showMenu();
            break;
        case 4:
            break;
        default:
            printf("Pilihan tidak valid\n"); // Menangani pilihan yang tidak valid
            break;
    }
}