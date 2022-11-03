#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_COUNT 10 //雷的数量
#define MINE '0' // 放雷数组 
#define SHOW '*' //  排雷数组

//初始化
void intogame(char arr[ROWS][COLS], int rows, int cols, char m);

//打印数组
void Printfarr(char arr[ROWS][COLS], int row, int col);

//安排雷
void add_mine(char mine[ROWS][COLS], int row, int col,int count);

//玩游戏数组
int PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
