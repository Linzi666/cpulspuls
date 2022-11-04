#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//递归和非递归 求 斐波那契数列 

//非递归方式
int a(int n)
{
	//
	int i = 0;
	int num1 = 1; // 第一项
	int num2 = 1; // 第二项
	int num3 = 1;//第三项
	for (int i = 3; i <= n; i++) //从第2项开始
	{
		//值交换
		num3 = num2 + num1;
		num1 = num2;
		num2 = num3;
	}
	return num3;
}

//递归方法
int b(int n)
{
	// k1 第一个数，k2，第二个数

	if (n<3) //限制条件
	{
		return 1;
	}
	else
		return  b(n-1) + b(n-2);

}

int main()
{
	int n = 0;
	scanf("%d",&n);
	//非递归方法
	if (n > 0)
	{
		int ret = a(n);
		printf("非递归方法 : %d\n", ret);

		//递归方法
		int ret2 = b(n, 1, 1);
		printf("递归方法 : %d\n", ret2);
	}

	return 0;
}