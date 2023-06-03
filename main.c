#include "game.h"

int main() {
    printf("Press enter key to start.\n");
    char buffer[2];
    fgets(buffer, 2, stdin);
    run();
}