#pragma once

#include<iostream>
#include<vector>

using namespace std;

namespace wyl
{

	template<class K,class V>
	struct HashDataNode
	{
		HashDataNode<K, V>* _next;
		pair<K, V> _kv;
		HashDataNode(const pair<K, V>& kv)
			:_next(nullptr)
			,_kv(kv){}
	};

	template<class K, class V>
	class LinkHash
	{
		typedef HashDataNode<K, V> Node;
		typedef LinkHash<K, V> self;
	public:
		LinkHash()
			:_n(0){}

		LinkHash(const self& s)
		{
			for (int i = 0; i < s._tables.size(); i++)
			{
				Node* cur = s._tables[i];
				while (cur)
				{
					insert(cur->_kv);
					cur = cur->_next;
				}
			}
		}

		~LinkHash()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					Node* next = cur->_next;
					erase(cur->_kv.first);
					cur = next;
				}
			}
		}

		Node* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			size_t start = key % _tables.size();
			Node* cur = _tables[start];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool insert(const pair<K,V>& kv)
		{
			//插入数据已存在
			if (find(kv.first))
				return false;

			//扩容
			if (_n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				std::vector<Node*> newTable;
				newTable.resize(newSize);
				
				//开始转移
				for (int i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t start = cur->_kv.first % newSize;
						cur->_next = newTable[start];
						newTable[start] = cur;
						cur = next;
					}
					cur = nullptr;
				}
				_tables.swap(newTable);	
			}
			
			//插入
			size_t index = kv.first % _tables.size();
			//头插
			Node* NewNode = new Node(kv);
			NewNode->_next = _tables[index];
			_tables[index] = NewNode;
			_n++;
		}


		bool erase(const K& key)
		{
			//找节点
			size_t index = key % _tables.size();
			if (_tables[index] == nullptr)
				return false;

			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur)
			{

				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						Node* next = cur->_next;
						_tables[index] = next;
					}
					else
					{
						Node* next = cur->_next;
						prev->_next = next;
					}
					delete cur;
					_n--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

	private:
		std::vector<Node*> _tables;
		size_t _n;
	};


	void HashTest2()
	{
		LinkHash<int, int> ch;
		ch.insert(make_pair(11, 11));
		ch.insert(make_pair(21, 21));
		ch.insert(make_pair(31, 31));
		ch.insert(make_pair(22, 41));
		ch.insert(make_pair(33, 41));
		ch.insert(make_pair(44, 41));
		ch.insert(make_pair(55, 41));
		ch.insert(make_pair(66, 41));
		ch.insert(make_pair(77, 41));
		ch.insert(make_pair(88, 41));
		ch.insert(make_pair(99, 41));

		LinkHash<int, int> lh(ch);


	}

	void HashTest3()
	{
		LinkHash<int, int>* ch = new LinkHash<int, int>();
		ch->insert(make_pair(11, 11));
		ch->insert(make_pair(21, 21));
		ch->insert(make_pair(31, 31));
		ch->insert(make_pair(22, 41));
		delete ch;

	}

}