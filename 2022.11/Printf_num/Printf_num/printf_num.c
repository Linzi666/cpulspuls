#define _CRT_SECURE_NO_WARNINGS 1


//��ӡһ������ÿһλ �ݹ�ʵ��

#include <stdio.h>

void Printf(int num)
{
	//�ݹ��������������λ�� С�� 9 ���������
	if (num > 9) //�ݹ���������
		Printf(num/10); //�ݹ� �����仯
		
	printf("%d ",num%10); //��ӡ��λ�� 
}

int main()
{
	int num = 0; //Ҫ��ӡ����
	scanf("%d",&num);
	Printf(num); //�����޷���ֵ������ num

	return 0;
}

