#define _CRT_SECURE_NO_WARNINGS 1

//计算汉诺塔步数，递归实现


#include <stdio.h>



int hanoi(int n)
{
	//递归限制
	if (n == 1)
		return 1;  //递推结束开始回归
	return 2*hanoi(n-1)+1; //每一层盘子的数量是  (n-1)*2+1
}

 
int main()
{
	hanoi(5);
	printf("%d ",hanoi(5));
	return 0;
}