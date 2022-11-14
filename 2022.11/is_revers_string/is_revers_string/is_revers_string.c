#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//str2 �� str1 ��ת����ַ�
//����1 �õ��������飬��� �ڶ�������ÿ����ת��� , Ȼ��ÿ����ת ������strcmp���Ƚ�

//д��ŷ��֣�����ת������ת��һ���ġ�����������ɾ��һ��Ҳ�ǿ��Ե�


int is_revers1(const char* str1 , const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	//���Ȳ���ȣ�����0
	if (len1 != len2)
		return 0;

	//����һ�����飬���ڴ洢
	char str3[6] = { 0 }; //����Ӧ��Ϊlen���������ⲻ֧�ֱ䳤����

	//����ת
	int i = 0;
	//��Ҫ��ת�Ĵ���
	for (i = 0; i < len2; i++)
	{
		//ÿһ�η�ת�� i��ʼ���� len����
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			//�� i֮ǰ��Ԫ���ƶ��� ���������� len - i+j+1��λ��
			*(str3 + len2 - i - 1 + j) = *(str2 + j);

		}
		//Ȼ��� i �����Ԫ�� �ƶ���str3��ǰ��
		for (j = 0; j < len2-i-1; j++)
		{
			*(str3 + j) = *(str2 + j+i+1);

		}

		if (strcmp(str1, str3) == 0)
			return 1;
	}

	//����ת
	for (i = 0; i < len2 ; i++)
	{
		
		int j = 0;
		for (j = 0; j <= i ; j++)
		{
			//�Ѵ����һ��Ԫ�ؿ�ʼ��ת��
			*(str3 + j) = *(str2 + len2 - 1 + j - i);
			
		}
		//Ȼ��� len - 1 - i ,Ϊ�ϴ�ѭ�����������
		for (j = 0; j < len2-i-1 ; j++)
		{
		    *(str3 + j +i+1)	= *(str2 + j);

		}

		if (strcmp(str1, str3) == 0)
			return 1;
	}

	return 0;
}


//�����������ν�����
int is_revers2(const char* str1, const char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char* p = str2;
	//���Ȳ���ȣ�����0
	if (len1 != len2)
		return 0;

	//����ת
	int i = 0;
	for (int i = 0; i < len1; i++) //��������
	{
		//ÿ�˽��� 
		char tmp = *p;  //��һ���ַ�
		//Ȼ��ȫ����ǰ��
		int j = 1;
		for (j = 1; j < len1; j++)
		{
			*(p + j - 1) = *(p + j);
		}
		//
		*(p + j-1) = tmp; //���һ��λ��
		if (strcmp(str1, str2) == 0)
			return 1;
	}

	//����ת
	for (int i = 0; i < len1; i++) //��������
	{
		//ÿ�˽���
		char tmp = *(p+len1-1);  //���
		//Ȼ��ȫ��������
		int j = 1;
		for (j = 0; j < len1-1; j++)
		{
			*(p + len1 - 1 - j) = *(p + len1- 2 - j);
		}
		//
		*p = tmp; //���һ��λ���Ƶ���ͷ
		if (strcmp(str1, str2) == 0)
			return 1;
	}

	return 0;
}



int main()
{
	char str1[] = "ABCDE";
	char str2[] = "EABCD";

	if (is_revers1(str1, str2))
		printf("Yes\n");
	else
		printf("No\n");

	if (is_revers2(str1, str2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}


