#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��



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

