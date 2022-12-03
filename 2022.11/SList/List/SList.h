#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//��������
typedef int DataType;

//�ڵ�ṹ�崴��

typedef struct SListNode
{
	//ֵ
	DataType data;
	//ָ����һ���ڵ��ָ��
	struct SListNode* next;
}SLNode;


//����ʵ��
//�����ӡ
void SListPrint(SLNode* phead);

//β��
void SListPushBack(SLNode** pphead,DataType x);

//�ڵ�ͷ��
void SListPushFront(SLNode** pphead, DataType x);

//�ڵ�βɾ
void SListPopBack(SLNode** pphead);

//�ڵ�ͷɾ
void SListPopFront(SLNode** pphead);

//���ҽڵ�
SLNode* SListFindNode(SLNode* phead,DataType x);

//ָ��λ�ò�������
void SListInsert(SLNode** pphead,SLNode* pos,DataType x);

//ɾ��ָ���ڵ�
void SListEase(SLNode** pphead, SLNode* pos);

//��������
void SListDestory(SLNode** pphead);


