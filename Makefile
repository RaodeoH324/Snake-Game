CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lncurses

snake: src/main.c src/game.c src/snake.c src/render.c
	$(CC) $(CFLAGS) src/*.c -Iinclude $(LIBS) -o snake

clean:
	rm -f snake