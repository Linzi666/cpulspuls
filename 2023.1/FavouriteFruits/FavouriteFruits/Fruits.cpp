#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;


//·Âº¯Êý
struct CompIteratorVal
{
	bool operator()(const map<string, int>::iterator l1, const map<string, int>::iterator l2)
	{
		return l1->second < l2->second;
	}
};

void test1(vector<string> fruits)
{
	map<string,int> countMap;
	for (auto& fruit : fruits)
	{
		countMap[fruit]++;
	}
	//map<string, int>::iterator it = countMap.begin();
	//while (it != countMap.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	priority_queue<map<string,int>::iterator,vector<map<string,int>::iterator>,CompIteratorVal> pq;	
	map<string, int>::iterator it = countMap.begin();
	while (it != countMap.end())
	{
		pq.push(it);
		++it;
	}

	int k = 2;
	while (k--)
	{
		cout << pq.top()->first << ":" << pq.top()->second << endl;
		pq.pop();
	}
}

//·Âº¯Êý
struct CompSortVal
{
	bool operator()(map<string,int>::iterator l1, map<string, int>::iterator l2)
	{
		return l1->second > l2->second;
	}
};


void test2(vector<string> fruits)
{
	map<string, int> countMap;
	for (auto& fruit : fruits)
	{
		countMap[fruit]++;
	}
	vector<map<string, int>::iterator>vit;
	map<string, int>::iterator it = countMap.begin();
	while (it != countMap.end())
	{
		vit.push_back(it);
		++it;
	}

	sort(vit.begin(),vit.end(),CompSortVal());
	int k = 5;
	vector<map<string, int>::iterator>::iterator it2 = vit.begin();
	while (k--)
	{
		cout << (*it2)->first<<":" << (*it2)->second << endl;
		++it2;
	}
	
}

//·Âº¯Êý
template<class key>
struct CompSortVal2
{
	bool operator()(const key& l1,const key& l2)const
	{
		return l1 > l2;
	}
};

void test3(vector<string> fruits)
{
	
	map<string, int> countMap;
	for (auto& fruit : fruits)
	{
		countMap[fruit]++;
	}
	multimap<int, string, CompSortVal2<int>> mmap;
	map<string, int>::iterator mit = countMap.begin();
	while (mit != countMap.end())
	{
		mmap.insert(make_pair(mit->second, mit->first));
		++mit;
	}

	multimap<int, string>::iterator mmit = mmap.begin();
	while (mmit != mmap.end())
	{
		cout << mmit->second << ":" << mmit->first << endl;
		++mmit;
	}
}

int main()
{
	
	vector<string> v= { "Æ»¹û","Ïã½¶" ,"²ÝÝ®" ,"Æ»¹û" ,"Æ»¹û" ,"²ÝÝ®" ,"Ïã½¶" ,"Æ»¹û" ,"Ó£ÌÒ","Àæ","Àæ","Àæ","Àæ","Àæ","Àæ" };
	test3(v);
	return 0;
}