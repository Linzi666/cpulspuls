#pragma once
#include<iostream>
using namespace std;


class Date
{
public:
	//友元函数,<<操作符重载
	friend ostream& operator<<(ostream& out,const Date& d);
	//>>操作符重载
	friend istream& operator>>(istream& in, Date& d);


	//构造函数
	Date(int year = 0, int month = 1,int day = 1);
	//获取月份天数
	int GetMonthDay(int year, int month);
	//打印日期
	void PrintDate();

	//检查日期合法性
	bool CheckDate();

	//计算两个日期之间相差多少天
	int GetMonthDay(const Date& d);

	//+=操作符重载
	Date& operator+=(int x);
	
	//+操作符重载
	Date operator+(int x);

	//>操作符重载
	bool operator>(const Date& d);

	//>操作符重载
	bool operator>=(const Date& d);

	//<操作符重载
	bool operator<(const Date& d);

	//<=操作符重载
	bool operator<=(const Date& d);

	//==操作符重载
	bool operator==(const Date& d);

	//!=操作符重载
	bool operator!=(const Date& d);

	//-=操作符重载
	Date& operator-=(int x);

	//-操作符重载
	Date operator-(int x);

	//前置++操作符重载
	Date operator++();

	//后置++操作符重载
	Date operator++(int);

	//前置--操作符重载
	Date operator--();

	//后置--操作符重载
	Date operator--(int);

	//计算2个日期之间相差天数
	int operator-(const Date& d);

	//获取今日是星期几
	int GetWeekDay();



private:
	int _year;
	int _month;
	int _day;
};

