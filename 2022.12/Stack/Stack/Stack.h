#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>


typedef int STDateType;

typedef struct Stack
{
	STDateType* Data;
	int top;
	int Capacity;
}ST;

//��ʼ��
void StackInto(ST* Stack);

//��ջ
void StackPush(ST* Stack, STDateType x);
//��ջ
STDateType StackTop(ST* Stack);

//��ȡջ��
STDateType StackTop(ST* Stack);

//��ӡ
void StackPrint(ST* Stack);

//ջ�Ƿ�Ϊ��
bool IsEmpty(ST* Stack);

//ջ�ĳ���
size_t StackSize(ST* Stack);


void StackDestroy(ST* Stack);
