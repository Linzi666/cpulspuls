#define _CRT_SECURE_NO_WARNINGS 1

//递归实现 n 的 k 次方

#include <stdio.h>
double power(int n,int k)
{
	 //第一种情况， k = 0 

	if (k == 0)
		return 1;
	//第二种情况，k>0
	else if (k > 0)
		return n * power(n, k-1);
	//第三种情况，k, < 0
	else
		return 1.0 * power(n, -k);
}

int main()
{
	int n = 0; //n
	int k = 0; // k 次方
	scanf("%d %d",&n,&k); // 分别输入 n 和 k 次方
	double ret = power(n,k);
	printf("%d 的 %d 次方 : %lf",n,k,ret);

	return 0;
}