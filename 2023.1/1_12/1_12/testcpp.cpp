#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//继承
//class Person
//{
//public:
//	/*Person()
//	{
//		cout << "Person" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		if (&p != this)
//		{
//			_name = p._name;
//		}
//		cout << "&Person" << endl;
//	}
//
//	~Person()
//	{
//		cout << "~Person" << endl;
//	}*/
//
//	void f()
//	{
//		cout << "Person" << endl;
//	}
//
//	string _name;
//};
//
//class Student : public Person
//{
//public:
//	void f()
//	{
//		cout << "Student" << endl;
//	}
//	int _num;
//};
//
//void test1()
//{
//	Student s;
//	s._name = "张三";
//	s._num = 1;
//	cout << s._name << " " << s._num << endl;
//}
//
////子类传给父类
//void test2()
//{
//	Person p;
//	Student s;
//	s._name = "李四";
//	s._num = 2;
//	p = s;
//	cout << p._name << endl;
//}
//
////父类传给子类
//void test3()
//{
//	Person p;
//	Student s;
//	p = s;
//	//p._name = "李四";
//	//s = p;
//	Person* pp = &p;
//	Student* ps = (Student*)pp;
//	ps->_name = "张三";
//	ps->_num = 10;
//	cout << ps->_name <<" " << ps->_num<< endl;
//
//}
//
//void test4()
//{
//	Student s;
//	s.Person::f();
//}

//
//class Person
//{
//public:
//	Person()
//	{
//		++_count;
//		cout << "Person" << endl;
//	}
//
//	Person(const Person& p)
//	{
//		if (&p != this)
//		{
//			_name = p._name;
//		}
//		cout << "&Person" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		_name = p._name;
//	}
//
//	~Person()
//	{
//		cout << "~Person" << endl;
//	}
//	static int _count;
//	string _name;
//};
//	int Person::_count = 0;
//
//class Student : virtual public Person
//{
//public:
//	Student()
//	{
//		cout << "Student" << endl;
//	}
//
//	Student(const Student& p)
//		:Person(p) //先调用基类的拷贝构造
//	{
//		if (&p != this)
//		{
//			_num = p._num;
//		}
//		cout << "&Student" << endl;
//	}
//
//	Student& operator=(const Student& p)
//	{
//		Person::operator=(p); //调用基类的 =赋值重载
//		_num = p._num;
//	}
//
//	~Student()
//	{
//		cout << "~Student" << endl;
//	}
//	int _num;
//};
//
//class Teacher : virtual public Person
//{
//public:
//	Teacher()
//	{
//		cout << "Teacher" << endl;
//	}
//
//	Teacher(const Teacher& p)
//		:Person(p) //先调用基类的拷贝构造
//	{
//		if (&p != this)
//		{
//			_num = p._num;
//		}
//		cout << "&Teacher" << endl;
//	}
//
//	Teacher& operator=(const Teacher& p)
//	{
//		Person::operator=(p); //调用基类的 =赋值重载
//		_num = p._num;
//	}
//
//	~Teacher()
//	{
//		cout << "~Teacher" << endl;
//	}
//	int _num;
//};
//
//class Assistant : public Teacher,public Student
//{
//public:
//	Assistant()
//	{
//		cout << "Assistant" << endl;
//	}
//
//	~Assistant()
//	{
//		cout << "~Assistant" << endl;
//	}
//	int _num;
//};
//
//void test1()
//{
//	Student s;
//	s._num = 100;
//	s._name = "张三";
//	Student s2(s);
//	cout << s2._name << " " << s2._num << endl;
//}
//
//void test2()
//{
//	Student s;
//	s._num = 100;
//	s._name = "张三";
//	Student s2 = s;
//	cout << s2._name << " " << s2._num << endl;
//}
//
//void test3()
//{
//	Person p;
//	Student s;
//	cout << p._count << ":" << &p._count << endl;
//	cout << s._count << ":" << &s._count << endl;
//}
//
//void test4()
//{
//	Assistant a;
//	a._name = "李四";
//	cout << a._name << endl;
//}



class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
		int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D :  public B,  public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	d._a = 0;

	return 0;
}