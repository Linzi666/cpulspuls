#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


void test1()
{
	HP hp;
	HeapInit(&hp);
	int arr[] = { 80,60,75,40,45,55,77 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
		HeapPush(&hp,arr[i]);

	HeapPrint(&hp);
}

int main()
{
	test1();
	return 0;
}