build:
	gcc -Wall -Werror main.c -o main


run: build
	-./main

clean:
	rm -rf main

full: clean build run