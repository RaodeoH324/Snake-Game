//Graphics of the game
#include <ncurses.h>
#include "render.h"

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

void draw_snake(Snake *s) {
    attron(COLOR_PAIR(1));
    for (int i = 0; i < s->length; i++) {
        mvprintw(s->y[i], s->x[i], i == 0 ? "O" : "o");     //Head is made O.
    }
    attroff(COLOR_PAIR(1));
}

void draw_food(int fx, int fy) {
    attron(COLOR_PAIR(2));
    mvprintw(fy, fx, "*");
    attroff(COLOR_PAIR(2));
}