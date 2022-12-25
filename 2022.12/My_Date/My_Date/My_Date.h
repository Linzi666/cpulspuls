#pragma once
#include<iostream>
using namespace std;


class Date
{
public:
	//��Ԫ����,<<����������
	friend ostream& operator<<(ostream& out,const Date& d);
	//>>����������
	friend istream& operator>>(istream& in, Date& d);


	//���캯��
	Date(int year = 0, int month = 1,int day = 1);
	//��ȡ�·�����
	int GetMonthDay(int year, int month);
	//��ӡ����
	void PrintDate();

	//������ںϷ���
	bool CheckDate();

	//������������֮����������
	int GetMonthDay(const Date& d);

	//+=����������
	Date& operator+=(int x);
	
	//+����������
	Date operator+(int x);

	//>����������
	bool operator>(const Date& d);

	//>����������
	bool operator>=(const Date& d);

	//<����������
	bool operator<(const Date& d);

	//<=����������
	bool operator<=(const Date& d);

	//==����������
	bool operator==(const Date& d);

	//!=����������
	bool operator!=(const Date& d);

	//-=����������
	Date& operator-=(int x);

	//-����������
	Date operator-(int x);

	//ǰ��++����������
	Date operator++();

	//����++����������
	Date operator++(int);

	//ǰ��--����������
	Date operator--();

	//����--����������
	Date operator--(int);

	//����2������֮���������
	int operator-(const Date& d);

	//��ȡ���������ڼ�
	int GetWeekDay();



private:
	int _year;
	int _month;
	int _day;
};

