#pragma once

#include "Contact.h"

//冒泡排序实现的头文件
enum SortOption
{
	AGE_ASC = 1,
	AGE_DEC,
	NAME_ASC,
	NAME_DEC
};


//函数声明
//比较函数声明
//年龄升序
int age_asc(void*e1 , void* e2 );
//年龄降序
int age_dec(void* e1, void* e2);
//姓名升序
int name_asc(void* e1, void* e2);
//姓名降序
int name_dec(void* e1, void* e2);

//冒泡排序声明
void bubble(void* base, size_t num, size_t width, int(*cmp)(void* e1, void* e2));