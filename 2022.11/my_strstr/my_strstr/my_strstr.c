#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//strstr ʵ��
char* my_strstr(char* str1, char* str2)
{
	//�������Ӵ�����ƶ���ָ��
	char* s1 = str1;
	char* s2 = str2;

	char* tmp = str1; //str1 ����ƶ���ָ��

	//tmpΪ\0 ʱ��˵��������������
	while (*tmp)
	{
		s1 = tmp; //  tmp �ߵ��ģ�s1��Ҫ�ߵ���

		//���������Ӵ����ʱ �� �Ӵ������������ܵ���\0���������Խ�����
		while (*s1 && *s2 && (*s1 == *s2))
		{
			//�Ǿͼ����ж�������һ���Ƿ����
			s1++;
			s2++;
		}

		//��� s2 �ߵ�\0�ˣ�˵�����������Ӵ�,�Ǿͷ���tmp�ĵ�ַ
		if (*s2 == '\0')
			return tmp;

		//�������ȣ����ҵ�λ�ü��� +1
		tmp++;

		//s2 ���˵���ʼλ��
		s2 = str2;
	}
	//ѭ��������û���ҵ���˵���������Ӵ�,���ؿ�ָ��
	return NULL;
}


int main()
{
	//strstr
	char arr1[] = "abcedfaaa";
	char arr2[] = "cedf";
	char* ret = my_strstr(arr1, arr2);
	if (NULL != ret)
		printf("%s\n", ret);
	else
		printf("û�ҵ�\n");

	return 0;
}