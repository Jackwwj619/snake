//
// Created by 李政杭 on 2024/7/20.
//
#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "SnakeMove.h"
#include "../include/nwindow.h"

WINDOW* score_win;
WINDOW* tutorial_win;

void setup_WIN() {
    wresize(stdscr,LINES-15,COLS);
    score_win = newwin(15,61,LINES - 15,0);
    tutorial_win = newwin(15,180,LINES - 15,61);
    box(score_win,0,0);
    box(tutorial_win,0,0);
    box(stdscr,0,0);
    wrefresh(score_win);
    wrefresh(tutorial_win);
    wrefresh(stdscr);
    mvprintw(0,COLS / 2,"Snake 1.0");
    mvprintw((LINES - 15)/2,COLS / 2,"Press any Key to continue...");
    getch();
}

void start_game() {
    setup_WIN();
    srand((unsigned)time(NULL));

    int speed = 800000;
    Border border;
    Food food;
    Dir dir = RIGHT;
    Snake *snake = (Snake *) malloc(sizeof(Snake));

    update_Border(&border);
    clear();
    refresh();
    initWin(stdscr,snake, &food, border, dir);
    timeout(0);

    while (1) {

        // 非阻塞处理键盘控制
        int res=dealControl(snake,&speed,&dir);

        if(res==0){         //同向按键无效
            continue;
        } else if (res==1){ //长度超过1后反向按键，自我碰撞
            break;
        }

        //撞墙
        if (checkCrashWall(stdscr, snake, &food, border, dir)) {
            break;
        }

        //未吃到食物，向当前方向前进一格，更新蛇身信息
        if (!checkEatFood(stdscr, snake, &food, border, dir)) {
            updateSnake(stdscr, snake, dir);
        }

        //程序睡眠(微秒)，实现速度控制
        usleep(speed);
    }

    //销毁窗口
    destroyWin();

    //退出curses模式
    endwin();
    return;
}
