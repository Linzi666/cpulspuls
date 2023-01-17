#pragma once

#include<utility>
#include<assert.h>
#include<queue>
#include<iostream>
using namespace std;

namespace wyl
{
	template<class K, class V>
	struct pair {
		K _first;
		V _second;
		pair(const K& first = K(), const V& second = V()) :_first(first), _second(second) {}

		pair<K, V> make_pair(K key, V val)
		{
			return pair<K, V>(key, val);
		}

		K* operator->()
		{
			return &_first;
		}
	};

	template<class K, class V>
	struct  AVLTreeNode
	{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		int _bf; //平衡因子
		pair<K, V> _kv;
		AVLTreeNode(const pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0)
			, _kv(kv){}

	};

	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		AVLTree() :_root(nullptr) {}

		bool insert(const pair<K, V>& kv)
		{
			//第一次插入
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* parent = nullptr;
			Node* cru = _root;
			//找节点
			while (cru)
			{
				if (cru->_kv._first > kv._first)
				{
					parent = cru;
					cru = cru->_left;
				}
				else if (cru->_kv._first < kv._first)
				{
					parent = cru;
					cru = cru->_right;
				}
				else
				{
					return false;
				}
			}

			//创建一个新节点
			cru = new Node(kv);
			if (cru->_kv._first < parent->_kv._first)
			{
				cru->_parent = parent;
				parent->_left = cru;
			}
			else
			{
				cru->_parent = parent;
				parent->_right = cru;
			}

			//平衡因子控制
			while (parent)
			{
				//如果cru在parent的左边，平衡因子--
				if (cru == parent->_left)
					parent->_bf--;
				else
					parent->_bf++;

				//如果平衡因子为0，表示树是平衡的
				if (parent->_bf == 0)
					break;
				else if (parent->_bf == 1 || parent->_bf == -1) //如果平衡因子为1或者-1
				{
					//继续往上更新平衡因子，因为当_bf =1 或者 -1时，说明在插入之前，parent是没有元素的
					//插入之后有了元素，高度也发生了变化
					cru = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2) //平衡因此到-2说明出现问题了，需要调整
				{
					//如果父亲的平衡因子是 -2 ，cru的平衡因子为-1，那么需要右单旋一下
					if (parent->_bf == -2 && cru->_bf == -1)
						ReverseR(parent);
					//左单旋
					else if (parent->_bf == 2 && cru->_bf == 1)
						ReverseL(parent);
					else if (parent->_bf == -2 && cru->_bf == 1)
						ReverseLR(parent);
					else if (parent->_bf == 2 && cru->_bf == -1)
						ReverseRL(parent);
					else
						assert(false);


					break;
				}
				else
				{
					//如果循环走到这说明整棵树在之前就有问题
					assert(false);
				}
			}
			return true;
		}
		//右单旋
		void ReverseR(Node* parent)
		{

			//取左右节点
			Node* SubL = parent->_left;
			Node* SubLR = SubL->_right;
			parent->_left = SubLR;

			//如果SubLR不为空，那么它的父亲指向parent
			if (SubLR)
			{
				SubLR->_parent = parent;
			}
			//保存爷爷节点
			Node* parentparent = parent->_parent;
			SubL->_right = parent;
			parent->_parent = SubL;

			//如果parentparent为空指针，说明parent 是整棵树的根
			if (parent == _root)
			{
				_root = SubL;
				_root->_parent = nullptr;
			}
			else
			{
				if (parentparent->_left == parent)
					parentparent->_left = SubL;
				else
					parentparent->_right = SubL;

				SubL->_parent = parentparent;
			}
			SubL->_bf = parent->_bf = 0;

		}
	
