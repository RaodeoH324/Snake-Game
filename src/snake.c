#include "snake.h"

void init_snake(Snake *s) {                         //initialize snake
    s->length = 1;
    s->dir = 'd';  // start moving right

    // Start in the middle of the board
    for (int i = 0; i < s->length; i++) {                   //initially, our snake is at 8 9 10 in x direction and 10,10,10 in y direction. i.e. moving towards right.
        s->x[i] = 10 - i;   // head at x=10, tail behind
        s->y[i] = HEIGHT / 2;
    }
}

void move_snake(Snake *s) {
    // Shift body — each part takes the position of the one ahead. Head remains unchanged.
    for (int i = s->length - 1; i > 0; i--) {
        s->x[i] = s->x[i - 1];                      //x coordinate changes from (8,9,10) --> (9,9,10) --> (10,10,9). 
        s->y[i] = s->y[i - 1];                      // since our y coordinates were (10,10,10) it doesnt change. as s->y[2] = s->y[2 - 1]; --> s->y[2] = s->y[ 1]; --> s->y[2]=10 which was orignally 10. so no change.
    }

    // Move head based on direction
    if (s->dir == 'w') s->y[0]--;   // UP
    if (s->dir == 's') s->y[0]++;   // DOWN
    if (s->dir == 'a') s->x[0]--;   // LEFT
    if (s->dir == 'd') s->x[0]++;   // RIGHT
}