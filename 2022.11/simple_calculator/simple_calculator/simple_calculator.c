#define _CRT_SECURE_NO_WARNINGS 1

//简易计算器，函数指针实现

#include<stdio.h>
void menu()
{
	printf("*************************\n");
	printf("***** 1.Add  2.Sub ******\n");
	printf("***** 3.Mul  4.Div ******\n");
	printf("*****   0.Exit     ******\n");
	printf("*************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int x = 0; //第一个操作数 
	int y = 0; //第二个操作数
	int input = 0; 
	int (*p[])(int, int) = { Add,Sub,Mul,Div };
	int len = sizeof(p) / sizeof(p[0]);

	do {
		menu();
		printf("请输入你的选择->");
		scanf("%d", &input);
		if (input <= len && input > 0)
		{
			printf("请输入两个操作数->");
			scanf("%d %d",&x,&y);
			printf("ret = %d\n", (*(p + input - 1))(x, y));
		}
		else if(input != 0)
			printf("输入错误重新输入\n");


	} while (input);


	return 0;
}