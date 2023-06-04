#ifndef GAME
#define GAME

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <string.h>
#include <unistd.h>

#define BOARD_WIDTH 21
#define BOARD_HEIGHT 13

#define CENTER_X 10
#define CENTER_Y 6

#define BORDER 1
#define WHITESPACE 2
#define SNAKE 3
#define APPLE 4

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct snake_t {
    int x_pos;
    int y_pos;
    int size;
    char direction;
} snake_t;

void draw_board(int board[BOARD_WIDTH][BOARD_HEIGHT], snake_t* snake);
void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void place_random_apple(int board[BOARD_WIDTH][BOARD_HEIGHT]);
int move_snake(int board[BOARD_WIDTH][BOARD_HEIGHT], snake_t* snake);
void run();

#endif