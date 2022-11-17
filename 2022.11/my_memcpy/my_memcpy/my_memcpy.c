#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>

//模拟实现memcpy
void* my_memcpy(void * arr1 ,const void* arr2 , size_t count)
{
	//断言
	assert(arr1 && arr2);
	//拷贝
	void* ret = arr1;
	while (count--)
	{
		//一个字节一个字节拷贝，强制转换char*
		*((char*)arr1) = *((char*)arr2);
		//arr1 arr2 ++
		arr1 = (char*)arr1 + 1;
		arr2 = (char*)arr2 + 1;
	}
	return ret;
}



int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[] = { 11,12,13,14,15 };
	my_memcpy(arr1,arr2,20);

	int i = 0;
	for (i = 0; i < 10; i++)
		printf("%d ",arr1[i]);

	return 0;
}