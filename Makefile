all:
	g++ -g -Wall -std=c++17 -I src/include -L src/lib -o snake snake.c -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf