#pragma once
#include<iostream>
using namespace std;
#include<time.h>

namespace wyl
{
	enum Color
	{
		RED,
		BLACK
	};

	//红黑树节点
	template<class K,class V>
	struct RBTreeNode
	{
		RBTreeNode(const pair<K,V>& kv)
			: _left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_col(RED)
			,_kv(kv){}
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		Color _col;
		pair<K, V> _kv;
	};
	
	//红黑树实现
	template<class K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	public:
		RBTree():_root(nullptr){}
		bool insert(const pair<K,V> kv)
		{
			//第一次插入
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
				return true;
			}
			//先查找值的位置
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_kv.first > kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_kv.first < kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else
					break;
			}
			//如果cur不为空说明有重复的值
			if (cur)
				return false;
			

			//创建新节点
			cur = new Node(kv);
			cur->_parent = parent;
			if (cur->_kv.first > parent->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;

			cur->_col = RED;
			//有连续的红节点,需要调整
			while (parent && parent->_col == RED)
			{
				Node* grandparent = parent->_parent;//祖父节点
				//parent是左孩子的情况
				if (parent == grandparent->_left)
				{
					// 叔叔节点
					Node* uncle = grandparent->_right;
					//如果叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
						//父亲和叔叔变黑
						parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;
						//迭代
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//叔叔为黑或者叔叔不存在
						if (cur == parent->_left)
						{
							//右单旋
							RotateR(grandparent); //旋转祖父
							parent->_col = BLACK;
							grandparent->_col = cur->_col = RED;
						}
						else
						{
							//左右双旋
							RotateL(parent);
							RotateR(grandparent);
							cur->_col = BLACK;
							parent->_col = grandparent->_col = RED;
						}	
					}
				}
				else
				{
					//parent是右孩子的情况
					Node* uncle = grandparent->_left;
					//叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
						uncle->_col = parent->_col = BLACK;
						grandparent->_col = RED;
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//叔叔不存在或为黑
						if (cur = parent->_right)
						{
							//左单旋
							RotateL(grandparent);
							grandparent->_col = cur->_col = RED;
							parent->_col = BLACK;
						}
						else
						{
							//右左双旋
							RotateR(parent);
							RotateL(grandparent);
							cur->_col = BLACK;
							parent->_col = grandparent->_col = RED;
						}
					}
	
				}
			}
			_root->_col = BLACK;	//不管如何，根节点的颜色一定为黑
			return true;
		}

		pair<K, V>* find(const K& key)
		{
			if (_root == nullptr)
				return nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first > key)
					cur = cur->_left;
				else if (cur->_kv.first < key)
					cur = cur->_right;
				else
					return &cur->_kv;
			}
			return nullptr;
		}


		//检查红黑树是否正常
		bool IsBalance()
		{
			if (_root->_col == RED)
			{
				cout << "根节点为红色" << endl;
				return false;
			}

			//找基准值
			Node* min = _root;
			int banchmark = 0;
			while (min)
			{
				if (min->_col == BLACK)
					banchmark++;
				min = min->_left;
			}
			return _IsBalance(_root,banchmark,0);
		}

	private:
		//右单旋
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = parent->_right;
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			Node* grandparent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;
			if (grandparent == nullptr)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (parent == grandparent->_left)
					grandparent->_left = subL;
				else
					grandparent->_right = subL;
				subL->_parent = grandparent;
			}
		}
		//左单旋
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			Node* grandparent = parent->_parent;
			subR->_left = parent;
			parent->_parent = subR;
			if (grandparent == nullptr)
			{
				_root = subR;
				_root->_parent = nullptr;
			}
			else
			{
				if (grandparent->_left == parent)
					grandparent->_left = subR;
				else
					grandparent->_right = subR;
				subR->_parent = grandparent;
			}
		}

		bool _IsBalance(Node* root,int banchmark,int BNNum)
		{
			if (root == nullptr)
			{
				if (banchmark != BNNum)
				{
					cout << "路径中黑节点数量不相等" << endl;
					return false;
				}
				return true;
			}
			if (root->_col == RED && root->_parent->_col == RED)
			{
				cout << "出现连续红节点"<<endl;
				return false;
			}

			if (root->_col == BLACK)
				BNNum++;

			return _IsBalance(root->_left, banchmark, BNNum) &&
			_IsBalance(root->_right, banchmark, BNNum);
		}
		
	private:
		Node* _root;
	};

	//以下是红黑树的测试代码
	void RBTTest1()
	{
		RBTree<int, int> rb;
		srand(time(0));
		int N = 10000000;
		size_t begin1 = clock();
		for (int i = 0; i < N; i++)
		{
			rb.insert(make_pair(i, i));
		}
		size_t end1 = clock();
		cout << "insert " << N << ":" << end1 - begin1 << endl;
		//rb.insert(make_pair(20, 20));
		//rb.insert(make_pair(10, 10));
		//rb.insert(make_pair(5, 5));
		//rb.insert(make_pair(3, 3));
		rb.IsBalance();
	}
}