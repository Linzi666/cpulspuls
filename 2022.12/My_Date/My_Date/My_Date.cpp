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
		cout << "日期非法->";
		PrintDate();
	}
}


void Date::PrintDate()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//计算两个日期之间相差多少天
int Date::GetMonthDay(const Date& d)
{
	return 0;
}


//+=操作符重载
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

//+操作符重载
Date Date::operator+(int x)
{
	Date d(*this);
	d += x;
	return d;
}

//>操作符重载
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

//==操作符重载
bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

//!=操作符重载
bool Date::operator!=(const Date& d)
{
	return !((*this) == d);
}


//>=操作符重载
bool Date::operator>=(const Date& d)
{
	return (*this) > d || (*this) == d;
}



//<操作符重载
bool Date::operator<(const Date& d)
{
	return !((*this) >= d);
}



//<=操作符重载
bool Date::operator<=(const Date& d)
{
	return (*this) < d || (*this) == d;
}


//-=操作符重载
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

//-操作符重载
Date Date::operator-(int x)
{
	Date d(*this);
	d -= x;
	return d;
}

//前置++操作符重载
Date Date::operator++()
{
	(*this) += 1;
	return (*this);
}


//后置++操作符重载
Date Date::operator++(int)
{
	Date ret(*this);
	(*this) += 1;
	return ret;
}


//前置--操作符重载
Date Date::operator--()
{
	(*this) -= 1;
	return *this;
}

//后置--操作符重载
Date Date::operator--(int)
{
	Date d1(*this);
	(*this) -= 1;
	return d1;
}


// <<操作符重载
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	cout << "请输入你的年月日:";
	in >> year >> month >> day;
	d._year = year;
	d._month = month;
	d._day = day;
	if (d.CheckDate())
	{
		cout << "输入日期非法->";
		d.PrintDate();
	}

	return in;
}

//计算2个日期之间相差天数
int Date::operator-(const Date& d)
{
	//大小时间
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

//获取今日是星期几
int Date::GetWeekDay()
{
	// 1970 - 1 - 1 是星期一
	Date source(1970, 1, 1);
	int day =   (*this) - source  ;
	return day % 7 + 1;
}
