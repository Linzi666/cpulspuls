#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//多态
class A
{};
class B :public A
{};

class Person
{
public:
	//三同(函数名，参数，返回值) + 虚函数 构成重写，多态。
	virtual A* func()
	{
		cout << "Person()" << endl;
		return new A;
	}
	virtual void Task()
	{		
	}
};

class Student : public Person
{
public:
	virtual B* func()
	{
		cout << "Student()" << endl;
		return new B;
	}
	virtual void Task()
	{
		cout << "好好学习，天天向上" << endl;
	}
};

class Teacher : public Person
{
public:
	virtual A* func()
	{
		cout << "Teacher()" << endl;
		return new A;
	}
	virtual void Task()
	{
		cout << "培养好学生" << endl;
	}
};

void test1(Person& p)
{
	p.func();
}


int main()
{
	Person p;
	Teacher t;
	Student s;
	test1(t);
	test1(s);
	test1(p);

	return 0;
}