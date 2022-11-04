#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//递归和非递归分别实现求n的阶乘（不考虑溢出的问题）

//非递归
int a(n)
{
	int avg = 1;
	for (int i = 1; i <= n; i++)
	{
		avg *= i;
	}
	return avg;
}

//递归求阶乘
int b(n)
{
	if (n == 1)
		return 1;
	else
		return n * (n - 1);
}


int main()
{
	int n = 0;
	scanf("%d",&n);
	//非递归求阶乘
	int ret1 = a(n);
	printf("非递归阶乘: %d \n",ret1);
	//递归求阶乘
	int ret2 = b(n);
	printf("递归阶乘: %d \n", ret1);

	return 0;
}