#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define MINE_COUNT 10 //�׵�����
#define MINE '0' // �������� 
#define SHOW '*' //  ��������

//��ʼ��
void intogame(char arr[ROWS][COLS], int rows, int cols, char m);

//��ӡ����
void Printfarr(char arr[ROWS][COLS], int row, int col);

//������
void add_mine(char mine[ROWS][COLS], int row, int col,int count);

//����Ϸ����
int PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
