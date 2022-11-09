#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

int main()
{
	//定义一个变量，为找到后的凶手
	char killer = 'A';
	for (; killer <= 'D'; killer++) //从A到D排查一遍
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
			//因为有3个人说了真话，所以把四个人说的话加起来，如果等于 3就是3个人说了真话
			printf("凶手:%c",killer);
		
	return 0;
}