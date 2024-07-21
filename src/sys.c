//
// Created by jackw on 2024/7/21.
//
#include "snakeMove.h"

void init_ncurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

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

    getch();
    char *help="A:decrease speed  S:pause  D:increase speed";
    mvprintw(LINES-1,(COLS-strlen(help))/2,help);
    refresh();
}


int dealControl(Snake *snake,int *speed,Dir *dir){

    //获取键盘输入
    int ch=getch();

    if (ch!=ERR){   //有键盘输入
        //同向按键无效
        if((ch==KEY_UP && *dir==UP) || (ch==KEY_DOWN && *dir==DOWN) ||
           (ch==KEY_LEFT && *dir==LEFT) || (ch==KEY_RIGHT && *dir==RIGHT)){
            return 1;
           }

        //反向按键，自我碰撞
        if (snake->next->next){
            if((ch==KEY_UP && *dir==DOWN) || (ch==KEY_DOWN && *dir==UP) ||
               (ch==KEY_LEFT && *dir==RIGHT) || (ch==KEY_RIGHT && *dir==LEFT)){
                return 0;
               }
        }

        //加减速，暂停，转向
        switch (ch) {
            case 'd':   //加速
            case 'D':
                if ((*speed)>200000){
                    *speed=(*speed)-200000;
                }
            break;
            case 'a':   //减速
            case 'A':
                if ((*speed)+200000<INT32_MAX){
                    *speed=(*speed)+200000;
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

    return 2;
}

WINDOW *createWin(Border *border) {

    border->height = LINES - 2;                        //窗口高度
    border->width = COLS - 6;                          //窗口宽度
    border->starty = (LINES - border->height) / 2;    // 计算窗口中心位置的行数
    border->startx = (COLS - border->width) / 2;      // 计算窗口中心位置的列数

    //显示游戏名称和操作提示
    char *name = "snake 1.0";
    mvprintw(0, (COLS - strlen(name)) / 2, "%s", name);
    char *message="Press any key continue ...";
    mvprintw(LINES-1,(COLS-strlen(message))/2,message);
    refresh();

    //创建窗口
    WINDOW *local_win;
    local_win = newwin(border->height, border->width, border->starty, border->startx);
    //显示边框
    box(local_win, 0, 0);
    wrefresh(local_win);

    return local_win;
}

void destroyWin(WINDOW *win){
    //显示退出游戏提示
    char *crash="crash !";
    char *quit="quiting...";

    attron(A_BOLD); //粗体文字
    mvprintw(LINES/2,(COLS-strlen(crash))/2,crash);
    mvprintw(LINES/2+1,(COLS-strlen(quit))/2,quit);
    attron(A_BOLD); //粗体文字
    refresh();

    //延时
    sleep(2);
    //销毁窗口
    delwin(win);
}