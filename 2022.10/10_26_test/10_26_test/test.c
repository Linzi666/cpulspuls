#define _CRT_SECURE_NO_WARNINGS 1

//��2�����������������С������
#include<stdio.h>

int main()
{
	//���������շת�����
	int num1 = 0;
	int num2 = 0;
	int k = 0; //���ڴ�� num2��ֵ
	printf("������������\n");
	scanf("%d%d",&num1,&num2);
	int n = num1;
	int m = num2; //�洢���������ֵ
	while (k = num1 % num2)
	{
		num1 = num2;  //�� num2��ֵ��num1
		num2 = k;  // �� num1 �� num2֮��� ������ num2
	}
	printf("���������:%d\n",num2);//num2����2�������������

	//��С�������� num1 * num2 / ��������������� ���������������С������
	printf("��С��������:%d",n*m/num2);


	return 0;
}