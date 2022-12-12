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

//�������
void CheckCacpcity(HP* hp)
{
	if (hp->Cacpcity == hp->sz)
	{
		//����
		size_t newCacpcity = hp->Cacpcity == 0 ? 4 : 2 * hp->Cacpcity;
		//����
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

//���ϵ���
void AdjustUp(HeapDataType* data, int child)
{
	//���ٱȽ�һ��
	do
	{
		int parent = (child - 1) / 2;
		//���
		//if (data[parent] < data[child])
		//С��
		if (data[parent] > data[child])
		{
			//����
			Swap(&data[parent],&data[child]);
			//����child
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
	//���ж������Ƿ���
	CheckCacpcity(hp);
	//��������
	hp->data[hp->sz] = x;
	hp->sz++;
	//���ϵ���
	AdjustUp(hp->data, hp->sz - 1);
}

//���µ���
void AdjustDown(HeapDataType* data, int n , int parent)
{
	//�������ӽڵ�
	int child = parent * 2 + 1;
	
	while (child < n)
	{
		//���
		if (child+1 < n && data[child + 1] > data[child])
		//С��
		//if (child + 1 < n && data[child + 1] < data[child])
		{
			child++;
		}
		//Ȼ��͸���Ԫ�Ƚ�
		//���
		if (data[child] > data[parent])
		//С��
		//if ( data[child] < data[parent] )
		{
			//λ�ý���
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
	//����λ��
	Swap(&hp->data[0], &hp->data[hp->sz - 1]);
	//Ȼ���Ƴ��ѵ�Ԫ��
	hp->sz--;
	//Ȼ�����µ���
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

