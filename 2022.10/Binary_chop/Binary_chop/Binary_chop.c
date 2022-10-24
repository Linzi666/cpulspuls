#define _CRT_SECURE_NO_WARNINGS 1

//二分查找法
#include <stdio.h>

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9 ,10 };
	int k = 7; // 要查找的数字
	int left = 0; //数组第一个元素下标
	int right = 9; //数组最后一个元素下标
	int flag = 0; //判断是否找到
	int mid = 0;  ////数组中间的元素下标
	while (left <= right) //当left >right时，说明已经查找完毕 
	{
		mid = (left + right) / 2; //数组中间的元素下标
		if (arr[mid] > k) //如果数组中间元素大于要查找的值，说明要查找的值再左边，把right移动到mid-1的位置
			right = mid - 1;
		else if (arr[mid] < k)
			left = mid + 1;//如果数组中间元素小于要查找的值，说明要查找的值在mid右边，把left移动到mid+1的位置
		else
		{
			flag = 1;
			break;
		}
	}

	if (flag)
		printf("%d在数组的下标为:%d\n", k, mid);
	else
		printf("没找到\n");


	return 0;

}