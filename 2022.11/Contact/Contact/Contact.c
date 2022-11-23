#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "BubbleSort.h"

//加载通讯录
void LoadContact(Contact* con)
{

	//读通讯录
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("InitContact::fopen");
		return;
	}

	//存放读取到的数据
	PeoInfo tmp = { 0 };
	//如果 fread 会返回读到的数据个数，如果为0，就说明读完了
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//通讯录增容
		void AddCapacity(Contact * con);
		*(con->data + con->sz) = tmp;
		con->sz++;
	}
	//关闭流
	fclose(pf);
	pf = NULL;

}


//初始化通讯录
void InitContact(Contact* con)
{
	assert(con);
	con->sz = 0; //初始长度为0
	//从data数组开始，每个字节设置为0，长度为整个数组大小
	//memset(con->data, 0, sizeof(con->data));	
	//动态内存管理版本
	//开辟初始的容量
	con->capacity = INTO_MAX;
	PeoInfo* ps = (PeoInfo*)malloc(con->capacity  * sizeof(PeoInfo));
	//如果开辟失败
	if (NULL == ps)
	{
		perror("InitContact::malloc");
		return;
	}
	//空间开辟成功
	con->data = ps;
	memset(con->data , 0 , con->capacity * sizeof(PeoInfo));
    LoadContact(con);
}


//释放通讯录内存
void ReleaseContact(Contact* con)
{
	free(con->data);
	con->data = NULL;
}



//增容函数
void AddCapacity(Contact* con)
{
	//增容
		//容积 +2 
	con->capacity += 2;
	PeoInfo* ps = (PeoInfo*)realloc(con->data, sizeof(PeoInfo) * con->capacity);

	//如果增容失败 
	if (ps == NULL)
	{
		perror("AddCaoacity::realloc");
		return;
	}
	//增容成功
	con->data = ps;
	
}

//添加联系人
void AddContact(Contact* con)
{
	assert(con);
	//如果容量不够
	if (con->sz == con->capacity)
	{
		AddCapacity(con);
	}


	//信息录入
	printf("请输入姓名->");
	scanf("%s",con->data[con->sz].name);
	printf("请输入年龄->");
	scanf("%d", &(con->data[con->sz].age));
	printf("请输入性别->");
	scanf("%s", (con->data+con->sz)->sex);
	printf("请输入电话->");
	scanf("%s", (con->data + con->sz)->tele);
	printf("请输入地址->");
	scanf("%s", (con->data + con->sz)->addrs);
	//存的人数 + 1
	con->sz++;
	printf("添加成功\n");
}


//打印联系人
void PrintContact(const Contact* const con)
{
	assert(con);
	int i = 0;
	printf("%-20s %-5s %-5s %-13s %-30s\n","姓名","年龄","性别","电话","地址");
	for (i = 0; i < con->sz; i++)
	{
		printf("%-20s %-5d %-5s %-13s %-30s\n",(con->data+i)->name, (con->data + i)->age, 
			(con->data + i)->sex,(con->data + i)->tele, (con->data + i)->addrs);
	}
}

//姓名查找联系人
static int FindByName(const Contact* con,const char* name)
{
	assert(con);
	//遍历查找
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		//拿 data数组的每个每个name 与 输入的name 比较，返回0表示相同,相同就返回索引
		if (0 == strcmp((con->data + i)->name, name))
			return i;
	}
	//循环结束没找到，返回-1
	return -1;
}


//删除联系人
void DelteContact(Contact* con)
{
	assert(con);

	if (con->sz == 0)
	{
		printf("通讯录为空，无法删除\n");
		return;
	}
	char name[NAME_MAX];
	printf("输入你要删除的姓名->");
	scanf("%s",name);
	//搜索
	int ret = FindByName(con, name);
	if (-1 == ret )
	{
		printf("没找到此人\n");
		return;
	}
	// 把data + 索引后面的字节 移动到 data + 索引的位置。
	int count = sizeof(con->data) - (ret+1) * sizeof(con->data[0]);
	memmove((con->data+ret), con->data+ret+1,count);
	//长度-1
	con->sz--;
	printf("删除成功\n");
	
}


//搜索联系人
void SeacherContact(Contact* con)
{
	assert(con);

	char name[NAME_MAX];
	printf("输入你要搜索的姓名->");
	scanf("%s", name);
	//搜索
	int ret = FindByName(con, name);
	if (-1 == ret)
	{
		printf("没找到此人\n");
		return;
	}

	//找到后打印此人信息
	printf("%-20s %-5s %-5s %-13s %-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s %-5d %-5s %-13s %-30s\n", (con->data + ret)->name, (con->data + ret)->age,
			(con->data + ret)->sex, (con->data + ret)->tele, (con->data + ret)->addrs);
}

//修改联系人
void ModifyContact(Contact* con)
{
	assert(con);

	char name[NAME_MAX];
	printf("输入你要修改的姓名->");
	scanf("%s", name);
	//搜索
	int ret = FindByName(con, name);
	if (-1 == ret)
	{
		printf("没找到此人\n");
		return;
	}
	//修改
	printf("请输入姓名->");
	scanf("%s", con->data[ret].name);
	printf("请输入年龄->");
	scanf("%d", &(con->data[ret].age));
	printf("请输入性别->");
	scanf("%s", (con->data + ret)->sex);
	printf("请输入电话->");
	scanf("%s", (con->data + ret)->tele);
	printf("请输入地址->");
	scanf("%s", (con->data + ret)->addrs);

	printf("修改成功\n");
}

//排序菜单
static void SortMenu()
{
	printf("************************************\n");
	printf("*****  1.Age_asc    2.Age_dec  *****\n");
	printf("*****  3.Name_asc   4.Name_dec *****\n");
	printf("************************************\n");
}


//排序
void SortContact(Contact* con)
{
	//打印菜单SortMenu()
	SortMenu();
	int input = 0;

	printf("请输入你的排序选择->");
	scanf("%d", &input);
	int falg = 1;
	switch (input)
	{
	case AGE_ASC:
		bubble(con->data, con->sz, sizeof(con->data[0]), age_asc);
		break;
	case AGE_DEC:
		bubble(con->data,  con->sz, sizeof(con->data[0]), age_dec);
		break;
	case NAME_ASC:
		bubble(con->data , con->sz, sizeof(con->data[0]), name_asc);
		break;
	case NAME_DEC:
		bubble(con->data,  con->sz, sizeof(con->data[0]), name_dec);
		break;
	default:
		printf("排序已取消\n");
		falg = 0;
		break;
	}
	if (falg)
		printf("排序成功\n");
}


//保存通讯录
void SaveContact(Contact* con)
{
	//打开文件
	FILE* fp = fopen("contact.dat","wb");
	if (fp == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//写数据
	int i = 0;
	for(i = 0 ; i < con->sz ; i++)
	fwrite(con->data+i,sizeof(PeoInfo),1,fp);

	//关闭文件
	fclose(fp);
	fp = NULL;
}


void DelAll(Contact* con)
{
	memset(con->data, 0, con->capacity * sizeof(PeoInfo));
	con->sz = 0;
	con->capacity = INTO_MAX;
}

