#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列

int main()
{
	int num = 10;
	int i = 0;

	//
	printf("从右向左打印\n");
	printf("偶数序列:");
	for (i = 0; i < 32; i += 2) //打印偶数序列
		printf("%d ", 10 & (num << i) ? 1 : 0);
	printf("奇数序列:");
	for (i = 1; i <= 31; i += 2)  //打印奇数序列
		printf("%d ", 10 & (num << i) ? 1 : 0);

	printf("\n从左向右打印\n");
	printf("偶数序列:");
	for (i = 30; i >= 0; i -= 2) //打印偶数序列
		printf("%d ", 10 & (num << i) ? 1 : 0);
	printf("奇数序列:");
	for (i = 31; i >= 1; i -= 2)  //打印奇数序列
		printf("%d ", 10 & (num << i) ? 1 : 0);
	return 0;
}