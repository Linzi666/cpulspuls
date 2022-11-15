#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include <stdio.h>
//升级版冒泡排序



//实现比较方式 比较int数组
int comp_int(void* e1,void * e2)
{
	return *(int*)e1 - *(int*)e2;
}


//实现比较方式 比较字符串排序
int comp_char(void* e1, void* e2)
{
	return *(char*)e1 - *(char*)e2;
}

//交换函数
void swap(char* e1,char* e2 , int width)
{
	//e1 是 第一个元素的地址
	//e2是第二个元素的地址 
	//width 是每个元素的长度
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
//升级版冒泡排序实现
void bubble_sort(void* base, int num,int width, int(*cop)(void *e1,void *e2))  //要传的数组，数组长度，每个元素字节大小，比较函数的函数指针
{
	int i = 0;
	for (i = 0; i < num; i++) //冒泡排序趟数
	{
		//每一趟冒泡排序
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{
			//判断大小
			if (cop((char*)base + j * width, (char*)base + (j + 1) * width) > 0)  //传入第一个元素和第二个元素
				//如果大则返回正数，小于或等于不交换
				swap((char*)base + (j * width), (char*)base + ((j + 1) * width),width); //交换函数
		}
	}
}

//-------------------------------------以上是冒泡排序函数

typedef struct Stu //一个学生结构体
{
	char name[20];
	unsigned int age;
	double score;

}Stu;


//实现结构体比较方式 按年龄排序
int comp_by_age(void* e1, void* e2)
{

	return (*(struct Stu*)e1).age - (*(struct Stu*)e2).age;
}

//实现结构体比较方式 按分数排序
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
	//排序整形数组
	bubble_sort(arr,len,sizeof(arr[0]),comp_int);
	//排序完，打印一下
	char str[] = "EGHDAJHAJJINAFSHAFKAFJINJAWSAFAE";
	//排序字符串
	bubble_sort(str, strlen(str), sizeof(char), comp_char);
	print_int(arr, len);
	printf("%s\n",str);

	//排序结构体
	Stu Students[] = { {"张三",22,98.5},{"李四",18,85.0},{"王炸",19,99.5}};
	bubble_sort(Students, sizeof(Students) / sizeof(Students[0]), sizeof(Students[0]), comp_by_score);
	printf("%s,%d,%.1lf\n",Students[0].name, Students[0].age, Students[0].score);
	printf("%s,%d,%.1lf\n", Students[1].name, Students[1].age, Students[1].score);
	printf("%s,%d,%.1lf\n", Students[2].name, Students[2].age, Students[2].score);

	return 0;
}