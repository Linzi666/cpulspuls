#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//���Ͼ��� ������
/*
	1  2  3  4
	5  6  7  8
	7  8  9 10
	9 10 11 12 
*/

int main()
{
	int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12}, {13,14,15,16} }; //��ά�����Ӧ���Ͼ���
	int input = 0;
	scanf("%d",&input);  //����Ҫ���ҵ�
	int row = sizeof(arr) / sizeof(*arr); //����
	int col = sizeof(*arr) / sizeof(**arr);//����
	int falg = 0;
	//�����ұߵ����֣������������ + 1�����С�� �� �ö��ֲ���
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if(arr[i][col-1] >=  input) //���������һ����������С����ô˵�������������һ��
		{ 
			//���ֲ���
			int left = 0;
			int right = col - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				if (arr[i][mid] == input)
				{
					falg = 1;
					j = mid;
					goto GOTO; //�ҵ��ˣ�ֱ��goto�������ѭ��
				}
				else if (arr[i][mid] > input)
					right = mid - 1;
				else
					left = mid + 1;
				
			}
		}
	}
GOTO:
	if (falg)
		printf("�ҵ��ˣ��±�Ϊ:%d,%d\n", i, j);
	else
		printf("û�ҵ�\n");

	return 0;
}