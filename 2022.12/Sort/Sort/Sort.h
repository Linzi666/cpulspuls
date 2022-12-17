#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Heap.h"

//´òÓ¡Êı×é
void PrintSort(int* data, int n);

//²åÈëÅÅĞò
void InsertSort(int* data , int n);

//Ï£¶ûÅÅĞò
void ShellSort(int* data, int n);

//Ñ¡ÔñÅÅĞò
void SelectSort(int* data, int n);

//¶ÑÅÅĞò
void HeapSort(int* data, int n);

//Ã°ÅİÅÅĞò
void BubbleSort(int* data, int n);

//¿ìÅÅ
void QuickSort(int* data, int n);

//·Çµİ¹é¿ìÅÅ
void QuickSortNonR(int* data, int left, int right);

//¹é²¢
void MergeSort(int*data,int n);

//·Çµİ¹é¹é²¢
void MergeSortNonR(int* data, int n);







