#define _CRT_SECURE_NO_WARNINGS 1

//���ֲ��ҷ�
#include <stdio.h>

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9 ,10 };
	int k = 7; // Ҫ���ҵ�����
	int left = 0; //�����һ��Ԫ���±�
	int right = 9; //�������һ��Ԫ���±�
	int flag = 0; //�ж��Ƿ��ҵ�
	int mid = 0;  ////�����м��Ԫ���±�
	while (left <= right) //��left >rightʱ��˵���Ѿ�������� 
	{
		mid = (left + right) / 2; //�����м��Ԫ���±�
		if (arr[mid] > k) //��������м�Ԫ�ش���Ҫ���ҵ�ֵ��˵��Ҫ���ҵ�ֵ����ߣ���right�ƶ���mid-1��λ��
			right = mid - 1;
		else if (arr[mid] < k)
			left = mid + 1;//��������м�Ԫ��С��Ҫ���ҵ�ֵ��˵��Ҫ���ҵ�ֵ��mid�ұߣ���left�ƶ���mid+1��λ��
		else
		{
			flag = 1;
			break;
		}
	}

	if (flag)
		printf("%d��������±�Ϊ:%d\n", k, mid);
	else
		printf("û�ҵ�\n");


	return 0;

}