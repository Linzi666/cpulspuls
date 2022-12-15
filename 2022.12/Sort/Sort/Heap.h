#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* data;
	size_t sz;
	size_t Cacpcity;
}HP;

void HeapInit(HP* hp);

void HeapDestroy(HP* hp);

void HeapPush(HP* hp, HeapDataType x);

void HeapPop(HP* hp);

void HeapPrint(HP* hp);

bool HeapEmpty(HP* hp);

HeapDataType HeapTop(HP* hp);
HeapDataType HeapBack(HP* hp);

void Swap(int* x, int* y);

void AdjustUp(HeapDataType* data, int child);

void AdjustDown(HeapDataType* data, int n, int parent);