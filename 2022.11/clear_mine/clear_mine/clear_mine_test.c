#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

//��ӡ�˵�
void menu()
{
	printf("**************************\n");
	printf("*******   1.Play    ******\n");
	printf("*******   2.Clear   ******\n");
	printf("*******   0.Eixt    ******\n");
	printf("**************************\n");
}

//��Ϸִ�з���
void game()
{
	//��һ��������2�����飬һ�������������ף�һ���������ڴ����
	//����׵�����
	char mine[ROWS][COLS] = { 0 }; //1 Ϊ �ף�0Ϊ����  
	//�Ų��׵�����
	char show[ROWS][COLS] = { 0 }; 

	//�����ʼ��
	intogame(mine,ROWS,COLS,MINE); //��ʼ�� mine ����
	intogame(show, ROWS, COLS, SHOW); //��ʼ�� mine ����
	//��ʼ����Ϻ�ֱ��ӡ2������
//	Printfarr(mine, ROW, COL); //������ܸ����ǿ�
	Printfarr(show, ROW, COL);

	//���� mine ���鰲����
	add_mine(mine,ROW,COL,MINE_COUNT);


	//�׳�ʼ���ú󣬿�ʼ����Ϸ
	int ret = PlayGame(mine,show,ROW,COL); //����һ������ж���Ӯ
	if (ret)
	{
		printf("\n");
		printf("--------��Ϸ���--------\n");
		printf("��ϲ�㣬�ų������е���\n");
	}
	else
	{
		printf("\n");
		printf("--------��Ϸ���--------\n");
		printf("��ȵ�����\n");
	}
	printf("\n");
	printf("--------����չʾ--------\n");
	Printfarr(mine, ROW, COL); //����ӡһ������
	printf("\n");

}

int main()
{
	srand((unsigned int)time(NULL));//α�����������
	//ɨ����Ϸ
	int input = 0;
	do
	{
		menu();
		printf("���������ѡ�� ->");
		scanf("%d",&input);
		//switch ��֧
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳��ɹ�\n");
			break;
		case 2: 
			system("cls");
			break;
		default :
			printf("�����������������\n");
			break;
		}
	} while (input);


	return 0;
}