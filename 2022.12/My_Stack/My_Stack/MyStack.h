#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	//存放数据的空间
	STDataType* data;
	//栈顶位置
	size_t top;
	//栈的容量
	size_t Cacpcity;
}ST;

//初始化
void StackInto(ST* ST);

//数据入栈
void StackPush(ST* ST, STDataType x);

//数据出栈
void StackPop(ST* ST);

//栈是否为空
bool StackEmpty(ST* ST);

//取栈顶的值
STDataType StackTop(ST* ST);

//销毁栈
void StackDestroy(ST* ST);