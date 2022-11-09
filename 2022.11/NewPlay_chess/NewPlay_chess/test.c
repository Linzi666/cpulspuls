
#include "game.h"
void game()
{
	//��������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	intoboard(board,ROW,COL);
	//printf ��ӡ����
	PrintBoard(board, ROW, COL);
	char win = 0; // QΪ ƽ��, CΪ��Ϸ����������CCHESS����Ӯ������PCHESS���Ӯ
	while (1)
	{
		//�������
		win = Player(board, ROW, COL); //�ѷ��ؽ���Ž�win��
		PrintBoard(board, ROW, COL);

		if (win != 'C') //win ������C ˵������Ϸ��������
			break;
		//��������
		win = Computer(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		if (win != 'C') //win ������C ˵������Ϸ��������
			break;
	}

	if (win == CCHESS)
		printf("�����ˣ�����Ӯ����Ϸ\n");
	else if (win == PCHESS)
		printf("��ϲ�㣬Ӯ������Ϸ\n");
	else
		printf("ƽ��");
		
}

//��ӡ�˵�
void menu()
{
		printf("*********************\n");
		printf("******  1.play  *****\n");
		printf("******  2.clear *****\n");
		printf("******  0.exit  *****\n");
		printf("*********************\n");
}

int main()
{
	int input = 0;
	//��ӡ�˵�
	srand((unsigned)time(NULL));

	do
	{
		menu();
		printf("���������ѡ��->>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			//��ʼ��Ϸ
			game();
			break;
		case 2:
			//����
			system("cls");
			break;
		case 0:
			break;
		default:
			printf("������������������\n");
			break;
		}
	} while (input);

	return 0;
}