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

//向上调整
void AdjustUp(HP* hp, int child)
{
	//至少比较一次
	do
	{
		int parent = (child - 1) / 2;
		//如果父亲小于孩子
		if (hp->data[parent] < hp->data[child])
		{
			//交换
			HeapDataType tmp = hp->data[child];
			hp->data[child] = hp->data[parent];
			hp->data[parent] = tmp;

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
	AdjustUp(hp, hp->sz - 1);
}


void HeapPop(HP* hp)
{
	assert(hp);
	hp->sz--;
}

void HeapPrint(HP* hp)
{
	for (int i = 0; i < hp->sz; i++)
		printf("%d ", hp->data[i]);
	printf("\n");
}