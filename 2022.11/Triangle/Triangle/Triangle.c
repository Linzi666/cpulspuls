#define _CRT_SECURE_NO_WARNINGS 1



/*
* ����Ļ�ϴ�ӡ������ǡ�
1
1 1
1 2 1
1 3 3 1
����
*/
#include <stdio.h>

int main()
{
	int arr[50][50]; //����һ�����飬���ڴ������
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++) //��ӡ����
	{
		int j = 0; 
		for (j = 0; j <= i; j++) //����
		{
			//��֪��һ�к����һ�� ����1
			if (j == 0 || j == i)
				arr[i][j] = 1;
			//�� i �� �� j �е�ֵ���� �� i-1 �� ���� j - 1 �� + j ��
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			printf("%d ", arr[i][j]);
			
		}
		printf("\n");
	}


	return 0;
}