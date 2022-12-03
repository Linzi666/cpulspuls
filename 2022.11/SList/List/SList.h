#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//数据类型
typedef int DataType;

//节点结构体创建

typedef struct SListNode
{
	//值
	DataType data;
	//指向下一个节点的指针
	struct SListNode* next;
}SLNode;


//函数实现
//链表打印
void SListPrint(SLNode* phead);

//尾插
void SListPushBack(SLNode** pphead,DataType x);

//节点头插
void SListPushFront(SLNode** pphead, DataType x);

//节点尾删
void SListPopBack(SLNode** pphead);

//节点头删
void SListPopFront(SLNode** pphead);

//查找节点
SLNode* SListFindNode(SLNode* phead,DataType x);

//指定位置插入数据
void SListInsert(SLNode** pphead,SLNode* pos,DataType x);

//删除指定节点
void SListEase(SLNode** pphead, SLNode* pos);

//销毁链表
void SListDestory(SLNode** pphead);


