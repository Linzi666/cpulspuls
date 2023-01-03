#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
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
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
以下为4个嫌疑犯的供词:
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
*/
void work2()
{
	char killer = 'A';
	for (killer; killer <= 'D'; killer++)
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
			cout << killer << endl;
}
//在屏幕上打印杨辉三角。
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