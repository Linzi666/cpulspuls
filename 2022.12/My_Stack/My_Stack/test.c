

#include "MyStack.h"


void test1()
{
	ST st;
	StackInto(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackDestroy(&st);

	//while (!StackEmpty(&st))
	//{
	//	STDataType top =  StackTop(&st);
	//	printf("%d ", top);
	//	StackPop(&st);
	//}

	
}

int main()
{
	test1();
	return 0;
}