#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

int B(char c)
{
	int num = c - 48; //数字
	int xx = c - 55; //大写字母
	int dx = c - 87;//小写字母
	if (num <= 9 && num >= 0)
		return num;
	else if (xx <= 15 && xx >= 10)
		return xx;
	else if (dx <= 15 && dx >= 10)
		return dx;
	else - 1; //16进制超出范围，报错
}

//输入一个16进制数，输出十进制
long long  A(char* str)
{
	//字符串的长度代表位数  大写A - F是65-70 ,小写a-f是 97 - 102
	int len = strlen(str);
	int i = 0;
	long long sum = 0;//所有数累加之和
	for (i; i < len; i++)
	{
		//因为是从第一位开始算起的
		int ret = B(str[i]); //字符转换成整形
		if (ret == -1)  //输入的字符串有误
			return 0;
		//16进制的最后一位是 * 16的0次方，倒数第二位是 16的 1 次方，所以 第一位就是 16的len-1次方
		sum += ret * pow(16, len - i - 1);
	}
	return sum;
}

int main()
{
	//输入字符串
	char nums[100] = { 0 };
	long long ret = 0;
	printf("请输入一个16进制数-->:");
	scanf("%s", nums);
	if (ret = A(nums))
		printf("%lld\n", ret);
	else
		printf("输入的数不是16进制");

	return 0;
}