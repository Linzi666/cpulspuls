#pragma once

#include "Contact.h"

//ð������ʵ�ֵ�ͷ�ļ�
enum SortOption
{
	AGE_ASC = 1,
	AGE_DEC,
	NAME_ASC,
	NAME_DEC
};


//��������
//�ȽϺ�������
//��������
int age_asc(void*e1 , void* e2 );
//���併��
int age_dec(void* e1, void* e2);
//��������
int name_asc(void* e1, void* e2);
//��������
int name_dec(void* e1, void* e2);

//ð����������
void bubble(void* base, size_t num, size_t width, int(*cmp)(void* e1, void* e2));