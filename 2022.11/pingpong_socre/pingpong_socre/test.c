#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
//��� P1042 [NOIP2003 �ռ���] ƹ����


int main()
{
	char arr[26] = { 0 };
	
	while (scanf("%s", arr) != EOF)
	{
		char* p = arr;
		//ÿ����һ�У����
		int len = 0;
		while ((*p != 'E') && (*p != '\0'))
		{
			len++;
			p++;
		}
		

		p = arr;
		//WWWWWWWWWWWWWWWWWWWWWWLWE

		//11 ���Ʊ������
		//11��һ��
		int j = len / 11;
		int myscore = 0;//�����ıȷ�
		int rival = 0;//���ֵıȷ�
		//ÿ������
		int i = 0;
		for (i = 0; i < j; i++)
		{
			int cs = 0;
			for (cs = 0; cs < 11; cs++)
			{
				if (*p == 'W')
					myscore++;
				else if (*p == 'L')
					rival++;
				p++;
			}

			//�����һ�ֵķ���
			printf("%d:%d\n", myscore, rival);
			myscore = 0;
			rival = 0;
		}
		//���һ������
		while ((*p) != '\0')
		{
			if (*p == 'W')
				myscore++;
			else if (*p == 'L')
				rival++;

			p++;
		}
		//�����һ�ֵķ���
		printf("%d:%d\n", myscore, rival);
		printf("\n");
		myscore = 0;
		rival = 0;
		p = arr;

		//21����
		j = len / 21;
		//ÿ������
		for (i = 0; i < j; i++)
		{
			//21��һ��ѭ��
			int cs = 0;
			for (cs = 0; cs < 21; cs++)
			{
				if (*p == 'W')
					myscore++;
				else if (*p == 'L')
					rival++;
				p++;
			}
			//һ���������ӡ
			printf("%d:%d\n", myscore, rival);
			//�������
			myscore = 0;
			rival = 0;
		}
		//��ӡʣ�����
		while (*p != '\0')
		{
			if (*p == 'W')
				myscore++;
			else if (*p == 'L')
				rival++;
			p++;
		}
		//һ���������ӡ
		printf("%d:%d\n", myscore, rival);
		//�������
		myscore = 0;
		rival = 0;
		printf("\n");
	}
	return 0;
}