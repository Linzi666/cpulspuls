#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


//开辟节点
SLNode* SLCreateNode(DataType x)
{
	//开辟一个节点
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->data = x;
	newNode->next = NULL;
	if (newNode == NULL)
	{
		printf("SListPushBack::newNode is Null\n");
		exit(-1);
	}
	return newNode;
}


//链表打印
void SListPrint(SLNode* head)
{
	SLNode* cru = head;
	while (cru)
	{
		printf("%d->",cru->data);
		cru = cru->next;
	}
	printf("NULL\n");
}

//链表尾插
void SListPushBack(SLNode** pphead, DataType x )
{
	
	SLNode* newNode  =  SLCreateNode(x);
	SLNode* tail = *pphead;
	
	//如果 头部为空，说明链表没有元素
	if (tail == NULL)
	{
		//链表没有元素。那么把开辟的节点给 pphead 用来当第一个元素
		*pphead = newNode;
		return;
	}

	//判断tail的下一个节点是否为NULL
	while (tail->next)
	{
		// 找到尾部
		tail = tail->next;
	}
	//tail指向的节点为NULL，说明是最后一个节点，让它指向newNode
	tail->next = newNode;
}

//节点头插
void SListPushFront(SLNode** pphead, DataType x)
{
	//创建一个节点
	SLNode* newNode =  SLCreateNode(x);
	
	//新节点指向 头节点
	newNode->next = *pphead;
	//然后把头节点 给 新节点
	*pphead = newNode;

}

//节点尾删
void SListPopBack(SLNode** pphead)
{
	//如果头为空，无法继续删除，粗暴结束程序
	assert(*pphead);

	//如果只有一条数据
	if ((*pphead)->next == NULL)
	{
		//释放头数据
		free(*pphead);
		*pphead = NULL;
		return;
	}

	//找到最后一个节点的地址，释放置空，并且要把它的前一个节点指向的节点置为空指针
	SLNode* end = *pphead; //最后的一个节点
	SLNode* prev = NULL; //倒数第二个节点

	while (end->next)
	{
		//先把最后的节点赋给prev
		prev = end;
		end = end->next;
	}

	//把prev指向的值置空
	prev->next = NULL;
	free(end);
	end = NULL;
}


//节点头删
void SListPopFront(SLNode** pphead)
{
	// 判断第一个节点是否为空
	assert(*pphead);

	//如果指向的值为空
	if ((*pphead) == NULL)
	{
		//直接头节点置空
		free(*pphead);
		*pphead = NULL;
		return;
	}

	SLNode* tmp = (*pphead)->next;
	//释放头节点的空间
	free(*pphead);
	//头节点更替成之前指向的空间
	*pphead = tmp;
}


//查找节点
SLNode* SListFindNode(SLNode* phead, DataType x)
{
	SLNode* cru = phead;

	while (cru)
	{
		if (cru->data == x)
		{
			return cru;
		}
		cru = cru->next;
	}
	return NULL;
}


//指定位置插入数据
void SListInsert(SLNode** pphead, SLNode* pos, DataType x)
{
	assert(pos);
	
	//如果是头插
	if ((*pphead) == pos)
	{
		SListPushFront(pphead,x);
		return;
	}
	else
	{

		//如果不是头插	
		//获取一个节点
		SLNode* newNode = SLCreateNode(x);

		//找到pos节点的前一个节点
		SLNode* cru = *pphead;
		while (cru->next != pos)
		{
			cru = cru->next;
		}
		//前节点指向新节点，新节点指向后节点
		cru->next = newNode;
		newNode->next = pos;
	}

}


//删除指定节点
void SListEase(SLNode** pphead, SLNode* pos)
{
	assert(pos);
	
	//判断要删除的节点是否为头节点
	if (pos == (*pphead))
	{
		SListPopFront(pphead);
		return;
	}

	SLNode* cru = *pphead;
	//找到删除节点的前一个位置
	while (cru->next != pos)
	{
		cru = cru->next;
	}
	//让cru指向pos的后一个节点
	cru->next = pos->next;
	//释放pos节点
	free(pos);
	pos = NULL;
}




//销毁链表
void SListDestory(SLNode** pphead)
{
	SLNode* cru = NULL;
	while (*pphead)
	{
		//把下一个位置存储起来
		cru = (*pphead)->next;
		//释放当前空间
		free(*pphead);
		//把下一个位置空间给头
		*pphead = cru;
	}
}
