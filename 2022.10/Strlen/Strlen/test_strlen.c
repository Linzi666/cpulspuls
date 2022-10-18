#define _CRT_SECURE_NO_WARNINGS 1



#include <stdio.h>
#include <string.h>
//今天我们来测试一下strlen函数
int main() {
	char ch1[] = { 'h','e','l','l','o' };  
	char ch2[] = "hello"; 
	printf("ch1 = %d\n",strlen(ch1));  //打印的是随机值
	printf("ch2 = %d\n", strlen(ch2)); //打印的是5
	//总结：
	/*
	strlen函数的结束标志是\0
	因为 {} 形式的定义，不会自带\0 , 而“” 定义字符串，会自带\0
	所以 strlen函数 扫描到\0，且不包括\0

	*/

	return 0;
}