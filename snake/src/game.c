//
// Created by 李政杭 on 2024/7/20.
//
#include <curses.h>
#include "../include/nwindow.h"
WINDOW* score_win;
WINDOW* tutorial_win;

void setup_WIN() {
    wresize(stdscr,LINES-15,COLS);
    score_win = newwin(15,61,LINES - 15,0);
    tutorial_win = newwin(15,180,LINES - 15,61);
    box(stdscr,0,0);
    box(score_win,0,0);
    box(tutorial_win,0,0);
    wrefresh(score_win);
    wrefresh(tutorial_win);
}

void start_game() {
    setup_WIN();
    return;
}
