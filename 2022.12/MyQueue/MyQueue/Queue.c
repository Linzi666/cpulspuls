#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//初始化
void QueueInto(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}

//创建节点
QueueNode* CreateNode(QDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("malloc faile\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->val = x;
	return newNode;
}

//数据入队
void QueuePush(Queue* q, QDataType x)
{
	//断言
	assert(q);

	//创建节点
	QueueNode* newNode = CreateNode(x);
	//如果head NULL
	if (q->head == NULL)
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		//尾节点指向新节点
		q->tail->next = newNode;
		//尾节点移动位置
		q->tail = newNode;
	}
}

//判断队列是否为空
bool QueueIsEmpty(Queue* q)
{
	return q->head == NULL;
}

//数据出队
void QueuePop(Queue* q)
{
	assert(q);
	//要保证队列里有数据可以删除
	assert(!QueueIsEmpty(q));

	//头删
	QueueNode* next = q->head->next;
	free(q->head);
	q->head = next;
}

//获取队头
QDataType QueueGetFront(Queue* q)
{
	assert(q);
	//要保证队列里有数据
	assert(!QueueIsEmpty(q));
	return q->head->val;
}

//获取队尾
QDataType QueueGetBack(Queue* q)
{
	assert(q);
	//要保证队列里有数据
	assert(!QueueIsEmpty(q));
	return q->tail->val;
}


//获取队列长度
size_t QueueGetSize(Queue* q)
{
	assert(q);
	//要保证队列里有数据
	assert(!QueueIsEmpty(q));
	int len = 1;
	QueueNode* head = q->head;
	QueueNode* tail = q -> tail;
	while (head != tail)
	{
		len++;
		head = head->next;
	}
	return len;
}

//销毁
void QueueDestroy(Queue* q)
{
	QueueNode* cru = q->head;
	while (cru != NULL)
	{
		//存储下一个位置地址
		QueueNode* next = cru->next;
		free(cru);
		cru = next;
	}
	
}