		void ReverseL(Node* parent)
		{
			//p的右子树
			Node* SubR = parent->_right;
			//保存SubR的左子树
			Node* SubRL = SubR->_left;
			parent->_right = SubRL;
			if (SubRL)
			{
				SubRL->_parent = parent;
			}
			Node* paretparet = parent->_parent;
			parent->_parent = SubR;
			SubR->_left = parent;
			if (parent == _root)
			{
				_root = SubR;
				_root->_parent = nullptr;
			}
			else
			{
				if (parent == paretparet->_left)
					paretparet->_left = SubR;
				else
					paretparet->_right = SubR;
				SubR->_parent = paretparet;
			}
			SubR->_bf = parent->_bf =  0;

		}
		//左右双旋
		void ReverseLR(Node* parent)
		{
			Node* SubL = parent->_left;
			Node* SubLR = SubL->_right;
			//保存三个节点的平衡因子
			int pbf = parent->_bf;
			int Lbf = SubL->_bf;
			int LRbf = SubLR->_bf;
			ReverseL(parent->_left);//左旋
			ReverseR(parent);//右旋

			//分三种情况
			// 如果LR是新增节点
			if (LRbf == 0)
			{
				SubL->_bf = 0;
				parent->_bf = 0;
				SubLR->_bf = 0;
			}
			//如果新增的是LR的右节点
			else if (LRbf == 1)
			{
				SubL->_bf = -1;
				parent->_bf = 0;
				SubLR->_bf = 0;
			}
			//如果新增的是LR的左节点
			else if (LRbf == -1)
			{
				SubLR->_bf = -1;
				SubL->_bf = -1;
				parent->_bf = 1;
			}
			else
				assert(false);

		}
		void ReverseRL(Node* parent)
		{
			Node* SubR = parent->_right;
			Node* SubRL = SubR->_left;
			int pbf = parent->_bf;
			int Rbf = SubR->_bf;
			int RLbf = SubRL->_bf;
			ReverseR(SubR); //右旋转
			ReverseL(parent); //左旋转

			//如果RL为新增节点
			if (RLbf == 0)
			{
				parent->_bf = 0;
				SubR->_bf = 0;
				SubRL->_bf = 0;
			}
			//如果RL的右子树为新增节点
			else if (RLbf == 1)
			{
				SubRL->_bf = 0;
				parent->_bf = -1;
				SubR->_bf = 0;
			}
			else if (RLbf == -1) //RL左子树为新增节点
			{
				SubR->_bf = 1;
				parent = 0;
				SubRL = 0;
			}
			else
				assert(false);

		}

		bool IsAVLTree()
		{
			return _IsAVLTree(_root);
		}

		bool _IsAVLTree(Node* root)
		{
			if (root == nullptr)
				return true;

			int LeftHeight = _Height(root->_left);
			int RightHeight = _Height(root->_right);
			if (root->_bf != RightHeight - LeftHeight)
			{
				cout << root->_kv._first <<"现在是平衡因子是:" << root->_bf << endl;
				cout << root->_kv._first <<"平衡因子应该是:" << RightHeight - LeftHeight << endl;
			}
			return abs(LeftHeight - RightHeight) < 2
				&& _IsAVLTree(root->_left)
				&& _IsAVLTree(root->_right);
		}

		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;
			
			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		}

		//层序遍历
		void Order()
		{
			queue<Node*> q;
			Node* cru = _root;
			q.push(cru);
			while (!q.empty())
			{
				Node* front = q.front();
				q.pop();
				if (front == nullptr)
				{
					cout << "N ";
				}
				else
				{
					q.push(front->_left);
					q.push(front->_right);
					cout << front->_kv._first <<" ";
				}
			}
		}

	private:
		Node* _root;
	};
	void AVLTest1()
	{
		AVLTree<int, int> avl;
		//int arr[] = {5,3,2,4};
		int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		pair<int, int> p;
		for (auto& e : arr)
		{
			cout << ":" << avl.IsAVLTree() << ":" ;
			avl.insert(p.make_pair(e,e));
		}
		avl.Order();

	}
}