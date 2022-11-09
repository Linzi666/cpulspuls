#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10 //��
#define COL 10 //��
#define WIN 5 //ʤ������
#define PCHESS '*'
#define CCHESS '#'

//��ʼ������
void intoboard(char board[ROW][COL], int row, int col);

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);

//�������
char Player(char board[ROW][COL] , int row, int col);

//��������
char Computer(char board[ROW][COL], int row, int col);