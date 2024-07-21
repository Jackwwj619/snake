#include <stdio.h>
#include <curses.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#include "menu.h"
#include "key.h"
#include "game.h"
#include "ranking.h"
// COLS:241
// LENS:56

void config_ncurses() {
    WINDOW* scr = initscr();// 初始化进入NCURSES模式
    noecho();// 不回显字符
    cbreak();// 禁用行缓冲
    keypad(stdscr, TRUE);   // 程序需要使用键盘
    curs_set(FALSE);//不显示光标
}

void print_ranking() {
    mvprintw(0,0,"Showing Ranking ! Fight ! Fight ! Fight !");

    int fd = open(RANK,O_RDONLY | O_EXCL);
    mvprintw(40,0,"Press any Key to back");
    if(fd == -1) {
        char error_message[COLS];
        snprintf(error_message, COLS, "Error: %s", strerror(errno));
        mvprintw(0,0,"%s",error_message);
        return;
    }

    Ranking rank;
    ssize_t n_bytes_read;
    int number = 0;
    while((n_bytes_read = read(fd,&rank,sizeof(rank))) > 0 ) {
        if(n_bytes_read == -1) {
            perror("Error reading file");
            close(fd);
            return;
        }
        mvprintw(number+2,0,"number:%d",rank.number);
        mvprintw(number+2,10,"name:%s",rank.name);
        mvprintw(number+2,20,"time:%s",rank.time);
        number++;
    }
    getch();
    clear();
    print_start_menu();//打印开始菜单
    if(getkey() == 0) {
        endwin();
        exit(1);
    }else if(getkey() == 1) {
        clear();
        start_game();
        getch();
    }else if(getkey() == 2) {
        clear();
        print_ranking();
    }
    return;
}

int main(void) {
    config_ncurses();//配置nueses环境
    print_start_menu();//打印开始菜单
    if(getkey() == 0) {
        endwin();
        return 1;
    }else if(getkey() == 1) {
        clear();
        start_game();
        getch();
    }else if(getkey() == 2) {
        clear();
        print_ranking();
    }
    endwin();
    return 0;
}