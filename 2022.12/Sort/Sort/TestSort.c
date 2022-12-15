#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

void InsertSortTest()
{
	int arr[] = { 3,1,2,5,7,6,4,5,8 };
	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));
}

void ShellSortTest()
{
	int arr[] = { 3,1,2,5,7,6,4,5,8 };
	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

}

void SelectSortTest()
{
	int arr[] = { 9,1,2,5,7,6,4,0,8 };
	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));

	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));
}

void HeapSortTest()
{
	int arr[] = { 9,1,2,5,7,6,4,0,8 };
	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

	HeapSort(arr, sizeof(arr) / sizeof(arr[0]) );

	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));
}

void QuickSortTest()
{
	int arr[] = { 9,1,2,5,7,6,4,0,8 };
	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));
}

void QuickSortNonRTest()
{
	int arr[] = { 9,1,2,5,7,6,4,0,8 ,11,111,2,3,111,22,23,11,2,2,23,55,44,22};
	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));

	QuickSortNonR(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

	PrintSort(arr, sizeof(arr) / sizeof(arr[0]));
}

void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	//InsertSort(a1, N);
	int end1 = clock();
	
	int begin2 = clock();
	//ShellSort(a2, N);
	int end2 = clock();
	
	//int begin3 = clock();
	//SelectSort(a3, N);
	//int end3 = clock();
	//int begin4 = clock();
	//HeapSort(a4, N);
	//int end4 = clock();
	int begin5 = clock();
	QuickSort(a2,  0, N-1 );
	int end5 = clock();
	//int begin6 = clock();
	//MergeSort(a6, N);
	//int end6 = clock();

	int begin7 = clock();
	QuickSortNonR(a3,0,N-1);
	int end7 = clock();

	//printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	//printf("SelectSort:%d\n", end3 - begin3);
	/*printf("HeapSort:%d\n", end4 - begin4);*/
	printf("QuickSort:%d\n", end5 - begin5);
	printf("QuickNonRSort:%d\n", end7 - begin7);
	//printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}


int main()
{
	//InsertSortTest();
	//ShellSortTest();
	// 
	//SelectSortTest();
	//QuickSortTest();
	//HeapSortTest();
	QuickSortNonRTest();

	TestOP();
}