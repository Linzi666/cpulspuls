#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;


namespace wyl
{
	enum status
	{
		EXIST,
		DELETE,
		EMPTY
	};

	template<class K>
	struct Hash
	{
		size_t operator()(const K& key)
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
			int i = 0;
			for (i = 0; i < str.size(); i++)
			{
				char ch = str[i];
				ret *= 31;
				ret +=  ch;
			}
			return ret;
		}
	};


	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		status _status = EMPTY;
		
	};

	template<class K, class V,class HashCom = Hash<K>>
	class HashTable
	{
	public:

		HashData<K,V>* Find(const K& key)
		{
			if (_n == 0)
				return nullptr;
			HashCom hc;
			size_t start = hc(key) % _tables.size();
			size_t index = start;
			size_t i = 0;
			while (_tables[index]._status == EXIST)
			{
				if (_tables[index]._kv.first == key)
					return &_tables[index];
				index = start + i * i;
				++i;
				index %= _tables.size();
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			HashData* find = Find(key);
			if (find == nullptr)
				return false;
			else
			{
				find->_status = DELETE;
				_n--;
				return true;
			}
		}

		bool insert(const pair<K,V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}
			
			if (_tables.size() == 0 || _n * 10 / _tables.size() == 7)
			{
				//À©Èİ
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				HashTable<K,V, HashCom> newHT;
				newHT._tables.resize(newSize);
				for (int i = 0; i < _tables.size(); i++)
				{
					newHT.insert(_tables[i]._kv);
				}
				swap(_tables,newHT._tables);
			}
			//²åÈë²Ù×÷
			HashCom hc;
			size_t start = hc(kv.first) % _tables.size();
			size_t index = start;
			size_t i = 0;
			while (_tables[index]._status != EMPTY)
			{
				index = start + i * i;
				index %= _tables.size();
				++i;
			}
			_tables[index]._kv = kv;
			_tables[index]._status = EXIST;
			++_n;
			return true;
		}
	private:
		vector<HashData<K, V>> _tables;
		size_t _n = 0;
	};

	void TestHashTable()
	{
		HashTable<int, int> hs;
		hs.insert(make_pair(11, 11));
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

	void TestHashTable2()
	{
		HashTable<string, string> hs;
		hs.insert(make_pair("sort", "ÅÅĞò"));
		hs.insert(make_pair("sort", "ÅÅĞò"));
		hs.insert(make_pair("left", "×ó±ß"));
		hs.insert(make_pair("right", "ÓÒ±ß"));
		Hash<string> hc;
		cout << hc(string("abcd")) << endl;
		cout << hc(string("aadd"));



	}

}


//namespace wyl
//{
//	enum status
//	{
//		EXIST,
//		DELETE,
//		EMPTY
//	};
//	
//	template<class K,class V>
//	struct HashData
//	{
//		pair<K, V> _kv;
//		status _status = EMPTY ;
//	};
//
//	template<class K, class V >
//	class HashTable
//	{		
//	public:
//		HashData<K,V>* Find(const K& key)
//		{
//			if (_n == 0)
//				return nullptr;
//			int start = key % _tables.size();
//			int i = 0;
//			int index = start;
//			while (_tables[index]._status == EXIST)
//			{
//				if (_tables[index]._kv.first == key)
//				{
//					return &_tables[index];
//				}
//				++i;
//				index =start + i * i;
//				index %= _tables.size();
//			}
//			return nullptr;
//		}
//
//		bool Erase(const K& key)
//		{
//			HashData<K,V>* find = Find(key);
//			if (find == nullptr)
//			{
//				return false;
//			}
//			else
//			{
//				find->_status = DELETE;
//				return true;
//			}
//		}
//
//		bool insert(const pair<K,V>& kv)
//		{
//			if (Find(kv.first))
//			{
//				return false;
//			}
//
//			//¼ì²é³¤¶È
//			if (_tables.size() == 0 || _n*10 / _tables.size() == 7 )
//			{
//				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
//				HashTable<K, V> newTable;
//				newTable._tables.resize(newSize);
//				for (int i = 0; i < _tables.size(); i++)
//				{
//					newTable.insert(_tables[i]._kv);
//				}
//				swap(newTable._tables, _tables);
//			}
//			//²åÈë
//			size_t i = 0;
//			size_t start = kv.first % _tables.size();
//			size_t index = start;
//			while (_tables[index]._status == EXIST)
//			{
//				++i;
//				index = start + i*i;
//				index %= _tables.size();
//			}
//			_tables[index]._kv = kv;
//			_tables[index]._status = EXIST;
//			++_n;
//			return true;
//		}
//
//	private:
//		vector<HashData<K, V>> _tables;
//		size_t _n;
//	};
//
//	void TestHashTable()
//	{
//		HashTable<int, int> hs;
//		hs.insert(make_pair(11,11));
//		hs.insert(make_pair(22, 22));
//		hs.insert(make_pair(34, 34));
//		hs.insert(make_pair(44, 44));
//		hs.insert(make_pair(55, 55));
//		hs.insert(make_pair(66, 66));
//		hs.insert(make_pair(77, 77));
//		hs.insert(make_pair(88, 88));
//		//hs.insert(make_pair(99, 99));
//		//hs.insert(make_pair(100, 100));
//		//hs.insert(make_pair(111, 111));
//
//
//
//
//	}
//}