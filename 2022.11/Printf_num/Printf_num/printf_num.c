#define _CRT_SECURE_NO_WARNINGS 1


//打印一个数的每一位 递归实现

#include <stdio.h>

void Printf(int num)
{
	//递归的限制条件，个位数 小于 9 后结束递推
	if (num > 9) //递归限制条件
		Printf(num/10); //递归 条件变化
		
	printf("%d ",num%10); //打印个位数 
}

int main()
{
	int num = 0; //要打印的数
	scanf("%d",&num);
	Printf(num); //函数无返回值，参数 num

	return 0;
}

