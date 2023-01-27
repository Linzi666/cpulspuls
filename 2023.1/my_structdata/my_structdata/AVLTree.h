#pragma once
#include<iostream>
#include<assert.h>
#include<queue>
using namespace std;

namespace wyl
{

	template<class K, class V>
	struct AVLNode
	{
		AVLNode<K, V>* _left;
		AVLNode<K, V>* _right;
		AVLNode<K, V>* _parent;
		int _bf; //平衡因子，记录高度差
		pair<K, V> _kv; //存储的一对数据
		//构造函数
		AVLNode(const pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0) //新增节点肯定是叶子节点，所以高度默认0
			, _kv(kv) {}
	};



	template <class K, class V>
	class AVLTree
	{
		typedef AVLNode<K, V> Node;
	public:
		AVLTree() :_root(nullptr){}

		bool insert(const pair<K,V>& kv)
		{
			//如果是第一次插入
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* cur = _root; //新增节点的插入位置
			Node* parent = nullptr; //插入位置的父亲节点
			while (cur)
			{
				parent = cur;
				if (cur->_kv.first > kv.first)//新插节点的值比当前节点小，往左子树找
					cur = cur->_left;
				else if (cur->_kv.first < kv.first)
					cur = cur->_right;
				else
					return false; //不允许插入重复值的节点
			}
			cur = new Node(kv); //创建新节点
			cur->_parent = parent; //连接父亲
			if (cur->_kv.first > parent->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;

			//节点插入成功，控制平衡因子,父亲为空，则说明调整到根节点了
			while (parent)
			{
				if (cur == parent->_right) //插入节点在父亲节点的右边
					parent->_bf++; //在右边++，在左边--
				else
					parent->_bf--;

				if (parent->_bf == 0)
				{
					//平衡因子为0，说明这棵树之前的平衡因子是-1或者1，也就是说插入新节点后变平衡了
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					//父亲的平衡因子是1或者-1，说明插入之前是0，也就是说插入之前是平衡的
					//插入之后高度发生了变化，所以需要继续往上更新平衡因子
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//平衡因子为2或者-2，说明这颗树或者子树不平衡了，那么调整这颗树
					if (parent->_bf == 2 && cur->_bf == 1)//右边一边高
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1)//左边一边高
						RotateR(parent);
					else if (parent->_bf == -2 && cur->_bf == 1)
						RotateLR(parent);
					else if (parent->_bf == 2 && cur->_bf == -1)
						RotateRL (parent);

						break;
				}
				else
					assert(false);
			}
		}
		// 左单旋
		void RotateL(Node* parent)
		{
			Node* grandparent = parent->_parent;
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//父亲连接subRL
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			//subR的左边连接parent
			subR->_left = parent;
			parent->_parent = subR;
			//grandparent连接subR
			if (grandparent == nullptr)
			{
				//grandparent为空，说明parent一开始是根节点
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				//如果parent一开是grandparent的左子树，则grandparent的左子树连接subR
				if (parent == grandparent->_left)
					grandparent->_left = subR;
				else
					grandparent->_right = subR;
				subR->_parent = grandparent;
			}
			//更新平衡因子
			parent->_bf = subR->_bf = 0;
		}

		//右单旋
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			Node* grandpraent = parent->_parent;
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;

			subL->_right = parent;
			parent->_parent = subL;
			if (grandpraent == nullptr)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (grandpraent->_left == parent)
					grandpraent->_left = subL;
				else
					grandpraent->_right = subL;
				subL->_parent = grandpraent;
			}
			subL->_bf = parent->_bf = 0;
		}
		//左右双旋
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int lrbf = subLR->_bf;

			//先左旋subL
			RotateL(subL);
			//右旋parent
			RotateR(parent);
			//保存LR的平衡因子
			if (lrbf == 0)
			{
				parent->_bf = subL->_bf = subLR->_bf = 0;
			}
			else if (lrbf == -1)
			{
				subL->_bf = subLR->_bf = 0;
				parent->_bf = 1;
			}
			else if (lrbf == 1)
			{
				subL->_bf = -1;
				subLR->_bf = parent->_bf = 0;
			}
			else
				assert(false);
		}
		//右左双旋
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int rlbf = subRL->_bf;
			RotateR(subR);
			RotateL(parent);
			if (rlbf == 0)
			{
				subR->_bf = subRL->_bf = parent->_bf = 0;
			}
			else if (rlbf == -1)
			{
				subRL->_bf = parent->_bf = 0;
				subR->_bf = 1;
			}
			else if (rlbf == 1)
			{
				parent->_bf = -1;
				subR->_bf = subRL->_bf = 0;
			}
			else
				assert(false);
		}

		//查找
		bool Find(const K& k)
		{
			if (_root == nullptr)
				return false;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_kv.first > k)
					cur = cur->_left;
				else if (cur->_kv.first < k)
					cur = cur->_right;
				else
					return true;
			}
			return false;
		}

		bool IsBalance()
		{
			return _IsBalance(_root);
		}

		bool _IsBalance(Node* root)
		{
			if (root == nullptr)
				return true;

			int LeftHeight = _Height(root->_left);
			int RightHeight = _Height(root->_right);
			if (root->_bf != RightHeight - LeftHeight)
			{
				cout << root->_kv.first << "现在是平衡因子是:" << root->_bf << endl;
				cout << root->_kv.first << "平衡因子应该是:" << RightHeight - LeftHeight << endl;
			}
			return abs(LeftHeight - RightHeight) < 2;
		}

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}

	private:
		Node* _root;//AVL树的根
	};
	void AVLTest1()
	{
		//int arr[] = { 1,2,3,4,5,6 };
		//int arr[] = { 6,5,4,3,2,1 };
		int arr[] =  {4, 2, 6, 1, 3, 5, 15, 7, 16, 14} ;
		AVLTree<int,int> avl;
		for (auto& e : arr)
		{
			avl.insert(make_pair(e, e));
		}
		avl.IsBalance();
		cout << avl.Find(1) << ":" << avl.Find(100);
	}
}