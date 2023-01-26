#pragma once
#include"HashTable.h"
namespace wyl
{

	template<class K,class hash = Hash<K>>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename HashTable<K, K, SetKeyOfT, hash>::hsiterator iterator;
		bool insert(const K& key)
		{
			return _ht.insert(key);
		}
		bool erase(const K& key)
		{
			return _ht.erase(key);
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
		HashTable<K, K, SetKeyOfT,hash> _ht;
	};

	void TestUnorderedSet()
	{
		unordered_set<int> us;
		//us.insert("AAA");
		//us.insert("BBB");
		//us.insert("CCC");
		//us.insert("DDD");
		//cout<<us.find("AAA");
		us.insert(1);
		us.insert(11);
		us.insert(21);
		us.insert(2);
		us.insert(12);
		us.insert(22);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end())
		{
			cout << *it << endl;
			++it;
		}
	}
}