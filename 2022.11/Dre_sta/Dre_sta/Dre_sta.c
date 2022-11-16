#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
Bessie 的大脑反应灵敏，仿佛真实地看到了她数过的一个又一个数。
她开始注意每一个数码（0 \ldots 90…9）：每一个数码在计数的过程中出现过多少次？
给出两个整数 M 和 N，求在序列 [M, M + 1, M + 2, \ldots, N - 1, N][M,M+1,M+2,…,N−1,N] 
中每一个数码出现了多少次。
*/

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d",&m,&n);
	int arr[10] = { 0 }; //存放 0 - 9 出现的次数
	int i = 0;
	for ( i = m; i <= n; i++)
	{
		int k = i;
		while (k)
		{
			arr[k % 10]++; // 一个数%10只会等于 0-9 ，对应的arr数组++就行
			k /= 10; // 除10后，开始下一位数的判断
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ",arr[i]);


	return 0;
}