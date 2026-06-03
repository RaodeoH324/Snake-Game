#include <ncurses.h>        //mvprintw(), getch(), refresh()
#include <stdlib.h>         //srand(), rand()
#include <time.h>
#include "game.h"           //game_over(), place_food()
#include "render.h"         //draw_snake(), draw_food()
#include "snake.h"          //Snake struct, move_snake()



int main() {
    initscr();           // start ncurses. without this ncurses wont work.
    noecho();            // don't print keypresses on the terminal. When we play we use wasd and we dont want those letters in the terminal.
    curs_set(0);         // hide cursor
    keypad(stdscr, TRUE);   // enables special keys like arrwo
    start_color();

    // Colors
    init_pair(1, COLOR_GREEN, COLOR_BLACK);  // snake
    init_pair(2, COLOR_RED,   COLOR_BLACK);  // food

    // Init game
    srand(time(NULL));
    Snake snake;
    init_snake(&snake);

    int fx, fy, score = 0;
    place_food(&fx, &fy);           //Random food position

    // Game loop
    while (1) {
        // Speed increases with score
        int speed = 200;
        // int speed = 300 - (score * 2);
        // if (speed < 100) speed = 100;         //Prevents speed becoming too fast, going less than 50ms
        timeout(speed);

        clear();

    draw_border();

    handle_input(&snake);
        move_snake(&snake);

        // Ate food?
        if (snake.x[0] == fx && snake.y[0] == fy) {
            snake.length++;
            score += 10;
            place_food(&fx, &fy);
        }

        // Wall collision?
        if (snake.x[0] <= 0 || snake.x[0] >= WIDTH - 1 ||
            snake.y[0] <= 0 || snake.y[0] >= HEIGHT - 1) {
            break;
        }

        // Self collision?
        for (int i = 1; i < snake.length; i++) {
            if (snake.x[0] == snake.x[i] &&
                snake.y[0] == snake.y[i]) {
                goto game_end;          //Jump directly to game_end
            }
        }

        draw_food(fx, fy);      //display food
        draw_snake(&snake);     //display snake
        mvprintw(HEIGHT + 1, 0, "Score: %d", score);
        refresh();
    }

    game_end:
    game_over(score);
    

    refresh();              //ncueses stores drawing internally. refresh will tell it to show it on screen.
    getch();             // wait for keyboard input. Program slows down here. Without this it would start, draw and close instantly.

    endwin();            // cleanup ncurses. Restores terminal back to normal.
    return 0;
}