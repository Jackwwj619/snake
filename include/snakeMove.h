#ifndef SNAKEMOVE_H
#define SNAKEMOVE_H


#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


typedef struct snake {
    int x;
    int y;
    struct snake *next;
} Snake;

typedef enum direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Dir;

typedef struct food {
    int x;
    int y;
    // int score = 5;
} Food;
//
// typedef struct food_mouse {
//     int x;
//     int y;
//     int score = 2;
// } Mouse;
//
// typedef struct obstacle {
//     int x;
//     int y;
// };

typedef struct border {
    int startx;
    int starty;
    int width;
    int height;
} Border;

void initWin(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir);
void refreshSnake(WINDOW *win, Snake *snake, Snake *lastTail);
void updateSnake(WINDOW *win, Snake *snake, Dir dir);
void refreshFood(WINDOW *win, Food *food, Border border, Dir dir);
void updateFood(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir);
int checkCrashWall(WINDOW *win, Snake *snake, Food *fod, Border border, Dir dir);
int checkEatFood(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir);
int dealControl(Snake *snake,int *speed,Dir *dir);
void init_ncurses();
WINDOW *createWin(Border *border);
void destroyWin(WINDOW *win);

#endif // SNAKEMOVE_H
