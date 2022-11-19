#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


//��������

#define CONTACT_MAX 1000 //ͨ��¼�ܴ����Ϣ������
#define NAME_MAX 20 //���ֳ���
#define SEX_MAX 5 //�Ա𳤶�
#define TELE_MAX 12 //�绰���볤�� 
#define ADDRS_MAX 30 //��ַ���� 


//����ö�٣��˵�ѡ��
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEACHER,
	MODIFY,
	SORT,
	PRINT,
	DELALL,
	CLEAR
};

// һ���洢������Ϣ�Ľṹ��
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addrs[ADDRS_MAX];
	int age;

}PeoInfo;

//ͨѶ¼�ṹ�壬�� 1000���˵���Ϣ
typedef struct Contact
{
	PeoInfo data[CONTACT_MAX];//�ܴ�ŵ� ��Ϣ����
	int sz;  // ��ǰ��ŵ�����
}Contact;


//��������
//��ʼ��ͨѶ¼
void InitContact(Contact* con);

//�����ϵ��
void AddContact(Contact* con);

//��ӡ��ϵ��
void PrintContact(Contact* con);

//ɾ����ϵ��
void DelteContact(Contact* con);

//������ϵ��
void SeacherContact(Contact* con);

//�޸���ϵ��
void ModifyContact(Contact* con);

//����
void SortContact(Contact* con);