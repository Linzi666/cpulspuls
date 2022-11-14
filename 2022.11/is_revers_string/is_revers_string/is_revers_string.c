#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//str2 是 str1 旋转后的字符
//方法1 用第三个数组，存放 第二个数组每次旋转后的 , 然后每次旋转 都拿用strcmp来比较

//写完才发现，右旋转和左旋转是一样的。。。。所以删掉一个也是可以的


int is_revers1(const char* str1 , const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//长度不相等，返回0
	if (len1 != len2)
		return 0;

	//创建一个数组，用于存储
	char str3[6] = { 0 }; //长度应该为len，但是我这不支持变长数组

	//左旋转
	int i = 0;
	//需要翻转的次数
	for (i = 0; i < len2; i++)
	{
		//每一次翻转从 i开始，到 len结束
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			//把 i之前的元素移动到 第三个数组 len - i+j+1的位置
			*(str3 + len2 - i - 1 + j) = *(str2 + j);

		}
		//然后把 i 后面的元素 移动到str3的前面
		for (j = 0; j < len2-i-1; j++)
		{
			*(str3 + j) = *(str2 + j+i+1);

		}

		if (strcmp(str1, str3) == 0)
			return 1;
	}

	//右旋转
	for (i = 0; i < len2 ; i++)
	{
		
		int j = 0;
		for (j = 0; j <= i ; j++)
		{
			//把从最后一个元素开始旋转，
			*(str3 + j) = *(str2 + len2 - 1 + j - i);
			
		}
		//然后把 len - 1 - i ,为上次循环的最后坐标
		for (j = 0; j < len2-i-1 ; j++)
		{
		    *(str3 + j +i+1)	= *(str2 + j);

		}

		if (strcmp(str1, str3) == 0)
			return 1;
	}

	return 0;
}


//方法二，依次交换法
int is_revers2(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char* p = str2;
	//长度不相等，返回0
	if (len1 != len2)
		return 0;

	//左旋转
	int i = 0;
	for (int i = 0; i < len1; i++) //交换趟数
	{
		//每趟交换 
		char tmp = *p;  //第一个字符
		//然后全部往前移
		int j = 1;
		for (j = 1; j < len1; j++)
		{
			*(p + j - 1) = *(p + j);
		}
		//
		*(p + j-1) = tmp; //最后一个位置
		if (strcmp(str1, str2) == 0)
			return 1;
	}

	//右旋转
	for (int i = 0; i < len1; i++) //交换趟数
	{
		//每趟交换
		char tmp = *(p+len1-1);  //最后
		//然后全部往后移
		int j = 1;
		for (j = 0; j < len1-1; j++)
		{
			*(p + len1 - 1 - j) = *(p + len1- 2 - j);
		}
		//
		*p = tmp; //最后一个位置移到开头
		if (strcmp(str1, str2) == 0)
			return 1;
	}

	return 0;
}



int main()
{
	char str1[] = "ABCDE";
	char str2[] = "EABCD";

	if (is_revers1(str1, str2))
		printf("Yes\n");
	else
		printf("No\n");

	if (is_revers2(str1, str2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}


