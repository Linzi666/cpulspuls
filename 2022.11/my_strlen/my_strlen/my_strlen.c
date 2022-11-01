#define _CRT_SECURE_NO_WARNINGS 1


//strlen的模拟（递归实现）
#include <stdio.h>

//my_strlen 实现
int my_strlen(char * c) // 用一个指针来接收地址
{
	//1.递归的限制条件
	if (*c != '\0') // 递归的限制条件是，指针解引用后不＝\0，如果 是\0，递推结束开始回归
		return 1 + my_strlen(c+1);//递归的限制条件
	else
		return 0; // 走到 \0了，返回0结束递推，开始回归
}

int main()
{
	char arr[]= "hello bit";//定义一个字符串
	int len = my_strlen(arr); //数组名是 首元素地址，所以传进去的是 h 的地址
	printf("%d",len);

	return 0;
}