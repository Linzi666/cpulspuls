#pragma once
#include "reverse_iterator.h"

namespace wyl
{
	//节点结构体
	template<class T>
	struct ListNode
	{
		typedef ListNode<T> Node;
		Node* _prve;
		Node* _next;
		T _data;

		//构造函数
		ListNode():_prve(nullptr),_next(nullptr),_data(0){}

		ListNode(const T& val)
			:_prve(nullptr)
			,_next(nullptr)
		{
			_data = val;
		}
	};

	//迭代器
	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
	
		typedef ListNode<T> Node;
		typedef _list_iterator<T,Ref,Ptr> self;
		Node* _it;
		// 构造函数
		_list_iterator(Node* node)
			:_it(node){}
		//前置++重载
		self& operator++()
		{
			_it = _it->_next;
			return *this;
		}

		//后置++重载
		self operator++(int)
		{
			self tmp(*this);
			_it = _it->_next;
			return tmp;
		}

		//前置--重载
		self& operator--()
		{
			_it = _it->_prve;
			return *this;
		}

		//后置--重载
		self operator--(int)
		{
			self tmp(*this);
			_it = _it->_prve;
			return tmp;
		}
		// *重载
		Ref operator*()
		{
			return _it->_data;
		}
		// !=重载
		bool operator!=(const self& it)const
		{
			return _it != it._it;
		}
		// ==重载
		bool operator==(const self& it)const
		{
			return _it == it._it;
		}

		Ptr operator->()
		{
			//返回对象的指针
			return &(_it->_data);
		}

	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		//迭代器
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;
		//反向迭代器
		typedef _reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef _reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		//构造函数
		list()
		{
			//开辟空间
			_head = new Node();
			//自己指向自己
			_head->_prve = _head;
			_head->_next = _head;
		}
		//迭代器区间初始化
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			//创建头节点
			_head = new Node();
			_head->_prve = _head;
			_head->_next = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//拷贝构造
		list(const list<T>& l1)
		{
			//创建头节点
			_head = new Node();
			_head->_prve = _head;
			_head->_next = _head;
			//创建新对象，利用迭代器区间
			list<T> tmp(l1.begin(), l1.end());
			//随后交换新对象和旧对象的成员
			swap(_head, tmp._head);
		}
		list<T>& operator=(const list<T>& l1)
		{
			list<T> tmp(l1);
			swap(_head, tmp._head);
			return *this;
		}

		//析构函数
		~list()
		{
			//清空链表
			clear();
			//释放头节点
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			//除了头节点外，其他都释放。
			iterator it = begin();
			while (it != end())
			{
				//保存下一个位置的地址
				iterator next = it++;
				delete next._it;
			}
			//释放完之后，头节点指向的是个野指针，所以我们让它指向自己
			_head->_next = _head;
			_head->_prve = _head;
		}

		void push_back(const T& val)
		{
			//创建一个新节点
			Node* newNode = new Node(val);
			//找到尾节点
			Node* tail = _head->_prve;
			//尾节点和创建的节点链接
			tail->_next = newNode;
			newNode->_prve = tail;
			_head->_prve = newNode;
			newNode->_next = _head;
		}

		void push_front(const T& val)
		{
			//创建一个新节点
			Node* newNode = new Node(val);
			//保存头节点的下一个节点
			Node* next = _head->_next;
			//链接
			_head->_next = newNode;
			newNode->_prve = _head;
			next->_prve = newNode;
			newNode->_next = next;
		}



		//迭代器获取
		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin()const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end()const
		{
			return const_iterator(_head);
		}

		//反向迭代器获取
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin()const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend()const
		{
			return const_reverse_iterator(begin());
		}


		//插入节点
		iterator insert(iterator pos, const T& val)
		{
			assert(pos._it);
			//保存pos的前一个位置
			Node* cru = pos._it;
			Node* prve = cru->_prve;
			//创建节点
			Node* newNode = new Node(val);
			//链接
			prve->_next = newNode;
			newNode->_prve = prve;
			newNode->_next = cru;
			cru->_prve = newNode;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos._it);
			Node* cru = pos._it;
			Node* prve = cru->_prve;
			Node* next = cru->_next;
			//链接
			prve->_next = next;
			next->_prve = prve;
			//释放cru
			delete cru;
			return next;
		}
		
		void pop_back()
		{
			erase(end());
		}

		void pop_front()
		{
			erase(begin());
		}

	private:
		Node* _head;
	};


	//--------------------------------------------------------------------------------------------
	//以下是测试内容

	void listTest1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_front(30);
		l.push_front(20);
		l.push_front(10);
	}

	void a(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 5;
			cout << *it << " ";
			it++;
		}
	}

	void listTest2()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			*it = 55;
			cout << *it << " ";
			++it;
		}
		//a(l);
	}

	void listTest3()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(4);
		l.push_back(5);
		l.insert(l.begin(),100);
		l.insert(l.end(), 10);

		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			if (*it % 2 == 0)
			{
				it = l.erase(it);
			}
			else
				++it;
		}
		it = l.begin();
		while (it != l.end())
		{
			cout << *it << " ";
			++it;
		}
	}

	void listTest4()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(4);
		l.push_back(5);
		l.clear();
		l.push_back(1);
		l.push_back(2);
		l.push_back(4); 
		l.push_back(5);
		list<int> l2 = l;
		list<int>::iterator it = l2.begin();
		while (it != l2.end())
		{
			cout << *it << " ";
			++it;
		}
	}


	void listTest5()
	{
		list<Date> l;
		l.push_back(Date(2022, 1, 3));
		l.push_back(Date(2022, 1, 4));
		l.push_back(Date(2022, 1, 5));

		list<Date>::iterator it = l.begin();
		while (it != l.end())
		{
			cout << it->_year << "/"<<it->_month<<"/"<<it->_day<<endl;
			++it;
		}

	}

	void listTest6()
	{
		list<Date> l;
		l.push_back(Date(2022, 1, 3));
		l.push_back(Date(2022, 1, 4));
		l.push_back(Date(2022, 1, 5));

		list<Date>::reverse_iterator it = l.rbegin();
		while (it != l.rend())
		{
			cout << it->_year << "/" << it->_month << "/" << it->_day << endl;
			++it;
		}

	}

}