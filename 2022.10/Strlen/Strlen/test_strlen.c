#define _CRT_SECURE_NO_WARNINGS 1



#include <stdio.h>
#include <string.h>
//��������������һ��strlen����
int main() {
	char ch1[] = { 'h','e','l','l','o' };  
	char ch2[] = "hello"; 
	printf("ch1 = %d\n",strlen(ch1));  //��ӡ�������ֵ
	printf("ch2 = %d\n", strlen(ch2)); //��ӡ����5
	//�ܽ᣺
	/*
	strlen�����Ľ�����־��\0
	��Ϊ {} ��ʽ�Ķ��壬�����Դ�\0 , ������ �����ַ��������Դ�\0
	���� strlen���� ɨ�赽\0���Ҳ�����\0

	*/

	return 0;
}