#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*

��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������У����������ӡ��
Ҫ�󣺲���ʹ��C�������е��ַ�������������
*/

//void reverse_string(char* arr,int left ,int right)
//{
//	//ʵ��˼·,��һ���ַ������һ���ַ� ����λ��
//	//left Ϊ���±꣬rightΪ���±�
//	if (left <= right) //�ݹ��������� 
//	{
//		//������С�����±꣬�������ݹ�
//		char temp = *(arr + left);
//		*(arr + left) = *(arr + right);
//		*(arr + right) = temp;
//		reverse_string(arr, left + 1, right - 1); //������+1��������-1
//	}
//}

int my_strlen(char* arr)
{
	int count = 0;
	while (*(arr + count))count++;
	return count;
}

//������������
void reverse_string(char* arr)
{
	int len = my_strlen(arr) - 1; //���һ��Ԫ�ص��±�

	char temp = *arr; //�洢��һ���ַ�
	*arr = *(arr + len);// ��һ���ַ��������һ���ַ�
	*(arr + len) = '\0'; // ���һ���ַ����\0���������´ε���ʱ�����һ���ַ�����ǰһ�ε��Ƶĵ����ڶ��ַ�
	if (len > 1)  //��� arr - arr+len ֮�����һ���ַ����Ǿͼ�������
	{
		reverse_string(arr+1); // arr ����ƶ�һ���´ε��ƾ��ǵڶ����뵹���ڶ��񽻻�
	}
	//���ƽ�������ʼ�ع飬�Ѹ��ǵ�\0 ���� �洢�˶�Ӧ�ַ��� temp
	*(arr + len) = temp;
}


int main()
{
	char arr[] = "abcdefg";
	printf("��תǰ:%s\n",arr);
	reverse_string(arr);
	printf("��ת��:%s", arr);
	
	return 0;
}