#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 0 Ϊȭͷ
// 1 Ϊ��
// 2 Ϊ����


void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  2.clear  *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}
void menu2()
{
	printf("*********************\n");
	printf("******  0.ȭͷ  *****\n");
	printf("******  1.��    *****\n");
	printf("******  2.����  *****\n");
	printf("*********************\n");
}
// -2��Ӯ�� -1���䣬1��Ӯ��2����
void game()
{
	//��Ϸ��

	char arr[3][5] = { "ȭͷ","��","����" }; //�ַ������飬�����ӡ
	int player = 0; //��ҳ�ȭ
	int computer = rand()%3; //���Գ�ȭ
	int win = 0; // 0 ƽ�֣� -1 �䣬 1 Ӯ
	menu2(); //��ӡ�˵�
	printf("���뿪ʼ��ȭ->>");
	scanf("%d",&player);//�Լ���ȭ

	switch (player-computer) //��Ϸ���
	{
	case 0:
		win = 0;
		break;
	case -2: 
	case 1:
		win = 1;
		break;
	case -1:
	case 2:
		win = -1;
		break;
	default :
	{
		printf("��������\n");
		return; //�����ú���
	}
	}

	//��ӡ˫�� ��ȭ
	printf("\n");
	printf("���Գ�ȭ���Ϊ:%s\n",arr[computer]);
	printf("��ĳ�ȭ���Ϊ:%s\n", arr[player]);

	//��ӡ��Ӯ
	switch (win)
	{
	case -1:
		printf("������\n");
		break;
	case 0:
		printf("ƽ��\n");
		break;
	case 1:
		printf("��Ӯ��\n");
		break;
	}	
}

int main()
{	
	int input = 0; // ѡ��
	srand(time(NULL)); //��ʼ�������������
	do
	{
		menu();
		printf("���������ѡ��->>");
		scanf("%d",&input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("��Ϸ���˳�\n");
			break;
		case 2:
			system("cls"); //����
			break;
		default :
			printf("�������\n");
		}
	} while (input);
	return 0;
}