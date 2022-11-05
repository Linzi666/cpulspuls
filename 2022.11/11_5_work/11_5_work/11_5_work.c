#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
int main()
{
	// 2 + 22 + 222 + 2222
	// 2 *10 + 2 ,22*10+2,222*10+2
	int num = 0;

	scanf("%d",&num);
	int sum = num;
	for (int i = 1; i < 5; i++)
	{
		num = num * 10 +2;
		sum += num;
	}
	printf("%d",sum);

	return 0;
}

