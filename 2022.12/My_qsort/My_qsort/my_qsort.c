#define _CRT_SECURE_NO_WARNINGS 1

#include "my_qsort.h"

void PrintArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
}

//void Swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}

int GetMid(int* arr, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (arr[left] > arr[right])
	{
		if (arr[right] > arr[mid])
			return right;
		else if (arr[left] > arr[mid])
			return mid;
		else
			return left;
	}
	else
	{
		if (arr[left] > arr[mid])
			return left;
		else if (arr[mid] < arr[right])
			return mid;
		else
			return right;
	}
}

//int Partition(int(*cmp)(void* e1, void* e2),int* arr, int left, int right)
//{
//	assert(arr);
//	int keyi = GetMid(arr,  left,  right);
//	Swap(&arr[left], &arr[keyi]);
//
//	keyi = left;
//	int prve = left;
//	int cru = prve + 1;
//
//	while (cru <= right)
//	{
//		if (arr[cru] < arr[keyi] && ++prve != cru)
//			Swap(&arr[prve], &arr[cru]);
//
//		cru++;
//	}
//
//	Swap(&arr[keyi], &arr[prve]);
//	return prve;
//}

//void my_qsort(void* arr, int left,int right)
//{
//	assert(arr);
//	if (left >= right)
//		return;
//
//	int keyi = Partition(cmp,arr,  left,  right);
//	my_qsort(cmp,arr, left, keyi - 1);
//	my_qsort(cmp,arr, keyi + 1, right);
//
//}

void Swap(char* x, char* y,size_t width)
{
	while (width)
	{
		char tmp = *x;
		*x = *y;
		*y = tmp;
		x++;
		y++;
		width--;
	}

}

void Partition(void* arr,size_t width, int(*cmp)(void* e1, void* e2), int left, int right)
{
	assert(arr);
	/*int keyi = GetMid(arr, left, right);
	Swap((char*)arr+left, (char*)arr + keyi,width);*/

	int keyi = left;
	int prve = left;
	int cru = prve + width;

	while (cru <= right)
	{
		if (cru <= right && (cmp((char*)arr + cru, (char*)arr + keyi) > 0) )
		{
			prve += width;
			Swap((char*)arr + prve, (char*)arr + cru, width);
		}
		cru+=width;
	}

	Swap((char*)arr + prve, (char*)arr + keyi, width);



	int Add = width;

	if (left + Add >= right)
		return;
	
	//左区间
	Partition(arr, width, cmp,left, prve - width);
	//右区间
	Partition(arr, width, cmp, prve + width,right);



}

void my_qsort(void* base, size_t num, size_t width, int(*cmp)(void* e1, void* e2))
{
	assert(base);
	Partition(base,width, cmp, 0, (num-1) * width);

}