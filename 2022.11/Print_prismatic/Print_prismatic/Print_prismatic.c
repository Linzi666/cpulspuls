#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//打印棱形
/*
	  *
	 ***
	*****
   *******
  *********
 ***********
*************
 ***********
  *********
   *******
	*****
	 ***
	  *
*/
int main()
{
	int n = 13; // 棱形行数，输入奇数，偶数会自动+1行
	int mid = n / 2 + 1; //中间行
	int i = 1;

	//上半部分
	for (i; i <= mid; i++) //第一行开始，到中间一行
	{
		//打印每行空格
		int j = 0; 
		for (; j < mid-i; j++) //每行打印 mid - 1 个空格，到中间行时没有空格
			printf(" ");
		//打印 *  ，每行多打印2个
		for (j = 1; j < i * 2; j++)
			printf("*");
		//换行
		printf("\n");
	}

	//下半部分
	for (i = mid - 1; i > 0 ; i--) //从中间行的下一行开始，到最后一行
	{
		//打印每行空格
		int j = 0;
		for (; j < mid - i; j++) //每行打印 mid - 1 个空格，到中间行时没有空格
			printf(" ");
		//打印 *  ，每行多打印2个
		for (j = 1; j < i * 2; j++)
			printf("*");
		//换行
		printf("\n");
	}
	return 0;
}