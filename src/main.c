// main.c
#include <ncurses.h>

#define WIDTH  100
#define HEIGHT 25

void draw_border() {
    for (int x = 0; x < WIDTH; x++) {
        mvprintw(0, x, "#");           // top row it will print # as the border
        mvprintw(HEIGHT, x, "#");      // bottom row it will print # as the border on 20th row.
    }
    for (int y = 0; y < HEIGHT; y++) {
        mvprintw(y, 0, "#");           // left border
        mvprintw(y, WIDTH - 1, "#");   // right. WIDTH-1 becuase we want to print till 39 which is the last col.
    }
}

int main() {
    initscr();           // start ncurses. without this ncurses wont work.
    noecho();            // don't print keypresses on the terminal. When we play we use wasd and we dont want those letters in the terminal.
    curs_set(0);         // hide cursor
    keypad(stdscr, TRUE);   // enables special keys like arrwo

    draw_border();
    refresh();              //ncueses stores drawing internally. refresh will tell it to show it on screen.
    getch();             // wait for keyboard input. Program slows down here. Without this it would start, draw and close instantly.

    endwin();            // cleanup ncurses. Restores terminal back to normal.
    return 0;
}