//
// Created by 李政杭 on 2024/7/21.
//
//
// Created by jackw on 2024/7/20.
//

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "SnakeMove.h"

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
    free(s->next);
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
    int flag;
    do {
        flag = 0;
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

int checkCrashWall(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir) {
    //按当前运动方向蛇头即将到达的下一个坐标
    int headx = snake->next->x, heady = snake->next->y;
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

    //撞墙
    if (headx <= 0 || headx >= border.width-1 || heady <= 0 || heady >= border.height-1) {
        //显示撞墙结果
        updateSnake(win,snake,dir);
        return 1;
    }

    //撞自己(身体)
    Snake *s=snake->next->next;
    while (s){
        if (s->x==headx && s->y==heady){
            return 1;
        }
        s=s->next;
    }

    return 0;
}

//
// int checkCrashWall(WINDOW *win, Snake *snake, Food *fod, Border border, Dir dir) {
//     Snake *s = snake->next;
//     int headx = s->x;
//     int heady = s->y;
//
//     int isCrashed = 0;
//     if (s->y == 0 && dir == UP)
//         isCrashed = 1;
//     else if (s->y == border.height - 2 && dir == DOWN)
//         isCrashed = 1;
//     else if (s->x == border.width && dir == RIGHT)
//         isCrashed = 1;
//     else if (s->x == 0 && dir == LEFT)
//         isCrashed = 1;
//
//     updateSnake(win, snake, dir);
//
//     // 检查是否碰到自己身体
//     while (s->next) {
//         s = s->next;
//         if (headx == s->next->x && heady == s->next ->y) {
//             //printf("crashed yourself!");
//             return 1;
//         }
//     }
//
//     return isCrashed;
// }

int checkEatFood(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir) {
    int headx = snake->next->x;
    int heady = snake->next->y;
    //
    // int nextx;
    // int nexty;
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
        // 插入一段新蛇头
        Snake *s = (Snake *) malloc(sizeof(Snake));
        s->x = food->x;
        s->y = food->y;
        s->next = snake->next;
        snake->next = s;

        // refresh而不是update因为只需增加一节，不用擦除
        refreshSnake(win, snake, NULL);

        updateFood(win, snake, food, border, dir);

        return 1;
    }

    return 0;
}

void initWin(WINDOW *win, Snake *snake, Food *food, Border border, Dir dir) {
    // 初始化这条snake
    Snake *s = (Snake *) malloc(sizeof(Snake));
    // 开局在中间
    s->x = border.width / 2;
    s->y = border.height / 2;
    s->next = NULL;
    snake->next = s;

    updateSnake(win, snake, dir);
    updateFood(win, snake, food, border, dir);
    box(win,0,0);

    getch();
    refresh();
}


int dealControl(Snake *snake,int *speed,Dir *dir){

    //获取键盘输入
    int ch=getch();

    if (ch!=ERR){   //有键盘输入
        //同向按键无效
        if((ch==KEY_UP && *dir==UP) || (ch==KEY_DOWN && *dir==DOWN) ||
           (ch==KEY_LEFT && *dir==LEFT) || (ch==KEY_RIGHT && *dir==RIGHT)){
            return 0;
           }

        //反向按键，自我碰撞
        if (snake->next->next){
            if((ch==KEY_UP && *dir==DOWN) || (ch==KEY_DOWN && *dir==UP) ||
               (ch==KEY_LEFT && *dir==RIGHT) || (ch==KEY_RIGHT && *dir==LEFT)){
                return 1;
               }
        }

        //加减速，暂停，转向
        switch (ch) {
            case 'd':   //加速
            case 'D':
                if ((*speed)>100000){
                    *speed=(*speed)-50000;
                }
            break;
            case 'a':   //减速
            case 'A':
                if ((*speed)+100000<INT32_MAX){
                    *speed=(*speed)+50000;
                }
            break;
            case 's':   //暂停
            case 'S':
                while (1) {
                    ch = getch();
                    if (ch == 's' || ch == 'S') {
                        break;
                    }
                }
            break;
            case KEY_UP:    //向上
                *dir = UP;  //修改当前运动方向
            break;
            case KEY_DOWN:  //向下
                *dir = DOWN;//修改当前运动方向
            break;
            case KEY_LEFT:  //向左
                *dir = LEFT;//修改当前运动方向
            break;
            case KEY_RIGHT: //向右
                *dir = RIGHT;//修改当前运动方向
            break;
            default:        //其他无效按键跳过
                return 1;
        }
    }
    fflush(stdout);
    return 2;
}

void destroyWin(){
    //显示退出游戏提示
    char *crash="crash !";
    char *quit="quiting...";

    attron(A_BOLD); //粗体文字
    mvprintw((LINES-15)/2,(COLS-strlen(crash))/2,"%s",crash);
    mvprintw((LINES-15)/2+1,(COLS-strlen(quit))/2,"%s",quit);
    attron(A_BOLD); //粗体文字
    refresh();

    //延时
    sleep(2);
}
void update_Border(Border* border) {
    border->height = LINES -15;
    border->width = COLS;
    border->startx = 0;
    border->starty = 0;
}