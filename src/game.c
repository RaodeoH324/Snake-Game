// simplified, core loop
#include <ncurses.h>
#include <stdlib.h>                         //Used for rand() and exit()
#include <time.h>
#include"snake.h"
#include "game.h"

void place_food(int *fx, int *fy) {
    *fx = (rand() % (WIDTH - 2)) + 1;       //rand() generates random numbers, and rand % WIDTH-2, since WIDTH is 40, means it will generate numbers from 0 to 38, +1 makes it 1 to 38, which is the valid range for food placement within the borders.
    *fy = (rand() % (HEIGHT - 2)) + 1;
}

void handle_input(Snake *s) {
    int ch = getch();                                       //inputs, reads ONE key press.
    if (ch == 'w'    && s->dir != 's') s->dir = 'w';     //This means if ch==upward key, if user has input upward key and current direction of snake should now be downwards. if this is true then the snake can move up.
    if (ch == 's'  && s->dir != 'w') s->dir = 's';     //Same logic for all.
    if (ch == 'a'  && s->dir != 'd') s->dir = 'a';
    if (ch == 'd' && s->dir != 'a') s->dir = 'd';
    if (ch == 'q'){
        endwin();
        exit(0);
    }

}

void game_over(int score) {
    clear();
    mvprintw(HEIGHT/2 - 1, WIDTH/2 - 5, "GAME OVER!");
    mvprintw(HEIGHT/2,     WIDTH/2 - 7, "Final Score: %d", score);
    mvprintw(HEIGHT/2 + 1, WIDTH/2 - 10, "Press any key to exit...");
    refresh();              //Show everything i drew
    nodelay(stdscr, FALSE);
    getch();
}