#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

//�����ڵ�
SLNode* SListCreateNode(ListDataType x)
{
	//�¿���һ���ڵ�
	SLNode* newNode = (SLNode*)malloc(sizeof(SLNode));
	if (newNode == NULL)
	{
		//�ռ俪��ʧ��
		printf("SListPushBack::newNode");
		exit(-1);
	}

	//�½ڵ�ָ��NULL���洢����x
	newNode->data = x;
	newNode->Next = NULL; 
	return newNode;
}

//β�����ݲ���
void SListPushBack(SLNode** phead, ListDataType x)
{
	
	SLNode* newNode = SListCreateNode(x);

	if (*phead == NULL)
	{
		//��ǰ����Ϊ�գ���ô��ֱ�����½ڵ����phead
		*phead = newNode;
		return;
	}

	//�ҵ����һ���ڵ�
	SLNode* cru = *phead;

	//���cruָ��NULL��˵��cru�����һ���ڵ�
	while (cru->Next != NULL)
	{
		cru = cru->Next;
	}
	//cru ָ���½ڵ�
	cru->Next = newNode; 
}

//�����ӡ
void SListPrint(SLNode* head)
{
	SLNode* cru = head;
	while (cru)
	{
		printf("%d->",cru->data);
		cru = cru->Next;
	}
	printf("NULL\n");
}


//ͷ�����ݲ���
void SListPushFront(SLNode** phead, ListDataType x)
{
	//�½��ڵ�
	SLNode* newNode = SListCreateNode(x);

	//�ýڵ�ָ��ͷ
	newNode->Next = *phead;
	//ͷ�ڵ����Ϊ�½ڵ�
	*phead = newNode;
	
}

//β������ɾ��
void SListPopBack(SLNode** phead)
{
	//����Ϊ���޷�ɾ��
	assert(*phead);

	//ֻ��һ���ڵ�ʱ
	if((*phead)->Next == NULL)
	{ 
		//�ͷ�ͷ�ռ�
		free(*phead);
		//��Ϊ��ָ��
		*phead = NULL;
		return;
	}

	SLNode* cru = *phead; //���һ���ڵ�
	SLNode* prve = NULL; //ǰһ���ڵ�

	//�ҵ����һ���ڵ�
	while (cru->Next)
	{
		prve = cru;
		cru = cru->Next;
	}
	//cru Ϊ���һ���ڵ㡣�ͷŵ�
	free(cru);
	//ǰһ���ڵ�ָ���
	prve->Next = NULL;

}


//ͷ������ɾ��
void SListPopFront(SLNode** phead)
{
	//����
	assert(*phead);

	//����Ϊ�գ��洢��һ��λ�õĵ�ַ
	SLNode* NextNode = (*phead)->Next;
	//�ͷ� *phead 
	free(*phead);
	//�洢�Ľڵ��*phead
	*phead = NextNode;

}

SLNode* SListFindNode(SLNode* head, ListDataType x)
{
	SLNode* cru = head;
	//����ֵ
	while (cru)
	{
		//�����ǰ�ڵ����Ҫ���ҵ�ֵ
		if (cru->data == x)
		{
			//���ص�ǰ�ڵ㣬Ҳ���Է����±꣬�Ѻ�������ֵ�ĳ�int
			return cru;
		}
		//��һ���ڵ�
		cru = cru->Next;
	}

	//������û���ҵ��� ���ؿ�ָ��
	return NULL;
}

//ָ������
void SListInsert(SLNode** phead, SLNode* pos, ListDataType x)
{
	//���Ȳ���֮ǰ�����Ǳ��뱣֤�������pos�ڵ���ڣ���Ȼ�޷�����
	assert(pos);

	//ͷ�ڵ����pos
	if (*phead == pos)
	{
		//����ͷ��
		SListPushFront(phead,x);
		return 0;
	}
	
	SLNode* cru = *phead; //�������ұ�����Ľڵ�

	//����pos�ڵ�
	while (cru->Next != pos)
	{
		cru = cru->Next;
	}

	//�ҵ��󣬴���һ���½ڵ�
	SLNode* newNode = SListCreateNode(x);
	//�½ڵ�ָ��pos
	newNode->Next = pos;
	//pos��ǰһ���ڵ�ָ��cru
	cru->Next = newNode;
}


//ָ���ڵ�ɾ��
void SListEase(SLNode** phead, SLNode* pos)
{
	//pos�ǿ�ָ�룬�ɵ�����
	assert(pos);

	//���ͷ�ڵ���pos��ȣ�ֱ�ӵ���ͷɾ
	if (*phead == pos)
	{
		SListPopFront(phead);
		return;
	}

	//����һ���ڵ�
	SLNode* cru = *phead;  //���ұ�ɾ���ڵ��ǰһ���ڵ�
	while (cru->Next != pos)
	{
		cru = cru->Next;
	}
	
	//cruָ�� pos ���λ��
	cru->Next = pos->Next;

	//�ͷ�pos���ڿռ�
	free(pos);
	pos = NULL;

}


//��������
void SListDestroy(SLNode** phead)
{
	SLNode* cru = NULL;

	while (*phead)
	{
		//�洢��һ���ڵ�ĵ�ַ
		cru = (*phead)->Next;
		//�ͷŵ�ǰ�ռ�
		free(*phead);
		//��ǰ��ַ�ÿ�
		*phead = NULL;
		//������һ���ڵ����
		*phead = cru;
	}

}


