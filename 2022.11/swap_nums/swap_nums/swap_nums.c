#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//交换两个变量（不创建临时变量）

//第一种方法

void swap1(int* a, int* b)
{
	*(a) = *(a)+*(b); //a 存了 a + b的值
	*(b) = *(a)-*(b);// a存了 a + b的值，所以 此时 a - b = a 一开始的值
	*(a) = *(a)-*(b); // 此时的 a 还是 a+b的值， b 是 一开始a的值，所以减去后就是一开始b的值
}

//第二种方法
void swap2(int* a, int* b)
{
	*(a) ^= *(b); // *a ＝ *a ^ *b
	*(b) ^= *(a); // a 此时是 a 和b 异或后的值，所以再异或b，b就是 a 了
	*(a) ^= *(b); //a 还是 a 和 b 异或后的值，但是 b 是一开始a的值，所以异或后 a 是一开始b的值

}

int main()
{
	int a = 10;
	int b = 20;
	printf("交换前\n");
	printf("a = %d\n",a);
	printf("b = %d\n", b);

	//swap1(&a, &b);
	swap2(&a, &b);

	printf("交换后\n");
	printf("a = %d\n", a);
	printf("b = %d\n", b);
	
	return 0;
}