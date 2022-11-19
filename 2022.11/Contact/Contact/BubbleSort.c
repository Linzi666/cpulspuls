#define _CRT_SECURE_NO_WARNINGS 1
#include "BubbleSort.h"

//Ã°ÅÝÅÅÐòÊµÏÖ
//ÄêÁäÉýÐò
int age_asc(void* e1, void* e2)
{
	return ((Contact*)e1)->data->age - ((Contact*)e2)->data->age;
}
//ÄêÁä½µÐò
int age_dec(void* e1, void* e2)
{
	int z = ((Contact*)e2)->data->age - ((Contact*)e1)->data->age;
	return ((Contact*)e2)->data->age -((Contact*)e1)->data->age ;

}
//ÐÕÃûÉýÐò
int name_asc(void* e1, void* e2)
{
	return strcmp(((Contact*)e1)->data->name, ((Contact*)e2)->data->name);
}
//ÐÕÃû½µÐò
int name_dec(void* e1, void* e2)
{
	return strcmp(((Contact*)e2)->data->name, ((Contact*)e1)->data->name);
}


static Swap(char* e1, char* e2, size_t width)
{
	assert(e1 && e2);
	while (width--)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}


void bubble(void* base, size_t num, size_t width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		int falg = 1;
		int j = 0;
		for (j = 0; j < num - 1 - i ; j++)
		{
			//ÅÅÐò
			if (cmp((char*)base + (j * width), (char*)base + (j + 1) * width) > 0)
				//½»»»
			{
				Swap((char*)base + (j * width), (char*)base + ((j + 1) * width), width);
				falg = 0;
			}
		}
		if (falg)
			break;
	}
}