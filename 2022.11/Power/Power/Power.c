#define _CRT_SECURE_NO_WARNINGS 1

//�ݹ�ʵ�� n �� k �η�

#include <stdio.h>
double power(int n,int k)
{
	 //��һ������� k = 0 

	if (k == 0)
		return 1;
	//�ڶ��������k>0
	else if (k > 0)
		return n * power(n, k-1);
	//�����������k, < 0
	else
		return 1.0 * power(n, -k);
}

int main()
{
	int n = 0; //n
	int k = 0; // k �η�
	scanf("%d %d",&n,&k); // �ֱ����� n �� k �η�
	double ret = power(n,k);
	printf("%d �� %d �η� : %lf",n,k,ret);

	return 0;
}