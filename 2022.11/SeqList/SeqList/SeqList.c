#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqList.h"

//��ʼ��˳���
void SeqListInit(SL* pSL)
{
	assert(pSL);
	//�ݻ������ݸ�����Ϊ0
	pSL->capacity = pSL->size = 0;

	pSL->data = NULL;
}

//�ͷ��ڴ�
void SeqListDestory(SL* pSL)
{
	free(pSL->data);
	pSL = NULL;
}

//��ӡ˳���
void SqeListPrint(SL* pSL) {
	for (int i = 0; i < pSL->size; i++)
	{
		printf("%d ",*(pSL->data+i));
	}
	printf("\n");
}

//�����������
void static SLCheckCapacity(SL* pSL)
{
	if (pSL->size == pSL->capacity)
	{
		//����������ݻ���ȣ�����һ��
		int newCapacity = pSL->capacity == 0 ? 4 : 2 * pSL->capacity;
		pSL->capacity = newCapacity;
		//���ٻ����ݿռ�
		SLDataType* tmp = (SLDataType*)realloc(pSL->data,newCapacity * sizeof(SLDataType));

		//�ռ俪��ʧ��
		if (tmp == NULL)
		{
			perror("SLCheckCapacity::realloc");
			exit(-1);//�ɵ�����
		}

		//���ٳɹ�
		pSL->data = tmp;
	}

}

//β����������
void SeqListPushBack(SL* pSL,int x)
{
	//���ȼ������
	//SLCheckCapacity(pSL);
	//
	////sizeλ�ò�������
	//*(pSL->data + pSL->size) = x;
	//pSL->size++;
	SeqListPushSet(pSL, pSL->size, x);
}

//ͷ����������
void SeqListPushFtont(SL* pSL, int x)
{
	//�������
	//SLCheckCapacity(pSL);

	////�ڶ����������һ����ȫ�������ƶ�һ��
	//int i = pSL->size;
	//while (i--)
	//{
	//	*(pSL->data + i + 1) = *(pSL->data + i);
	//}
	//pSL->data[0] = x;
	//pSL->size++;
	SeqListPushSet(pSL, 0,x);

}


//β��ɾ������
void SeqListMoveBack(SL* pSL)
{
	/*if (pSL->size > 0)
		pSL->size--;*/
	 SeqListMoveSet( pSL, pSL->size - 1);
}

//ͷ��ɾ������
void SeqListMoveFront(SL* pSL)
{
	//sizeΪ0����ɾ������
	//if (pSL->size <= 0)
	//	return;

	////ɾ��ͷ�����ݣ��ӵڶ�����������ǰ��
	//int begin = 1;
	//while (begin < pSL->size)
	//{
	//	*(pSL->data + begin - 1) = *(pSL->data + begin);
	//	begin++;
	//}
	//pSL->size--;
	//ֱ�ӵ���ָ��λ��ɾ�����ݺ���
	SeqListMoveSet(pSL,0);
}

//ָ��λ��ɾ������
void SeqListMoveSet(SL* pSL, int pos)
{
	//�ж� pos �Ƿ��size������������Ϊ����
	if ((pSL->size - 1 < pos) || pos < 0)
	{
		printf("pos no exit\n");
		return;
	}
	//ɾ�����ݣ�ֻ��Ҫ�� pos �����λ��ǰ��
	int begin = pos+1;
	while (begin < pSL->size)
	{
		*(pSL->data + begin - 1) = *(pSL->data + begin) ;
		begin++;
	}
	pSL->size--;

}

//ָ��λ�ò�������
void SeqListPushSet(SL* pSL, int pos, int x)
{
	//�ж� pos �Ƿ��size��1��������������Ϊ����
	if ((pSL->size < pos) || pos < 0)
	{
		printf("pos no exit\n");
		return;
	}

	//�������
	SLCheckCapacity(pSL);

	//��pos �����ȫ�������ƶ�һ��
	for (int i = pSL->size - 1 ; i >= pos ; i--)
	{
		*(pSL->data + i + 1) = *(pSL->data + i);
	}
	//����x
	*(pSL->data + pos) = x;

	pSL->size++;
}


int SeqListFind(SL* pSL, SLDataType x)
{
	int i = 0;
	for (i = 0; i < pSL->size; i++)
	{
		if (pSL->data[i] == x)
			return i;
	}

	return -1;
}