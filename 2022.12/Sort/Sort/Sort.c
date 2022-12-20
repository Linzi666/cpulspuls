#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "MyStack.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//��ӡ
void PrintSort(int* data, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", data[i]);

	printf("\n");
}

//��������
void InsertSort(int* data, int n)
{
	assert(data);
	
	//�ӵ�һ������ʼ�������ڶ���ֹͣ
	for (int i = 0; i < n - 2; i++)
	{
		
		int end = i;
		//xָ��end�����
		int x = data[end + 1];

		//һ�˲���
		while (end >= 0)
		{
			if (data[end] > x)
			{
				data[end + 1] = data[end];
				end--;
			}
			else
			{
				break;
			}
		}
		//��һ�˵����ֵ�� end+1��λ��
		data[end + 1] = x;
	}
}

//ϣ������
void ShellSort(int* data, int n)
{
	assert(data);
	int gap = n;

	while (gap > 1)
	{
		//gap / 3 ��Ч����죬���gapһ�������1����gap=1ʱ�������һ�˲�������
		gap = gap / 3 + 1;
		//ÿ���gap������Ϊһ�飬���в�������
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = data[end + gap];
			//һ�˲�������
			while (end >= 0)
			{
				if (data[end] > x)
				{
					data[end + gap] = data[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			data[end + gap] = x;

		}
	}
	
}

//ѡ������
void SelectSort(int* data, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;

		for (int i = begin; i <= end; i++)
		{
			if (data[i] > data[maxi])
				maxi = i;

			if (data[i] < data[mini])
				mini = i;
		}

		Swap(&data[begin], &data[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&data[end], &data[maxi]);

		begin++;
		end--;
	}
}

//������
void HeapSort(int* data, int n)
{
	assert(data);
	//�����һ�����׿�ʼ�����µ���
	int LastFather = (n - 1 - 1) / 2;

	//��ǰ���µ��������
	while (LastFather >= 0)
	{
		AdjustDownDsc(data, n, LastFather);
		LastFather--;
	}

	//�����Ѻ�
	int end = n - 1;
	while (end > 0)
	{
		//�Ѷ������һ��Ԫ�ؽ��н���
		Swap(&data[0], &data[end]);
		//���µ���
		AdjustDownDsc(data,end-1,0 );
		--end;
	}
}

//ð������
void BubbleSort(int* data, int n)
{
	int end = n - 1;
	while (end--)
	{
		int falg = 1;
		for (int i = 0; i <= end; i++)
		{
			if (data[i] > data[i+1])
			{
				Swap(&data[i], &data[i+1]);
				falg = 0;
			}
		}
		if (falg)
			break;
	}
}


//����ȡ��

int GetMid(int* data,int left, int right)
{
	int mid = left + (right - left) / 2;

	return data[left] > data[right] ? (data[left] < data[mid] ? left :
		(data[mid] < data[right] ? right : mid)) : (data[left] > data[mid] ? left :
			(data[mid] > data[right]) ? right : mid);
}

//Hoare��
int Partition(int* data, int left, int right)
{
	assert(data);
	
	int key = GetMid(data,left,right);
	Swap(&data[key], &data[left]);
	key = left;

	while (left < right)
	{
		while (left < right && data[right] >= data[key])
			right--;
		

		while (left < right  && data[left] <= data[key])				
			left++;

		Swap(&data[left], &data[right]);
	}
	
	Swap(&data[left], &data[key]);

	return left;
}


//�ڿӷ�
int Partition2(int* data, int left, int right)
{
	assert(data);

	int key = GetMid(data, left, right);
	Swap(&data[key], &data[left]);
	int pit = left;
	int keyx = data[left];

	while (left < right)
	{
		//�ұ���С
		while (left < right && data[right] >= keyx)
		{
			right--;
		}
		data[pit] = data[right];
		pit = right;

		//����Ҵ�
		while (left < right && data[left] <= keyx)
		{
			left++;
		}
		data[pit] = data[left];
		pit = left;
	}
	
	data[pit] = keyx;
	return pit;
	
}

//˫ָ��
int Partition3(int* data, int left, int right)
{
	assert(data);
	int key = GetMid(data, left, right);
	Swap(&data[key], &data[left]);

	int prve = left;
	int cru = prve + 1;
	 key = left;
	
	while (cru <= right)
	{
		if (data[cru] < data[key] && ++prve != cru)
		{
			Swap(&data[cru], &data[prve]);
		}
		cru++;
	}
	Swap(&data[prve], &data[key]);
	return prve;
}

//����
void QuickSort(int* data, int left,int right)
{
	assert(data);
	if (left >= right)
		return;

	//�������Ϊ10���ò�������,С�����Ż�
	if (right - left + 1 < 10)
	{
		InsertSort(data+left,right-left + 1);
	}
	else
	{
		int key = Partition3(data, left, right);
		QuickSort(data, left, key - 1);
		QuickSort(data, key + 1, right);
	}
}

//�ǵݹ�Ŀ�������
//void QuickSortNonR(int* data, int left, int right)
//{
//	assert(data);
//	ST st;
//	StackInto(&st);
//	//������������ջ
//	StackPush(&st, left);
//	StackPush(&st, right);
//	//ջ��Ϊ�գ�һֱִ��
//	while (!StackEmpty(&st))
//	{
//		int end = StackTop(&st);
//		StackPop(&st);
//		int begin = StackTop(&st);
//		StackPop(&st);
//		int keyi = Partition3(data,begin,end);
//
//		//�ұ�������ջ
		//[left,key-1]  key [key+1,right]
//		if (keyi < end - 1)
//		{
//			StackPush(&st, keyi + 1);
//			StackPush(&st, end);
//		}
//		//���������ջ
//		if (begin + 1 < end)
//		{
//			StackPush(&st, begin);
//			StackPush(&st, keyi - 1);
//		}
//	}
//}

void QuickSortNonR(int* data, int left, int right)
{
	assert(data);
	ST st;
	StackInto(&st);
	//������������ջ
	StackPush(&st,left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		right = StackTop(&st);
		StackPop(&st);
		left = StackTop(&st);
		StackPop(&st);
		int key = Partition3(data, left, right);
		if (left < right)
		{
			StackPush(&st,left);
			StackPush(&st, key - 1);
			StackPush(&st, key + 1);
			StackPush(&st, right);
		}

	}

}

//�鲢
void _MergeSort(int* data, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	//���м��һ����
	int mid = (left + right) / 2;
	
	//������ݹ�鲢
	_MergeSort(data, left, mid, tmp);

	//������ݹ�鲢
	_MergeSort(data, mid+1, right, tmp);

	//�鲢���� 
	//������ left,mid �� ������ mid+1,right
	int begin1 = left; 
	int end1 = mid;
	//������
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		//�鲢
		if (data[begin1] < data[begin2])
		{
			tmp[i++] = data[begin1++];
		}
		else
		{
			tmp[i++] = data[begin2++];
		}
	}

	//����ϳ�����ĺ�������
	while (begin1 <= end1)
	{
		tmp[i++] = data[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = data[begin2++];
	}
	
	for (int j = left; j <= right;j++)
	{
		data[j] = tmp[j];
	}
}

void MergeSort(int* data, int n)
{
	assert(data);
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(data, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;

}

//�ǵݹ�鲢
void MergeSortNonR(int* data, int n)
{
	assert(data);
	int* tmp = (int*)malloc(sizeof(int) * n );
	int gap = 1;

	int i = 0;

	while (gap < n)
	{
		//��������һ�˲���
		for (int i = 0; i < n; i += gap * 2)
		{
			//�����䷶Χ [i,i+gap-1]
			int begin1 = i;
			int end1 = i + gap - 1;
			//�����䷶Χ[i+gap,i+2*gap-1]
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			//�߽����
			if (end1 >= n)
			{
				end1 = n - 1;

			}

			//�߽����
			if (begin2 >= n)
			{
				begin2 = n ;
				end2 = n - 1;
			}

			//�߽����
			if (end2 >= n)
				end2 = n - 1;

			//tmpд�������±��¼
			int index = begin1;

			//����鲢
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (data[begin1] < data[begin2])
				{
					tmp[index++] = data[begin1++];
				}
				else
				{
					tmp[index++] = data[begin2++];

				}
			}

			//�鲢�ϳ�����
			while (begin1 <= end1)
			{

				tmp[index++] = data[begin1++];
			}

			while (begin2 <= end2)
			{

				tmp[index++] = data[begin2++];
			}


		}
		//��������
		for (int j = 0; j < n; j++)
			data[j] = tmp[j];

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;

}
