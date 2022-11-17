#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
//memmove函数实现
void* my_memmove(void* desc,const void* src, size_t count)
{
	assert(desc && src);
	void* ret = desc;
	//如果dest > src 从后往前拷贝，否则从前往后
	if (desc > src)
	{
		//后往前
		while (count--)
		{
			*((char*)desc + count) = *((char*)src + count);
		}

	}
	else
	{
		//前往后
		while (count--)
		{
			*((char*)desc) = *((char*)src);
			desc = (char*)desc + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 ,10};
	my_memmove(arr,arr+2,20);

	int i = 0;
	for (; i < 10; i++)
		printf("%d ",arr[i]);

	return 0;
}