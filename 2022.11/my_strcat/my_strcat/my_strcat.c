#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<assert.h>

//strcatģ��ʵ�� ,�� һ���ַ����ӵ���һ���ַ������档
char* my_strcat(char* str1 , char* str2)
{
	assert(str1 && str2);
	char* ret = str1; //����str1�ĵ�ַ

	//��str2 ���� str1 ���棬����str1 ��\0��λ��
	while (*str1)
		str1++;

	//str2 �ӵ�str1
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