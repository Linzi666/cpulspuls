#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include<time.h>

void PrintTopK(int* data, int len, int k)
{
	//����һ����
	HP hp;
	HeapInit(&hp);
	//����K������
	for (int i = 0; i < k; i++)
	{
		HeapPush(&hp, data[i]);
	}
	//�����бȽϣ��Ƿ��ջ��Ԫ�ش�
	for (int i = k; i < len; i++)
	{
		//���
		if (data[i] < HeapTop(&hp))
		//С��
		//if (data[i] > HeapTop(&hp))
		{
			//����λ��
			//�ѶѶ�Ԫ��ɾ��
			HeapPop(&hp);
			//Push������
			HeapPush(&hp, data[i]);	
		}
	}

	HeapPrint(&hp);
}

void TopKTest()
{
	int n = 50000;
	//����1������� �Ŀռ�
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000+10; 
	}
	int k = 10;
	//����10�����ֵ
	/*a[20009] = 1000000 + 1;
	a[30007] = 1000000 + 2;
	a[20006] = 1000000 + 3;
	a[10008] = 1000000 + 4;
	a[10007] = 1000000 + 5;
	a[16000] = 1000000 + 6;
	a[10005] = 1000000 + 7;
	a[40004] = 1000000 + 8;
	a[30003] = 1000000 + 9;
	a[10001] = 1000000 + 10;*/
	//��10����Сֵ
	a[20009] = 0;
	a[30007] = 1;
	a[20006] = 2;
	a[10008] = 3;
	a[10007] = 4;
	a[16000] = 5;
	a[10005] = 6;
	a[40004] = 7;
	a[30003] = 8;
	a[10001] = 9;

	PrintTopK(a,n,k);
}


int main()
{
	srand(time(NULL));

	TopKTest();
	return 0;
}