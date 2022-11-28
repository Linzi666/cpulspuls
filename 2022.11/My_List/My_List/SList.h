#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListDataType;

typedef struct SListNode
{
	ListDataType  data;
	struct SListNode* Next;

}SLNode;



//尾部数据插入
void SListPushBack(SLNode** phead, ListDataType x);

//链表打印
void SListPrint(SLNode* head);

//头部数据插入
void SListPushFront(SLNode** phead, ListDataType x);

//尾部数据删除
void SListPopBack(SLNode** phead);

//头部数据删除
void SListPopFront(SLNode** phead);


//查找节点
SLNode* SListFindNode(SLNode* head, ListDataType x);

//指定插入
void SListInsert(SLNode** phead,SLNode* pos, ListDataType x);

//指定节点删除
void SListEase(SLNode** phead, SLNode* pos);

//销毁链表
void SListDestroy(SLNode** phead);


