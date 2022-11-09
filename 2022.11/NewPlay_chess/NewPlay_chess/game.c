#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��ʼ������
void intoboard(char board[ROW][COL], int row, int col)
{
	//��Ϸ�տ�ʼ��ÿ�����궼Ϊ��
	int i = 0;
	int j = 0;
	for (i; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}

//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col)
{
	//���̸�ʽ�� c   |   |   ��һ��
	//�ڶ���      ---|---|
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		//��ӡ��һ��
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j != col - 1)
				printf("|");
		}
		//һ�д��껻��
		printf("\n");
		//��ӡ�ڶ���
		for (j = 0; j < col; j++)
		{
			//��������һ�У���---���ô�ӡ
			if (i != row - 1)
			{
				printf("---", board[i][j]);
				if (j != col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}


//�������
char Player(char board[ROW][COL],int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("���������������->>");
		scanf("%d %d", &x, &y);
		//��Ϊ��������꣬�������Ӧ����������1���������ж������ʱ����Ҫx��y����ȥ1
		if (board[x - 1][y - 1] == ' ' && x > 0 && x <= row && y > 0 && y <= col)
		{
			board[x - 1][y - 1] = PCHESS;
			return Iswin(board,row,col,x-1,y-1); //��Ϊ���������������������1�����Դ���ȥʱ-1
		}
		else
			printf("����Ƿ�������������\n");

	}
}

char Computer(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row; //�����±� 0 -  ��row -1�� 
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = CCHESS;
			printf("��������:%d,%d\n",x+1,y+1);
			return Iswin(board, row, col, x, y);
		}
	}
}

//�ж������Ƿ�����
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i; i < row; i++)
		for (j = 0; j < col; j++)
			if (board[i][j] == ' ') //������̵���' '��˵������λ�ã�����0
				return 0;

	return 1;
}



static int Iswin(char board[ROW][COL], int row, int col, int x, int y)
{
	int i = 1;
	int count = 1; //��Ϊ�����ӵ㿪ʼ������count ��ʼֵΪ1
	//ÿ�У�ÿ�У�ÿ���Խǣ�����2������,��WIN��Ӯ�õ�������������Ҫ�Ų�WIN-1������
	for (i = 1; i < WIN; i++)
		//����Ҫ��������Խ�磬���Ժ��滹Ҫ��������
		if (board[x][y] == board[x + i][y] && x + i < row)
			count++; //�������������� +1 

	//Ȼ���ж���һ��
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x - i][y] && x - i >= 0)
			count++; 

	//��� һ���ߵ��ж����ˣ������ʱ count >= WIN�����ǾͿ����ж���Ϸʤ������������count��ֵ
	if (count >= WIN)
		return board[x][y]; //�����Լ��ַ�
	else
		count = 1;

	//������ �е��Ų飬��ô�У��Խ��ߵ��Ų�ͬ�����

	//�Ų���
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x][y+i] && y + i < row)
			count++; //�������������� +1 

	//Ȼ���ж���һ��
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x][y-i] && y - i >= 0)
			count++;

	if (count >= WIN)
		return board[x][y]; 
	else
		count = 1;

	//�Ų��һ���Խ���

	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x+i][y + i] && (x+i < col) && (y + i < row))
			count++; //�������������� +1 

	//Ȼ���ж���һ��
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x - i][y - i] && (x - i >= 0) && (y - i >= 0))
			count++;

	if (count >= WIN)
		return board[x][y];
	else
		count = 1;

	//�ڶ����Խ���
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x + i][y - i] && (x + i < col) && (y - i >= 0))
			count++; //�������������� +1 

	//Ȼ���ж���һ��
	for (i = 1; i < WIN; i++)
		if (board[x][y] == board[x - i][y + i] && (x - i >= 0) && (y + i < col))
			count++;

	if (count >= WIN)
		return board[x][y];

	//�ж������Ƿ�����
	if (is_full(board, row,col))
		return 'Q';

	return 'C';
}