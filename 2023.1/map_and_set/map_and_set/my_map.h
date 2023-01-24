#pragma once
#include"RBTree.h"


namespace wyl
{
	template<class K, class V>
	class map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};

		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}


		iterator end()
		{
			return _t.end();
		}

		iterator Find(const K& key)
		{
			return _t.Find(key);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _t.insert(kv);
		}
	private:
		RBTree<const K, pair<K,V>, MapKeyOfT> _t;
	};


	void MapTest()
	{
		map<int,int> s;
		int arr[] = { 8,5,4,3,2,1,6, 7 };

		for (auto e : arr)
		{
			s.insert(make_pair(e,e));
		}
		map<int,int>::iterator it = s.begin();
		//while (it != s.end())
		//{
		//	cout << it->first << ":"<<it->second<<endl;
		//	++it;
		//}
		for (int i = 0; i < 7; i++)
			++it;

		while (it != nullptr)
		{
			cout << it->first << ":" << it->second << endl;
			--it;
		}
	}
	void MapTest2()
	{
		map<string, string> s;
		s.insert(make_pair("left", "左边"));
		s.insert(make_pair("right", "右边"));
		s.insert(make_pair("map", "地图"));

		for (auto e : s)
		{
			cout << e.first << ":" << e.second << endl;
		}
		s["right"] = "正确的";
		for (auto e : s)
		{
			cout << e.first << ":" << e.second << endl;
		}
	}
}