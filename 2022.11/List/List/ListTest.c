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
	printf("****   1.ͷ��       2.β��     ****\n");
	printf("****   3.ͷɾ       4.βɾ     ****\n");
	printf("****   5.����       6.��ӡ     ****\n");
	printf("****   7.ָ������   8.ָ��ɾ��  ****\n");
	printf("**********************************\n");
}

int getInput()
{
	printf("������ֵ->");
	int input = 0;
	scanf("%d",&input);
	return input;
}

void InsterFun(SLNode** pphead)
{
		int site = 0;
		int x = 0;
		printf("������Ҫ�����λ��(���ڸ�����ǰ��):->");
		scanf("%d", &site);
		printf("������Ҫ�����ֵ:->");
		scanf("%d", &x);
		SLNode* pos = SListFindNode(*pphead, site);
		if (pos == NULL)
		{
			printf("�����ֵ�����б���\n");
		}
		else
		{
			printf("%d�ɹ�����%d��ǰ��\n",x,site);
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
		printf("�������->");
		scanf("%d",&input);

		switch (input)
		{
		case EXIT:
			SListDestory(&SL);
			printf("�˳��ɹ�\n");
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
				printf("�ҵ���\n");
			}
			else
			{
				printf("��ֵ������\n");
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
			printf("����������������\n");
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