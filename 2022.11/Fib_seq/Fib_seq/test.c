#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//�ݹ�ͷǵݹ� �� 쳲��������� 

//�ǵݹ鷽ʽ
int a(int n)
{
	//
	int i = 0;
	int num1 = 1; // ��һ��
	int num2 = 1; // �ڶ���
	int num3 = 1;//������
	for (int i = 3; i <= n; i++) //�ӵ�2�ʼ
	{
		//ֵ����
		num3 = num2 + num1;
		num1 = num2;
		num2 = num3;
	}
	return num3;
}

//�ݹ鷽��
int b(int n)
{
	// k1 ��һ������k2���ڶ�����

	if (n<3) //��������
	{
		return 1;
	}
	else
		return  b(n-1) + b(n-2);

}

int main()
{
	int n = 0;
	scanf("%d",&n);
	//�ǵݹ鷽��
	if (n > 0)
	{
		int ret = a(n);
		printf("�ǵݹ鷽�� : %d\n", ret);

		//�ݹ鷽��
		int ret2 = b(n, 1, 1);
		printf("�ݹ鷽�� : %d\n", ret2);
	}

	return 0;
}