#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


//��̬
class A
{};
class B :public A
{};

class Person
{
public:
	//��ͬ(������������������ֵ) + �麯�� ������д����̬��
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
		cout << "�ú�ѧϰ����������" << endl;
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
		cout << "������ѧ��" << endl;
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