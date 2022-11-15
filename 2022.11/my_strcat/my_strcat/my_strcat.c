#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<assert.h>

//strcat模拟实现 ,把 一个字符串加到另一个字符串后面。
char* my_strcat(char* str1 , char* str2)
{
	assert(str1 && str2);
	char* ret = str1; //存下str1的地址

	//把str2 加在 str1 后面，先让str1 到\0的位置
	while (*str1)
		str1++;

	//str2 加到str1
	while (*str1++ = *str2++);

	return ret;
}

int main()
{
	char arr1[20] = "abcd";
	char arr2[] = "efg";
	printf("%s",my_strcat(arr1,arr2));

	return 0;
}