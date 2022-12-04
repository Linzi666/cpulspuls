#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//初始化
void StackInto(ST* Stack)
{
	assert(Stack);
	Stack->Data = NULL;
	Stack->top = 0;
	Stack->Capacity = 0;
}

void CheckCacpcity(ST* Stack)
{
	if (Stack->top == Stack->Capacity)
	{
		int NewCapacity = Stack->Capacity == 0 ? 4 : Stack->Capacity * 2;
		STDateType* NewST = (STDateType*)realloc(Stack->Data,sizeof(STDateType) * NewCapacity);
		if (NewST == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		Stack->Data = NewST;
		Stack->Capacity = NewCapacity;
	}

}


//入栈
void StackPush(ST* Stack, STDateType x)
{
	assert(Stack);
	CheckCacpcity(Stack);
	Stack->Data[Stack->top] = x;
	Stack->top++;
}
//出栈
void StackPop(ST* Stack)
{
	assert(Stack);
	assert(!IsEmpty(Stack));
	Stack->top--;
}

//获取栈顶
STDateType StackTop(ST* Stack)
{
	assert(Stack);
	assert(!IsEmpty(Stack));
	return Stack->Data[Stack->top - 1];
}

//打印
void StackPrint(ST* Stack)
{
	assert(Stack);
	int i = 0;
	for (i = 0; i < Stack->top; i++)
		printf("%d ", Stack->Data[i]);

	printf("\n");
}

//栈是否为空
bool IsEmpty(ST* Stack)
{
	assert(Stack);
	return Stack->top == 0;
}

//栈的长度
size_t StackSize(ST* Stack)
{
	assert(Stack);
	return Stack->top;
}

//摧毁栈
void StackDestroy(ST* Stack)
{
	assert(Stack);
	Stack->top = Stack->Capacity = 0;
	free(Stack->Data);
	Stack->Data = NULL;
}
