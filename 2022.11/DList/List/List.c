
#include "List.h"



//�����ʼ��
LSNode* ListInto()
{
	//����һ���ڵ�
	LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
	//ָ���Լ�
	newNode->next = newNode;
	newNode->prve = newNode;
	
	return newNode;
}

//�����ڵ�
LSNode* CreateListNode(ListValType x)
{
	LSNode* newNode = (LSNode*)malloc(sizeof(LSNode));
	if (newNode == NULL)
	{
		//�ռ俪��ʧ�ܣ�������
		exit(-1);
	}
	newNode->val = x;
	return newNode;
}

//β��
void ListPushBack(LSNode* phead, ListValType x)
{
	/*
	//���ԣ�phead����Ϊ��
	assert(phead);

	//����һ���½ڵ�
	LSNode* newNode = CreateListNode(x);
	//��¼ͷ�ڵ��ǰһ���ڵ㣬Ҳ����β�ڵ�
	LSNode* tail = phead->prve;
	//β�ڵ�ָ�� �½ڵ�
	tail->next = newNode;
	//�½ڵ�ǰ�ڵ�ָ��β�ڵ�
	newNode->prve = tail;
	//��ڵ�ָ��ͷ�ڵ�
	newNode->next = phead;
	//ͷ�ڵ�ǰ�ڵ�ָ���½ڵ�
	phead->prve = newNode;
	*/
	ListInsert(phead, phead->prve, x);

}

//��ӡ����
void ListPrint(LSNode* phead)
{
	assert(phead);
	//ͷ�ڵ��ŵ�����Чֵ�����Դ�ͷ�ڵ���һ��λ�ÿ�ʼ��ӡ
	LSNode* cru = phead->next;
	//cru == pheadʱ˵����������һȦ��
	while (cru != phead)
	{
		printf("%d->", cru->val);
		cru = cru->next;
	}
	printf(".....\n");
}


//ͷ��
void ListPushFront(LSNode* phead, ListValType x)
{
	/*
	//���ԣ�phead����Ϊ��
	assert(phead);

	//����һ���½ڵ�
	LSNode* newNode = CreateListNode(x);
	//����ͷ�ڵ����һ���ڵ�
	LSNode* Next = phead->next;
	//nextǰ�ڵ�ָ���½ڵ�
	Next->prve = newNode;
	//�½ڵ�nextָ��Next
	newNode->next = Next;
	//ͷ�ڵ�nextָ���½ڵ�
	phead->next = newNode;
	//�½ڵ�ǰ�ڵ�ָ��ͷ�ڵ�
	newNode->prve = phead;
	*/
	ListInsert(phead,phead->next,x);
}

//βɾ
void ListPopBack(LSNode* phead)
{
	/*
	//phead����Ϊ��
	assert(phead);
	//β�ڵ㲻��ͷ�ڵ�һ��
	assert(phead != phead->prve);
	
	//β�ڵ�
	LSNode* tail = phead->prve;
	//β�ڵ��ǰһ���ڵ�
	LSNode* prvetail = tail->prve;
	//�ͷ�β�ڵ�
	free(tail);
	//prvetail ���� ͷ�ڵ�
	prvetail->next = phead;
	phead->prve = prvetail;
	*/

	ListEase(phead, phead->prve);
}

//ͷɾ
void ListPopFront(LSNode* phead)
{
	/*
	assert(phead);
	assert(phead != phead->prve);

	//ͷ�ڵ����һ���ڵ�
	LSNode* headNext = phead->next;
	//���¸��ڵ�
	LSNode* nextnext = headNext->next;
	//����ͷ�ڵ�� nextnext
	nextnext->prve = phead;
	phead->next = nextnext;

	//�ͷ�headNext
	free(headNext);
	headNext = NULL;
	*/
	ListEase(phead, phead->next);
}



//����
LSNode* ListFindNode(LSNode* phead, ListValType x)
{
	assert(phead);
	//ͷ�ڵ��ŵ�����Чֵ�����Դ�ͷ�ڵ���һ��λ�ÿ�ʼ����
	LSNode* cru = phead->next;
	//cru == pheadʱ˵����������һȦ��
	while (cru != phead)
	{
		if (cru->val == x)
			return cru;

		cru = cru->next;
	}
	return NULL;
}

//ָ������
void ListInsert(LSNode* phead, LSNode* pos, ListValType x)
{
	//pos��phead����Ϊ��
	assert(pos && phead);
	
	//�����ڵ�
	LSNode* newNode = CreateListNode(x);

	//����pos��ǰһ���ڵ�
	LSNode* posprve = pos->prve;
	//Ȼ����������
	posprve->next = newNode;
	newNode->prve = posprve;
	newNode->next = pos;
	pos->prve = newNode;
}

//ָ��ɾ��
void ListEase(LSNode* phead, LSNode* pos)
{
	//pos��phead����Ϊ��
	assert(pos && phead);

	//����posǰ��ڵ�
	LSNode* posprve = pos->prve;
	LSNode* posnext = pos->next;

	//ǰ��ڵ�����
	posprve->next = posnext;
	posnext->prve = posprve;

	//�ͷ�pos�ռ�
	free(pos);
	pos = NULL;
}


//��������,��Ϊ��ı�ԭ����phead�ڵ㣬������Ҫ������ָ��
void ListDestroy(LSNode** pphead)
{
	assert(*pphead);
	
	LSNode* cru = (*pphead)->next;
	while (1)
	{
		//�����һ���ڵ�
		LSNode* next = cru->next;
		//�ͷ�cru
		free(cru);
		//����
		cru = next;
		//���cru ��ͷ�ڵ���ȣ�˵��ͷ�ڵ����Ķ�ɾ����
		if (cru == *pphead)
		{
			//�ͷ�ͷ�ڵ�ռ�
			free(*pphead);
			//ָ���ÿ�
			*pphead = NULL;
			//����ѭ��
			break;	
		}
	}

}