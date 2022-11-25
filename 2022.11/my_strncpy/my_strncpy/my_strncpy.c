#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strncpy(char* dest,const char* src, size_t count)
{
	assert(dest && src);
	int i = 0;
	char* ret = dest;
	if (dest > src)
	{
		//从后往前
		for (i = count - 1; i >= 0; i--)
			*(dest + i) = *(src + i);
	}
	else
	{
		//从前往后
		for(i  = 0 ; i < count ; i++)
			*(dest + i) = *(src + i);
	}

	return ret;
}

int main()
{
	char arr1[] = "abcdefg";
	char arr2[] = "edfgEFG";
	my_strncpy(arr1 + 2, arr1, 3);
	printf("%s",arr1);
	return 0;
}