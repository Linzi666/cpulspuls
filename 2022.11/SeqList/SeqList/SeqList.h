#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//顺序表结构体
typedef int SLDataType;

typedef struct SeqList
{
	//动态开辟
	//指向的动态内存指针
	SLDataType* data;
	//存放数据的个数
	int size;
	//存储容积
	int capacity;
}SL;


//函数声明

//打印顺序表
void SqeListPrint(SL* pSL);


//初始化顺序表
void SeqListInit(SL* pSL);

//释放内存
void SeqListDestory(SL* pSL);

//尾部插入数据
void SeqListPushBack(SL* pSL, SLDataType x);

//头部插入数据
void SeqListPushFtont(SL* pSL, SLDataType x);

//尾部删除数据
void SeqListMoveBack(SL* pSL);

//头部删除数据
void SeqListMoveFront(SL* pSL);

//指定位置删除数据
void SeqListMoveSet(SL* pSL,int pos);

//指定位置插入数据
void SeqListPushSet(SL* pSL, int pos, SLDataType x);

//查找数据下标
int SeqListFind(SL* pSL , SLDataType x);


