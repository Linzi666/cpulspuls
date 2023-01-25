#pragma once
#include<iostream>
#include<vector>
using namespace std;



namespace wyl
{
	enum status
	{
		EXIST,
		DELETE,
		EMPTY
	};
	
	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		status _status = EMPTY ;
	};

	template<class K, class V >
	class HashTable
	{		
	public:
		HashData<K,V>* Find(const K& key)
		{
			if (_n == 0)
				return nullptr;
			int start = key % _tables.size();
			int i = 0;
			int index = start;
			while (_tables[index]._status == EXIST)
			{
				if (_tables[index]._kv.first == key)
				{
					return &_tables[index];
				}
				++i;
				index =start + i * i;
				index %= _tables.size();
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			HashData<K,V>* find = Find(key);
			if (find == nullptr)
			{
				return false;
			}
			else
			{
				find->_status = DELETE;
				return true;
			}
		}

		bool insert(const pair<K,V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			//检查长度
			if (_tables.size() == 0 || _n*10 / _tables.size() == 7 )
			{
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K, V> newTable;
				newTable._tables.resize(newSize);
				for (int i = 0; i < _tables.size(); i++)
				{
					newTable.insert(_tables[i]._kv);
				}
				swap(newTable._tables, _tables);
			}
			//插入
			size_t i = 0;
			size_t start = kv.first % _tables.size();
			size_t index = start;
			while (_tables[index]._status == EXIST)
			{
				++i;
				index = start + i*i;
				index %= _tables.size();
			}
			_tables[index]._kv = kv;
			_tables[index]._status = EXIST;
			++_n;
			return true;
		}

	private:
		vector<HashData<K, V>> _tables;
		size_t _n;
	};

	void TestHashTable()
	{
		HashTable<int, int> hs;
		hs.insert(make_pair(11,11));
		hs.insert(make_pair(22, 22));
		hs.insert(make_pair(34, 34));
		hs.insert(make_pair(44, 44));
		hs.insert(make_pair(55, 55));
		hs.insert(make_pair(66, 66));
		hs.insert(make_pair(77, 77));
		hs.insert(make_pair(88, 88));
		//hs.insert(make_pair(99, 99));
		//hs.insert(make_pair(100, 100));
		//hs.insert(make_pair(111, 111));




	}
}