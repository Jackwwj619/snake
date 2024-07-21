<<<<<<< HEAD
//
// Created by jackw on 2024/7/20.
//

#include <stdio.h>
#include "snakeMove.h"

=======
#include <stdio.h>
#include "snakeMove.h"


>>>>>>> 597f789ddbc2fd649a9bd48dd01b9a0b7826938c
int main() {
    srand((unsigned) time(NULL));
    init_ncurses();

<<<<<<< HEAD
    int speed = 500000;
    Border border;
    Food food;
    Dir dir = RIGHT;
    Snake *snake = (Snake *) malloc(sizeof(Snake));
=======

    int speed = 5000000;
    Border border;
    Food food;
    Dir dir = RIGHT;
    Snake *snake = (Snake *) malloc(sizeof(Snake *));
>>>>>>> 597f789ddbc2fd649a9bd48dd01b9a0b7826938c

    WINDOW *win = createWin(&border);
    initWin(win, snake, &food, border, dir);


    timeout(0);

    while (1) {

        // 非阻塞处理键盘控制
        int res=dealControl(snake,&speed,&dir);
        if(res==1){         //同向按键无效
            continue;
        } else if (res==0){ //长度超过1后反向按键，自我碰撞
            break;
        }

        //撞墙
        if (checkCrashWall(win, snake, &food, border, dir)) {
            break;
        }

        //未吃到食物，向当前方向前进一格，更新蛇身信息
        if (!checkEatFood(win, snake, &food, border, dir)) {
            updateSnake(win, snake, dir);
        }

        //程序睡眠(微秒)，实现速度控制
        usleep(speed);
    }

    //销毁窗口
    destroyWin(win);

    //退出curses模式
    endwin();
<<<<<<< HEAD

    return 0;
=======
>>>>>>> 597f789ddbc2fd649a9bd48dd01b9a0b7826938c
}
