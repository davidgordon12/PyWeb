# drawing out how I will program the game

- first we need to decide on our board size, ill choose 12x20, it'll be a 2d array

- 12x20 is the playing field, 1 extra row/column for perimeter, hashtag as border, @ is apple, ^ is snake, * is whitespace

- snake len can be depicted as int array, add 1 if we eat an apple, die if we hit wall or self

- will need to handle framerate with delta time or whatever