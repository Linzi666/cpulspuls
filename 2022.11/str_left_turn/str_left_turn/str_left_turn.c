#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/

int my_strlen(const char* str)
{
	int count = 0;
	while (*str++)
		count ++ ;
	return count;

}

//方法 1
char* str_move(char* str, int k)
{


	char* pstr = str;
	int sz = my_strlen(str);
	if (k > sz)//如果k大于长度，实际旋转次数是余数
		k %= sz;
	//创建一个数组当作容器
	char str2[100] = { 0 };
	//把第str第 1 位元素移动到 str2的sz-k位，把第k位元素移动到 sz - 1 位
	int i = 0;
	for (i = 0; i < k; i++)
	{
//str2 + sz -1，为对应的最后一个元素地址，最后一个元素地址 -(k-1)，为替换的位置，+i是每次换位置会+地址往后走一格
		*(str2+sz-k+i) = *(str + i); 	
	
	}
	//把str ，第k位后面的字符 + 到 str2第i位的前面
	for(i = 0 ; i < sz-k ; i++)
	*(str2 + i) = *(str + k + i);
	
	char* p = str2;
	//最后，str2 覆盖str1
	while (*str++ = *p++);
	return pstr;
}

//方法2

char* str_move2(char* str, int k)
{
	int len = my_strlen(str);
	char* p = str;
	k %= len;
	while (k--)
	{
		char tmp = *str; //存储第一个字符
		int j = 0;
		for (j = 1; j < len; j++)  //把后面的往前移
			*(str + j - 1) = *(str + j);
		///最后一个位置 把tmp补上
		*(str + len - 1) = tmp;

	}
	return p;
}

//字符串翻转
void A(char* str, int right)
{
	
	int left = 0;

	while (left < right)
	{
		char tmp = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = tmp;
		left++;
		right--;
	}
}

//方法三，逆转
char* str_move3(char* str, int k)
{
	//把 0 - k 个字符翻转 ，k - len个字符翻转
	int len = my_strlen(str);
	k %= len;
	A(str,k);
	A(str + k, len - k);
	A(str, len-1);
}


int main()
{
	char str[] = "ABCDEFG";
	int k = 100;
	str_move(str,k);
	printf("方法一:%s\n",str);
	str_move2(str, 5);
	printf("方法二:%s\n", str);
	str_move2(str, 7);
	printf("方法三:%s\n", str);

	return 0;
}