#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。

void print(int* arr, int len)
{
	int i = 0;
	for (i; i < len; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void init(int* arr, int len)
{
	int i = 0;
	for (i; i < len; i++)
		*(arr + i) = 0;
}

void reverse(int* arr , int len)
{
	int left = 0;
	int right = len - 1;
	int temp = 0;
	while (left < right)
	{
		temp = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = temp;
		left++;
		right--;
	}

}

int main()
{
	int arr[] = { 1,2,3,4,5,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("数组初始化打印\n");
	print(arr,len);


	reverse(arr,len);
	printf("数组逆转后打印\n");
	print(arr, len);

	printf("数组清空后\n");
	init(arr,len);
	print(arr, len);
	
	return 0;
}