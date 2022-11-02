#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h" 

//��ʼ������ʵ��
void intoboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) //����
	{
		for (j = 0; j < col; j++) //����
		{
			board[i][j] = ' '; //��ʼ����ֵλ�ո�
		}
	}



}

//��ӡ����ʵ��
void PrintfBoard(char board[ROW][COL], int row, int col)
{
	//��ӡ ���� 
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//ÿһ���� 2 �У�   |   | 
		//               ---|---|---
		//��ӡ��һ��   |   |
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]); //��ӡ���̵ķ����Լ����߿ո�
			if (j < col - 1) //���Կ������ұ���û��|�ģ�����Ҫ��������
				printf("|");
		}
		//��ӡ ����
		printf("\n");
		//��ӡ�ڶ��� ---|---|---
		if (i < row - 1) //���һ�����߲�Ҫ
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1) //���Կ������ұ���û��|�ģ�����Ҫ��������
					printf("|");
			}
		}
		//��ӡ����
		printf("\n");
	}
}

//�������
void Player(char board[ROW][COL], int row, int col)
{
	//��һ������ʾ����
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("�����������������->:");
		//��������
		scanf("%d %d", &x, &y);
	
		if (x <= row && y <= col && x > 0 && y > 0 && (board[x - 1][y - 1] == ' '))
		{
			board[x - 1][y - 1] = Pc;
			break;
		}
		else
			printf("��������Ƿ�,����������\n");
	}
}

//��������
void Computer(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		//����2�������
		int x = rand() % row; //������ɺ�����
		int y = rand() % col; //�������������
		if ((board[x][y] == ' '))
		{
			board[x][y] = Cc;
			break;
		}
	}
}

//�ж����Ƿ�������
 static int is_full_board(char board[ROW][COL], int row, int col)
{
	 int i = 0;
	 int j = 0;
	 for (i = 0; i < row; i++)
	 {
		 for (j = 0; j < col; j++)
		 {
			 if (board[i][j] == ' ')
				 return 0;
		 }
	 }
	 return 1;
}

//�ж���Ӯ
char isWin(char board[ROW][COL], int row, int col)
{
	 //�ж����У�����
	int i = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[1][i] != ' '))
			return board[1][i];
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][1] != ' '))
			return board[i][0];
	}
	//�ж�б�Խ�
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[3][3]) && (board[1][1] != ' '))
		return board[i][0];

	if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2]) && (board[1][1] != ' '))
		return board[i][0];

	//�ж������Ƿ�����
	if(is_full_board(board,ROW,COL))
		return 'Q';
	return 'C';
}

