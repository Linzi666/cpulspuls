#define _CRT_SECURE_NO_WARNINGS 1

//将数组A中的内容和数组B中的内容进行交换。（数组一样大）

#include <stdio.h>

void print(int* arr, int sz)
{
	int i = 0;
	for (i; i < sz; i++)
		printf("%d ", *(arr + i));
	printf("\n");
}

void swaparr(int * arr1,int* arr2,int sz) 
{
	//存储变量
	int tmp = 0;

	while (sz--) //交换次数
	{
		tmp = *(arr2 + sz);
		*(arr2 + sz) = *(arr1 + sz)  ;
		*(arr1 + sz) = tmp;
	}
}


int main()
{
	int arr[5] = { 1,2,3,4,5 };
	int arr2[5] = { 6,7,8,9,10 };
	int len = sizeof(arr)/sizeof(arr[0]);
	printf("交换前:\n");
	print(arr,len);
	print(arr2, len);
	swaparr(arr,arr2,len);
	printf("交换后:\n");
	print(arr, len);
	print(arr2, len);
}

