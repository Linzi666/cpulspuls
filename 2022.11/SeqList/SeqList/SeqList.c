#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//初始化顺序表
void SeqListInit(SL* pSL)
{
	assert(pSL);
	//容积和数据个数置为0
	pSL->capacity = pSL->size = 0;

	pSL->data = NULL;
}

//释放内存
void SeqListDestory(SL* pSL)
{
	free(pSL->data);
	pSL = NULL;
}

//打印顺序表
void SqeListPrint(SL* pSL) {
	for (int i = 0; i < pSL->size; i++)
	{
		printf("%d ",*(pSL->data+i));
	}
	printf("\n");
}

//检查数据容量
void static SLCheckCapacity(SL* pSL)
{
	if (pSL->size == pSL->capacity)
	{
		//数组个数和容积相等，扩容一倍
		int newCapacity = pSL->capacity == 0 ? 4 : 2 * pSL->capacity;
		pSL->capacity = newCapacity;
		//开辟或扩容空间
		SLDataType* tmp = (SLDataType*)realloc(pSL->data,newCapacity * sizeof(SLDataType));

		//空间开辟失败
		if (tmp == NULL)
		{
			perror("SLCheckCapacity::realloc");
			exit(-1);//干掉程序
		}

		//开辟成功
		pSL->data = tmp;
	}

}

//尾部插入数据
void SeqListPushBack(SL* pSL,int x)
{
	//首先检查容量
	//SLCheckCapacity(pSL);
	//
	////size位置插入数据
	//*(pSL->data + pSL->size) = x;
	//pSL->size++;
	SeqListPushSet(pSL, pSL->size, x);
}

//头部插入数据
void SeqListPushFtont(SL* pSL, int x)
{
	//检查容量
	//SLCheckCapacity(pSL);

	////第二个数到最后一个数全部往后移动一格
	//int i = pSL->size;
	//while (i--)
	//{
	//	*(pSL->data + i + 1) = *(pSL->data + i);
	//}
	//pSL->data[0] = x;
	//pSL->size++;
	SeqListPushSet(pSL, 0,x);

}


//尾部删除数据
void SeqListMoveBack(SL* pSL)
{
	/*if (pSL->size > 0)
		pSL->size--;*/
	 SeqListMoveSet( pSL, pSL->size - 1);
}

//头部删除数据
void SeqListMoveFront(SL* pSL)
{
	//size为0不能删除数据
	//if (pSL->size <= 0)
	//	return;

	////删除头部数据，从第二个数据依次前移
	//int begin = 1;
	//while (begin < pSL->size)
	//{
	//	*(pSL->data + begin - 1) = *(pSL->data + begin);
	//	begin++;
	//}
	//pSL->size--;
	//直接调用指定位置删除数据函数
	SeqListMoveSet(pSL,0);
}

//指定位置删除数据
void SeqListMoveSet(SL* pSL, int pos)
{
	//判断 pos 是否比size大且索引不能为负数
	if ((pSL->size - 1 < pos) || pos < 0)
	{
		printf("pos no exit\n");
		return;
	}
	//删除数据，只需要把 pos 后面的位置前移
	int begin = pos+1;
	while (begin < pSL->size)
	{
		*(pSL->data + begin - 1) = *(pSL->data + begin) ;
		begin++;
	}
	pSL->size--;

}

//指定位置插入数据
void SeqListPushSet(SL* pSL, int pos, int x)
{
	//判断 pos 是否比size大1以上且索引不能为负数
	if ((pSL->size < pos) || pos < 0)
	{
		printf("pos no exit\n");
		return;
	}

	//检查容量
	SLCheckCapacity(pSL);

	//把pos 后面的全部往后移动一格
	for (int i = pSL->size - 1 ; i >= pos ; i--)
	{
		*(pSL->data + i + 1) = *(pSL->data + i);
	}
	//插入x
	*(pSL->data + pos) = x;

	pSL->size++;
}


int SeqListFind(SL* pSL, SLDataType x)
{
	int i = 0;
	for (i = 0; i < pSL->size; i++)
	{
		if (pSL->data[i] == x)
			return i;
	}

	return -1;
}