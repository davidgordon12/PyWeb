build:
	gcc main.c -o bin/main.o -c
	gcc game.c -o bin/game.o -c
	gcc -o snake bin/main.o bin/game.o

run: build
	-./snake