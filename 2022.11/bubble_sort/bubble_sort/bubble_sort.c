#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//ð������
void bubble_sort(int arr[],int sz)
{
	//ʵ��ð������,ð�����������Ƚϣ�����Ѵ�������ұ�
	int i = 0; //ð�����������
	int j = 0; //ÿ���������

	for (int i = 0; i < sz - 1; i++) //��Ϊ���һ��������Ҫ��������ֻ�� sz-1��
	{
		int flag = 1; //�ж��������û�н���ѭ��
		//ð�������ÿһ��
		for (int j = 0; j < sz - 1 - i; j++) //Ҳ��sz-1�ɣ���Ϊ�����ڶ�����������һ�����Ƚ�,ÿ�αȽ���,�Ͳ�������Ѿ��ȽϹ�����
		{
			if (arr[j] > arr[j + 1]) //������Ⱥ����һ������
			{
				//����λ��
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 0; //���������ѭ���ˣ�˵����û�����
			}
		}
		if (flag) //���flag ���ǣ�1��˵���Ѿ�������ˣ�ֱ���˳�ѭ��
			break; 
	}

}

//��ӡ����
void Printf_arr(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 9,0,1,2,3,4,5,6,7,8 }; //һ����������
	printf("����ǰ:");
	Printf_arr(arr, sizeof(arr) / sizeof(arr[0]));
	bubble_sort(arr,sizeof(arr)/sizeof(arr[0])); //���������Լ����鳤��
	printf("�����:");
	Printf_arr(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}