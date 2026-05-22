#include "snake.h"

void init_snake(Snake *s) {                         //initialize snake
    s->length = 3;
    s->dir = 'd';  // start moving right

    // Start in the middle of the board
    for (int i = 0; i < s->length; i++) {
        s->x[i] = 10 - i;   // head at x=10, tail behind
        s->y[i] = HEIGHT / 2;
    }
}

void move_snake(Snake *s) {
    // Shift body — each part takes the position of the one ahead
    for (int i = s->length - 1; i > 0; i--) {
        s->x[i] = s->x[i - 1];
        s->y[i] = s->y[i - 1];
    }

    // Move head based on direction
    if (s->dir == 'w') s->y[0]--;   // UP
    if (s->dir == 's') s->y[0]++;   // DOWN
    if (s->dir == 'a') s->x[0]--;   // LEFT
    if (s->dir == 'd') s->x[0]++;   // RIGHT
}