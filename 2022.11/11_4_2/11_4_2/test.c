#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 

//дһ���������ز����������� 1 �ĸ�����
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


int main()
{
	int num1 = 0;
	int num2 = 0; 
	int count = 0; //��¼��ͬ�ĸ���
	scanf("%d %d",&num1,&num2);
	int num3 = num1 ^ num2; // �����ͬΪ 0 ������Ϊ 1
	int i = 0;
	//for (i = 0; i < 32; i++)
	//{
	//	//��� num3 ���� & 1
	//	if (num3 & (1<<i))
	//		count++;
	//}
	count = get_binary(num3);

	printf("%d",count);

	return 0;
}