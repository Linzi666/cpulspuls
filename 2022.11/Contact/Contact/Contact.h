#pragma once

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdlib.h>


//类型声明

#define CONTACT_MAX 1000 //通信录能存放信息的数量
#define NAME_MAX 20 //名字长度
#define SEX_MAX 5 //性别长度
#define TELE_MAX 12 //电话号码长度 
#define ADDRS_MAX 30 //地址长度 
#define INTO_MAX 1 //通讯录的初始大小


//定义枚举，菜单选项
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

// 一个存储个人信息的结构体
typedef struct PeoInfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addrs[ADDRS_MAX];
	int age;

}PeoInfo;

//通讯录结构体，含 1000个人的信息
typedef struct Contact
{
	//PeoInfo data[CONTACT_MAX];//能存放的 信息数量
	//动态内存版本
	PeoInfo* data;
	int sz;  // 当前存放的人数
	int capacity; //当前的存储容量
}Contact;


//函数声明
//初始化通讯录
void InitContact(Contact* con);

//添加联系人
void AddContact(Contact* con);

//打印联系人
void PrintContact(Contact* con);

//删除联系人
void DelteContact(Contact* con);

//搜索联系人
void SeacherContact(Contact* con);

//修改联系人
void ModifyContact(Contact* con);

//排序
void SortContact(Contact* con);

//释放通讯录
void ReleaseContact(Contact* con);