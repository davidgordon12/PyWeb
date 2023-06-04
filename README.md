# Snake
Classic Snake game written in C without the use of any graphics libraries 

# How to play
 - W, A, S, D
 - Collect Apples (@)
 - Don't run into the Walls (#) or yourself (^)

## Prerequisites
- make (optional)
- gcc

## Build Instructions with make
- Clone repo
- Run ```make run``` in a terminal

## Build Instructions without make
- Clone repo
- In a terminal, run the following in order
```mkdir -p bin
   gcc main.c -o bin/main.o -c
   gcc game.c -o bin/game.o -c
   gcc -o snake bin/main.o bin/game.o
   ./snake
