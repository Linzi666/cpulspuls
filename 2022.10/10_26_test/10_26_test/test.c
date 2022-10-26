#define _CRT_SECURE_NO_WARNINGS 1

//求2个数的最大公因数和最小公倍数
#include<stdio.h>

int main()
{
	//最大公因数，辗转相除法
	int num1 = 0;
	int num2 = 0;
	int k = 0; //用于存放 num2的值
	printf("请输入两个数\n");
	scanf("%d%d",&num1,&num2);
	int n = num1;
	int m = num2; //存储输入的两个值
	while (k = num1 % num2)
	{
		num1 = num2;  //把 num2的值给num1
		num2 = k;  // 把 num1 和 num2之间的 余数给 num2
	}
	printf("最大公因数是:%d\n",num2);//num2就是2个数的最大公因数

	//最小公倍数， num1 * num2 / 两个数的最大公因数 ，就是这个数的最小公倍数
	printf("最小公倍数是:%d",n*m/num2);


	return 0;
}