#include <stdio.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 12

int main() {
    int board[BOARD_WIDTH][BOARD_HEIGHT];

    for(int x = 0; x < BOARD_WIDTH; x++) {
        for(int y = 0; y < BOARD_HEIGHT; y++) {
            board[x][y] = 1;
        }
    }

    printf("%d \n", board[5][5]);
    return -1;
}