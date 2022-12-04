
#include "MyStack.h"

//��ʼ��
void StackInto(ST* ST)
{
	ST->data = NULL;
	ST->top = 0;
	ST->Cacpcity = 0;
}

//��������
void CheckCacpcity(ST* ST)
{
	//��������topʱ��˵������û�пռ���
	if (ST->Cacpcity == ST->top)
	{
		//����ռ�Ϊ0����ʼ�ռ�4�������Ϊ0���ռ�*2
		int NewCacpcity = ST->Cacpcity == 0 ? 4 : ST->Cacpcity * 2;
		//����
		STDataType* newdata = (STDataType*)realloc(ST->data,sizeof(STDataType) * NewCacpcity);
		//�����Ƿ�ɹ�
		if (newdata == NULL)
		{
			printf("reallo fail\n");
			exit(-1);
		}
		ST->data = newdata;
		//��������
		ST->Cacpcity = NewCacpcity;
	}
}

//������ջ
void StackPush(ST* ST, STDataType x)
{
	//���ԣ���������ָ�벻��Ϊ��
	assert(ST);
	//���������Զ�����
	CheckCacpcity(ST);

	//β��������ջ
	*(ST->data+ST->top) = x;
	ST->top++;
}

//���ݳ�ջ
void StackPop(ST* ST)
{
	assert(ST);
	//���top����0��˵��û��Ԫ����
	assert(ST->top > 0);

	//��ջ������������ô��
	ST->top--;

}

//ջ�Ƿ�Ϊ��
bool StackEmpty(ST* ST)
{
	assert(ST);
	return ST->top == 0;
}

//ȡջ����ֵ
STDataType StackTop(ST* ST)
{
	assert(ST);
	assert(!StackEmpty(ST));
	return ST->data[ST->top - 1];
}
//����
void StackDestroy(ST* ST)
{
	assert(ST);
	ST->top = ST->Cacpcity = 0;
	free(ST->data);
	ST->data = NULL;
}
