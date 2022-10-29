#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//判断一个数是否是自幂数
//一个n位自然数等于自身各个数位上数字的n次幂之和，则称此数为自幂数。

//获取一个数的位数
int get_number(int i)
{
	int index = 1;
	while (i /= 10) //除10 位数 +1 ，直到0结束循环
		index++;
	return index;
}

//求一个数的 n 次方
int num_mul(int a, int w)
{
	//a 是要求的数
	//w 是 次方
	int k = 1;
	while (w--)
		k *= a;
	return k;
}

//判断是否是自幂数
int num_armstrong(int k)
{
	int w = get_number(k); //获取 这个数的位数
	int sum = 0; // 位数 次方后的总和
	int k2 = k; // 存储k的值
	int a = 0; // 每个位的数
	while (k2)
	{
		a = k2 % 10; // 当前数个位的数
		sum += num_mul(a, w); // 该数的w次方 + sum
		k2 /= 10; //  除10开始下次循环
	}
	return sum == k; //如果2个数相等，会返回1，否则返回0
}

int main()
{
	int i = 0;
	int k = 0; //输入范围 
	scanf("%d", &k);
	for (i = 10; i <= k; i++)
	{
		if (num_armstrong(i))
			printf("%d ", i);
	}

	return 0;
}