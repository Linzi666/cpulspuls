#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//打印菜单
void menu()
{
	printf("**************************\n");
	printf("*******   1.Play    ******\n");
	printf("*******   2.Clear   ******\n");
	printf("*******   0.Eixt    ******\n");
	printf("**************************\n");
}

//游戏执行方法
void game()
{
	//第一步，创建2个数组，一个数组用于排雷，一个数组用于存放雷
	//存放雷的数组
	char mine[ROWS][COLS] = { 0 }; //1 为 雷，0为非雷  
	//排查雷的数组
	char show[ROWS][COLS] = { 0 }; 

	//数组初始化
	intogame(mine,ROWS,COLS,MINE); //初始化 mine 数组
	intogame(show, ROWS, COLS, SHOW); //初始化 mine 数组
	//初始化完毕后分别打印2个数组
//	Printfarr(mine, ROW, COL); //这个不能给你们看
	Printfarr(show, ROW, COL);

	//随后给 mine 数组安排雷
	add_mine(mine,ROW,COL,MINE_COUNT);


	//雷初始化好后，开始玩游戏
	int ret = PlayGame(mine,show,ROW,COL); //接收一个结果判断输赢
	if (ret)
	{
		printf("\n");
		printf("--------游戏结果--------\n");
		printf("恭喜你，排除了所有的雷\n");
	}
	else
	{
		printf("\n");
		printf("--------游戏结果--------\n");
		printf("你踩到雷了\n");
	}
	printf("\n");
	printf("--------雷区展示--------\n");
	Printfarr(mine, ROW, COL); //最后打印一次数组
	printf("\n");

}

int main()
{
	srand((unsigned int)time(NULL));//伪随机数生成器
	//扫雷游戏
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择 ->");
		scanf("%d",&input);
		//switch 分支
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出成功\n");
			break;
		case 2: 
			system("cls");
			break;
		default :
			printf("输入错误请重新输入\n");
			break;
		}
	} while (input);


	return 0;
}