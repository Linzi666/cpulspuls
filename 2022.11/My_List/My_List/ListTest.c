#define _CRT_SECURE_NO_WARNINGS 1


#include "SList.h"

void test1()
{
	SLNode* SL = NULL;
	SListPushBack(&SL,1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SListPopBack(&SL);
	SListPopBack(&SL);
	SListPopBack(&SL);
	SListPushFront(&SL, 10);
	SListPushFront(&SL, 20);
	SListPushFront(&SL, 30);
	SListPrint(SL);

}

void test2()
{
	SLNode* SL = NULL;
	SListPushBack(&SL, 1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SListPrint(SL);
	SListPopFront(&SL);
	SListPrint(SL);

}

void test3()
{
	SLNode* SL = NULL;
	SListPushBack(&SL, 1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SLNode* pos = SListFindNode(SL,1);
	if (pos != NULL)
	{
		//1前面插入20
		SListInsert(&SL, pos, 20);
		//20前面插入30
		pos = SListFindNode(SL, 20);
		SListInsert(&SL, pos, 30);
		//30前面插入40
		pos = SListFindNode(SL, 30);
		SListInsert(&SL, pos, 40);
	}
	else
	{
		printf("没找到\n");
	}
	SListPrint(SL);
}


void test4()
{
	SLNode* SL = NULL;
	SListPushBack(&SL, 1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SListPushBack(&SL, 4);
	SListPushBack(&SL, 5);
	SListPushBack(&SL, 6);
	SLNode* pos = SListFindNode(SL, 3);
	SListPrint(SL);
	if (pos != NULL)
	{
		//删除节点3
		SListEase(&SL, pos);
		SListPrint(SL);
		//删除节点4
		pos = SListFindNode(SL, 4);
		SListEase(&SL, pos);
		SListPrint(SL);
		//删除节点5
		pos = SListFindNode(SL, 5);
		SListEase(&SL, pos);
		SListPrint(SL);
		//删除头节点 1
		pos = SListFindNode(SL, 1);
		SListEase(&SL, pos);
		SListPrint(SL);
		//删除头节点2
		pos = SListFindNode(SL, 2);
		SListEase(&SL, pos);
		SListPrint(SL);
		//删除头节点6
		pos = SListFindNode(SL, 6);
		SListEase(&SL, pos);
		SListPrint(SL);
	}


}

void test5()
{
	SLNode* SL = NULL;
	SListPushBack(&SL, 1);
	SListPushBack(&SL, 2);
	SListPushBack(&SL, 3);
	SListPushBack(&SL, 4);
	SListPushBack(&SL, 5);
	SListPushBack(&SL, 6);
	printf("节点销毁前:\n");
	SListPrint(SL);
	SListDestroy(&SL);
	printf("节点销毁后:\n");
	SListPrint(SL);




}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4()
	test5();
	return 0;
}