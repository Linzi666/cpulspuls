#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

int B(char c)
{
	int num = c - 48; //����
	int xx = c - 55; //��д��ĸ
	int dx = c - 87;//Сд��ĸ
	if (num <= 9 && num >= 0)
		return num;
	else if (xx <= 15 && xx >= 10)
		return xx;
	else if (dx <= 15 && dx >= 10)
		return dx;
	else - 1; //16���Ƴ�����Χ������
}

//����һ��16�����������ʮ����
long long  A(char* str)
{
	//�ַ����ĳ��ȴ���λ��  ��дA - F��65-70 ,Сдa-f�� 97 - 102
	int len = strlen(str);
	int i = 0;
	long long sum = 0;//�������ۼ�֮��
	for (i; i < len; i++)
	{
		//��Ϊ�Ǵӵ�һλ��ʼ�����
		int ret = B(str[i]); //�ַ�ת��������
		if (ret == -1)  //������ַ�������
			return 0;
		//16���Ƶ����һλ�� * 16��0�η��������ڶ�λ�� 16�� 1 �η������� ��һλ���� 16��len-1�η�
		sum += ret * pow(16, len - i - 1);
	}
	return sum;
}

int main()
{
	//�����ַ���
	char nums[100] = { 0 };
	long long ret = 0;
	printf("������һ��16������-->:");
	scanf("%s", nums);
	if (ret = A(nums))
		printf("%lld\n", ret);
	else
		printf("�����������16����");

	return 0;
}