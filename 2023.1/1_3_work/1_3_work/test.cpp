#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
*/
void work1()
{
	int A, B, C, D, E;
	for (A = 1; A <= 5; A++)
	{
		for (B = 1; B <= 5; B++)
		{
			for (C = 1; C <= 5; C++)
			{
				for (D = 1; D <= 5; D++)
				{
					for (E = 1; E <= 5; E++)
					{
						if ((((A == 3) + (B == 2)) == 1)
							&& ((B == 2) + (E == 4) == 1)
							&& (C == 1) + (D == 2) == 1
							&& (D == 3) + (C == 5) == 1
							&& (E == 4) + (A == 1) == 1
							&& A*B*C*D*E == 120)
						{
							cout << A << " " << B << " " << C << " " << D << " " << E << endl;
						}
					}
				}
			}
		}
	}
}

/*
�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
����Ϊ4�����ɷ��Ĺ���:
A˵�������ҡ�
B˵����C��
C˵����D��
D˵��C�ں�˵
��֪3����˵���滰��1����˵���Ǽٻ���
*/
void work2()
{
	char killer = 'A';
	for (killer; killer <= 'D'; killer++)
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
			cout << killer << endl;
}
//����Ļ�ϴ�ӡ������ǡ�
void work3()
{
	int n = 0;
	scanf("%d", &n);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(sizeof(int) * (i + 1));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);

}

int main()
{
	//work1();
	//work2();
	work3();
	return 0;
}