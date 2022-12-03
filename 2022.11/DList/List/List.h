#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//存放的类型
typedef int ListValType;

//节点结构体声明
typedef struct ListNode
{
	ListValType val;
	struct ListNode* prve;
	struct ListNode* next;
}LSNode;


//链表初始化
LSNode* ListInto();

//尾插
void ListPushBack(LSNode* phead, ListValType x);

//打印链表
void ListPrint(LSNode* phead);

//头插
void ListPushFront(LSNode* phead, ListValType x);

//尾删
void ListPopBack(LSNode* phead);

//头删
void ListPopFront(LSNode* phead);

//查找
LSNode* ListFindNode(LSNode* phead, ListValType x);

//指定插入
void ListInsert(LSNode* phead,LSNode* pos, ListValType x);

//指定删除
void ListEase(LSNode* phead, LSNode* pos);

//销毁链表
void ListDestroy(LSNode** pphead);
