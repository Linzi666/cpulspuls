#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//创建节点
SLNode* SListCreateNode(ListDataType x)
{
	//新开辟一个节点
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
	{
		//空间开辟失败
		printf("SListPushBack::newNode");
		exit(-1);
	}

	//新节点指向NULL，存储数据x
	newNode->data = x;
	newNode->Next = NULL; 
	return newNode;
}

//尾部数据插入
void SListPushBack(SLNode** phead, ListDataType x)
{
	
	SLNode* newNode = SListCreateNode(x);

	if (*phead == NULL)
	{
		//当前链表为空，那么我直接让新节点替代phead
		*phead = newNode;
		return;
	}

	//找到最后一个节点
	SLNode* cru = *phead;

	//如果cru指向NULL，说明cru是最后一个节点
	while (cru->Next != NULL)
	{
		cru = cru->Next;
	}
	//cru 指向新节点
	cru->Next = newNode; 
}

//链表打印
void SListPrint(SLNode* head)
{
	SLNode* cru = head;
	while (cru)
	{
		printf("%d->",cru->data);
		cru = cru->Next;
	}
	printf("NULL\n");
}


//头部数据插入
void SListPushFront(SLNode** phead, ListDataType x)
{
	//新建节点
	SLNode* newNode = SListCreateNode(x);

	//让节点指向头
	newNode->Next = *phead;
	//头节点更替为新节点
	*phead = newNode;
	
}

//尾部数据删除
void SListPopBack(SLNode** phead)
{
	//链表为空无法删除
	assert(*phead);

	//只有一个节点时
	if((*phead)->Next == NULL)
	{ 
		//释放头空间
		free(*phead);
		//置为空指针
		*phead = NULL;
		return;
	}

	SLNode* cru = *phead; //最后一个节点
	SLNode* prve = NULL; //前一个节点

	//找到最后一个节点
	while (cru->Next)
	{
		prve = cru;
		cru = cru->Next;
	}
	//cru 为最后一个节点。释放掉
	free(cru);
	//前一个节点指向空
	prve->Next = NULL;

}


//头部数据删除
void SListPopFront(SLNode** phead)
{
	//断言
	assert(*phead);

	//链表不为空，存储下一个位置的地址
	SLNode* NextNode = (*phead)->Next;
	//释放 *phead 
	free(*phead);
	//存储的节点给*phead
	*phead = NextNode;

}

SLNode* SListFindNode(SLNode* head, ListDataType x)
{
	SLNode* cru = head;
	//查找值
	while (cru)
	{
		//如果当前节点等于要查找的值
		if (cru->data == x)
		{
			//返回当前节点，也可以返回下标，把函数返回值改成int
			return cru;
		}
		//下一个节点
		cru = cru->Next;
	}

	//遍历完没有找到， 返回空指针
	return NULL;
}

//指定插入
void SListInsert(SLNode** phead, SLNode* pos, ListDataType x)
{
	//首先插入之前，我们必须保证被插入的pos节点存在，不然无法插入
	assert(pos);

	//头节点就是pos
	if (*phead == pos)
	{
		//调用头插
		SListPushFront(phead,x);
		return 0;
	}
	
	SLNode* cru = *phead; //用来查找被插入的节点

	//查找pos节点
	while (cru->Next != pos)
	{
		cru = cru->Next;
	}

	//找到后，创建一个新节点
	SLNode* newNode = SListCreateNode(x);
	//新节点指向pos
	newNode->Next = pos;
	//pos的前一个节点指向cru
	cru->Next = newNode;
}


//指定节点删除
void SListEase(SLNode** phead, SLNode* pos)
{
	//pos是空指针，干掉程序
	assert(pos);

	//如果头节点与pos相等，直接调用头删
	if (*phead == pos)
	{
		SListPopFront(phead);
		return;
	}

	//创建一个节点
	SLNode* cru = *phead;  //查找被删除节点的前一个节点
	while (cru->Next != pos)
	{
		cru = cru->Next;
	}
	
	//cru指向 pos 后的位置
	cru->Next = pos->Next;

	//释放pos所在空间
	free(pos);
	pos = NULL;

}


//销毁链表
void SListDestroy(SLNode** phead)
{
	SLNode* cru = NULL;

	while (*phead)
	{
		//存储下一个节点的地址
		cru = (*phead)->Next;
		//释放当前空间
		free(*phead);
		//当前地址置空
		*phead = NULL;
		//换成下一个节点继续
		*phead = cru;
	}

}


