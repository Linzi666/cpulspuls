#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//˳���ṹ��
typedef int SLDataType;

typedef struct SeqList
{
	//��̬����
	//ָ��Ķ�̬�ڴ�ָ��
	SLDataType* data;
	//������ݵĸ���
	int size;
	//�洢�ݻ�
	int capacity;
}SL;


//��������

//��ӡ˳���
void SqeListPrint(SL* pSL);


//��ʼ��˳���
void SeqListInit(SL* pSL);

//�ͷ��ڴ�
void SeqListDestory(SL* pSL);

//β����������
void SeqListPushBack(SL* pSL, SLDataType x);

//ͷ����������
void SeqListPushFtont(SL* pSL, SLDataType x);

//β��ɾ������
void SeqListMoveBack(SL* pSL);

//ͷ��ɾ������
void SeqListMoveFront(SL* pSL);

//ָ��λ��ɾ������
void SeqListMoveSet(SL* pSL,int pos);

//ָ��λ�ò�������
void SeqListPushSet(SL* pSL, int pos, SLDataType x);

//���������±�
int SeqListFind(SL* pSL , SLDataType x);


