#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
//�� 1-10000��ˮ�ɻ���

//����һ������λ��
int A(int n)
{
	int count = 1;
	while (n /= 10)count++;
	return count;
}

//�ж�һ�����Ƿ���������
int B(int n)
{
	int n2 = n;
	int sz = A(n);
	int sum = 0;
	while (n2)
	{
		sum += pow(n2 % 10, sz);
		n2 /= 10;
	}
	return sum == n ? 1 : 0;
}

//��������
int main()
{
	//1-10000��������
	for (int i = 1; i <= 10000; i++)
	{
		if (B(i))
			printf("%d ",i);
	}
	return 0;
}