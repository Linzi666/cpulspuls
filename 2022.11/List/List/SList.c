#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"


//���ٽڵ�
SLNode* SLCreateNode(DataType x)
{
	//����һ���ڵ�
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	newNode->data = x;
	newNode->next = NULL;
	if (newNode == NULL)
	{
		printf("SListPushBack::newNode is Null\n");
		exit(-1);
	}
	return newNode;
}


//�����ӡ
void SListPrint(SLNode* head)
{
	SLNode* cru = head;
	while (cru)
	{
		printf("%d->",cru->data);
		cru = cru->next;
	}
	printf("NULL\n");
}

//����β��
void SListPushBack(SLNode** pphead, DataType x )
{
	
	SLNode* newNode  =  SLCreateNode(x);
	SLNode* tail = *pphead;
	
	//��� ͷ��Ϊ�գ�˵������û��Ԫ��
	if (tail == NULL)
	{
		//����û��Ԫ�ء���ô�ѿ��ٵĽڵ�� pphead ��������һ��Ԫ��
		*pphead = newNode;
		return;
	}

	//�ж�tail����һ���ڵ��Ƿ�ΪNULL
	while (tail->next)
	{
		// �ҵ�β��
		tail = tail->next;
	}
	//tailָ��Ľڵ�ΪNULL��˵�������һ���ڵ㣬����ָ��newNode
	tail->next = newNode;
}

//�ڵ�ͷ��
void SListPushFront(SLNode** pphead, DataType x)
{
	//����һ���ڵ�
	SLNode* newNode =  SLCreateNode(x);
	
	//�½ڵ�ָ�� ͷ�ڵ�
	newNode->next = *pphead;
	//Ȼ���ͷ�ڵ� �� �½ڵ�
	*pphead = newNode;

}

//�ڵ�βɾ
void SListPopBack(SLNode** pphead)
{
	//���ͷΪ�գ��޷�����ɾ�����ֱ���������
	assert(*pphead);

	//���ֻ��һ������
	if ((*pphead)->next == NULL)
	{
		//�ͷ�ͷ����
		free(*pphead);
		*pphead = NULL;
		return;
	}

	//�ҵ����һ���ڵ�ĵ�ַ���ͷ��ÿգ�����Ҫ������ǰһ���ڵ�ָ��Ľڵ���Ϊ��ָ��
	SLNode* end = *pphead; //����һ���ڵ�
	SLNode* prev = NULL; //�����ڶ����ڵ�

	while (end->next)
	{
		//�Ȱ����Ľڵ㸳��prev
		prev = end;
		end = end->next;
	}

	//��prevָ���ֵ�ÿ�
	prev->next = NULL;
	free(end);
	end = NULL;
}


//�ڵ�ͷɾ
void SListPopFront(SLNode** pphead)
{
	// �жϵ�һ���ڵ��Ƿ�Ϊ��
	assert(*pphead);

	//���ָ���ֵΪ��
	if ((*pphead) == NULL)
	{
		//ֱ��ͷ�ڵ��ÿ�
		free(*pphead);
		*pphead = NULL;
		return;
	}

	SLNode* tmp = (*pphead)->next;
	//�ͷ�ͷ�ڵ�Ŀռ�
	free(*pphead);
	//ͷ�ڵ�����֮ǰָ��Ŀռ�
	*pphead = tmp;
}


//���ҽڵ�
SLNode* SListFindNode(SLNode* phead, DataType x)
{
	SLNode* cru = phead;

	while (cru)
	{
		if (cru->data == x)
		{
			return cru;
		}
		cru = cru->next;
	}
	return NULL;
}


//ָ��λ�ò�������
void SListInsert(SLNode** pphead, SLNode* pos, DataType x)
{
	assert(pos);
	
	//�����ͷ��
	if ((*pphead) == pos)
	{
		SListPushFront(pphead,x);
		return;
	}
	else
	{

		//�������ͷ��	
		//��ȡһ���ڵ�
		SLNode* newNode = SLCreateNode(x);

		//�ҵ�pos�ڵ��ǰһ���ڵ�
		SLNode* cru = *pphead;
		while (cru->next != pos)
		{
			cru = cru->next;
		}
		//ǰ�ڵ�ָ���½ڵ㣬�½ڵ�ָ���ڵ�
		cru->next = newNode;
		newNode->next = pos;
	}

}


//ɾ��ָ���ڵ�
void SListEase(SLNode** pphead, SLNode* pos)
{
	assert(pos);
	
	//�ж�Ҫɾ���Ľڵ��Ƿ�Ϊͷ�ڵ�
	if (pos == (*pphead))
	{
		SListPopFront(pphead);
		return;
	}

	SLNode* cru = *pphead;
	//�ҵ�ɾ���ڵ��ǰһ��λ��
	while (cru->next != pos)
	{
		cru = cru->next;
	}
	//��cruָ��pos�ĺ�һ���ڵ�
	cru->next = pos->next;
	//�ͷ�pos�ڵ�
	free(pos);
	pos = NULL;
}




//��������
void SListDestory(SLNode** pphead)
{
	SLNode* cru = NULL;
	while (*pphead)
	{
		//����һ��λ�ô洢����
		cru = (*pphead)->next;
		//�ͷŵ�ǰ�ռ�
		free(*pphead);
		//����һ��λ�ÿռ��ͷ
		*pphead = cru;
	}
}
