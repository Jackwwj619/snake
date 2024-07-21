//
// Created by 李政杭 on 2024/7/20.
//

#ifndef MENU_H
#define MENU_H
#include <unistd.h>
#include <fcntl.h>

#include "curses.h"

ssize_t count_file(int fd);

void print_file(char* path,unsigned int x,unsigned int y);

void print_start_menu();
#endif //MENU_H
