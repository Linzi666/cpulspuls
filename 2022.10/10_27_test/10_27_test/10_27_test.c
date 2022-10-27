#define _CRT_SECURE_NO_WARNINGS 1

//猜数字小游戏

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}

//猜数字游戏体
void game()
{
	//生成一个随机数 
	int ret = rand()%100 +1 ;  //生成 1 - 100的随机数
	int input = 0;
	while (1) // 死循环
	{
		printf("请输入你猜的数->>:");
		scanf("%d", &input);
		//判断是否猜大猜小
		if (input > ret)
			printf("你猜的数大了\n");
		else if (input < ret)
			printf("你猜的数小了\n");
		else
		{
			printf("猜中了！！\n");
			break;
		}
			
	}

}

int main()
{
	srand(time(NULL));  //利用时间戳初始化伪随机数 , 只用执行一次
	//第一步，出现菜单
	//菜单至少打印一次，所以用do while循环
	int input = 0;
	do
	{
		menu(); //打印菜单的函数
		//打印完菜单后，提升输入
		printf("你的选择是->>:");
		scanf("%d",&input); //输入选项
		system("cls"); //输入完清屏
		switch (input)
		{
			case 0: 
				printf("你已退出游戏\n");
				break;
			case 1: 
				game();
				break;
			default: 
				printf("输入错误，请重新输入\n");
				break;
		}


	} while (input);

	return 0;
}