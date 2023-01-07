#pragma once
#include<iostream>
#include "ReverseIterator.h"
using namespace std;
namespace wyl
{
	
	template<class T>
	struct ListNode
	{
		ListNode* _next;
		ListNode* _prve;
		T _val;
		
		ListNode(const T& val = T())
			: _next(nullptr)
			,_prve(nullptr)
			,_val(val)
		{}
	};
	
	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
		typedef ListNode<T> Node;
		typedef _list_iterator<T, Ref, Ptr> self;
		Node* _node;
		_list_iterator(Node* node)
		{
			_node = node;
		}

		//前置++
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		//后置++
		self operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prve;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prve;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_val;
		}


		bool operator!=(const self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const self& s)const
		{
			return _node == s._node;
		}

		T* operator->()const
		{
			return &_node->_val;
		}

	};


	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, T*> const_iterator;

		typedef _reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef _reverse_iterator<iterator,const T&,const T*> const_reverse_iterator;

		       
		list()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prve = _head;
		}
		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//迭代器区间构造函数
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prve = _head;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//拷贝构造
		list(list<T>& lt)
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prve = _head;
			list<T> l2(lt.begin(), lt.end());
			swap(l2._head, _head);
		}

		list<T>& operator=(list<T>& lt)
		{
			list l2(lt);
			swap(l2._head, _head);
			return *this;
		}

		void clear()
		{
			//清除
			iterator it = begin();
			while (it != end())
			{
				iterator dec = it++;
				delete dec._node;
			}
			_head->_next = _head;
			_head->_prve = _head;
		}

		void push_back(const T& val)
		{
			//Node* newnode = new Node(val);
			//Node* tail = _head->_prve;
			//tail->_next = newnode;
			//newnode->_prve = tail;
			//_head->_prve = newnode;
			//newnode->_next = _head;
			insert(end(),val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		iterator insert(iterator pos,const T& val)
		{
			Node* newnode = new Node(val);
			Node* cru = pos._node;
			Node* prve = cru->_prve;
			prve->_next = newnode;
			newnode->_prve = prve;
			newnode->_next = cru;
			cru->_prve = newnode;
			return pos;
		}

		//迭代器
		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		//迭代器
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		//反向迭代器
		reverse_iterator rbegin()
		{
			return reverse_iterator(_head);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(_head->_next);
		}

		//反向迭代器
		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(_head);
		}

		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(_head->_next);
		}


	private:
		Node* _head;
		
	};

	struct Date
	{
		int _year;
		int _month;
		int _day;
		Date(int year = 1 , int month = 1 , int day = 1)
			:_year(year)
			,_month(month)
			,_day(day)
		{}
	};


	void list_test1()
	{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	lt.push_back(5);
	it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	}	

	void a(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//(*it)++;
			cout << *it << " ";
			++it;
		}
	}

	void list_test2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		cout << endl;
		a(lt);
	}
	
	void list_test3()
	{
		list<Date> lt;
		lt.push_back(Date(2022,1,  13));
		lt.push_back(Date(2022, 1, 14));
		lt.push_back(Date(2022, 1, 15));
		list<Date> lt2;
		lt2 = lt;

		list<Date>::iterator it = lt2.begin();
		while (it != lt2.end())
		{
			//(*it)++;
			cout << it->_year << "/" << it->_month << "/" << it->_day <<endl;
			++it;
		}
	}

	void list_test4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		//lt.insert(lt.begin(), 50);
		lt.push_front(50);
		lt.push_back(100);
		lt.push_back(100);
		lt.push_back(100);


		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void list_test5()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		//lt.insert(lt.begin(), 50);

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend())
		{
			cout << *rit << " ";
			++rit;
		}
		cout << endl;
	}

}

