#define _CRT_SECURE_NO_WARNINGS 1

//�ݹ�ʵ�� n �� k �η�

#include <stdio.h>
int power(int n,int k)
{
	if (k != 0) //�ݹ���������
	{
		k--; //�ݹ������仯
		return n * power(n, k); 
	}
	else
		return 1;		
}

int main()
{
	int n = 0; //n
	int k = 0; // k �η�
	scanf("%d %d",&n,&k); // �ֱ����� n �� k �η�
	int ret = power(n,k);
	printf("%d �� %d �η� : %d",n,k,ret);

	return 0;
}