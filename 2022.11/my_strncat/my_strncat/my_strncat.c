#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strncat(char* dest ,const char* src , size_t count)
{
	assert(dest && src);
	char* ret = dest;

	//�ҳ�dest \0��λ��
	while (*dest)
		dest++;
	//��Դ�ַ���������Ŀ���ַ������� size_t���ֽ�
	while (count--)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return ret;
}


int main()
{
	char arr1[20] = "abcdefg";
	char arr2[] = {'a','b','c','d','e'};
	printf("%s",my_strncat(arr1,arr1,3));

	return 0;
}