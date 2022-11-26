#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//删除有序数组中的重复项

int DeleteRepeat(int* arr, size_t sz)
{
	//判断sz是否为0
	if (sz == 0)
		return 0;

	//定义三个下标
	int index = 0;//要替换的下标
	int left = 0; 
	int right = 0;
	while (right < sz)
	{
		//如果 下标 left 的值不等于下标right ，那么就替换下标index
		if (arr[left] != arr[right])
		{
			arr[index] = arr[left];
			left = right;
			right++;
			index++;
		}
		else
		{
			right++;
		}
	}
	//循环结束， left所处的下标肯定是没有加上的，因为right已经等于sz，进不去循环了
	arr[index] = arr[left];
	return index + 1;
}



int main()
{
	int arr[] = { 1,1,2,2,3,4,4,5,5,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	len = DeleteRepeat(arr,len);
	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);

	return 0;
}