#define _CRT_SECURE_NO_WARNINGS 1

//���㺺ŵ���������ݹ�ʵ��


#include <stdio.h>



int hanoi(int n)
{
	//�ݹ�����
	if (n == 1)
		return 1;  //���ƽ�����ʼ�ع�
	return 2*hanoi(n-1)+1; //ÿһ�����ӵ�������  (n-1)*2+1
}

 
int main()
{
	hanoi(5);
	printf("%d ",hanoi(5));
	return 0;
}