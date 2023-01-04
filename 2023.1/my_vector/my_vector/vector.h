#pragma once

#include <iostream>
#include <assert.h>
using namespace std;
namespace wyl
{
	template<class T>
	class vector {
	public:
		//������
		typedef T* iterator;
		typedef const T* const_iterator;


		//���캯��
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
		}
		//�����������ʼ��
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

		//��������
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
			//��������ʼ��
			vector<T> tmp(v.begin(),v.end());
			swap(tmp);
		}

		//��������
		~vector()
		{
			delete[] _start;
		}

		//=����
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		//[]����
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



		//��ȡ��С
		size_t size()const
		{
			return _finish - _start;
		}

		//��ȡ����
		size_t cacpcity()const
		{
			return _endofstorage - _start;
		}

		//������
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
		
		//�ı�����
		void reserve(size_t t)
		{
			if (cacpcity() < t)
			{
				//����
				T* tmp = new T[t];
				//�Ѿɿռ�Ŀ������¿ռ�
				memcpy(tmp,_start,size()*sizeof(T));
				_finish = tmp + size();
				delete[] _start;
				_start = tmp;
				_endofstorage = _start + t;
			}
		}

		void resize(size_t t,const T& val = T())
		{
			//������������t�ȳ���С
			if (t <= size())
			{
				_finish = _start + t;
			}
			else
			{
				//����
				reserve(t);
				//����tλ�ú����ʼ���� val
				while (_finish != _start + t)
				{
					*_finish++ = val;
				}
			}
		}

		//β��
		void push_back(T val)
		{
			//�ж�����
			if (_finish == _endofstorage)
			{
				//����
				reserve(cacpcity() == 0 ? 4 : cacpcity() * 2);
			}
			*_finish = val;
			++_finish;
		}

		//βɾ
		void pop_back()
		{
			assert(_finish != _start);
			--_finish;
		}
		//ָ�����룬���ص�����
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

		//ָ��λ��ɾ��
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			//pos��һ��λ�ÿ�ʼ��ǰ����
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

		//ɾ�����е�ż��
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