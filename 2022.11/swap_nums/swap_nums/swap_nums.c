#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//����������������������ʱ������

//��һ�ַ���

void swap1(int* a, int* b)
{
	*(a) = *(a)+*(b); //a ���� a + b��ֵ
	*(b) = *(a)-*(b);// a���� a + b��ֵ������ ��ʱ a - b = a һ��ʼ��ֵ
	*(a) = *(a)-*(b); // ��ʱ�� a ���� a+b��ֵ�� b �� һ��ʼa��ֵ�����Լ�ȥ�����һ��ʼb��ֵ
}

//�ڶ��ַ���
void swap2(int* a, int* b)
{
	*(a) ^= *(b); // *a �� *a ^ *b
	*(b) ^= *(a); // a ��ʱ�� a ��b �����ֵ�����������b��b���� a ��
	*(a) ^= *(b); //a ���� a �� b �����ֵ������ b ��һ��ʼa��ֵ���������� a ��һ��ʼb��ֵ

}

int main()
{
	int a = 10;
	int b = 20;
	printf("����ǰ\n");
	printf("a = %d\n",a);
	printf("b = %d\n", b);

	//swap1(&a, &b);
	swap2(&a, &b);

	printf("������\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}