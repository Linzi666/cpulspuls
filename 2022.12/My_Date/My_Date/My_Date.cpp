#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Date.h"


int Date::GetMonthDay(int year, int month)
{
	static int monthdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = monthdays[month];
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0))
	{
		day += 1;
	}
	return day;
}

bool Date::CheckDate()
{
	if (!(_year >= 0 && _month > 0 && _month < 13
		&& _day > 0 && _day <= GetMonthDay(_year, _month)))
	{
		return true;
	}
	return false;
}


Date::Date(int year, int month, int day )
{
	_year = year;
	_month = month;
	_day = day;

	if (CheckDate())
	{
		cout << "���ڷǷ�->";
		PrintDate();
	}
}


void Date::PrintDate()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//������������֮����������
int Date::GetMonthDay(const Date& d)
{
	return 0;
}


//+=����������
Date& Date::operator+=(int x)
{
	_day += x;
	
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;

		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;	
}

//+����������
Date Date::operator+(int x)
{
	Date d(*this);
	d += x;
	return d;
}

//>����������
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if ((_year == d._year) && (_month > d._month))
	{
		return true;
	}
	else if ((_year == d._year) && (_month == d._month) &&( _day > d._day))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//==����������
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

//!=����������
bool Date::operator!=(const Date& d)
{
	return !((*this) == d);
}


//>=����������
bool Date::operator>=(const Date& d)
{
	return (*this) > d || (*this) == d;
}



//<����������
bool Date::operator<(const Date& d)
{
	return !((*this) >= d);
}



//<=����������
bool Date::operator<=(const Date& d)
{
	return (*this) < d || (*this) == d;
}


//-=����������
Date& Date::operator-=(int x)
{
	_day -= x;
	while (_day < 1)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day +=GetMonthDay(_year, _month);
	}
	return (*this);
}

//-����������
Date Date::operator-(int x)
{
	Date d(*this);
	d -= x;
	return d;
}

//ǰ��++����������
Date Date::operator++()
{
	(*this) += 1;
	return (*this);
}


//����++����������
Date Date::operator++(int)
{
	Date ret(*this);
	(*this) += 1;
	return ret;
}


//ǰ��--����������
Date Date::operator--()
{
	(*this) -= 1;
	return *this;
}

//����--����������
Date Date::operator--(int)
{
	Date d1(*this);
	(*this) -= 1;
	return d1;
}


// <<����������
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	cout << "���������������:";
	in >> year >> month >> day;
	d._year = year;
	d._month = month;
	d._day = day;
	if (d.CheckDate())
	{
		cout << "�������ڷǷ�->";
		d.PrintDate();
	}

	return in;
}

//����2������֮���������
int Date::operator-(const Date& d)
{
	//��Сʱ��
	Date max = (*this);
	Date min = d;
	int falg = 1; 
	int count = 0;
	if (min > max)
	{
		max = d;
		min = (*this);
		falg = -1;
	}

	while (max != min)
	{
		min++;
		count++;
	}
	return count * falg;
}

//��ȡ���������ڼ�
int Date::GetWeekDay()
{
	// 1970 - 1 - 1 ������һ
	Date source(1970, 1, 1);
	int day =   (*this) - source  ;
	return day % 7 + 1;
}
