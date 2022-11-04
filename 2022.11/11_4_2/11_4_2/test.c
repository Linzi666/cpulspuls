#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 

//写一个函数返回参数二进制中 1 的个数。
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


int main()
{
	int num1 = 0;
	int num2 = 0; 
	int count = 0; //记录不同的个数
	scanf("%d %d",&num1,&num2);
	int num3 = num1 ^ num2; // 亦或，相同为 0 ，相异为 1
	int i = 0;
	//for (i = 0; i < 32; i++)
	//{
	//	//求出 num3 右移 & 1
	//	if (num3 & (1<<i))
	//		count++;
	//}
	count = get_binary(num3);

	printf("%d",count);

	return 0;
}