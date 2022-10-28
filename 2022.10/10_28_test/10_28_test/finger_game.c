#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 0 为拳头
// 1 为布
// 2 为剪刀


void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  2.clear  *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}
void menu2()
{
	printf("*********************\n");
	printf("******  0.拳头  *****\n");
	printf("******  1.布    *****\n");
	printf("******  2.剪刀  *****\n");
	printf("*********************\n");
}
// -2是赢， -1是输，1是赢，2是输
void game()
{
	//游戏体

	char arr[3][5] = { "拳头","布","剪刀" }; //字符串数组，方便打印
	int player = 0; //玩家出拳
	int computer = rand()%3; //电脑出拳
	int win = 0; // 0 平局， -1 输， 1 赢
	menu2(); //打印菜单
	printf("输入开始猜拳->>");
	scanf("%d",&player);//自己出拳

	switch (player-computer) //游戏结果
	{
	case 0:
		win = 0;
		break;
	case -2: 
	case 1:
		win = 1;
		break;
	case -1:
	case 2:
		win = -1;
		break;
	default :
	{
		printf("输入有误\n");
		return; //结束该函数
	}
	}

	//打印双方 出拳
	printf("\n");
	printf("电脑出拳结果为:%s\n",arr[computer]);
	printf("你的出拳结果为:%s\n", arr[player]);

	//打印输赢
	switch (win)
	{
	case -1:
		printf("你输了\n");
		break;
	case 0:
		printf("平局\n");
		break;
	case 1:
		printf("你赢了\n");
		break;
	}	
}

int main()
{	
	int input = 0; // 选项
	srand(time(NULL)); //初始化随机数生成器
	do
	{
		menu();
		printf("请输入你的选择->>");
		scanf("%d",&input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("游戏已退出\n");
			break;
		case 2:
			system("cls"); //清屏
			break;
		default :
			printf("输入错误\n");
		}
	} while (input);
	return 0;
}