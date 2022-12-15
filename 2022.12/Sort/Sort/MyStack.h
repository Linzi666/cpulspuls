#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	//������ݵĿռ�
	STDataType* data;
	//ջ��λ��
	size_t top;
	//ջ������
	size_t Cacpcity;
}ST;

//��ʼ��
void StackInto(ST* ST);

//������ջ
void StackPush(ST* ST, STDataType x);

//���ݳ�ջ
void StackPop(ST* ST);

//ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ST);

//ȡջ����ֵ
STDataType StackTop(ST* ST);

//����ջ
void StackDestroy(ST* ST);