#pragma once
#include<string.h>
#include<iostream>
using namespace std;

namespace wyl
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//ȱʡ�Ĺ��캯�� 
		string(const char* str = "")
			: _size(strlen(str))
			,_cacpcity(_size)
		{
			//����һ���ڴ�
			_str = new char[_cacpcity + 1];
			strcpy(_str, str);
		}

		//��������
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _cacpcity = 0;
		}

		//��������
		string(const string& s)
			:_size(s._size)
			, _cacpcity(s._cacpcity)
		{
			//����һ���sһ���Ŀռ�
			_str = new char[_cacpcity+1];
			strcpy(_str, s._str);
		}

		//��ֵ����������
		string& operator=(const string& s)
		{
			//��������Լ����Լ���ֵ
			if (this != &s)
			{
				//����һ���¿ռ�
				char* tmp = new char[s._cacpcity+1];
				//����
				strcpy(tmp, s._str);
				//���پɿռ�
				delete[] _str;
				_str = tmp;
				_size = s._size;
				_cacpcity = s._cacpcity;
			}
			return *this;
		}

		//��ȡ����
		size_t size()
		{
			return _size;
		}
		
		//�±����
		char& operator[](size_t pos)
		{
			return _str[pos];
		}
		//ֻ��
		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		//��������ʼλ��
		iterator begin()
		{
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}

		//������ĩβλ��
		iterator end()
		{
			return _str + _size;
		}

		const_iterator end()const
		{
			return _str + _size;
		}

		// ����
		void AddCacpcity(size_t newCacpcity)
		{
				char* str = new char[newCacpcity + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_cacpcity = newCacpcity;
		}

		//β��һ���ַ�
		void push_back(char c)
		{
			//�������
			if (_size == _cacpcity)
			{
				AddCacpcity(_cacpcity == 0 ? 15 : _cacpcity * 2);
			}
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';
		}


		string& operator+=(char c)
		{
			push_back(c);
			return *this;
		}

		//׷��һ���ַ���
		void append(const char* str)
		{
			if (_cacpcity < (_size)+strlen(str))
			{
				AddCacpcity(_size + strlen(str));
			}
			strcpy(_str + _size, str);
			_size += strlen(str);
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;

		}

		//+����
		string operator+(const char* str)
		{
			string s(*this);
			s += str;

			return s;
		}

		string operator+(const string& str)
		{
			string s(*this);
			s += str._str;

			return s;
		}


		//���
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}

		//�ַ�������
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_cacpcity, s._cacpcity);
		}

		//��c�ķ�ʽ�����ַ���
		const char* c_str()const
		{
			return _str;
		}

		//�ж��ַ����Ƿ�Ϊ��
		bool empty()const
		{
			return _str[0] == '\0';
		}

		//�޸ĳ���
		void resize(size_t n, char c = '\0')
		{
			//����޸ĵ�ֵ�ȵ�ǰ����С
			if (n <= _size)
			{
				//�ض�
				_size = n;
				_str[_size] = '\0';
			}
			//����޸ĵ�ֵ�ȵ�ǰ���ȴ�
			else
			{
				//����
				if(n > _cacpcity)
				{
					AddCacpcity(n);
				}
				//��sizeλ�õ�n��λ������Ϊc
				memset(_str + _size, c, n - _size);
				//���λ������\0
				_size = n;
				_str[_size] = '\0';
			}
		}

		//ָ��������ֻ���ӣ����ٲ�����
		void reserve(size_t n)
		{
			if (n > _cacpcity)
			{
				AddCacpcity(n);
			}
		}

		//�ַ����ȽϺ�������
		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator<=(const string& s)
		{
			return (*this < s) || (*this == s);
		}

		bool operator>(const string& s)
		{
			return !((*this) <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		// ����c��string�е�һ�γ��ֵ�λ��
		size_t find(char c, size_t pos = 0) const
		{
			for (int i = pos; i < _size; i++)
			{
				if (_str[i] == c)
					return i;
			}
			
			return nops;
		}

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��
		size_t find(const char* s, size_t pos = 0) const
		{
			char* tmp = strstr(_str, s);
			if (tmp == NULL)
				return nops;
			
			return tmp - _str;
		}

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
		string& insert(size_t pos, char c)
		{
			//�ж�����
			if (_size == _cacpcity)
			{
				AddCacpcity(_cacpcity == 0 ? 15 : _cacpcity * 2);
			}
			//posλ�ú�������
			size_t end = _size + 1;
			while (pos < end)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[pos] = c;
			_size++;

			return *this;
		}

		//�����ַ���
		string& insert(size_t pos, const char* str)
		{
			size_t len = strlen(str);
			//�ж�����
			if (_cacpcity < (len + _size))
			{
				AddCacpcity(len + _size);
			}
			//�ƶ�len��
			size_t end1 = _size+1;
			size_t end2 = _size + len ;
			while (pos < end1 )
			{
				_str[end2] = _str[end1-1]  ;
				end1--;
				end2--;
			}
			int i = pos;
			while (*str)
			{
				 _str[i++] = *str++;
			}
			_size += len;
			return *this;
		}



		// ɾ��
		string& erase(size_t pos, size_t len)
		{
			//���Ҫɾ���ĳ��ȴ��ں����ʣ�೤��
			if (len >= _size - pos)
			{
				len = _size - pos;
				_size -= len;
				_str[pos] = '\0';
				return *this;
			}
			//�Ѻ������ǰ�ƣ�����ʽɾ��
			size_t begin = pos+len;
			while (_str[begin])
			{
				_str[begin-len] = _str[begin];
				begin++;
			}
			_size -= len;
			return *this;
		}
		

	private:
		char* _str;
		size_t _size;
		size_t _cacpcity;

		static const size_t nops = -1;



	};


	void stringtest1()
	{
		string s1("aaaa");
		string s2;
		string s3(s1);
		s2 = s1;

 	}

	void stringtest2()
	{
		string s1("abcdtfg");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
		for (auto e : s1)
		{
			cout << e << " ";

		}
	}

	void stringtest3()
	{
		string s1("abcdtfgaaaa");
		s1.push_back('A');
		s1.append("BCDEFGGGGGGGGGGGGGGGG");

		string s2("abcdtfgaaaa");
		s2 += 'g';
		s2 += 'h';
		s2 += "ggggggggggg";
		//s2.clear();
		s1.swap(s2);
	}

	void stringtest4()
	{
		string s1("abcdtfgaaaa");
		s1.reserve(50);
		s1 += "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

		string s2("abcdefg");
		s2.resize(10, 'a');

	}

	void stringtest5()
	{
		string s1("aa");
		string s2("ab");
		string s3("aaa");
		string s4("aaa");

		if (s1 > s2)
			cout << " s1 > s2 " << endl;

		if (s2 < s1)
			cout << " s2 < s1 " << endl;

		if (s3 == s4)
			cout << " s3 == s4 " << endl;

		if(s3 >= s4)
			cout << " s3 >= s4 " << endl;

		if (s3 <= s4)
			cout << " s3 <= s4 " << endl;

		if (s2 > s3)
			cout << "s2 > s3";
	}

	void stringtest6()
	{
		string s1("ABCDEF");
		//cout << s1.find("efgA") << endl;
		s1 += "";
		s1.insert(2, "GH");


		string s2("abcdefg");
		size_t pos = s2.find('e');
		s2.insert(pos, 'A');
	//	s2.insert(0, "ABCDEFF");
		s2.erase(5, 50);

		string s3(s1 + s2);

	}
}