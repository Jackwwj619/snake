//
// Created by 李政杭 on 2024/7/21.
//
#include "key.h"
#include <stdio.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int getkey() {
    while(1) {
        char ch = getch();
        if(ch == YES) {
            return 1;
        }else if(ch == TABLE) {
            return 2;
        }else if(ch == ESC){
            return 0;
        }
        sleep(0.1);
    }
}