#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。



int main()
{
	int nums[] = { 1,2,5,2};
	int i = 0;
	int num = 0;
	int dig = 0;
	int a1 = 0;
	int a2 = 0;
	int len = sizeof(nums) / sizeof(nums[0]);
	for (i = 0; i < len; i++)
	{
		num ^= nums[i];
	}

	for (i = 0; i < 32; i++)
	{
		if (((num>>i)&1) == 1)
		{
			dig = i;
			break;
		}
	}

	for (i = 0; i < len; i++)
	{
		if (((nums[i]>>dig)&1)==1)
			a1 ^= nums[i];
		else
			a2 ^= nums[i];
	}

	printf("%d,%d",a1,a2);
	

	return 0;
}

