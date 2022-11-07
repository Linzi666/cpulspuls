#define _CRT_SECURE_NO_WARNINGS 1



/*
* 在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
……
*/
#include <stdio.h>

int main()
{
	int arr[50][50]; //定义一个数组，用于存放数据
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++) //打印行数
	{
		int j = 0; 
		for (j = 0; j <= i; j++) //列数
		{
			//已知第一列和最后一列 都是1
			if (j == 0 || j == i)
				arr[i][j] = 1;
			//第 i 行 第 j 列的值等于 第 i-1 行 ，第 j - 1 列 + j 列
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			printf("%d ", arr[i][j]);
			
		}
		printf("\n");
	}


	return 0;
}