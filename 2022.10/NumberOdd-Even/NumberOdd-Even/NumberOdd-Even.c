#define _CRT_SECURE_NO_WARNINGS 1

//���ÿ�����룬���������������Odd������ż����Even����

#include  <stdio.h>

int main() {
	int num1 = 0;//��������
	while (scanf("%d", &num1) == 1) { // 
		if (num1 % 2 == 0)  //��� ������� %2����0��˵����ż��
			printf("Even\n");   //���Even
		else printf("Odd\n");   //�������Odd
	}

	return 0;
}