#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include<time.h>


//TopK
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

//������ ��ʽһ
void Heap_Sort1(int* data,int n)
{
	assert(data);

	//��С��
	HP hp;
	HeapInit(&hp);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		//����push
		HeapPush(&hp,data[i]);
	}

	int* tmp = data;
	//ȡÿ�ζѶ�Ԫ��
	while (!HeapEmpty(&hp))
	{
		//ȡ�Ѷ�
		HeapDataType top = HeapTop(&hp);
		//��������
		*tmp = top;
		tmp++;
		//�Ƴ��Ѷ�
		HeapPop(&hp);
	}

}

void Heap_Sort2(int* data, int n)
{
	assert(data);
	//�����鹹���ɶ�
	int TailFather = (n - 1 - 1) / 2; //���һ������
	while (TailFather >= 0)
	{
		//���µ���
		AdjustDown(data,n,TailFather);
		TailFather--;
	}

	//���һ��Ԫ��
	int end = n - 1;
	while (end >= 0)
	{
		//����λ��
		Swap(&data[0], &data[end]);
		//����ȡ��
		AdjustDown(data, end, 0);
		end--;
	}

}

int main()
{
	int arr[] = {20,60,50,70,40,10};
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d ", arr[i]);
	printf("\n");

	Heap_Sort2(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}