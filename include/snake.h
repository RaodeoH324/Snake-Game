#ifndef SNAKE_H                         //IF NOT DEFINED SNAKE_H. Has SNAKE_H already been defined?
#define SNAKE_H

#define MAX_LENGTH 100                   //snake can have maximum 100 body parts.
#define WIDTH  40
#define HEIGHT 20

#define UP     'w'
#define DOWN   's'
#define LEFT   'a'
#define RIGHT  'd'

typedef struct {
    int x[MAX_LENGTH];                  // storing position x
    int y[MAX_LENGTH];                  // storing position y
    int length;                         //stores current length of the snake
    char dir;                           // w=UP s=DOWN a=LEFT d=RIGHT
} Snake;

void init_snake(Snake *s);
void move_snake(Snake *s);

#endif