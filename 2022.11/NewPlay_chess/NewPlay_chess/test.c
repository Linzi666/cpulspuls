
#include "game.h"
void game()
{
	//创建棋盘
	char board[ROW][COL] = { 0 };
	//初始化数组
	intoboard(board,ROW,COL);
	//printf 打印棋盘
	PrintBoard(board, ROW, COL);
	char win = 0; // Q为 平局, C为游戏继续，返回CCHESS电脑赢，返回PCHESS玩家赢
	while (1)
	{
		//玩家下棋
		win = Player(board, ROW, COL); //把返回结果放进win里
		PrintBoard(board, ROW, COL);

		if (win != 'C') //win 不等于C 说明，游戏不继续了
			break;
		//电脑下棋
		win = Computer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		if (win != 'C') //win 不等于C 说明，游戏不继续了
			break;
	}

	if (win == CCHESS)
		printf("你输了，电脑赢得游戏\n");
	else if (win == PCHESS)
		printf("恭喜你，赢得了游戏\n");
	else
		printf("平局");
		
}

//打印菜单
void menu()
{
		printf("*********************\n");
		printf("******  1.play  *****\n");
		printf("******  2.clear *****\n");
		printf("******  0.exit  *****\n");
		printf("*********************\n");
}

int main()
{
	int input = 0;
	//打印菜单
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("请输入你的选择->>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			//开始游戏
			game();
			break;
		case 2:
			//清屏
			system("cls");
			break;
		case 0:
			break;
		default:
			printf("输入有误请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}