#pragma once

//��������ͷ�ļ�

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROW 3 // ��
#define COL 3 // ��
#define Pc '*'
#define Cc '#'
#define WIN 3 //ʤ��������5������5������һ��ʤ��



//��ʼ������
void intoboard(char board[ROW][COL], int, int); 

//��ӡ����
void PrintfBoard(char board[ROW][COL], int, int);

//�������
char Player(char board[ROW][COL], int, int);

//��������
char Computer(char board[ROW][COL], int, int);

//�ж���Ӯ������һ���ַ�ֵ
//char isWin(char board[ROW][COL], int, int);
