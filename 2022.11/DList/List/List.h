#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//��ŵ�����
typedef int ListValType;

//�ڵ�ṹ������
typedef struct ListNode
{
	ListValType val;
	struct ListNode* prve;
	struct ListNode* next;
}LSNode;


//�����ʼ��
LSNode* ListInto();

//β��
void ListPushBack(LSNode* phead, ListValType x);

//��ӡ����
void ListPrint(LSNode* phead);

//ͷ��
void ListPushFront(LSNode* phead, ListValType x);

//βɾ
void ListPopBack(LSNode* phead);

//ͷɾ
void ListPopFront(LSNode* phead);

//����
LSNode* ListFindNode(LSNode* phead, ListValType x);

//ָ������
void ListInsert(LSNode* phead,LSNode* pos, ListValType x);

//ָ��ɾ��
void ListEase(LSNode* phead, LSNode* pos);

//��������
void ListDestroy(LSNode** pphead);
