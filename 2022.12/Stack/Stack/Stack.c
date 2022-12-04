#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//��ʼ��
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


//��ջ
void StackPush(ST* Stack, STDateType x)
{
	assert(Stack);
	CheckCacpcity(Stack);
	Stack->Data[Stack->top] = x;
	Stack->top++;
}
//��ջ
void StackPop(ST* Stack)
{
	assert(Stack);
	assert(!IsEmpty(Stack));
	Stack->top--;
}

//��ȡջ��
STDateType StackTop(ST* Stack)
{
	assert(Stack);
	assert(!IsEmpty(Stack));
	return Stack->Data[Stack->top - 1];
}

//��ӡ
void StackPrint(ST* Stack)
{
	assert(Stack);
	int i = 0;
	for (i = 0; i < Stack->top; i++)
		printf("%d ", Stack->Data[i]);

	printf("\n");
}

//ջ�Ƿ�Ϊ��
bool IsEmpty(ST* Stack)
{
	assert(Stack);
	return Stack->top == 0;
}

//ջ�ĳ���
size_t StackSize(ST* Stack)
{
	assert(Stack);
	return Stack->top;
}

//�ݻ�ջ
void StackDestroy(ST* Stack)
{
	assert(Stack);
	Stack->top = Stack->Capacity = 0;
	free(Stack->Data);
	Stack->Data = NULL;
}
