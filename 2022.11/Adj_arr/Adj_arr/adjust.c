#define _CRT_SECURE_NO_WARNINGS 1

//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
void adj(int* p,int sz)
{
	int i = 0;
	int j = 0; //�滻���ڼ�����
	for(i ; i < sz ; i++)
		if(p[i] % 2 == 1 ) //������ ������λ�� 
		{ 
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			j++;
		}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	adj(arr,len);
	return 0;
}
