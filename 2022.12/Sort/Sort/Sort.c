#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#include "MyStack.h"

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//打印
void PrintSort(int* data, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", data[i]);

	printf("\n");
}

//插入排序
void InsertSort(int* data, int n)
{
	assert(data);
	
	//从第一个数开始到倒数第二个停止
	for (int i = 0; i < n - 2; i++)
	{
		
		int end = i;
		//x指向end后的数
		int x = data[end + 1];

		//一趟插入
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
		//这一趟的最大值在 end+1的位置
		data[end + 1] = x;
	}
}

//希尔排序
void ShellSort(int* data, int n)
{
	assert(data);
	int gap = n;

	while (gap > 1)
	{
		//gap / 3 ，效率最快，最后gap一定会等于1，而gap=1时就是最后一趟插入排序
		gap = gap / 3 + 1;
		//每间隔gap的数据为一组，进行插入排序
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int x = data[end + gap];
			//一趟插入排序
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

//选择排序
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

//堆排序
void HeapSort(int* data, int n)
{
	assert(data);
	//从最后一个父亲开始，向下调整
	int LastFather = (n - 1 - 1) / 2;

	//往前向下调整建大堆
	while (LastFather >= 0)
	{
		AdjustDownDsc(data, n, LastFather);
		LastFather--;
	}

	//建完大堆后
	int end = n - 1;
	while (end > 0)
	{
		//堆顶与最后一个元素进行交换
		Swap(&data[0], &data[end]);
		//向下调整
		AdjustDownDsc(data,end-1,0 );
		--end;
	}
}

//冒泡排序
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


//三数取中

int GetMid(int* data,int left, int right)
{
	int mid = left + (right - left) / 2;

	return data[left] > data[right] ? (data[left] < data[mid] ? left :
		(data[mid] < data[right] ? right : mid)) : (data[left] > data[mid] ? left :
			(data[mid] > data[right]) ? right : mid);
}

//Hoare法
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


//挖坑法
int Partition2(int* data, int left, int right)
{
	assert(data);

	int key = GetMid(data, left, right);
	Swap(&data[key], &data[left]);
	int pit = left;
	int keyx = data[left];

	while (left < right)
	{
		//右边找小
		while (left < right && data[right] >= keyx)
		{
			right--;
		}
		data[pit] = data[right];
		pit = right;

		//左边找大
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

//双指针
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

//快排
void QuickSort(int* data, int left,int right)
{
	assert(data);
	if (left >= right)
		return;

	//如果区间为10，用插入排序,小区间优化
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

//非递归的快速排序
//void QuickSortNonR(int* data, int left, int right)
//{
//	assert(data);
//	ST st;
//	StackInto(&st);
//	//把左右区间入栈
//	StackPush(&st, left);
//	StackPush(&st, right);
//	//栈不为空，一直执行
//	while (!StackEmpty(&st))
//	{
//		int end = StackTop(&st);
//		StackPop(&st);
//		int begin = StackTop(&st);
//		StackPop(&st);
//		int keyi = Partition3(data,begin,end);
//
//		//右边区间入栈
		//[left,key-1]  key [key+1,right]
//		if (keyi < end - 1)
//		{
//			StackPush(&st, keyi + 1);
//			StackPush(&st, end);
//		}
//		//左边区间入栈
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
	//把左右区间入栈
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

//归并
void _MergeSort(int* data, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	//找中间点一刀切
	int mid = (left + right) / 2;
	
	//左区间递归归并
	_MergeSort(data, left, mid, tmp);

	//右区间递归归并
	_MergeSort(data, mid+1, right, tmp);

	//归并操作 
	//左区间 left,mid ， 右区间 mid+1,right
	int begin1 = left; 
	int end1 = mid;
	//右区间
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		//归并
		if (data[begin1] < data[begin2])
		{
			tmp[i++] = data[begin1++];
		}
		else
		{
			tmp[i++] = data[begin2++];
		}
	}

	//处理较长数组的后面数据
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

//非递归归并
void MergeSortNonR(int* data, int n)
{
	assert(data);
	int* tmp = (int*)malloc(sizeof(int) * n );
	int gap = 1;

	int i = 0;

	while (gap < n)
	{
		//整组数据一趟操作
		for (int i = 0; i < n; i += gap * 2)
		{
			//左区间范围 [i,i+gap-1]
			int begin1 = i;
			int end1 = i + gap - 1;
			//右区间范围[i+gap,i+2*gap-1]
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			//边界控制
			if (end1 >= n)
			{
				end1 = n - 1;

			}

			//边界控制
			if (begin2 >= n)
			{
				begin2 = n ;
				end2 = n - 1;
			}

			//边界控制
			if (end2 >= n)
				end2 = n - 1;

			//tmp写入数据下标记录
			int index = begin1;

			//区间归并
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

			//归并较长区间
			while (begin1 <= end1)
			{

				tmp[index++] = data[begin1++];
			}

			while (begin2 <= end2)
			{

				tmp[index++] = data[begin2++];
			}


		}
		//更新数组
		for (int j = 0; j < n; j++)
			data[j] = tmp[j];

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;

}
