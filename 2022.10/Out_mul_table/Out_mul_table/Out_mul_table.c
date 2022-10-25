#define _CRT_SECURE_NO_WARNINGS 1

//打印乘法口诀表
#include<stdio.h>
int main()
{
	int i = 1;
	int j = 1;
	for (; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d x %d = %d  ", i, j, (i * j));
		}
		printf("\n");
	}
	return 0;
}