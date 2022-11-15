#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<assert.h>

//strcmp模拟实现

int my_strcmp(const char* str1 ,const char* str2)
{
	assert(str1 && str2);

	//如果两个相等，继续往后比较
	while (*str1 == *str2)
	{
		str1++;
		str2++;
		//如果有一个是\0，那就说明比较完了，返回0
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