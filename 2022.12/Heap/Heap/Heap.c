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

//���ϵ���
void AdjustUp(HP* hp, int child)
{
	//���ٱȽ�һ��
	do
	{
		int parent = (child - 1) / 2;
		//�������С�ں���
		if (hp->data[parent] < hp->data[child])
		{
			//����
			HeapDataType tmp = hp->data[child];
			hp->data[child] = hp->data[parent];
			hp->data[parent] = tmp;

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