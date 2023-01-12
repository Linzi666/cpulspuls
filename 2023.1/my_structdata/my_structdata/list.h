#pragma once
#include "reverse_iterator.h"

namespace wyl
{
	//�ڵ�ṹ��
	template<class T>
	struct ListNode
	{
		typedef ListNode<T> Node;
		Node* _prve;
		Node* _next;
		T _data;

		//���캯��
		ListNode():_prve(nullptr),_next(nullptr),_data(0){}

		ListNode(const T& val)
			:_prve(nullptr)
			,_next(nullptr)
		{
			_data = val;
		}
	};

	//������
	template<class T,class Ref,class Ptr>
	struct _list_iterator
	{
	
		typedef ListNode<T> Node;
		typedef _list_iterator<T,Ref,Ptr> self;
		Node* _it;
		// ���캯��
		_list_iterator(Node* node)
			:_it(node){}
		//ǰ��++����
		self& operator++()
		{
			_it = _it->_next;
			return *this;
		}

		//����++����
		self operator++(int)
		{
			self tmp(*this);
			_it = _it->_next;
			return tmp;
		}

		//ǰ��--����
		self& operator--()
		{
			_it = _it->_prve;
			return *this;
		}

		//����--����
		self operator--(int)
		{
			self tmp(*this);
			_it = _it->_prve;
			return tmp;
		}
		// *����
		Ref operator*()
		{
			return _it->_data;
		}
		// !=����
		bool operator!=(const self& it)const
		{
			return _it != it._it;
		}
		// ==����
		bool operator==(const self& it)const
		{
			return _it == it._it;
		}

		Ptr operator->()
		{
			//���ض����ָ��
			return &(_it->_data);
		}

	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		
	public:
		//������
		typedef _list_iterator<T,T&,T*> iterator;
		typedef _list_iterator<T,const T&,const T*> const_iterator;
		//���������
		typedef _reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef _reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		//���캯��
		list()
		{
			//���ٿռ�
			_head = new Node();
			//�Լ�ָ���Լ�
			_head->_prve = _head;
			_head->_next = _head;
		}
		//�����������ʼ��
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			//����ͷ�ڵ�
			_head = new Node();
			_head->_prve = _head;
			_head->_next = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		//��������
		list(const list<T>& l1)
		{
			//����ͷ�ڵ�
			_head = new Node();
			_head->_prve = _head;
			_head->_next = _head;
			//�����¶������õ���������
			list<T> tmp(l1.begin(), l1.end());
			//��󽻻��¶���;ɶ���ĳ�Ա
			swap(_head, tmp._head);
		}
		list<T>& operator=(const list<T>& l1)
		{
			list<T> tmp(l1);
			swap(_head, tmp._head);
			return *this;
		}

		//��������
		~list()
		{
			//�������
			clear();
			//�ͷ�ͷ�ڵ�
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			//����ͷ�ڵ��⣬�������ͷš�
			iterator it = begin();
			while (it != end())
			{
				//������һ��λ�õĵ�ַ
				iterator next = it++;
				delete next._it;
			}
			//�ͷ���֮��ͷ�ڵ�ָ����Ǹ�Ұָ�룬������������ָ���Լ�
			_head->_next = _head;
			_head->_prve = _head;
		}

		void push_back(const T& val)
		{
			//����һ���½ڵ�
			Node* newNode = new Node(val);
			//�ҵ�β�ڵ�
			Node* tail = _head->_prve;
			//β�ڵ�ʹ����Ľڵ�����
			tail->_next = newNode;
			newNode->_prve = tail;
			_head->_prve = newNode;
			newNode->_next = _head;
		}

		void push_front(const T& val)
		{
			//����һ���½ڵ�
			Node* newNode = new Node(val);
			//����ͷ�ڵ����һ���ڵ�
			Node* next = _head->_next;
			//����
			_head->_next = newNode;
			newNode->_prve = _head;
			next->_prve = newNode;
			newNode->_next = next;
		}



		//��������ȡ
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

		//�����������ȡ
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


		//����ڵ�
		iterator insert(iterator pos, const T& val)
		{
			assert(pos._it);
			//����pos��ǰһ��λ��
			Node* cru = pos._it;
			Node* prve = cru->_prve;
			//�����ڵ�
			Node* newNode = new Node(val);
			//����
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
			//����
			prve->_next = next;
			next->_prve = prve;
			//�ͷ�cru
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
	//�����ǲ�������

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