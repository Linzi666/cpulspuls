#define _CRT_SECURE_NO_WARNINGS 1


//strlen��ģ�⣨�ݹ�ʵ�֣�
#include <stdio.h>

//my_strlen ʵ��
int my_strlen(char * c) // ��һ��ָ�������յ�ַ
{
	//1.�ݹ����������
	if (*c != '\0') // �ݹ�����������ǣ�ָ������ú󲻣�\0����� ��\0�����ƽ�����ʼ�ع�
		return 1 + my_strlen(c+1);//�ݹ����������
	else
		return 0; // �ߵ� \0�ˣ�����0�������ƣ���ʼ�ع�
}

int main()
{
	char arr[]= "hello bit";//����һ���ַ���
	int len = my_strlen(arr); //�������� ��Ԫ�ص�ַ�����Դ���ȥ���� h �ĵ�ַ
	printf("%d",len);

	return 0;
}