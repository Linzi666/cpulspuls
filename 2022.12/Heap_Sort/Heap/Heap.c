#define _CRT_SECURE_NO_WARNINGS 1


#include "Heap.h"


void HeapInit(HP* hp)
{
	hp->data = NULL;
	hp->sz = hp->Cacpcity = 0;
}


void HeapDestroy(HP* hp)
{
	free(hp->data);
	hp->data = NULL;
	hp->sz = hp->Cacpcity = 0;
}

//检查容量
void CheckCacpcity(HP* hp)
{
	if (hp->Cacpcity == hp->sz)
	{
		//扩容
		size_t newCacpcity = hp->Cacpcity == 0 ? 4 : 2 * hp->Cacpcity;
		//扩容
		HP* newhp = realloc(hp->data, sizeof(HeapDataType) * newCacpcity);
		if (newhp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		hp->data = newhp;
		hp->Cacpcity = newCacpcity;
	}
}

void Swap(int* x,int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整
void AdjustUp(HeapDataType* data, int child)
{
	//至少比较一次
	do
	{
		int parent = (child - 1) / 2;
		//大堆
		//if (data[parent] < data[child])
		//小堆
		if (data[parent] > data[child])
		{
			//交换
			Swap(&data[parent],&data[child]);
			//更新child
			child = parent;
		}
		else
		{
			break;
		}
	} while (child > 0);

}

void HeapPush(HP* hp, HeapDataType x)
{
	assert(hp);
	//先判断容量是否够用
	CheckCacpcity(hp);
	//插入数据
	hp->data[hp->sz] = x;
	hp->sz++;
	//向上调整
	AdjustUp(hp->data, hp->sz - 1);
}

//向下调整
void AdjustDown(HeapDataType* data, int n , int parent)
{
	//定义左孩子节点
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		//大堆
		if (child+1 < n && data[child + 1] > data[child])
		//小堆
		//if (child + 1 < n && data[child + 1] < data[child])
		{
			child++;
		}
		//然后和父亲元比较
		//大堆
		if (data[child] > data[parent])
		//小堆
		//if ( data[child] < data[parent] )
		{
			//位置交换
			Swap(&data[parent], &data[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}

void HeapPop(HP* hp)
{
	assert(hp);
	//交换位置
	Swap(&hp->data[0], &hp->data[hp->sz - 1]);
	//然后移除堆底元素
	hp->sz--;
	//然后向下调整
	AdjustDown(hp->data,hp->sz,0);

}

void HeapPrint(HP* hp)
{
	for (int i = 0; i < hp->sz; i++)
		printf("%d ", hp->data[i]);
	printf("\n");
}


bool HeapEmpty(HP* hp)
{
	assert(hp);
	return hp->sz == 0;
}

HeapDataType HeapTop(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->data[0];
}

HeapDataType HeapBack(HP* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->data[hp->sz-1];
}

