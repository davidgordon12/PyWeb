#include <stdio.h>

#define BOARD_WIDTH 21
#define BOARD_HEIGHT 13

#define CENTER_X 10
#define CENTER_Y 6

#define BORDER = 1
#define WHITESPACE = 2
#define SNAKE = 3

void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void draw_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void place_apple();

int main() {
    int board[BOARD_WIDTH][BOARD_HEIGHT];

    init_board(board);

    draw_board(board);

    return -1;
}

void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
    for(int x = 0; x < BOARD_WIDTH; x++) {
        for(int y = 0; y < BOARD_HEIGHT; y++) {
            if( (x == 0) || (y == 0) ) {
                board[x][y] BORDER;    
            }
            else if( (x == 20) || (y == 12)) {
                board[x][y] BORDER;
            }
            else {
                board[x][y] WHITESPACE;
            }
        }
    }

    board[CENTER_X][CENTER_Y] SNAKE;
}

void draw_board(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
    for(int y = 0; y < BOARD_HEIGHT; y++) {
        for(int x = 0; x < BOARD_WIDTH; x++) {
            printf(" ");
            if(board[x][y] == 1) {
                printf("#");
            }
            else if(board[x][y] == 2) {
                printf("*");
            }
            else if(board[x][y] == 3) {
                printf("^");
            }
            if(x == 20) {
                printf("\n");
            }
        }
    }
}

void place_apple() {
}