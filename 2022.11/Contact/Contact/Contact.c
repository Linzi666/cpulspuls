#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
#include "BubbleSort.h"

//����ͨѶ¼
void LoadContact(Contact* con)
{

	//��ͨѶ¼
	FILE* pf = fopen("contact.dat", "rb");
	if (pf == NULL)
	{
		perror("InitContact::fopen");
		return;
	}

	//��Ŷ�ȡ��������
	PeoInfo tmp = { 0 };
	//��� fread �᷵�ض��������ݸ��������Ϊ0����˵��������
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//ͨѶ¼����
		void AddCapacity(Contact * con);
		*(con->data + con->sz) = tmp;
		con->sz++;
	}
	//�ر���
	fclose(pf);
	pf = NULL;

}


//��ʼ��ͨѶ¼
void InitContact(Contact* con)
{
	assert(con);
	con->sz = 0; //��ʼ����Ϊ0
	//��data���鿪ʼ��ÿ���ֽ�����Ϊ0������Ϊ���������С
	//memset(con->data, 0, sizeof(con->data));	
	//��̬�ڴ����汾
	//���ٳ�ʼ������
	con->capacity = INTO_MAX;
	PeoInfo* ps = (PeoInfo*)malloc(con->capacity  * sizeof(PeoInfo));
	//�������ʧ��
	if (NULL == ps)
	{
		perror("InitContact::malloc");
		return;
	}
	//�ռ俪�ٳɹ�
	con->data = ps;
	memset(con->data , 0 , con->capacity * sizeof(PeoInfo));
    LoadContact(con);
}


//�ͷ�ͨѶ¼�ڴ�
void ReleaseContact(Contact* con)
{
	free(con->data);
	con->data = NULL;
}



//���ݺ���
void AddCapacity(Contact* con)
{
	//����
		//�ݻ� +2 
	con->capacity += 2;
	PeoInfo* ps = (PeoInfo*)realloc(con->data, sizeof(PeoInfo) * con->capacity);

	//�������ʧ�� 
	if (ps == NULL)
	{
		perror("AddCaoacity::realloc");
		return;
	}
	//���ݳɹ�
	con->data = ps;
	
}

//�����ϵ��
void AddContact(Contact* con)
{
	assert(con);
	//�����������
	if (con->sz == con->capacity)
	{
		AddCapacity(con);
	}


	//��Ϣ¼��
	printf("����������->");
	scanf("%s",con->data[con->sz].name);
	printf("����������->");
	scanf("%d", &(con->data[con->sz].age));
	printf("�������Ա�->");
	scanf("%s", (con->data+con->sz)->sex);
	printf("������绰->");
	scanf("%s", (con->data + con->sz)->tele);
	printf("�������ַ->");
	scanf("%s", (con->data + con->sz)->addrs);
	//������� + 1
	con->sz++;
	printf("��ӳɹ�\n");
}


//��ӡ��ϵ��
void PrintContact(const Contact* const con)
{
	assert(con);
	int i = 0;
	printf("%-20s %-5s %-5s %-13s %-30s\n","����","����","�Ա�","�绰","��ַ");
	for (i = 0; i < con->sz; i++)
	{
		printf("%-20s %-5d %-5s %-13s %-30s\n",(con->data+i)->name, (con->data + i)->age, 
			(con->data + i)->sex,(con->data + i)->tele, (con->data + i)->addrs);
	}
}

//����������ϵ��
static int FindByName(const Contact* con,const char* name)
{
	assert(con);
	//��������
	int i = 0;
	for (i = 0; i < con->sz; i++)
	{
		//�� data�����ÿ��ÿ��name �� �����name �Ƚϣ�����0��ʾ��ͬ,��ͬ�ͷ�������
		if (0 == strcmp((con->data + i)->name, name))
			return i;
	}
	//ѭ������û�ҵ�������-1
	return -1;
}


//ɾ����ϵ��
void DelteContact(Contact* con)
{
	assert(con);

	if (con->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��޷�ɾ��\n");
		return;
	}
	char name[NAME_MAX];
	printf("������Ҫɾ��������->");
	scanf("%s",name);
	//����
	int ret = FindByName(con, name);
	if (-1 == ret )
	{
		printf("û�ҵ�����\n");
		return;
	}
	// ��data + ����������ֽ� �ƶ��� data + ������λ�á�
	int count = sizeof(con->data) - (ret+1) * sizeof(con->data[0]);
	memmove((con->data+ret), con->data+ret+1,count);
	//����-1
	con->sz--;
	printf("ɾ���ɹ�\n");
	
}


//������ϵ��
void SeacherContact(Contact* con)
{
	assert(con);

	char name[NAME_MAX];
	printf("������Ҫ����������->");
	scanf("%s", name);
	//����
	int ret = FindByName(con, name);
	if (-1 == ret)
	{
		printf("û�ҵ�����\n");
		return;
	}

	//�ҵ����ӡ������Ϣ
	printf("%-20s %-5s %-5s %-13s %-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s %-5d %-5s %-13s %-30s\n", (con->data + ret)->name, (con->data + ret)->age,
			(con->data + ret)->sex, (con->data + ret)->tele, (con->data + ret)->addrs);
}

//�޸���ϵ��
void ModifyContact(Contact* con)
{
	assert(con);

	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ�����->");
	scanf("%s", name);
	//����
	int ret = FindByName(con, name);
	if (-1 == ret)
	{
		printf("û�ҵ�����\n");
		return;
	}
	//�޸�
	printf("����������->");
	scanf("%s", con->data[ret].name);
	printf("����������->");
	scanf("%d", &(con->data[ret].age));
	printf("�������Ա�->");
	scanf("%s", (con->data + ret)->sex);
	printf("������绰->");
	scanf("%s", (con->data + ret)->tele);
	printf("�������ַ->");
	scanf("%s", (con->data + ret)->addrs);

	printf("�޸ĳɹ�\n");
}

//����˵�
static void SortMenu()
{
	printf("************************************\n");
	printf("*****  1.Age_asc    2.Age_dec  *****\n");
	printf("*****  3.Name_asc   4.Name_dec *****\n");
	printf("************************************\n");
}


//����
void SortContact(Contact* con)
{
	//��ӡ�˵�SortMenu()
	SortMenu();
	int input = 0;

	printf("�������������ѡ��->");
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
		printf("������ȡ��\n");
		falg = 0;
		break;
	}
	if (falg)
		printf("����ɹ�\n");
}


//����ͨѶ¼
void SaveContact(Contact* con)
{
	//���ļ�
	FILE* fp = fopen("contact.dat","wb");
	if (fp == NULL)
	{
		perror("SaveContact::fopen");
		return;
	}
	//д����
	int i = 0;
	for(i = 0 ; i < con->sz ; i++)
	fwrite(con->data+i,sizeof(PeoInfo),1,fp);

	//�ر��ļ�
	fclose(fp);
	fp = NULL;
}


void DelAll(Contact* con)
{
	memset(con->data, 0, con->capacity * sizeof(PeoInfo));
	con->sz = 0;
	con->capacity = INTO_MAX;
}

