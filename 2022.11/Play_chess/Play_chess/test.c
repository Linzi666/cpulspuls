#define _CRT_SECURE_NO_WARNINGS 1

//三子棋

#include "game.h" //引入游戏头文件

//打印菜单函数
void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  2.clear *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}

//生成随机数并且返回



//游戏函数
void game()
{
	// 第一步，创建棋盘数组
	char board[ROW][COL] = { 0 };
	//第二步，初始化棋盘
	intoboard(board,ROW,COL);
	//第二步，打印棋盘
	PrintfBoard(board,ROW,COL);
	//下棋功能，这边使用随机，随机下棋
	char win = 0;
	while (1)
	{
			Player(board,ROW,COL);
			PrintfBoard(board, ROW, COL); //打印棋盘
			win = isWin(board, ROW, COL);
			if(win != 'C')//判断输赢
			break;

			printf("---------电脑下棋----------\n");
			Computer(board, ROW, COL);
			PrintfBoard(board, ROW, COL); // 打印棋盘

			win = isWin(board, ROW, COL);
			if (win != 'C')//判断输赢
			break;	
	}
	if (win == '*')
		printf("你赢了\n");
	else if (win == '#')
		printf("电脑赢了\n");
	else
		printf("平局\n");

}


int main()
{
	srand((unsigned int)time(NULL)); //初始化伪随机数生成器
	int input = 0; //选择
	//至少选择一次

	do
	{
		//打印菜单
		menu(); 
		//提示输入
		printf("请输入你的选择->:"); 
		//输入选择
		scanf("%d",&input);  

		//switch 分支判断
		switch (input)
		{
		case 1:
			game(); //游戏开始函数
			break;
		case 2:
			system("cls");
			break;
		case 0 :
			printf("退出成功\n");
			break;
		default :
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);


	return 0;
}