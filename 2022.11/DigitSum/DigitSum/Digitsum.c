#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int digit_sum(int num)
{
	//�ݹ���������,���� num < 9ʱ
	if (num < 9)
		return num; //���ֻʣһλ��ʱ������������ֵ
	else
		return num % 10 + digit_sum(num / 10); //%10 �ǵ�ǰ���ĸ�λ����/10 ���ø�������10

	
}

int main()
{
	int num = 0; //��������ֵ
	scanf("%d",&num);
	int sum = digit_sum(num); // ���շ���ֵ
	printf("%d",sum);
	return 0;
}