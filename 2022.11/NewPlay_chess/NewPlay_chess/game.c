#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//初始化棋盘
void intoboard(char board[ROW][COL], int row, int col)
{
	//游戏刚开始，每个坐标都为空
	int i = 0;
	int j = 0;
	for (i; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}

//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col)
{
	//棋盘格式是 c   |   |   第一行
	//第二行      ---|---|
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//打印第一行
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j != col - 1)
				printf("|");
		}
		//一行打完换行
		printf("\n");
		//打印第二行
		for (j = 0; j < col; j++)
		{
			//如果是最后一行，这---不用打印
			if (i != row - 1)
			{
				printf("---", board[i][j]);
				if (j != col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}


//玩家下棋
char Player(char board[ROW][COL],int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("请输入下棋的坐标->>");
		scanf("%d %d", &x, &y);
		//因为输入的坐标，和数组对应的坐标会相差1，所以再判断数组的时候需要x和y都减去1
		if (board[x - 1][y - 1] == ' ' && x > 0 && x <= row && y > 0 && y <= col)
		{
			board[x - 1][y - 1] = PCHESS;
			return Iswin(board,row,col,x-1,y-1); //因为数组坐标和输入坐标会相差1，所以传进去时-1
		}
		else
			printf("坐标非法，请重新输入\n");

	}
}

char Computer(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row; //数组下标 0 -  （row -1） 
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = CCHESS;
			printf("电脑下棋:%d,%d\n",x+1,y+1);
			return Iswin(board, row, col, x, y);
		}
	}
}

//判断棋盘是否下满
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i; i < row; i++)
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ') //如果棋盘等于' '，说明还有位置，返回0
				return 0;

	return 1;
}



static int Iswin(char board[ROW][COL], int row, int col, int x, int y)
{
	int i = 1;
	int count = 1; //因为从落子点开始，所以count 初始值为1
	//每行，每列，每个对角，都有2个方向,而WIN是赢得的条件，我们需要排查WIN-1个坐标
	for (i = 1; i < WIN; i++)
		//我们要避免数组越界，所以后面还要加上限制
		if (board[x][y] == board[x + i][y] && x + i < row)
			count++; //满足条件，计数 +1 

	//然后判断另一半
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x - i][y] && x - i >= 0)
			count++; 

	//最后 一条线的判断完了，如果此时 count >= WIN，我们就可以判断游戏胜利，否则重置count的值
	if (count >= WIN)
		return board[x][y]; //返回自己字符
	else
		count = 1;

	//以上是 行的排查，那么列，对角线的排查同样如此

	//排查列
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x][y+i] && y + i < row)
			count++; //满足条件，计数 +1 

	//然后判断另一半
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x][y-i] && y - i >= 0)
			count++;

	if (count >= WIN)
		return board[x][y]; 
	else
		count = 1;

	//排查第一条对角线

	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x+i][y + i] && (x+i < col) && (y + i < row))
			count++; //满足条件，计数 +1 

	//然后判断另一半
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x - i][y - i] && (x - i >= 0) && (y - i >= 0))
			count++;

	if (count >= WIN)
		return board[x][y];
	else
		count = 1;

	//第二条对角线
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x + i][y - i] && (x + i < col) && (y - i >= 0))
			count++; //满足条件，计数 +1 

	//然后判断另一半
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x - i][y + i] && (x - i >= 0) && (y + i < col))
			count++;

	if (count >= WIN)
		return board[x][y];

	//判断棋盘是否下满
	if (is_full(board, row,col))
		return 'Q';

	return 'C';
}