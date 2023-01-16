#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//
//class A{};
//class B:public A
//{};
//
//class Person
//{
//	virtual A* BuyTicket()
//	{
//		new A();
//	}
//};
//class Student : public Person
//{
//	virtual B* BuyTicket()
//	{
//		new B();
//	}
//};
//
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "成年人买票" << endl;
//	}
//	virtual ~Person()
//	{
//		cout << "~Person" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "学生买票" << endl;
//	}
//	virtual ~Student()
//	{
//		cout << "~Student" << endl;
//	}
//	 int _a;
//
//};
//
//void a(Person* pp)
//{
//	delete pp;
//}
//int main()
//{
//	Person* p = new Person();
//	Student* s = new Student();
//	a(s);	
//
//	s->_a = 10;
//	s->_a = 20;
//	s->_a = 30;
//	return 0;
//}


//class car
//{
//public:
//	 void func() 
//	{
//		cout << "car::func" << endl;
//	}
//};
//
//class Benz:public car
//{
//public:
//	virtual void func() override
//	{
//		cout << "Benz::func" << endl;
//	}
//};

//void a(car& c)
//{
//	c.func();
//}
//
//int main()
//{
//	car c;
//	Benz b;
//	a(c);
//	a(b);
//
//	return 0;
//}



class Base1
{
public:
	virtual void fun1()
	{
		cout << "Base::fun1()" << endl;
	}

	virtual void fun2()
	{
		cout << "Base::fun2()" << endl;
	}

	 int _p;
};
class Base2
{
public:
	virtual void fun3()
	{
		cout << "Base2::fun3()" << endl;
	}
	virtual void fun4()
	{
		cout << "Base2::fun4()" << endl;
	}

};

class me :public Base1,public Base2
{
	virtual void fun1()
	{
		cout << "me::fun1()" << endl;
	}
	virtual void fun2()
	{
		cout << "me::fun2()" << endl;
	}
	virtual void fun5()
	{
		cout << "me::fun5()" << endl;
	}
	virtual void fun6()
	{
		cout << "me::fun6()" << endl;
	}
};


typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i+1, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl << endl;
}
//int main()
//{
//	me m;
//
//	VFPTR * vTableb = (VFPTR*)(*(void**)&m);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(void**)((char*)&m+sizeof(Base1)));
//	PrintVTable(vTabled);
//	return 0;
//}

#include<stdio.h>
int main()
{
	int i  = 0;
	for (i = 1; i <= 5; i++)
		switch (i%5) {
		case 0:printf("*"); break;
		case 1:printf("#"); break; 
		default:printf("\n"); 
		case 2:printf("&");
		}
	return 0;
}
