#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//ɾ�����������е��ظ���

int DeleteRepeat(int* arr, size_t sz)
{
	//�ж�sz�Ƿ�Ϊ0
	if (sz == 0)
		return 0;

	//���������±�
	int index = 0;//Ҫ�滻���±�
	int left = 0; 
	int right = 0;
	while (right < sz)
	{
		//��� �±� left ��ֵ�������±�right ����ô���滻�±�index
		if (arr[left] != arr[right])
		{
			arr[index] = arr[left];
			left = right;
			right++;
			index++;
		}
		else
		{
			right++;
		}
	}
	//ѭ�������� left�������±�϶���û�м��ϵģ���Ϊright�Ѿ�����sz������ȥѭ����
	arr[index] = arr[left];
	return index + 1;
}



int main()
{
	int arr[] = { 1,1,2,2,3,4,4,5,5,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	len = DeleteRepeat(arr,len);
	for (int i = 0; i < len; i++)
		printf("%d", arr[i]);

	return 0;
}