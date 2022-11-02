#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//冒泡排序
void bubble_sort(int arr[],int sz)
{
	//实现冒泡排序,冒泡排序，两两比较，升序把大的数放右边
	int i = 0; //冒泡排序的趟数
	int j = 0; //每趟排序次数

	for (int i = 0; i < sz - 1; i++) //因为最后一个数不需要排序，所以只用 sz-1躺
	{
		int flag = 1; //判断这个数有没有进入循环
		//冒泡排序的每一趟
		for (int j = 0; j < sz - 1 - i; j++) //也是sz-1躺，因为倒数第二个数会和最后一个数比较,每次比较完,就不用理会已经比较过的数
		{
			if (arr[j] > arr[j + 1]) //这个数比后面的一个数大
			{
				//交换位置
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0; //这个数进入循环了，说明还没排序好
			}
		}
		if (flag) //如果flag 还是＝1，说明已经排序好了，直接退出循环
			break; 
	}

}

//打印数组
void Printf_arr(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9,0,1,2,3,4,5,6,7,8 }; //一个逆序数组
	printf("排序前:");
	Printf_arr(arr, sizeof(arr) / sizeof(arr[0]));
	bubble_sort(arr,sizeof(arr)/sizeof(arr[0])); //传入数组以及数组长度
	printf("排序后:");
	Printf_arr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}