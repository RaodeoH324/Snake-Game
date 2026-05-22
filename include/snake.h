#define MAX_LENGTH 100                   //snake can have maximum 100 body parts.

typedef struct {
    int x[MAX_LENGTH];                  // storing position x
    int y[MAX_LENGTH];                  // storing position y
    int length;                         //stores current length of the snake
    char dir;                           // w=UP s=DOWN a=LEFT d=RIGHT
} Snake;