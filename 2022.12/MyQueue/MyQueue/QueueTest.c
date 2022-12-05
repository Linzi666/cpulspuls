#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"

void test1()
{
	Queue Q;
	QueueInto(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	QueuePop(&Q);
	QueuePop(&Q);
	QueuePop(&Q);
	QueuePop(&Q);
}

void test2()
{
	Queue Q;
	QueueInto(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);
	QueuePush(&Q, 3);
	printf("%d,%d\n", QueueGetFront(&Q),QueueGetBack(&Q));
	printf("%d,", QueueGetSize(&Q));
	QueueDestroy(&Q);

}


int main()
{
	//test1();
	test2();
	return 0;
}