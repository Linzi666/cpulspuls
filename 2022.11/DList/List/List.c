
#include "List.h"



//链表初始化
LSNode* ListInto()
{
	//创建一个节点
	LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
	//指向自己
	newNode->next = newNode;
	newNode->prve = newNode;
	
	return newNode;
}

//创建节点
LSNode* CreateListNode(ListValType x)
{
	LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
	if (newNode == NULL)
	{
		//空间开辟失败，不玩了
		exit(-1);
	}
	newNode->val = x;
	return newNode;
}

//尾插
void ListPushBack(LSNode* phead, ListValType x)
{
	/*
	//断言，phead不能为空
	assert(phead);

	//创建一个新节点
	LSNode* newNode = CreateListNode(x);
	//记录头节点的前一个节点，也就是尾节点
	LSNode* tail = phead->prve;
	//尾节点指向 新节点
	tail->next = newNode;
	//新节点前节点指向尾节点
	newNode->prve = tail;
	//后节点指向头节点
	newNode->next = phead;
	//头节点前节点指向新节点
	phead->prve = newNode;
	*/
	ListInsert(phead, phead->prve, x);

}

//打印链表
void ListPrint(LSNode* phead)
{
	assert(phead);
	//头节点存放的是无效值，所以从头节点下一个位置开始打印
	LSNode* cru = phead->next;
	//cru == phead时说明链表走了一圈了
	while (cru != phead)
	{
		printf("%d->", cru->val);
		cru = cru->next;
	}
	printf(".....\n");
}


//头插
void ListPushFront(LSNode* phead, ListValType x)
{
	/*
	//断言，phead不能为空
	assert(phead);

	//创建一个新节点
	LSNode* newNode = CreateListNode(x);
	//保存头节点的下一个节点
	LSNode* Next = phead->next;
	//next前节点指向新节点
	Next->prve = newNode;
	//新节点next指向Next
	newNode->next = Next;
	//头节点next指向新节点
	phead->next = newNode;
	//新节点前节点指向头节点
	newNode->prve = phead;
	*/
	ListInsert(phead,phead->next,x);
}

//尾删
void ListPopBack(LSNode* phead)
{
	/*
	//phead不能为空
	assert(phead);
	//尾节点不能头节点一样
	assert(phead != phead->prve);
	
	//尾节点
	LSNode* tail = phead->prve;
	//尾节点的前一个节点
	LSNode* prvetail = tail->prve;
	//释放尾节点
	free(tail);
	//prvetail 连接 头节点
	prvetail->next = phead;
	phead->prve = prvetail;
	*/

	ListEase(phead, phead->prve);
}

//头删
void ListPopFront(LSNode* phead)
{
	/*
	assert(phead);
	assert(phead != phead->prve);

	//头节点的下一个节点
	LSNode* headNext = phead->next;
	//下下个节点
	LSNode* nextnext = headNext->next;
	//连接头节点和 nextnext
	nextnext->prve = phead;
	phead->next = nextnext;

	//释放headNext
	free(headNext);
	headNext = NULL;
	*/
	ListEase(phead, phead->next);
}



//查找
LSNode* ListFindNode(LSNode* phead, ListValType x)
{
	assert(phead);
	//头节点存放的是无效值，所以从头节点下一个位置开始查找
	LSNode* cru = phead->next;
	//cru == phead时说明链表走了一圈了
	while (cru != phead)
	{
		if (cru->val == x)
			return cru;

		cru = cru->next;
	}
	return NULL;
}

//指定插入
void ListInsert(LSNode* phead, LSNode* pos, ListValType x)
{
	//pos和phead不能为空
	assert(pos && phead);
	
	//创建节点
	LSNode* newNode = CreateListNode(x);

	//保存pos的前一个节点
	LSNode* posprve = pos->prve;
	//然后连接起来
	posprve->next = newNode;
	newNode->prve = posprve;
	newNode->next = pos;
	pos->prve = newNode;
}

//指定删除
void ListEase(LSNode* phead, LSNode* pos)
{
	//pos和phead不能为空
	assert(pos && phead);

	//保存pos前后节点
	LSNode* posprve = pos->prve;
	LSNode* posnext = pos->next;

	//前后节点连接
	posprve->next = posnext;
	posnext->prve = posprve;

	//释放pos空间
	free(pos);
	pos = NULL;
}


//销毁链表,因为会改变原来的phead节点，所以需要传二级指针
void ListDestroy(LSNode** pphead)
{
	assert(*pphead);
	
	LSNode* cru = (*pphead)->next;
	while (1)
	{
		//保存后一个节点
		LSNode* next = cru->next;
		//释放cru
		free(cru);
		//迭代
		cru = next;
		//如果cru 和头节点相等，说明头节点后面的都删完了
		if (cru == *pphead)
		{
			//释放头节点空间
			free(*pphead);
			//指针置空
			*pphead = NULL;
			//跳出循环
			break;	
		}
	}

}