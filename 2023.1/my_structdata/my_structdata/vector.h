#pragma once
#include<assert.h>
#include<iostream>
#include"reverse_iterator.h"
using namespace std;
namespace wyl
{
	template<class T>
	class vector
	{
	public:
		//普通迭代器
		typedef T* iterator;
		//const迭代器
		typedef const T* const_iterator;
		//反向迭代器
		typedef _reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef _reverse_iterator<const_iterator, const T&,const T*> const_reverse_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
		}
		//迭代器区间初始化
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				//把迭代器数据依次插入当前对象
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		vector(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			//交换
			swap(tmp);
		}

		T& operator[](const T& val)
		{
			return *(_start + val);
		}

		vector<T>& operator=(const vector<int> v)
		{
			vector v2(v);
			swap(v2);
			return *this;
		}

		const T& operator[](const T& val)const
		{
			return *(_start + val);;
		}

		size_t size()
		{
			return _finish - _start;
		}

		size_t size()const
		{
			return _finish - _start;
		}


		size_t cacpcity()
		{
			return _endofstorage - _start;
		}
		size_t cacpcity()const
		{
			return _endofstorage - _start;
		}

		void reserve(size_t n)
		{
			//n比当前容量大
			if (cacpcity() < n)
			{
				//开辟n个空间
				T* tmp = new T[n];
				//拷贝
				for (int i = 0; i < size(); i++)
				{
					*(tmp + i) = *(_start + i);
				}
				//更新_finish
				_finish = tmp + size();
				//销毁旧空间
				delete[] _start;
				//更新
				_start = tmp;
				_endofstorage = _start + n;
			}
		}

		////指定位置插入
		iterator insert(iterator pos, const T& val)
		{
			//pos必须在 _start  - _finish之间
			assert(pos >= _start && pos <= _finish);
			//判断空间是否足够
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				//空间不够，增容，是0增容4，不是0增容2倍
				reserve(cacpcity() == 0 ? 4 : 2 * cacpcity());
				pos = _start + len;
			}
			//把pos - finish 的位置都往后移动
			iterator end = _finish;
			while (end > pos)
			{
				*(end) = *(end - 1);
				--end;
			}
			*pos = val;
			++_finish;
			//返回pos迭代器
			return pos;
		}

		iterator erase(iterator pos)
		{
			//pos必须在start - finish区间，且 size不能为空
			assert(size() > 0);
			assert(pos >= _start && pos < _finish);
			int len = pos - _start;
			//从pos的下一个位置开始，往前覆盖
			iterator begin = pos + 1;
			while (begin != _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			_finish--;

			return pos;
		}

		void pop_back()
		{
			erase(end() - 1);
		}

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
		//反向迭代器
		reverse_iterator rbegin()
		{
			return reverse_iterator(_finish);
		}

		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(_finish);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_start);
		}

		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(_start);
		}


		void push_back(const T& val)
		{
			//复用insert
			insert(end(), val);
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};


	void a(const vector<int>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			//v[i] = 10;
			cout << v[i] << " ";
		}
	}
	void test1()
	{
		vector<int> v;
		v.push_back(1);
		cout << v.size() << "," << v.cacpcity() << endl;
		v.push_back(2);
		cout << v.size() << "," << v.cacpcity() << endl;
		v.push_back(3);
		cout << v.size() << "," << v.cacpcity() << endl;
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << "," << v.cacpcity() << endl;
		
		vector<int>::iterator it = v.begin();
		//while (it != v.end())
		//{
		//	
		//	cout << *it << " ";
		//	++it;
		//}
		for (int i = 0; i < v.size(); i++)
		{
			v[i] = 10;
			cout << v[i] << " ";
		}
		a(v);

	}

	void test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		//v.erase(v.begin());
		//v.erase(v.end()-1);


		vector<int> v2 = v;
		vector<int>::reverse_iterator rit = v2.rbegin();
		while (rit != v2.rend())
		{
			
			cout << *rit << " ";
			++rit;
		}
	}
	struct Date
	{
		int _year;
		int _month;
		int _day;
		Date(int year = 1,int month = 1,int day = 1)
			:_year(year)
			,_month(month)
			,_day(day)
		{}
	};

	void b(const vector<Date>& v)
	{
		vector<Date>::const_reverse_iterator rit = v.rbegin();
		while (rit != v.rend())
		{
			cout << rit->_year << " " << rit->_month << " " << rit->_day << endl;
			++rit;
		}
	}

	void test3()
	{
		vector<Date> v;
		v.push_back(Date(2022, 1, 1));
		v.push_back(Date(2022, 2, 1));
		v.push_back(Date(2022, 3, 1));
		b(v);

	}
}

