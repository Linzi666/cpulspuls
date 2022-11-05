#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
//求 1-10000的水仙花数

//返回一个数的位数
int A(int n)
{
	int count = 1;
	while (n /= 10)count++;
	return count;
}

//判断一个数是否是自幂数
int B(int n)
{
	int n2 = n;
	int sz = A(n);
	int sum = 0;
	while (n2)
	{
		sum += pow(n2 % 10, sz);
		n2 /= 10;
	}
	return sum == n ? 1 : 0;
}

//求自幂数
int main()
{
	//1-10000的自幂数
	for (int i = 1; i <= 10000; i++)
	{
		if (B(i))
			printf("%d ",i);
	}
	return 0;
}