#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�
//Ҫ��ʱ�临�Ӷ�С��O(N);
void test1()
{
	int arr[3][3] = { {1,2,3},{3,4,5},{4,5,6} };
	int i = 0;
	int j = 2;
	int x = 6;
	while (i < 3 && j >= 0)
	{
		if (arr[i][j] < x)
		{
			i++;
		}
		else 
		{
			if (arr[i][j] == x)
			{
				break;
			}
			j--;
		}
	}
	if (j == -1 || i == 3)
	{
		printf("û�ҵ�");
	}
	else
		printf("�±�Ϊ%d,%d", i, j);
}


//ʵ��һ�����������������ַ����е�k���ַ���
void reverse(char* str,int left,int right)
{
	while (left < right)
	{
		char tmp = *(str + left);
		*(str + left) = *(str + right);
		*(str + right) = tmp;
		left++;
		--right;
	}
}

void test2()
{
	int k = 3;
	char str[] = "ABCDE";
	int len = strlen(str);
	printf("%s\n", str);
	reverse(str,0, k - 1);
	reverse(str,k, len-1);
	reverse(str,0, len - 1);
	printf("%s\n", str);

}

//�����Ӵ�
int A(char* str1,char* str2)
{
	char* a = str1;
	char* b = str2;
	char* cru = str2;
	while (*cru)
	{
		if (*cru == *a)
		{
			b = cru;
			while (*a)
			{
				if (*b++ != *a++)
					break;
			}
			if (*a == '\0')
				return 1;
			a = str1;
		}
		++cru;
	}
	return 0;
	
}

void test3()
{
	char str1[] = "AABCD";
	char str2[] = "BCDAA";
	int len = strlen(str1);
	char* str3 = (char*)malloc(len * 2);
	strncpy(str3, str1, len);
	strncpy(str3+len, str1, len);
	printf("%d",A(str2, str3));

}
int main()
{
	//test1();
	test3();
	return 0;
}