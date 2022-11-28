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



//β�����ݲ���
void SListPushBack(SLNode** phead, ListDataType x);

//�����ӡ
void SListPrint(SLNode* head);

//ͷ�����ݲ���
void SListPushFront(SLNode** phead, ListDataType x);

//β������ɾ��
void SListPopBack(SLNode** phead);

//ͷ������ɾ��
void SListPopFront(SLNode** phead);


//���ҽڵ�
SLNode* SListFindNode(SLNode* head, ListDataType x);

//ָ������
void SListInsert(SLNode** phead,SLNode* pos, ListDataType x);

//ָ���ڵ�ɾ��
void SListEase(SLNode** phead, SLNode* pos);

//��������
void SListDestroy(SLNode** phead);


