#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*/

int my_strlen(const char* str)
{
	int count = 0;
	while (*str++)
		count ++ ;
	return count;

}

//���� 1
char* str_move(char* str, int k)
{


	char* pstr = str;
	int sz = my_strlen(str);
	if (k > sz)//���k���ڳ��ȣ�ʵ����ת����������
		k %= sz;
	//����һ�����鵱������
	char str2[100] = { 0 };
	//�ѵ�str�� 1 λԪ���ƶ��� str2��sz-kλ���ѵ�kλԪ���ƶ��� sz - 1 λ
	int i = 0;
	for (i = 0; i < k; i++)
	{
//str2 + sz -1��Ϊ��Ӧ�����һ��Ԫ�ص�ַ�����һ��Ԫ�ص�ַ -(k-1)��Ϊ�滻��λ�ã�+i��ÿ�λ�λ�û�+��ַ������һ��
		*(str2+sz-k+i) = *(str + i); 	
	
	}
	//��str ����kλ������ַ� + �� str2��iλ��ǰ��
	for(i = 0 ; i < sz-k ; i++)
	*(str2 + i) = *(str + k + i);
	
	char* p = str2;
	//���str2 ����str1
	while (*str++ = *p++);
	return pstr;
}

//����2

char* str_move2(char* str, int k)
{
	int len = my_strlen(str);
	char* p = str;
	k %= len;
	while (k--)
	{
		char tmp = *str; //�洢��һ���ַ�
		int j = 0;
		for (j = 1; j < len; j++)  //�Ѻ������ǰ��
			*(str + j - 1) = *(str + j);
		///���һ��λ�� ��tmp����
		*(str + len - 1) = tmp;

	}
	return p;
}

//�ַ�����ת
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

//����������ת
char* str_move3(char* str, int k)
{
	//�� 0 - k ���ַ���ת ��k - len���ַ���ת
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
	printf("����һ:%s\n",str);
	str_move2(str, 5);
	printf("������:%s\n", str);
	str_move2(str, 7);
	printf("������:%s\n", str);

	return 0;
}