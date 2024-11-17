#include "game.h"
#include <stdio.h>
#include <string.h>

int papan[3][3];
void resetPapan()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            papan[i][j] = ' ';
        }
    }
}

void menampilkanPapan()
{
    printf("========2048  Game=======\n");
    printf("-------------------------\n");
    printf("|  %d  |  %d  |  %d  |  %d  |\n", papan[0][0], papan[0][1], papan[0][2], papan[0][3]);
    printf("-------------------------\n");
    printf("|  %d  |  %d  |  %d  |  %d  |\n", papan[1][0], papan[1][1], papan[1][2], papan[1][3]);
    printf("-------------------------\n");
    printf("|  %d  |  %d  |  %d  |  %d  |\n", papan[2][0], papan[2][1], papan[2][2], papan[2][3]);
    printf("-------------------------\n");
    printf("|  %d  |  %d  |  %d  |  %d  |\n", papan[3][0], papan[3][1], papan[3][2], papan[3][3]);
    printf("-------------------------\n");

}