#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>

//strcpy��ģ��ʵ��
char* my_strcpy(char* str1,const char* str2)
{
	assert(str1 && str2);
	char* ret = str1;
	while (*str1++ = *str2++);

	return ret;
}


int main()
{
	char arr1[20] = "abcdxxxxxxx";
	char arr2[] = "hello bit";
	printf("%s\n",my_strcpy(arr1,arr2));

	return 0;
}
