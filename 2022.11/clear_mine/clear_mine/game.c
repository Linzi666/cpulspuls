#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//初始化数组
void intogame(char arr[ROWS][COLS], int rows, int cols, char m)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			arr[i][j] = m;
	}
}


//打印数组
void Printfarr(char arr[ROWS][COLS], int row, int col) 
{
	int i = 1 ; //数组 从下标为1 位置开始打印
	int j = 1 ;
	for (int i = 0; i <= col; i++)
		printf(" %d",i);
	printf("\n");
	for (int i = 0; i <= col; i++)
		printf("--", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= col; j++)
			printf(" %c",arr[i][j]);
		printf("\n");
	}

}

//安排雷
void add_mine(char mine[ROWS][COLS], int row, int col, int count)
{

	while (count)
	{
		int x = rand() % row + 1; //1-row 之间
		int y = rand() % col + 1;// 1- col 之间
		if (mine[x][y] == '0') //避免雷重复
		{
			mine[x][y] = '1'; //放雷
			count--;
		}
	}
}

//获得周围雷的数量
static int mine_num(char mine[ROWS][COLS], int x , int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y]
		+ mine[x + 1][y + 1] - 8 * '0';
}

//玩扫雷  返回 1，赢了， 0 死了，
int PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0; //排雷次数
	//首先输入一个坐标
	
	while (1)
	{

		int x = 0;
		int y = 0;

		printf("输入坐标排查雷 ->");
		scanf("%d %d", &x, &y);
		//判断坐标的合法性
		if (x < 1 || y < 1 || x > row || y > col)
		{
			printf("坐标不合法,请重新输入\n");
			continue;
		}
		//踩的数量+1
		count++;

		//坐标合法，三步判断，1 是否踩到雷。
		if (mine[x][y] == '1') //踩到雷了，再见
			return 0;

		//没有踩到雷 ，判断游戏是否结束
		if ((row * col - count) == MINE_COUNT)
			return 1;

		//没输也没赢，游戏还在进行
		//判断输入的坐标周围有几个雷
		int num = mine_num(mine, x, y);
		show[x][y] = num + '0';
		system("cls");
		Printfarr(show, row, col);

	}

}