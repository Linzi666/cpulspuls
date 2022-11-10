#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 

//дһ���������ز����������� 1 �ĸ�����

//����һ������32��λ
int get_binary(int n)
{
	//��ȡ1�ĸ���
	int i = 0;
	int count = 0; //������
	for (i; i < 32; i++)
		if (n & (1 << i)) // ������ʽΪ�棬˵����Ӧ��λ��1
			count++;
	return count;
}

//������
int get_binary2(int n)
{
	//��ת�����޷�����������Ϊ�����Ĵ洢��ʽ��ͬ
	unsigned tep = n;
	int count = 0;
	while (tep)
	{
		if (tep % 2)
			count++;
		tep /= 2;
	}

	return count;
}

//���湫ʽ  n & (n-1) 
int get_binary3(int n)
{
	int count = 0;
	while (n)
	{
		n = n& (n - 1);
			count++;
	}
	return count;
}


int main()
{
	int num1 = 0;
	int num2 = 0; 
	int count = 0; //��¼��ͬ�ĸ���
	scanf("%d %d",&num1,&num2);
	int num3 = num1 ^ num2; // �����ͬΪ 0 ������Ϊ 1
	count = get_binary(num3);
	printf("����һ:%d\n",count);

	count = get_binary2(num3);
	printf("������:%d\n", count);

	count = get_binary3(num3);
	printf("������:%d\n", count);
	return 0;
}