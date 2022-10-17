#define _CRT_SECURE_NO_WARNINGS 1

//针对每行输入，输出该数是奇数（Odd）还是偶数（Even）。

#include  <stdio.h>

int main() {
	int num1 = 0;//变量定义
	while (scanf("%d", &num1) == 1) { // 
		if (num1 % 2 == 0)  //如果 输入的数 %2等于0，说明是偶数
			printf("Even\n");   //输出Even
		else printf("Odd\n");   //否则输出Odd
	}

	return 0;
}