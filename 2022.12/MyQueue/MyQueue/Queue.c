#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

//��ʼ��
void QueueInto(Queue* q)
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}

//�����ڵ�
QueueNode* CreateNode(QDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		printf("malloc faile\n");
		exit(-1);
	}
	newNode->next = NULL;
	newNode->val = x;
	return newNode;
}

//�������
void QueuePush(Queue* q, QDataType x)
{
	//����
	assert(q);

	//�����ڵ�
	QueueNode* newNode = CreateNode(x);
	//���head NULL
	if (q->head == NULL)
	{
		q->head = newNode;
		q->tail = newNode;
	}
	else
	{
		//β�ڵ�ָ���½ڵ�
		q->tail->next = newNode;
		//β�ڵ��ƶ�λ��
		q->tail = newNode;
	}
}

//�ж϶����Ƿ�Ϊ��
bool QueueIsEmpty(Queue* q)
{
	return q->head == NULL;
}

//���ݳ���
void QueuePop(Queue* q)
{
	assert(q);
	//Ҫ��֤�����������ݿ���ɾ��
	assert(!QueueIsEmpty(q));

	//ͷɾ
	QueueNode* next = q->head->next;
	free(q->head);
	q->head = next;
}

//��ȡ��ͷ
QDataType QueueGetFront(Queue* q)
{
	assert(q);
	//Ҫ��֤������������
	assert(!QueueIsEmpty(q));
	return q->head->val;
}

//��ȡ��β
QDataType QueueGetBack(Queue* q)
{
	assert(q);
	//Ҫ��֤������������
	assert(!QueueIsEmpty(q));
	return q->tail->val;
}


//��ȡ���г���
size_t QueueGetSize(Queue* q)
{
	assert(q);
	//Ҫ��֤������������
	assert(!QueueIsEmpty(q));
	int len = 1;
	QueueNode* head = q->head;
	QueueNode* tail = q -> tail;
	while (head != tail)
	{
		len++;
		head = head->next;
	}
	return len;
}

//����
void QueueDestroy(Queue* q)
{
	QueueNode* cru = q->head;
	while (cru != NULL)
	{
		//�洢��һ��λ�õ�ַ
		QueueNode* next = cru->next;
		free(cru);
		cru = next;
	}
	
}