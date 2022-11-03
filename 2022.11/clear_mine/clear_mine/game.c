#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


//��ʼ������
void intogame(char arr[ROWS][COLS], int rows, int cols, char m)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			arr[i][j] = m;
	}
}


//��ӡ����
void Printfarr(char arr[ROWS][COLS], int row, int col) 
{
	int i = 1 ; //���� ���±�Ϊ1 λ�ÿ�ʼ��ӡ
	int j = 1 ;
	for (int i = 0; i <= col; i++)
		printf(" %d",i);
	printf("\n");
	for (int i = 0; i <= col; i++)
		printf("--", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d|", i);
		for (j = 1; j <= col; j++)
			printf(" %c",arr[i][j]);
		printf("\n");
	}

}

//������
void add_mine(char mine[ROWS][COLS], int row, int col, int count)
{

	while (count)
	{
		int x = rand() % row + 1; //1-row ֮��
		int y = rand() % col + 1;// 1- col ֮��
		if (mine[x][y] == '0') //�������ظ�
		{
			mine[x][y] = '1'; //����
			count--;
		}
	}
}

//�����Χ�׵�����
static int mine_num(char mine[ROWS][COLS], int x , int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y]
		+ mine[x + 1][y + 1] - 8 * '0';
}

//��ɨ��  ���� 1��Ӯ�ˣ� 0 ���ˣ�
int PlayGame(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int count = 0; //���״���
	//��������һ������
	
	while (1)
	{

		int x = 0;
		int y = 0;

		printf("���������Ų��� ->");
		scanf("%d %d", &x, &y);
		//�ж�����ĺϷ���
		if (x < 1 || y < 1 || x > row || y > col)
		{
			printf("���겻�Ϸ�,����������\n");
			continue;
		}
		//�ȵ�����+1
		count++;

		//����Ϸ��������жϣ�1 �Ƿ�ȵ��ס�
		if (mine[x][y] == '1') //�ȵ����ˣ��ټ�
			return 0;

		//û�вȵ��� ���ж���Ϸ�Ƿ����
		if ((row * col - count) == MINE_COUNT)
			return 1;

		//û��ҲûӮ����Ϸ���ڽ���
		//�ж������������Χ�м�����
		int num = mine_num(mine, x, y);
		show[x][y] = num + '0';
		system("cls");
		Printfarr(show, row, col);

	}

}