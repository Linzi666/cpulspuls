#define _CRT_SECURE_NO_WARNINGS 1

#include"My_Date.h"


void DateTest1()
{
	Date d1(2022,1,1);
	d1.PrintDate();
	Date d2(2022, 2, 28);
	d2.PrintDate();
	Date d3(2000, 2, 29);
	d3.PrintDate();
	d2 = (d3 += 2);
	d2.PrintDate();

}

void DateTest2()
{
	Date d1(2022, 1, 1);
	d1.PrintDate();
	//Date d2(2022, 2, 28);
	//d2.PrintDate();
	Date d3;
	d3 = d1 + 3;
	d1.PrintDate();
	d3.PrintDate();
	d1 = d3;
	d1.PrintDate();

}

void DateTest3()
{
	Date d1(2021, 11, 4);
	Date d2(2021, 11, 4);
	if (d1 == d2)
	{
		cout << "1123" << endl;
	}

}

void DateTest4()
{
	//Date d1(2021, 11, 4);
	//Date d2(2021, 11, 4);
	//d2 = d1 - 5;
	//d2.PrintDate();
	Date d1(2022, 12, 24);
	Date d2(2022, 12, 23);
	if (d1 <= d2)
	{
		cout << "aaa" << endl;
	}
}


void DateTest5()
{
	Date d1(2022, 12, 25);
	Date d2(2022, 12, 26);
	//cin >> d1 >> d2;
	cout << d2-d1 << endl;
	cout << d1.GetWeekDay() << endl;

}

int main()
{
	//DateTest1();
	//DateTest2();
	//DateTest3();
	//DateTest4();
	DateTest5();


	return 0;
}