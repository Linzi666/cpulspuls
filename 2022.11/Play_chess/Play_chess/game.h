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


//��ʼ������
void intoboard(char board[ROW][COL], int, int); 

//��ӡ����
void PrintfBoard(char board[ROW][COL], int, int);

//�������
void Player(char board[ROW][COL], int, int);

//��������
void Computer(char board[ROW][COL], int, int);

//�ж���Ӯ������һ���ַ�ֵ
char isWin(char board[ROW][COL], int, int);
