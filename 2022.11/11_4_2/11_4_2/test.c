#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 

//写一个函数返回参数二进制中 1 的个数。

//方法一，遍历32个位
int get_binary(int n)
{
	//获取1的个数
	int i = 0;
	int count = 0; //计数器
	for (i; i < 32; i++)
		if (n & (1 << i)) // 如果表达式为真，说明对应的位是1
			count++;
	return count;
}

//方法二
int get_binary2(int n)
{
	//先转换成无符号整数，因为负数的存储方式不同
	unsigned tep = n;
	int count = 0;
	while (tep)
	{
		if (tep % 2)
			count++;
		tep /= 2;
	}

	return count;
}

//神奇公式  n & (n-1) 
int get_binary3(int n)
{
	int count = 0;
	while (n)
	{
		n = n& (n - 1);
			count++;
	}
	return count;
}


int main()
{
	int num1 = 0;
	int num2 = 0; 
	int count = 0; //记录不同的个数
	scanf("%d %d",&num1,&num2);
	int num3 = num1 ^ num2; // 亦或，相同为 0 ，相异为 1
	count = get_binary(num3);
	printf("方法一:%d\n",count);

	count = get_binary2(num3);
	printf("方法二:%d\n", count);

	count = get_binary3(num3);
	printf("方法三:%d\n", count);
	return 0;
}