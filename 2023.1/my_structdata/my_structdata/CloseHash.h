#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace wyl
{

	enum status
	{
		EXIST, // 表示哈希表里存在这个数
		DELETE,//表示这个数被哈希表移除
		EMPTY//表示这个位置为空
	};

	template<class K,class V>
	struct HashData
	{
		pair<K, V> _kv;
		status _status = EMPTY;
	};

	template<class K, class V>
	class CloseHash
	{
	public:
		bool insert(const pair<K,V>& kv)
		{
			//如果出现重复数字，插入失败
			if (find(kv.first))
				return false;

			if (_tables.size()== 0 || _n * 10 / _tables.size() == 7) //如果元素数量在数组长度的0.7以上，则发生扩容
			{
				//扩容
				size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				//创建一个新的哈希表来转移数据
				CloseHash<K, V> newHT;
				newHT._tables.resize(newSize);
				for (int i = 0; i < _tables.size(); i++)
				{
					//数据转移
					newHT.insert(_tables[i]._kv);
				}
				//转换2张表
				_tables.swap(newHT._tables);
			}

			//插入数据
			size_t start = kv.first % _tables.size(); //起始位置
			size_t i = 0;
			size_t index = start;
			while (_tables[index]._status == EXIST) //空位置和DELETE位置都可以插入
			{
				index = start + i * i;
				index %= _tables.size();
				++i;
			}
			//找到空位置
			_tables[index]._kv = kv;
			_tables[index]._status = EXIST; //状态置为存在
			_n++;
			return true;
		}


		HashData<K,V>* find(const K& key)
		{
			if (_tables.size() == 0)
				return nullptr;

			size_t start = key % _tables.size(); //起始位置
			size_t i = 0;
			size_t index = start;
			while (_tables[index]._status != EMPTY) //找到空位置，结束
			{
				if (_tables[index]._status == EXIST && _tables[index]._kv.first == key)
				{
					//找到了
					return &_tables[index];
				}
				index = start + i * i;
				index %= _tables.size();
				++i;
			}
			return nullptr;
		}

		bool erase(const K& key)
		{
			HashData<K, V>* ret = find(key);
			if (ret)
			{
				ret->_status = DELETE;
				_n--;
				return true;
			}
			else
				return false;
		}

	private:
		std::vector<HashData<K,V>> _tables;
		size_t _n = 0;
	};


	void HashTest1()
	{
		CloseHash<int, int> ch;
		ch.insert(make_pair(11, 11));
		ch.insert(make_pair(21, 21));
		ch.insert(make_pair(31, 31));
		ch.insert(make_pair(41, 41));
		ch.erase(11);
		ch.erase(21);
		ch.erase(51);
		ch.erase(41);
		cout << ch.find(11) << endl;
		cout << ch.find(21) << endl;
		cout << ch.find(31) << endl;
		cout << ch.find(41) << endl;

	}

}