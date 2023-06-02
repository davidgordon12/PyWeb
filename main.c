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

void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void draw_board(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void place_random_apple(int board[BOARD_WIDTH][BOARD_HEIGHT]);
void move_snake(int board[BOARD_WIDTH][BOARD_HEIGHT], snake_t* snake);
void run();

typedef struct snake_t {
    int x_pos;
    int y_pos;
    char direction;
} snake_t;

int main() {
    printf("Press enter key to start.\n");
    char buffer[2];
    fgets(buffer, 2, stdin);
    run();
}

void run() {
    snake_t snake;

    snake.x_pos = 10;
    snake.y_pos = 6;
    snake.direction = 'w';


    int board[BOARD_WIDTH][BOARD_HEIGHT];

    init_board(board);

    place_random_apple(board);

    draw_board(board); */

    char c;
    struct termios new_kbd_mode;
    struct termios g_old_kbd_mode;

    /* put keyboard (stdin) in raw, unbuffered mode */
    tcgetattr (0, &g_old_kbd_mode);
    memcpy (&new_kbd_mode, &g_old_kbd_mode, sizeof (struct termios));

    new_kbd_mode.c_lflag &= ~(ICANON | ECHO);
    new_kbd_mode.c_cc[VTIME] = 0;
    new_kbd_mode.c_cc[VMIN] = 1;
    tcsetattr (0, TCSANOW, &new_kbd_mode);

    int alive = 1;

    while(alive) {
        sleep(1);
        read (0, &c, 1);
        switch(c) {
            case UP:
                snake.direction = UP;
            case DOWN:
                snake.direction = DOWN;
            case LEFT:
                snake.direction = LEFT;
            case RIGHT:
                snake.direction = RIGHT;
        }
        move_snake(snake);
    }
}

void init_board(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
    for(int x = 0; x < BOARD_WIDTH; x++) {
        for(int y = 0; y < BOARD_HEIGHT; y++) {
            if( (x == 0) || (y == 0) ) {
                board[x][y] = BORDER;    
            }
            else if( (x == 20) || (y == 12)) {
                board[x][y] = BORDER;
            }
            else {
                board[x][y] = WHITESPACE;
            }
        }
    }

    board[CENTER_X][CENTER_Y] = SNAKE;
}

void draw_board(int board[BOARD_WIDTH][BOARD_HEIGHT], snake_t* snake) {
    for(int y = 0; y < BOARD_HEIGHT; y++) {
        for(int x = 0; x < BOARD_WIDTH; x++) {
            printf(" ");
            if(board[x][y] == BORDER) {
                printf("#");
            }
            else if(board[x][y] == WHITESPACE) {
                printf("*");
            }
            else if(board[x][y] == SNAKE) {
                printf("^");
            }
            else if(board[x][y] == APPLE) {
                printf("@");
            }
            if(x == 20) {
                printf("\n");
            }
        }
    }
}

void place_random_apple(int board[BOARD_WIDTH][BOARD_HEIGHT]) {
    srand(time(NULL));

    int rand_x = rand() % 19 + 1;
    int rand_y = rand() % 11 + 1;

    while( (rand_x == 10) && (rand_y == 6) ) {
        rand_x = rand() % 19 + 1;
        rand_y = rand() % 11 + 1;
    }

    board[rand_x][rand_y] = APPLE;
}

void move_snake(int board[BOARD_WIDTH][BOARD_HEIGHT], snake_t* snake) {
    if(snake->direction == UP && snake->y_pos != 20) {
        snake->y_pos+1;
    }

    board[snake->x_pos][snake->y_pos] = 3;
}