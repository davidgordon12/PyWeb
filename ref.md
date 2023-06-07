# drawing out how I will program the game

## board

- first we need to decide on our board size, ill choose 13x21, it'll be a 2d array

- 12x20 is the playing field, 1 extra row/column for perimeter, hashtag as border, @ is apple, ^ is snake, * is whitespace

- snake len can be depicted as int array, add 1 if we eat an apple, die if we hit wall or self

- will need to handle framerate with delta time or whatever, redraw board every x seconds with new position

- need RAND method between 0 and BOARD_WIDTH/HEIGHT - 1 to place apple each time we get the old one, redraw entire board.


## movement

- we will need to keep track of our snakes current position, perhaps create a struct snake with the required values

- on key input we change the direction of our snake

- iterate through linked list snake_t, save the position of each node, set the position of node->prev to node

## eating apples

- when we eat an apple, we can create a new node(snake_t), and set the prev value(node->prev) to be equal to the last snake we had, which will keep adding snake heads to the front of the list