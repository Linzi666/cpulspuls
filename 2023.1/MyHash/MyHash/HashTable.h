#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace wyl
{
	template<class K, class T, class ValueOfT, class HashFunc>
	class HashTable;

	template<class K>
	struct Hash
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};

	template<>
	struct Hash<string>
	{
		size_t operator()(const string& str)
		{
			size_t ret = 0;
			for (int i = 0; i < str.size(); i++)
			{
				ret *= 31;
				char ch = str[i];
				ret += ch;
			}
			return ret;
		}
	};



	//节点
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		T _data;
		ListNode(const T& data):_next(nullptr),_data(data){}
	};

	//  迭代器
	template<class T, class Ref, class Ptr,class K,class ValueOfT, class HashFunc>
	struct HTiterator
	{
		typedef HTiterator<T, Ref, Ptr,K,ValueOfT,HashFunc> self;
		typedef ListNode<T> Node;
		HTiterator(Node* node, HashTable<K, T, ValueOfT, HashFunc>* hptr) 
			:_node(node)
			,_hptr(hptr){}

		self& operator++()
		{
			size_t index = 0;
			if (_node->_next)
			{
				_node = _node->_next;
			}
			else
			{
				ValueOfT vot;
				HashFunc hf;
				index = hf(vot(_node->_data)) % _hptr->_tables.size();
				++index;
				while (index < _hptr->_tables.size())
				{
					if (_hptr->_tables[index])
					{
						_node = _hptr->_tables[index];
						break;
					}
					else
						index++;
				}

				if (index == _hptr->_tables.size())
				{
					_node = nullptr;
				}			
			}
			return *this;
		}

		bool operator!=(const self& sf)const
		{
			return _node != sf._node;
		}

		bool operator==(const self& sf)const
		{
			return _node == sf._node;
		}
		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Node* _node;
		HashTable<K, T, ValueOfT, HashFunc>* _hptr;
	};

	template<class K,class T,class ValueOfT,class HashFunc>
	class HashTable
	{
		typedef ListNode<T> Node;
		template<class T, class Ref, class Ptr, class K, class ValueOfT, class HashFunc>
		friend struct HTiterator;
	public:
		typedef HTiterator<T, T&, T*, K, ValueOfT, HashFunc> hsiterator;
		Node* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			ValueOfT voft;
			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (hf(voft(cur->_data)) == hf(key))
					return cur;
				else
					cur = cur->_next;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			if (_tables.size() == 0)
				return false;
			
			ValueOfT voft;
			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_data == key)
				{
					//删除
					if (prev == nullptr)
					{
						//头删
						Node* next = cur->_next;
						_tables[index] = next;
					}
					else
					{
						//非头删
						Node* next = cur->_next;
						prev->_next = next;
					}
					delete cur;
					cur = nullptr;
					--_n;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

		bool insert(const T& data)
		{
			ValueOfT voft;
			HashFunc hf;
			if (find((voft(data))))
				return false;

			if (_n == 0 || _n == _tables.size())
			{
				//扩容的情况
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, T, ValueOfT, HashFunc> newHT;
				newHT._tables.resize(newSize);
				//把旧表的值移动到新表
				for (int i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t start = hf(voft(cur->_data)) % newHT._tables.size();
						cur->_next = newHT._tables[start];
						newHT._tables[start] = cur;
						cur = next;	
					}	
					_tables[i] = nullptr;
				}
				_tables.swap(newHT._tables);
			}
			size_t index = hf(voft(data)) % _tables.size();
			Node* newNode = new Node(data);
			newNode->_next = _tables[index];
			_tables[index] = newNode;
			++_n;
			return true;
		}

		hsiterator begin()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				if (_tables[i])
					return hsiterator(_tables[i],this);
			}
			return end();
		}
		hsiterator end()
		{
			return hsiterator(nullptr,this);
		}

	private:
		vector<Node*>_tables;
		size_t _n = 0;
	};

	/*void TestHash1()
	{
		HashTable<int,int> ht;
		ht.insert(make_pair(1, 1));
		ht.insert(make_pair(11, 11));
		ht.insert(make_pair(11, 11));
		ht.insert(make_pair(11, 11));
		ht.insert(make_pair(11, 11));
		ht.insert(make_pair(21, 21));
		ht.insert(make_pair(31, 31));
		ht.insert(make_pair(41, 41));
		ht.insert(make_pair(51, 51));
		ht.insert(make_pair(61, 61));
		ht.insert(make_pair(33, 33));
		ht.insert(make_pair(43, 43));
		ht.insert(make_pair(53, 53));
		ht.insert(make_pair(63, 63));
	}

	void TestHash2()
	{
		HashTable<int, int> ht;
		ht.insert(make_pair(1, 1));
		ht.insert(make_pair(11, 11));
		ht.insert(make_pair(22, 22));
		ht.insert(make_pair(33, 33));
		ht.insert(make_pair(44, 44));
		ht.insert(make_pair(55, 55));
		ht.erase(1);
		ht.erase(11);
		ht.erase(22);
		ht.erase(33);
		ht.erase(44);

	}*/

}
