#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct information
{
	string _name;
	int _age;
};

class informaMassage
{
public:
	informaMassage(const char* filename)
		:_filename(filename)
	{}

	void WiterBin(information& inf)
	{
		ofstream ofs(_filename.c_str(), ios_base::out | ios_base::binary);
		ofs.write((char*)&inf,sizeof(information));
	}

	void ReadBin(information& inf)
	{
		ifstream ifs(_filename.c_str(), ios_base::in | ios_base::binary);
		ifs.read((char*)&inf, sizeof(information));
	}

	void WirteTest(information& im)
	{
		ofstream ofs(_filename);
		ofs << im._name << " " << im._age;
	}
	void ReadTest(information& im)
	{
		ifstream ifs(_filename);
		ifs >> im._name >> im._age;
	}

private:
	string _filename;
};

void TestBin()
{
	informaMassage im("Wriet.bin");
	information ifm;
	//im.WiterBin(ifm);
	im.ReadBin(ifm);
	cout << ifm._name << " " << ifm._age;
}

void TestText()
{
	//informaMassage massage("Wriet.text");
	//information ifm = { "李四",26 };
	//massage.WirteTest(ifm);

	informaMassage massage("Wriet.text");
	information ifm;
	massage.ReadTest(ifm);
	cout << ifm._name << " " << ifm._age;

}

//**********************************************************************
//继承

class person
{
public:
	void printf()
	{
		cout << "person" << endl;
	}	
protected:
	string _name;
	int _age;
};

class Student : public person
{
public:
	void f()
	{
		_name = "张三";
		_age = 18;
		d = 3.14;
		cout << _name << _age << d << endl;
	}
protected:
	double d;
};

class Teacher : public person
{
public:
	void f()
	{
		_name = "李四";
		_age = 28;
		c = 'A';
		cout << _name << _age<< c << endl;
	}
protected:
	char c;
};

void Test3()
{
	Student s;
	s.f();
	Teacher t;
	t.f();
	person p;
	p = s;
	p.printf();
	
}

int main()
{
	//TestText();
	Test3();
	return 0;
}