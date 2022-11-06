#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*

编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列，不是逆序打印。
要求：不能使用C函数库中的字符串操作函数。
*/

//void reverse_string(char* arr,int left ,int right)
//{
//	//实现思路,第一个字符与最后一个字符 交换位置
//	//left 为左下标，right为右下标
//	if (left <= right) //递归限制条件 
//	{
//		//左坐标小于右下标，交换，递归
//		char temp = *(arr + left);
//		*(arr + left) = *(arr + right);
//		*(arr + right) = temp;
//		reverse_string(arr, left + 1, right - 1); //左坐标+1，右坐标-1
//	}
//}

int my_strlen(char* arr)
{
	int count = 0;
	while (*(arr + count))count++;
	return count;
}

//不传长度做法
void reverse_string(char* arr)
{
	int len = my_strlen(arr) - 1; //最后一个元素的下标

	char temp = *arr; //存储第一个字符
	*arr = *(arr + len);// 第一个字符换成最后一个字符
	*(arr + len) = '\0'; // 最后一个字符变成\0，以至于下次递推时的最后一个字符，是前一次递推的倒数第二字符
	if (len > 1)  //如果 arr - arr+len 之间大于一个字符，那就继续递推
	{
		reverse_string(arr+1); // arr 向后移动一格，下次递推就是第二格与倒数第二格交换
	}
	//递推结束，开始回归，把覆盖的\0 换成 存储了对应字符的 temp
	*(arr + len) = temp;
}


int main()
{
	char arr[] = "abcdefg";
	printf("翻转前:%s\n",arr);
	reverse_string(arr);
	printf("翻转后:%s", arr);
	
	return 0;
}