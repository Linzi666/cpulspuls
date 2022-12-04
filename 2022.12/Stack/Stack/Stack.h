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

//初始化
void StackInto(ST* Stack);

//入栈
void StackPush(ST* Stack, STDateType x);
//出栈
STDateType StackTop(ST* Stack);

//获取栈顶
STDateType StackTop(ST* Stack);

//打印
void StackPrint(ST* Stack);

//栈是否为空
bool IsEmpty(ST* Stack);

//栈的长度
size_t StackSize(ST* Stack);


void StackDestroy(ST* Stack);
