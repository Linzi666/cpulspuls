#define _CRT_SECURE_NO_WARNINGS 1

//���׼�����������ָ��ʵ��

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
	int x = 0; //��һ�������� 
	int y = 0; //�ڶ���������
	int input = 0; 
	int (*p[])(int, int) = { Add,Sub,Mul,Div };
	int len = sizeof(p) / sizeof(p[0]);

	do {
		menu();
		printf("���������ѡ��->");
		scanf("%d", &input);
		if (input <= len && input > 0)
		{
			printf("����������������->");
			scanf("%d %d",&x,&y);
			printf("ret = %d\n", (*(p + input - 1))(x, y));
		}
		else if(input != 0)
			printf("���������������\n");


	} while (input);


	return 0;
}