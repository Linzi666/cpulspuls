#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
namespace wyl
{
	template<class T>
	class vector {
	public:
		//迭代器
		typedef T* iterator;
		typedef const T* const_iterator;


		//构造函数
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
		}
		//迭代器区间初始化
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//函数交换
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			//迭代器初始化
			vector<T> tmp(v.begin(),v.end());
			swap(tmp);
		}

		//析构函数
		~vector()
		{
			delete[] _start;
		}

		//=重载
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		//[]重载
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](size_t pos)const
		{
			assert(pos < size());
			return *(_start + pos);
		}



		//获取大小
		size_t size()const
		{
			return _finish - _start;
		}

		//获取容量
		size_t cacpcity()const
		{
			return _endofstorage - _start;
		}

		//迭代器
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}
		
		//改变容量
		void reserve(size_t t)
		{
			if (cacpcity() < t)
			{
				//扩容
				T* tmp = new T[t];
				//把旧空间的拷贝到新空间
				memcpy(tmp,_start,size()*sizeof(T));
				_finish = tmp + size();
				delete[] _start;
				_start = tmp;
				_endofstorage = _start + t;
			}
		}

		void resize(size_t t,const T& val = T())
		{
			//三种情况，如果t比长度小
			if (t <= size())
			{
				_finish = _start + t;
			}
			else
			{
				//扩容
				reserve(t);
				//随后把t位置后面初始化成 val
				while (_finish != _start + t)
				{
					*_finish++ = val;
				}
			}
		}

		//尾插
		void push_back(T val)
		{
			//判断容量
			if (_finish == _endofstorage)
			{
				//扩容
				reserve(cacpcity() == 0 ? 4 : cacpcity() * 2);
			}
			*_finish = val;
			++_finish;
		}

		//尾删
		void pop_back()
		{
			assert(_finish != _start);
			--_finish;
		}
		//指定插入，返回迭代器
		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(cacpcity() == 0 ? 4 : cacpcity() * 2);
				pos = _start + len;
			}

			iterator end = _finish;
			while (pos < end)
			{
				*end = *(end - 1);
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}

		//指定位置删除
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			//pos后一个位置开始往前覆盖
			iterator first = pos + 1;
			while (first != _finish)
			{
				*(first - 1) = *(first);
				++first;
			}

			--_finish;
			return pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};


	void vectortest1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);
		v.push_back(5);
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << "cacpcity:" << v.cacpcity() << endl;
		cout << "size:" << v.size() << endl;

		v.reserve(30);
		cout << "cacpcity:" << v.cacpcity() << endl;
		cout << "size:" << v.size() << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}

		v.resize(10);
		cout << "cacpcity:" << v.cacpcity() << endl;
		cout << "size:" << v.size() << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
	}


	void vectortest2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		vector<int> v1(v);
		v1.push_back(4);
		vector<int> v2;
		v2 = v1;
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		v2.pop_back();
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;

		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void vectortest3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		cout << v[3] << endl;
	}

	void vectortest4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		vector<int>::iterator it = find(v.begin(),v.end(),2);
		if (it != v.end())
		{
			for (int i = 1; i < 5; i++)
			{
				it = v.insert(it, i*10);
			}
		}
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;

	}
	void vectortest5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);

		//删除所有的偶数
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
			{
				it = v.erase(it);
			}
			else
			{
				it++;
			}
		}
		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
		cout << "size:" << v.size() << endl;
		cout << "cacpcity:" << v.cacpcity() << endl;
	}
}