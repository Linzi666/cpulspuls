#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10 //行
#define COL 10 //列
#define WIN 5 //胜利条件
#define PCHESS '*'
#define CCHESS '#'

//初始化棋盘
void intoboard(char board[ROW][COL], int row, int col);

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);

//玩家下棋
char Player(char board[ROW][COL] , int row, int col);

//电脑下棋
char Computer(char board[ROW][COL], int row, int col);