#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//�ж�һ�����Ƿ���������
//һ��nλ��Ȼ���������������λ�����ֵ�n����֮�ͣ���ƴ���Ϊ��������

//��ȡһ������λ��
int get_number(int i)
{
	int index = 1;
	while (i /= 10) //��10 λ�� +1 ��ֱ��0����ѭ��
		index++;
	return index;
}

//��һ������ n �η�
int num_mul(int a, int w)
{
	//a ��Ҫ�����
	//w �� �η�
	int k = 1;
	while (w--)
		k *= a;
	return k;
}

//�ж��Ƿ���������
int num_armstrong(int k)
{
	int w = get_number(k); //��ȡ �������λ��
	int sum = 0; // λ�� �η�����ܺ�
	int k2 = k; // �洢k��ֵ
	int a = 0; // ÿ��λ����
	while (k2)
	{
		a = k2 % 10; // ��ǰ����λ����
		sum += num_mul(a, w); // ������w�η� + sum
		k2 /= 10; //  ��10��ʼ�´�ѭ��
	}
	return sum == k; //���2������ȣ��᷵��1�����򷵻�0
}

int main()
{
	int i = 0;
	int k = 0; //���뷶Χ 
	scanf("%d", &k);
	for (i = 10; i <= k; i++)
	{
		if (num_armstrong(i))
			printf("%d ", i);
	}

	return 0;
}