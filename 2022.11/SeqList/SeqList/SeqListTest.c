#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void test1()
{
	SL sl;
	SeqListInit(&sl);


	////尾部插入数据测试
	SeqListPushBack(&sl,1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SqeListPrint(&sl);
	//头部插入数据测试
	SeqListPushFtont(&sl,30);
	SeqListPushFtont(&sl, 20);
	SeqListPushFtont(&sl, 10);
	SqeListPrint(&sl);
	//尾部删除数据测试
	SeqListMoveBack(&sl);
	SeqListMoveBack(&sl);
	SeqListMoveBack(&sl);
	SqeListPrint(&sl);
	//删除头部数据测试
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SeqListPushFtont(&sl, 10);
	SeqListPushFtont(&sl, 10);

	SqeListPrint(&sl);


	SeqListDestory(&sl);

}

void test2()
{
	SL sl;
	SeqListInit(&sl);

	SeqListPushFtont(&sl, 30);
	SeqListPushFtont(&sl, 20);
	SeqListPushFtont(&sl, 10);
	SqeListPrint(&sl);
	//指定位置删除
//	SeqListMoveSet(&sl, 1);
	SqeListPrint(&sl);
	//指定位置插入
	SeqListPushSet(&sl,3,100);
	//SeqListPushSet(&sl, 5, 1000);
	SeqListPushSet(&sl, 0, 200);
	SqeListPrint(&sl);
	SeqListDestory(&sl);

}

void test3()
{
	//头部插入数据
	SL sl;
	SeqListInit(&sl);
	SeqListPushFtont(&sl, 30);
	SeqListPushFtont(&sl, 20);
	SeqListPushFtont(&sl, 10);
	SqeListPrint(&sl);
	//尾部插入数据
	SeqListPushBack(&sl, 40);
	SeqListPushBack(&sl, 50);
	SqeListPrint(&sl);
	//头部删除数据
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SqeListPrint(&sl);

	//40前面插入一个35
	int pos = SeqListFind(&sl,40);
	SeqListPushSet(&sl,pos,35);
	SqeListPrint(&sl);
	//删除40
	 pos = SeqListFind(&sl, 40);
	SeqListMoveSet(&sl, pos);
	SqeListPrint(&sl);


	//尾部删除数据
	SeqListMoveBack(&sl);
	SeqListMoveBack(&sl);
	SqeListPrint(&sl);

	SeqListDestory(&sl);
}


int main()
{
	//test1();
	//test2();	
	test3();
	return 0;

}