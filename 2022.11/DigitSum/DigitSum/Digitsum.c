#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int digit_sum(int num)
{
	//递归限制条件,就是 num < 9时
	if (num < 9)
		return num; //最后只剩一位数时，返回它本身值
	else
		return num % 10 + digit_sum(num / 10); //%10 是当前数的个位数，/10 是让该数除以10

	
}

int main()
{
	int num = 0; //被操作的值
	scanf("%d",&num);
	int sum = digit_sum(num); // 接收返回值
	printf("%d",sum);
	return 0;
}