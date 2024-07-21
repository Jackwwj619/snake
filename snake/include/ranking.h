//
// Created by 李政杭 on 2024/7/21.

#ifndef RANKING_H
#define RANKING_H
#define RANK "res/ranking.txt"
#define SIZE_NAME 25
#define SIZE_TIME 50

#include <curses.h>
#include <string.h>
#include <utime.h>

typedef struct utimbuf Mytime;

typedef struct ranking  {
    int number;
    char name[SIZE_NAME];
    char time[SIZE_TIME];
}Ranking;

#endif //RANKING_H
