#ifndef GAME_H
#define GAME_H

#include "snake.h"

void place_food(int*fx, int *fy);
void handle_input(Snake *s);
void game_over(int score);

#endif