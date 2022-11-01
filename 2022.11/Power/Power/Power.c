#define _CRT_SECURE_NO_WARNINGS 1

//递归实现 n 的 k 次方

#include <stdio.h>
int power(int n,int k)
{
	if (k != 0) //递归限制条件
	{
		k--; //递归条件变化
		return n * power(n, k); 
	}
	else
		return 1;		
}

int main()
{
	int n = 0; //n
	int k = 0; // k 次方
	scanf("%d %d",&n,&k); // 分别输入 n 和 k 次方
	int ret = power(n,k);
	printf("%d 的 %d 次方 : %d",n,k,ret);

	return 0;
}