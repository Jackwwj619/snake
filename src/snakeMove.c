//
// Created by jackw on 2024/7/20.
//

#include "snakeMove.h"

//srand((unsigned) time(NULL));

void updateSnake(WINDOW *win, Snake *snake, Dir dir) {
    //初始化新蛇头
    Snake *s = (Snake *)malloc(sizeof(Snake));
    s->x = snake->next->x;
    s->y = snake->next->y;

    switch (dir) {
        case UP:
            s->y--;
            break;
        case DOWN:
            s->y++;
            break;
        case LEFT:
            s->x--;
            break;
        case RIGHT:
            s->x++;
            break;
    }

    s->next = snake->next;
    snake->next = s;

    // 只找到蛇尾的前一个节点，然后s->next就是lastTail
    while (s->next->next) {
        s = s->next;
    }

    refreshSnake(win, snake, s->next);

    s->next = NULL;
}

void refreshSnake(WINDOW *win, Snake *snake, Snake *lastTail) {
    Snake *s = snake->next;
    mvwaddch(win, s->y, s->x, '#');

    if (lastTail) {
        mvwaddch(win, lastTail->y, lastTail->x, ' ');
    }

    wrefresh(win);
}

void updateFood(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir) {
    int flag = 0;
    do {
        food->x = rand() % (border.width - 2) + 1;
        food->y = rand() % (border.height - 2) + 1;

        Snake *s = snake->next;
        while (s) {
            if (s->x == food->x && s->y == food->y) {
                flag = 1;
                break;
            }
            s = s->next;
        }
    }while (flag);

    refreshFood(win, food, border, dir);
}

void refreshFood(WINDOW *win, Food *food, Border border, Dir dir) {
    mvwaddch(win, food->y, food->x, '*');
    wrefresh(win);
}

int checkCrashWall(WINDOW *win, Snake *snake, Food *fod, Border border, Dir dir) {
    Snake *s = snake->next;
    int headx = s->x;
    int heady = s->y;

    int isCrashed = 0;
    if (s->y == 0 && dir == UP)
        isCrashed = 1;
    else if (s->y == border.height - 2 && dir == DOWN)
        isCrashed = 1;
    else if (s->x == border.width && dir == RIGHT)
        isCrashed = 1;
    else if (s->x == 0 && dir == LEFT)
        isCrashed = 1;

    updateSnake(win, snake, dir);

    // 检查是否碰到自己身体
    while (s->next) {
        s = s->next;
        if (headx == s->next->x && heady == s->next ->y) {
            //printf("crashed yourself!");
            return 1;
        }
    }

    return isCrashed;
}

int checkEatFood(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir) {
    int headx = snake->next->x;
    int heady = snake->next->y;

    int nextx;
    int nexty;

    switch (dir) {
        case UP:
            heady--;
            break;
        case DOWN:
            heady++;
            break;
        case LEFT:
            headx--;
            break;
        case RIGHT:
            headx++;
            break;
    }

    if (headx == food->x && heady == food->y) {
        Snake *s = (Snake *) malloc(sizeof(Snake));
        s->x = food->x;
        s->y = food->y;
        s->next = snake->next;
        snake->next = s;

        refreshSnake(win, snake, NULL);

        refreshFood(win, food, border, dir);

        return 1;
    }

    return 0;
}

