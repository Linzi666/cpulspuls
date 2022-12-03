#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


//void test1()
//{
//	SLNode* SL = NULL;
//	SListPushBack(&SL,1);
//	SListPushBack(&SL, 2);
//	SListPushBack(&SL, 3);
//	SListPrint(SL);
//	SListPushFront(&SL, 10);
//	SListPushFront(&SL, 20);
//	SListPushFront(&SL, 30);
//	SListPushFront(&SL, 30);
//	SListPrint(SL);
//	SListPopBack(&SL);
//	SListPopBack(&SL);
//	SListPopBack(&SL);
//
//	SListPrint(SL);
//}
//
//void test2()
//{
//	SLNode* SL = NULL;
//	SListPushFront(&SL, 10);
//	//SListPushFront(&SL, 20);
//	//SListPushFront(&SL, 30);
//	//SListPopFront(&SL);
//	SListPrint(SL);
//
//	SLNode* pos = SListFindNode(SL, 10);
//	if (pos)
//	{
//		SListInsert(&SL,pos,50);
//		SListPrint(SL);
//
//	}
//
//	pos = SListFindNode(SL, 50);
//	SListInsert(&SL, pos, 500);
//	SListPrint(SL);
//
//}
//
//void test3()
//{
//	SLNode* SL = NULL;
//	SListPushFront(&SL, 10);
//	SListPushFront(&SL, 20);
//	SListPushFront(&SL, 30);
//	SListPrint(SL);
//
//	SLNode* pos = SListFindNode(SL, 10);
//	if (pos)
//	{
//		SListEase(&SL, pos);
//	    pos = SListFindNode(SL, 20);
//		SListEase(&SL, pos);
//		pos = SListFindNode(SL, 30);
//		SListEase(&SL, pos);
//		SListPrint(SL);
//	}
//
//}

enum Option
{
	EXIT,
	PushFront,
	PushBack,
	PopFront,
	PopBack,
	FIND,
	PRINT,
	Insert,
	EASE
};

void Menu()
{
	printf("**********************************\n");
	printf("****   1.头插       2.尾插     ****\n");
	printf("****   3.头删       4.尾删     ****\n");
	printf("****   5.查找       6.打印     ****\n");
	printf("****   7.指定插入   8.指定删除  ****\n");
	printf("**********************************\n");
}

int getInput()
{
	printf("请输入值->");
	int input = 0;
	scanf("%d",&input);
	return input;
}

void InsterFun(SLNode** pphead)
{
		int site = 0;
		int x = 0;
		printf("请输入要插入的位置(插在该数的前面):->");
		scanf("%d", &site);
		printf("请输入要插入的值:->");
		scanf("%d", &x);
		SLNode* pos = SListFindNode(*pphead, site);
		if (pos == NULL)
		{
			printf("输入的值不在列表中\n");
		}
		else
		{
			printf("%d成功插入%d的前面\n",x,site);
			SListInsert(pphead, pos, x);
		}

}

void ListTest()
{
	int input = 0;
	SLNode* SL = NULL;
	do
	{
		Menu();
		printf("输入操作->");
		scanf("%d",&input);

		switch (input)
		{
		case EXIT:
			SListDestory(&SL);
			printf("退出成功\n");
			break;
		case PushFront:
			SListPushFront(&SL, getInput());
			break;
		case PushBack:
			SListPushBack(&SL, getInput());
			break;
		case PopFront:
			SListPopFront(&SL);
			break;
		case PopBack:
			SListPopBack(&SL);
			break;
		case FIND:
			if (SListFindNode(SL, getInput()))
			{
				printf("找到了\n");
			}
			else
			{
				printf("该值不存在\n");
			}
			break;
		case PRINT:
			SListPrint(SL);
			break;
		case Insert:
			InsterFun(&SL);
			break;
		case EASE:
			SListEase(&SL, SListFindNode(SL, getInput()));
			break;
		default:
			printf("输入有误重新输入\n");
			break;
		}

	} while (input);
}



int main()
{
	//test1();
	//test2();
	//test3();
	ListTest();
	return 0;
}