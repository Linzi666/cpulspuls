#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;

//���еĽڵ�
typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QueueNode;


//����
typedef struct Queue
{
	//һ��ָ��ָ��ͷ
	QueueNode* head;
	//һ��ָ��ָ��β
	QueueNode* tail;
}Queue;

//���г�ʼ��
void QueueInto(Queue* q);

//�������
void QueuePush(Queue* q,QDataType x);

//�ж϶����Ƿ�Ϊ��
bool QueueIsEmpty(Queue* q);

//���ݳ���
void QueuePop(Queue* q);

//��ȡ��ͷ
QDataType QueueGetFront(Queue* q);

//��ȡ��β
QDataType QueueGetBack(Queue* q);


//��ȡ���г���
size_t QueueGetSize(Queue* q);


//����
void QueueDestroy(Queue* q);