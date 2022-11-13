#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//杨氏矩阵 找数字
/*
	1  2  3  4
	5  6  7  8
	7  8  9 10
	9 10 11 12 
*/

int main()
{
	int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} }; //二维数组对应杨氏矩阵
	int input = 0;
	scanf("%d",&input);  //输入要查找的
	int row = sizeof(arr) / sizeof(*arr); //行数
	int col = sizeof(*arr) / sizeof(**arr);//列数
	int falg = 0;
	//找最右边的数字，如果比它大，行 + 1，如果小， 列 用二分查找
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if(arr[i][col-1] >=  input) //输入的数比一列中最大的数小，那么说明这个数就在这一列
		{ 
			//二分查找
			int left = 0;
			int right = col - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (arr[i][mid] == input)
				{
					falg = 1;
					j = mid;
					goto GOTO; //找到了，直接goto跳出多层循环
				}
				else if (arr[i][mid] > input)
					right = mid - 1;
				else
					left = mid + 1;
				
			}
		}
	}
GOTO:
	if (falg)
		printf("找到了，下标为:%d,%d\n", i, j);
	else
		printf("没找到\n");

	return 0;
}