#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>


//����һ���������飬��ɶ�����Ĳ���
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
//ʵ��print()  ��ӡ�����ÿ��Ԫ��
//ʵ��reverse()  �����������Ԫ�ص����á�

void print(int* arr, int len)
{
	int i = 0;
	for (i; i < len; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void init(int* arr, int len)
{
	int i = 0;
	for (i; i < len; i++)
		*(arr + i) = 0;
}

void reverse(int* arr , int len)
{
	int left = 0;
	int right = len - 1;
	int temp = 0;
	while (left < right)
	{
		temp = *(arr + left);
		*(arr + left) = *(arr + right);
		*(arr + right) = temp;
		left++;
		right--;
	}

}

int main()
{
	int arr[] = { 1,2,3,4,5,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("�����ʼ����ӡ\n");
	print(arr,len);


	reverse(arr,len);
	printf("������ת���ӡ\n");
	print(arr, len);

	printf("������պ�\n");
	init(arr,len);
	print(arr, len);
	
	return 0;
}