#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

int main()
{
	int num = 10;
	int i = 0;

	//
	printf("���������ӡ\n");
	printf("ż������:");
	for (i = 0; i < 32; i += 2) //��ӡż������
		printf("%d ", 10 & (num << i) ? 1 : 0);
	printf("��������:");
	for (i = 1; i <= 31; i += 2)  //��ӡ��������
		printf("%d ", 10 & (num << i) ? 1 : 0);

	printf("\n�������Ҵ�ӡ\n");
	printf("ż������:");
	for (i = 30; i >= 0; i -= 2) //��ӡż������
		printf("%d ", 10 & (num << i) ? 1 : 0);
	printf("��������:");
	for (i = 31; i >= 1; i -= 2)  //��ӡ��������
		printf("%d ", 10 & (num << i) ? 1 : 0);
	return 0;
}