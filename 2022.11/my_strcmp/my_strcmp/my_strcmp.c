#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>

//strcmpģ��ʵ��

int my_strcmp(const char* str1 ,const char* str2)
{
	assert(str1 && str2);

	//���������ȣ���������Ƚ�
	while (*str1 == *str2)
	{
		str1++;
		str2++;
		//�����һ����\0���Ǿ�˵���Ƚ����ˣ�����0
		if (*str1 == '\0')
			return 0;
	}
	
	return *str1 - *str2;

}


int main()
{
	char arr1[] = "abq";
	char arr2[] = "abq";
	printf("%d",my_strcmp(arr1,arr2));

	return 0;
}