
#include "MyStack.h"

//初始化
void StackInto(ST* ST)
{
	ST->data = NULL;
	ST->top = 0;
	ST->Cacpcity = 0;
}

//容量更新
void CheckCacpcity(ST* ST)
{
	//容量等于top时，说明数组没有空间了
	if (ST->Cacpcity == ST->top)
	{
		//如果空间为0，初始空间4，如果不为0，空间*2
		int NewCacpcity = ST->Cacpcity == 0 ? 4 : ST->Cacpcity * 2;
		//扩容
		STDataType* newdata = (STDataType*)realloc(ST->data,sizeof(STDataType) * NewCacpcity);
		//扩容是否成功
		if (newdata == NULL)
		{
			printf("reallo fail\n");
			exit(-1);
		}
		ST->data = newdata;
		//更新容量
		ST->Cacpcity = NewCacpcity;
	}
}

//数据入栈
void StackPush(ST* ST, STDataType x)
{
	//断言，传进来的指针不能为空
	assert(ST);
	//容量不够自动增容
	CheckCacpcity(ST);

	//尾部数据入栈
	*(ST->data+ST->top) = x;
	ST->top++;
}

//数据出栈
void StackPop(ST* ST)
{
	assert(ST);
	//如果top等于0，说明没有元素了
	assert(ST->top > 0);

	//出栈操作，就是这么简单
	ST->top--;

}

//栈是否为空
bool StackEmpty(ST* ST)
{
	assert(ST);
	return ST->top == 0;
}

//取栈顶的值
STDataType StackTop(ST* ST)
{
	assert(ST);
	assert(!StackEmpty(ST));
	return ST->data[ST->top - 1];
}
//销毁
void StackDestroy(ST* ST)
{
	assert(ST);
	ST->top = ST->Cacpcity = 0;
	free(ST->data);
	ST->data = NULL;
}
