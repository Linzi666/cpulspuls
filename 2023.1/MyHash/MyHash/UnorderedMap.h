#pragma once
#include"HashTable.h"


namespace wyl
{
	template<class K,class V,class hash = Hash<K>>
	class unordered_map
	{
		struct MapOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename HashTable<K, pair<K,V>, MapOfT, hash>::hsiterator iterator;
		bool insert(const pair<K, V>& kv)
		{
			return _ht.insert(kv);
		}

		bool erase(const K& k)
		{
			return _ht.erase(k);
		}

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}
	private:
		HashTable<K, pair<K, V>, MapOfT, hash> _ht;
	};

	void TestUnorderedMap()
	{
		unordered_map<string,string> us;
		us.insert(make_pair("AAA","AAA"));
		us.insert(make_pair("BBB", "ABBBAA"));
		us.insert(make_pair("CCC", "CCC"));
		us.insert(make_pair("DDD", "DDD"));
		//cout<<us.find("AAA");
	}

	void TestUnorderedMap2()
	{
		unordered_map<int,int> us;
		//us.insert("AAA");
		//us.insert("BBB");
		//us.insert("CCC");
		//us.insert("DDD");
		//cout<<us.find("AAA");
		us.insert(make_pair(1,1));
		us.insert(make_pair(11, 11));
		us.insert(make_pair(21, 21));
		us.insert(make_pair(2, 2));
		us.insert(make_pair(12, 12));
		us.insert(make_pair(22, 22));

		unordered_map<int,int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << it->first<<":"<<it->second<< endl;
			++it;
		}
	}

}