#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

void test1()
{
	ST st;
	StackInto(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPop(&st);
	StackPrint(&st);
	StackPop(&st);
	StackPop(&st);
	StackPrint(&st);

}

void test2()
{
	ST st;
	StackInto(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPrint(&st);
	printf("Õ»¶¥:%d\n",StackTop(&st));
	StackPop(&st);
	StackPrint(&st);
	printf("Õ»¶¥:%d\n", StackTop(&st));

	StackDestroy(&st);

}

int main()
{
	//test1();
	test2();
	return 0;
}