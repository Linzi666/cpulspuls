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
	//创建通讯录
	Contact con;

	//初始化通讯录
	InitContact(&con);

	do
	{
		//菜单打印
		menu();
		printf("请输入你的选择->");
		scanf("%d",&input);
		switch (input)
		{
		case ADD:
			AddContact(&con); //添加联系人
			break;
		case DEL:
			DelteContact(&con); //删除联系人
			break;
		case SEACHER:
			SeacherContact(&con); //搜索联系人
			break;
		case MODIFY:
			ModifyContact(&con); //修改联系人
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case DELALL:
			//删除所有联系人
			InitContact(&con);
			printf("通讯录已全部清空\n");
			break;
		case CLEAR:
			system("cls"); //清屏
			break;
		case EXIT:
			printf("通讯录退出成功\n");
			//释放通讯录申请的动态内存
			ReleaseContact(&con);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);

}

int main()
{

	ContactTest();
	
	
	return 0;
}