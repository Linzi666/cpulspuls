#pragma once

#include <iostream>
#include <vector>
#include "My_Date.h"
using namespace std;

namespace wyl
{
	template<class T>
	struct Less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	//特化
	template<>
	struct Less<Date*>
	{
		bool operator()(const Date* x, const Date* y)
		{
			return *x < *y;
		}
	};

	template<class T>
	struct Greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	//优先级队列
	template<class T, class container = vector<T>,class compare = Less<T>>
	class piority_queue
	{
	private:
		void adjust_up(size_t child)
		{
			compare cmp;
			//父节点
			size_t parent = (child-1) / 2;
			while (child > 0)
			{
				//if (_con[child] < _con[parent]) // 小堆调整
				if(cmp(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjust_down(size_t parent)
		{
			compare cmp;
			//最后一个节点的父节点开始
			size_t child = parent * 2 +1;
			while (child < _con.size())
			{
				//if ( child + 1 < _con.size() && _con[child] > _con[child + 1])
				if (child + 1 < _con.size() && cmp(_con[child],_con[child+1]))
				{
					child++;
				}
				//if (_con[child] < _con[parent])
				if(cmp(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
	public:
		piority_queue() {}

		void push(const T& val)
		{
			//push是一个尾部插入，向上调整的过程
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}
		T& top()
		{
			return _con[0];
		}
		void pop()
		{
			//堆顶元素和末尾元素交换，然后向下调整。
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}
		bool empty()
		{
			return _con.empty();
		}
		size_t size()
		{
			return _con.size();
		}

	private:
		container _con;
	};



	void priority_queueTest1()
	{
		//piority_queue<Date,vector<Date>,Greater<Date>> pq;
		piority_queue<Date*, vector<Date*>, Less<Date*>> pq;
		Date* d1 = new Date(2022, 1, 3);
		Date* d2 = new Date(2022, 1, 4);
		Date* d3 = new Date(2022, 1, 5);
		Date* d4 = new Date(2022, 1, 6);
		pq.push(d1);
		pq.push(d2);
		pq.push(d3);
		pq.push(d4);


		//pq.push(Date(2022,1,3));
		//pq.push(Date(2022, 1, 4));
		//pq.push(Date(2022, 1, 5));
		//pq.push(Date(2022, 1, 6));
	
		while (!pq.empty()) 
		{
			cout << *pq.top() << " ";
			pq.pop();
		}


	}

}