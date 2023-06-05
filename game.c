#include "game.h"

void run() {
    /* put keyboard (stdin) in raw, unbuffered mode */
    char c;

    struct termios new_kbd_mode;
    struct termios g_old_kbd_mode;

    tcgetattr (0, &g_old_kbd_mode);
    memcpy (&new_kbd_mode, &g_old_kbd_mode, sizeof (struct termios));

    new_kbd_mode.c_lflag &= ~(ICANON | ECHO);
    new_kbd_mode.c_cc[VTIME] = 0;
    new_kbd_mode.c_cc[VMIN] = 1;
    tcsetattr (0, TCSANOW, &new_kbd_mode);

    snake_t snake;

    snake.x_pos = 10;
    snake.y_pos = 6;
    snake.size = 1;
    snake.direction = 'w';

    int board[BOARD_WIDTH][BOARD_HEIGHT];

    init_board(board);

    place_random_apple(board);

    draw_board(board, &snake);

    int alive = 1;

    while(alive) {
        read (0, &c, 1);
        switch(c) {
            case UP:
                snake.direction = UP;
                alive = move_snake(board, &snake);
                break;

            case DOWN:
                snake.direction = DOWN;
                alive = move_snake(board, &snake);
                break;

            case LEFT:
                snake.direction = LEFT;
                alive = move_snake(board, &snake);
                break;

            case RIGHT:
                snake.direction = RIGHT;
                alive = move_snake(board, &snake);
                break;
            
            default: 
                break;
        }

        if(alive) {
            draw_board(board, &snake);
        }
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

int move_snake(int board[BOARD_WIDTH][BOARD_HEIGHT], snake_t* snake) {
    int prev_x = snake->x_pos;
    int prev_y = snake->y_pos;
    board[snake->x_pos][snake->y_pos] = WHITESPACE;

    if(snake->direction == UP) {
        snake->y_pos--;
    }

    if(snake->direction == DOWN) {
        snake->y_pos++;
    }
    
    if(snake->direction == LEFT) {
        snake->x_pos--;
    }

    if(snake->direction == RIGHT) {
        snake->x_pos++;
    }

    if(board[snake->x_pos][snake->y_pos] == APPLE) {
        snake->size++;
        place_random_apple(board);
        board[prev_x][prev_y] = SNAKE;
    }

    if(board[snake->x_pos][snake->y_pos] == SNAKE) {
        printf("\n Game Over! Final score: %d \n", snake->size);
        return 0;
    }

    if(board[snake->x_pos][snake->y_pos] == BORDER) {
        printf("\n Game Over! Final score: %d \n", snake->size-1);
        return 0;
    }

    board[snake->x_pos][snake->y_pos] = 3;

    return 1;
}