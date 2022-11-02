#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h" 

//初始化棋盘实现
void intoboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) //三行
	{
		for (j = 0; j < col; j++) //三列
		{
			board[i][j] = ' '; //初始化赋值位空格
		}
	}



}

//打印棋盘实现
void PrintfBoard(char board[ROW][COL], int row, int col)
{
	//打印 三行 
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//每一行有 2 行，   |   | 
		//               ---|---|---
		//打印第一行   |   |
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]); //打印棋盘的符号以及两边空格
			if (j < col - 1) //可以看到最右边是没有|的，所以要把它砍掉
				printf("|");
		}
		//打印 换行
		printf("\n");
		//打印第二行 ---|---|---
		if (i < row - 1) //最后一行虚线不要
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1) //可以看到最右边是没有|的，所以要把它砍掉
					printf("|");
			}
		}
		//打印换行
		printf("\n");
	}
}

//玩家下棋
void Player(char board[ROW][COL], int row, int col)
{
	//第一步，提示下棋
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入你下棋的坐标->:");
		//输入坐标
		scanf("%d %d", &x, &y);
	
		if (x <= row && y <= col && x > 0 && y > 0 && (board[x - 1][y - 1] == ' '))
		{
			board[x - 1][y - 1] = Pc;
			break;
		}
		else
			printf("输入坐标非法,请重新输入\n");
	}
}

//电脑下棋
void Computer(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		//生成2个随机数
		int x = rand() % row; //随机生成横坐标
		int y = rand() % col; //随机生成纵坐标
		if ((board[x][y] == ' '))
		{
			board[x][y] = Cc;
			break;
		}
	}
}

//判断棋是否下满了
 static int is_full_board(char board[ROW][COL], int row, int col)
{
	 int i = 0;
	 int j = 0;
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 if (board[i][j] == ' ')
				 return 0;
		 }
	 }
	 return 1;
}

//判断输赢
char isWin(char board[ROW][COL], int row, int col)
{
	 //判断三行，三列
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[1][i] != ' '))
			return board[1][i];
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
			return board[i][0];
	}
	//判断斜对角
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[3][3]) && (board[1][1] != ' '))
		return board[i][0];

	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[1][1] != ' '))
		return board[i][0];

	//判断棋盘是否满了
	if(is_full_board(board,ROW,COL))
		return 'Q';
	return 'C';
}

