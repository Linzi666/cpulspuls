#define _CRT_SECURE_NO_WARNINGS 1

//������С��Ϸ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");
}

//��������Ϸ��
void game()
{
	//����һ������� 
	int ret = rand()%100 +1 ;  //���� 1 - 100�������
	int input = 0;
	while (1) // ��ѭ��
	{
		printf("��������µ���->>:");
		scanf("%d", &input);
		//�ж��Ƿ�´��С
		if (input > ret)
			printf("��µ�������\n");
		else if (input < ret)
			printf("��µ���С��\n");
		else
		{
			printf("�����ˣ���\n");
			break;
		}
			
	}

}

int main()
{
	srand(time(NULL));  //����ʱ�����ʼ��α����� , ֻ��ִ��һ��
	//��һ�������ֲ˵�
	//�˵����ٴ�ӡһ�Σ�������do whileѭ��
	int input = 0;
	do
	{
		menu(); //��ӡ�˵��ĺ���
		//��ӡ��˵�����������
		printf("���ѡ����->>:");
		scanf("%d",&input); //����ѡ��
		system("cls"); //����������
		switch (input)
		{
			case 0: 
				printf("�����˳���Ϸ\n");
				break;
			case 1: 
				game();
				break;
			default: 
				printf("�����������������\n");
				break;
		}


	} while (input);

	return 0;
}