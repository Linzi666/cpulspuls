#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩

//�ǵݹ�
int a(n)
{
	int avg = 1;
	for (int i = 1; i <= n; i++)
	{
		avg *= i;
	}
	return avg;
}

//�ݹ���׳�
int b(n)
{
	if (n == 1)
		return 1;
	else
		return n * (n - 1);
}


int main()
{
	int n = 0;
	scanf("%d",&n);
	//�ǵݹ���׳�
	int ret1 = a(n);
	printf("�ǵݹ�׳�: %d \n",ret1);
	//�ݹ���׳�
	int ret2 = b(n);
	printf("�ݹ�׳�: %d \n", ret1);

	return 0;
}