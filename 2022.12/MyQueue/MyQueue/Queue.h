#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;

//队列的节点
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QueueNode;


//队列
typedef struct Queue
{
	//一个指针指向头
	QueueNode* head;
	//一个指针指向尾
	QueueNode* tail;
}Queue;

//队列初始化
void QueueInto(Queue* q);

//数据入队
void QueuePush(Queue* q,QDataType x);

//判断队列是否为空
bool QueueIsEmpty(Queue* q);

//数据出队
void QueuePop(Queue* q);

//获取队头
QDataType QueueGetFront(Queue* q);

//获取队尾
QDataType QueueGetBack(Queue* q);


//获取队列长度
size_t QueueGetSize(Queue* q);


//销毁
void QueueDestroy(Queue* q);