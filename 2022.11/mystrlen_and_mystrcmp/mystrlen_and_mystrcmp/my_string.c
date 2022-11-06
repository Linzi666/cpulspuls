#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>

//模拟实现库函数strlen
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str++)count++;
	return count;
}

//模拟实现库函数strcpy
char* my_strcpy(char * dest, const char *src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++);
	return ret; 
}

int main()
{


	char name1[] = "wang    zha";
	char name2[20] = {0};
	printf("strlen:%d\n", my_strlen(name1));
	printf("arr2:%s\n", my_strcpy(name2,name1));

	return 0;
}