#pragma once

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


void PrintArr(int* arr, int len);

//qsort( void *base, size_t num, size_t width, int (__cdecl *compare )(const void *elem1, const void *elem2 ) );
void my_qsort(void* base, size_t num, size_t width, int(*cmp)(void* e1, void* e2));