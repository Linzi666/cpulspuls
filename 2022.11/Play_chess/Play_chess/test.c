#define _CRT_SECURE_NO_WARNINGS 1

//������

#include "game.h" //������Ϸͷ�ļ�

//��ӡ�˵�����
void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  2.clear *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}

//������������ҷ���



//��Ϸ����
void game()
{
	// ��һ����������������
	char board[ROW][COL] = { 0 };
	//�ڶ�������ʼ������
	intoboard(board,ROW,COL);
	//�ڶ�������ӡ����
	PrintfBoard(board,ROW,COL);
	//���幦�ܣ����ʹ��������������
	char win = 0;
	while (1)
	{
			Player(board,ROW,COL);
			PrintfBoard(board, ROW, COL); //��ӡ����
			win = isWin(board, ROW, COL);
			if(win != 'C')//�ж���Ӯ
			break;

			printf("---------��������----------\n");
			Computer(board, ROW, COL);
			PrintfBoard(board, ROW, COL); // ��ӡ����

			win = isWin(board, ROW, COL);
			if (win != 'C')//�ж���Ӯ
			break;	
	}
	if (win == '*')
		printf("��Ӯ��\n");
	else if (win == '#')
		printf("����Ӯ��\n");
	else
		printf("ƽ��\n");

}


int main()
{
	srand((unsigned int)time(NULL)); //��ʼ��α�����������
	int input = 0; //ѡ��
	//����ѡ��һ��

	do
	{
		//��ӡ�˵�
		menu(); 
		//��ʾ����
		printf("���������ѡ��->:"); 
		//����ѡ��
		scanf("%d",&input);  

		//switch ��֧�ж�
		switch (input)
		{
		case 1:
			game(); //��Ϸ��ʼ����
			break;
		case 2:
			system("cls");
			break;
		case 0 :
			printf("�˳��ɹ�\n");
			break;
		default :
			printf("���������������\n");
			break;
		}
	} while (input);


	return 0;
}