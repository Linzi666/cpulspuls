
#include "List.h"

void ListTest1()
{
	LSNode* LS = ListInto();
	ListPushBack(LS, 1);
	ListPushBack(LS, 2);
	ListPushBack(LS, 3);
	ListPushFront(LS, 4);
	ListPushFront(LS, 5);
	ListPushFront(LS, 6);
	ListPopBack(LS);
	ListPrint(LS);
	ListPopBack(LS);
	ListPrint(LS);
}

void ListTest2()
{
	LSNode* LS = ListInto();
	ListPushBack(LS, 1);
	ListPushBack(LS, 2);
	ListPushBack(LS, 3);
	ListPushFront(LS, 4);
	ListPushFront(LS, 5);
	ListPushFront(LS, 6);
	ListPrint(LS);
	ListPopFront(LS);
	ListPrint(LS);
	ListPopFront(LS);
	ListPrint(LS);
}

void ListTest3()
{
	LSNode* LS = ListInto();
	ListPushBack(LS, 1);
	ListPushBack(LS, 2);
	ListPushBack(LS, 3);
	ListPushFront(LS, 4);
	ListPushFront(LS, 5);
	ListPushFront(LS, 6);
	LSNode* pos = ListFindNode(LS, 1);
	if (pos)
	{
		//1前面追加个10
		ListInsert(LS, pos, 10);
		ListPrint(LS);
		pos = ListFindNode(LS, 6);
		//6前面加个60
		ListInsert(LS, pos, 60);
		ListPrint(LS);

	}
}

void ListTest4()
{
	LSNode* LS = ListInto();
	ListPushBack(LS, 1);
	ListPushBack(LS, 2);
	ListPushBack(LS, 3);
	ListPushFront(LS, 4);
	ListPushFront(LS, 5);
	ListPushFront(LS, 6);
	LSNode* pos = ListFindNode(LS, 1);
	if (pos)
	{
		//删除1所在的节点
		ListEase(LS, pos);
		ListPrint(LS);
		pos = ListFindNode(LS, 6);
		//删除6
		ListEase(LS, pos);
		ListPrint(LS);

	}
	ListDestroy(&LS);
	if (LS == NULL)
	{
		printf("销毁成功\n");
	}
}

int main()
{
	//ListTest1();
	//ListTest2();
	//ListTest3();
	ListTest4();
	return 0;
}