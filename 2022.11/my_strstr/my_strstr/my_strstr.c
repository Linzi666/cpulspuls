#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//strstr 实现
char* my_strstr(char* str1, char* str2)
{
	//主串和子串向后移动的指针
	char* s1 = str1;
	char* s2 = str2;

	char* tmp = str1; //str1 向后移动的指针

	//tmp为\0 时，说明主串查找完了
	while (*tmp)
	{
		s1 = tmp; //  tmp 走到哪，s1就要走到哪

		//当主串和子串相等时 ， 子串和主串都不能等于\0，否则会引越界访问
		while (*s1 && *s2 && (*s1 == *s2))
		{
			//那就继续判断它们下一个是否相等
			s1++;
			s2++;
		}

		//如果 s2 走到\0了，说明主串包含子串,那就返回tmp的地址
		if (*s2 == '\0')
			return tmp;

		//如果不相等，查找的位置继续 +1
		tmp++;

		//s2 回退到初始位置
		s2 = str2;
	}
	//循环结束，没有找到，说明不包含子串,返回空指针
	return NULL;
}


int main()
{
	//strstr
	char arr1[] = "abcedfaaa";
	char arr2[] = "cedf";
	char* ret = my_strstr(arr1, arr2);
	if (NULL != ret)
		printf("%s\n", ret);
	else
		printf("没找到\n");

	return 0;
}