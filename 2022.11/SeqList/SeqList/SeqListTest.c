#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void test1()
{
	SL sl;
	SeqListInit(&sl);


	////β���������ݲ���
	SeqListPushBack(&sl,1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SqeListPrint(&sl);
	//ͷ���������ݲ���
	SeqListPushFtont(&sl,30);
	SeqListPushFtont(&sl, 20);
	SeqListPushFtont(&sl, 10);
	SqeListPrint(&sl);
	//β��ɾ�����ݲ���
	SeqListMoveBack(&sl);
	SeqListMoveBack(&sl);
	SeqListMoveBack(&sl);
	SqeListPrint(&sl);
	//ɾ��ͷ�����ݲ���
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
	//ָ��λ��ɾ��
//	SeqListMoveSet(&sl, 1);
	SqeListPrint(&sl);
	//ָ��λ�ò���
	SeqListPushSet(&sl,3,100);
	//SeqListPushSet(&sl, 5, 1000);
	SeqListPushSet(&sl, 0, 200);
	SqeListPrint(&sl);
	SeqListDestory(&sl);

}

void test3()
{
	//ͷ����������
	SL sl;
	SeqListInit(&sl);
	SeqListPushFtont(&sl, 30);
	SeqListPushFtont(&sl, 20);
	SeqListPushFtont(&sl, 10);
	SqeListPrint(&sl);
	//β����������
	SeqListPushBack(&sl, 40);
	SeqListPushBack(&sl, 50);
	SqeListPrint(&sl);
	//ͷ��ɾ������
	SeqListMoveFront(&sl);
	SeqListMoveFront(&sl);
	SqeListPrint(&sl);

	//40ǰ�����һ��35
	int pos = SeqListFind(&sl,40);
	SeqListPushSet(&sl,pos,35);
	SqeListPrint(&sl);
	//ɾ��40
	 pos = SeqListFind(&sl, 40);
	SeqListMoveSet(&sl, pos);
	SqeListPrint(&sl);


	//β��ɾ������
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