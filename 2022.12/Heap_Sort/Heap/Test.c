#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"
#include<time.h>


//TopK
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

//堆排序 方式一
void Heap_Sort1(int* data,int n)
{
	assert(data);

	//建小堆
	HP hp;
	HeapInit(&hp);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		//依次push
		HeapPush(&hp,data[i]);
	}

	int* tmp = data;
	//取每次堆顶元素
	while (!HeapEmpty(&hp))
	{
		//取堆顶
		HeapDataType top = HeapTop(&hp);
		//放入数组
		*tmp = top;
		tmp++;
		//移除堆顶
		HeapPop(&hp);
	}

}

void Heap_Sort2(int* data, int n)
{
	assert(data);
	//把数组构建成堆
	int TailFather = (n - 1 - 1) / 2; //最后一个父亲
	while (TailFather >= 0)
	{
		//向下调整
		AdjustDown(data,n,TailFather);
		TailFather--;
	}

	//最后一个元素
	int end = n - 1;
	while (end >= 0)
	{
		//交换位置
		Swap(&data[0], &data[end]);
		//向下取整
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