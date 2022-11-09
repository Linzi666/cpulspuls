#pragma once

//声明函数头文件

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROW 15 // 行
#define COL 15 // 列
#define Pc '*'
#define Cc '#'
#define WIN 5 //胜利条件，5个就是5个连在一起胜利



//初始化棋盘
void intoboard(char board[ROW][COL], int, int); 

//打印棋盘
void PrintfBoard(char board[ROW][COL], int, int);

//玩家下棋
char Player(char board[ROW][COL], int, int);

//电脑下棋
char Computer(char board[ROW][COL], int, int);

//判断输赢，返回一个字符值
//char isWin(char board[ROW][COL], int, int);
