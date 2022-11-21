#define _CRT_SECURE_NO_WARNINGS 1


#include "Contact.h"

void menu()
{
	printf("*******************************\n");
	printf("****   1.Add    2.Del      ****\n");
	printf("****   3.Search 4.Modify   ****\n");
	printf("****   5.Sort   6.Print    ****\n");
	printf("****   7.DelAll 8.Clear    ****\n");
	printf("****       0.Exit          ****\n");
	printf("*******************************\n");
}


void ContactTest()
{
	int input = 0;
	//����ͨѶ¼
	Contact con;

	//��ʼ��ͨѶ¼
	InitContact(&con);

	do
	{
		//�˵���ӡ
		menu();
		printf("���������ѡ��->");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con); //�����ϵ��
			break;
		case DEL:
			DelteContact(&con); //ɾ����ϵ��
			break;
		case SEACHER:
			SeacherContact(&con); //������ϵ��
			break;
		case MODIFY:
			ModifyContact(&con); //�޸���ϵ��
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case DELALL:
			//ɾ��������ϵ��
			InitContact(&con);
			printf("ͨѶ¼��ȫ�����\n");
			break;
		case CLEAR:
			system("cls"); //����
			break;
		case EXIT:
			printf("ͨѶ¼�˳��ɹ�\n");
			//�ͷ�ͨѶ¼����Ķ�̬�ڴ�
			ReleaseContact(&con);
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);

}

int main()
{

	ContactTest();
	
	
	return 0;
}