#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include"Heap.h"

//��ӡ����
void PrintSort(int* data, int n);

//��������
void InsertSort(int* data , int n);

//ϣ������
void ShellSort(int* data, int n);

//ѡ������
void SelectSort(int* data, int n);

//������
void HeapSort(int* data, int n);

//ð������
void BubbleSort(int* data, int n);

//����
void QuickSort(int* data, int n);

//�ǵݹ����
void QuickSortNonR(int* data, int left, int right);

//�鲢
void MergeSort(int*data,int n);

//�ǵݹ�鲢
void MergeSortNonR(int* data, int n);







