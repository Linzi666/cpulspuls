#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include<time.h>

void PrintTopK(int* data, int len, int k)
{
	//建立一个堆
	HP hp;
	HeapInit(&hp);
	//插入K个数据
	for (int i = 0; i < k; i++)
	{
		HeapPush(&hp, data[i]);
	}
	//随后进行比较，是否比栈顶元素大
	for (int i = k; i < len; i++)
	{
		//大堆
		if (data[i] < HeapTop(&hp))
		//小堆
		//if (data[i] > HeapTop(&hp))
		{
			//交换位置
			//把堆顶元素删掉
			HeapPop(&hp);
			//Push新数据
			HeapPush(&hp, data[i]);	
		}
	}

	HeapPrint(&hp);
}

void TopKTest()
{
	int n = 50000;
	//开辟1万个数组 的空间
	int* a = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 1000000+10; 
	}
	int k = 10;
	//给上10个最大值
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
	//给10个最小值
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