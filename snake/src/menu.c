//
// Created by 李政杭 on 2024/7/20.
//
#include "curses.h"
#include <unistd.h>
#include <fcntl.h>

#define MENU "res/menu.txt"
#define START "res/start.txt"
#define CREDITS "res/credits.txt"

//读取文件大小
ssize_t count_file(int fd) {
    ssize_t len = lseek(fd,0,SEEK_END);
    lseek(fd,0,SEEK_SET);
    return len;
}

void print_file(char* path,unsigned int x,unsigned int y) {
    //读取文件
    int fd = open(path,O_RDONLY);
    if(fd == -1) {
        perror("Error opening file");
        _exit(1);
    }

    char buffer[count_file(fd) + 1];
    ssize_t n_bytes_read = read(fd,buffer,count_file(fd));

    if(n_bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        endwin();
    }

    buffer[count_file(fd)] = 0;//设置末尾为0
    // 将内容打印出来
    mvprintw(y,x,buffer);
    close(fd);
}

void print_start_menu() {
    print_file(MENU,0,0);
    print_file(START,0,5);
    print_file(CREDITS,0,10);
}