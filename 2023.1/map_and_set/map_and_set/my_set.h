#pragma once
#include"RBTree.h"

namespace wyl
{

	template<class K>
	class set
	{
		typedef RBTreeNode<K> Node;
	public:
		struct SetOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};


		typedef typename RBTree<K, K, SetOfT>::iterator iterator;

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

		pair<iterator, bool> insert(const K& k)
		{
			return _t.insert(k);
		}
	private:
		RBTree<const K, K, SetOfT> _t;
	};

	void SetTest()
	{
		set<int> s;
		int arr[] = { 8,5,4,3,2,1,6, 7};
		
		for (auto e: arr)
		{
			s.insert(e);
		}
		set<int>::iterator it = s.begin();
		for (int i = 0; i < 7; i++)
			++it;

		while (it != s.begin())
		{
			cout << *it << " ";
			--it;
		}
		
	}

	void SetTest2()
	{
		set<int> s1;
		int arr[] = { 8,5,4,3,2,1,6, 7 };

		for (auto e : arr)
		{
			s1.insert(e);
		}
		//set<int> s2(s1);
		set<int> s2;
		s2 = s1;
		for (auto e : s2)
		{
			cout << e << " ";
		}
		set<int>::iterator it= s2.Find(8);

		
	}
}