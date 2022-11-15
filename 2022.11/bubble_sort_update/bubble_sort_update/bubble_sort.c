#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include <stdio.h>
//������ð������



//ʵ�ֱȽϷ�ʽ �Ƚ�int����
int comp_int(void* e1,void * e2)
{
	return *(int*)e1 - *(int*)e2;
}


//ʵ�ֱȽϷ�ʽ �Ƚ��ַ�������
int comp_char(void* e1, void* e2)
{
	return *(char*)e1 - *(char*)e2;
}

//��������
void swap(char* e1,char* e2 , int width)
{
	//e1 �� ��һ��Ԫ�صĵ�ַ
	//e2�ǵڶ���Ԫ�صĵ�ַ 
	//width ��ÿ��Ԫ�صĳ���
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
//������ð������ʵ��
void bubble_sort(void* base, int num,int width, int(*cop)(void *e1,void *e2))  //Ҫ�������飬���鳤�ȣ�ÿ��Ԫ���ֽڴ�С���ȽϺ����ĺ���ָ��
{
	int i = 0;
	for (i = 0; i < num; i++) //ð����������
	{
		//ÿһ��ð������
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			//�жϴ�С
			if (cop((char*)base + j * width, (char*)base + (j + 1) * width) > 0)  //�����һ��Ԫ�غ͵ڶ���Ԫ��
				//������򷵻�������С�ڻ���ڲ�����
				swap((char*)base + (j * width), (char*)base + ((j + 1) * width),width); //��������
		}
	}
}

//-------------------------------------������ð��������

typedef struct Stu //һ��ѧ���ṹ��
{
	char name[20];
	unsigned int age;
	double score;

}Stu;


//ʵ�ֽṹ��ȽϷ�ʽ ����������
int comp_by_age(void* e1, void* e2)
{

	return (*(struct Stu*)e1).age - (*(struct Stu*)e2).age;
}

//ʵ�ֽṹ��ȽϷ�ʽ ����������
int comp_by_score(void* e1, void* e2)
{

	return (int)((*(struct Stu*)e2).score - (*(struct Stu*)e1).score);
}



void print_int(int*arr,int sz)
{
	int i = 0;
	for (i; i < sz; i++)
		printf("%d ",*(arr+i));
	printf("\n");
}

int main()
{
	//
	int arr[] = { 9,8,7,6,5,10,3,2,1,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	//������������
	bubble_sort(arr,len,sizeof(arr[0]),comp_int);
	//�����꣬��ӡһ��
	char str[] = "EGHDAJHAJJINAFSHAFKAFJINJAWSAFAE";
	//�����ַ���
	bubble_sort(str, strlen(str), sizeof(char), comp_char);
	print_int(arr, len);
	printf("%s\n",str);

	//����ṹ��
	Stu Students[] = { {"����",22,98.5},{"����",18,85.0},{"��ը",19,99.5}};
	bubble_sort(Students, sizeof(Students) / sizeof(Students[0]), sizeof(Students[0]), comp_by_score);
	printf("%s,%d,%.1lf\n",Students[0].name, Students[0].age, Students[0].score);
	printf("%s,%d,%.1lf\n", Students[1].name, Students[1].age, Students[1].score);
	printf("%s,%d,%.1lf\n", Students[2].name, Students[2].age, Students[2].score);

	return 0;
}