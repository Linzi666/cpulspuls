#pragma once
#include<iostream>
#include<assert.h>
#include<queue>
using namespace std;
namespace wyl
{
	//pair封装key和value
	template<class K, class V>
	struct pair
	{
		pair() {};
		pair(const K& key,const V& value)
			:_first(key)
			, _second(value) {}
		pair<K,V> make_pair(const K k, const V v)
		{
			return pair<K, V>(k, v);
		}
		K _first;
		V _second;
	};



	template<class K, class V>
	struct  AVLTreeNode
	{
		AVLTreeNode<K, V>* _left;
		AVLTreeNode<K, V>* _right;
		AVLTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		int _bf;
		AVLTreeNode(const pair<K,V> kv) :_left(nullptr), _right(nullptr), _parent(nullptr), _bf(0),_kv(kv) {};

	};

	template<class K, class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:
		AVLTree() :_root(nullptr) {};

		bool insert(const pair<K, V>& kv)
		{
			//如果是第一次插入
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}

			Node* parent = nullptr; //记录父亲
			Node* cru = _root;  //从根节点开始找
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
					return false;
			}

			cru = new Node(kv);
			cru->_parent = parent;
			//如果在cru在父亲的左边
			if (parent->_kv._first > kv._first)
				parent->_left = cru;
			else
				parent->_right = cru;


			//控制平衡因子
			while (parent)
			{
				//因为cru是parent的子节点，所以新增节点会改变父节点的值
				if (parent->_left == cru)
					parent->_bf--;
				else
					parent->_bf++;

				//判断
				if (parent->_bf == 0) //树的形状正常
					break;
				else if (parent->_bf == 1 || parent->_bf == -1) //新增了一个节点，需要继续往上更新平衡因子
				{
					cru = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == -2 || parent->_bf == 2) //平衡因子为2说明树不平衡了
				{
					if (parent->_bf == 2 && cru->_bf == 1) //右边一边高，左单旋
						ReverseL(parent);
					else if (parent->_bf == -2 && cru->_bf == -1)
						ReverseR(parent);
					else if (parent->_bf == -2 && cru->_bf == 1) //左右双旋
						ReverseLR(parent);
					else if (parent->_bf == 2 && cru->_bf == -1)
						ReverseRL(parent);
					break;
				}

			}

		}
		//左单旋
		void ReverseL(Node* parent)
		{
			Node* SubR = parent->_right;
			Node* SubRL = SubR->_left;
			parent->_right = SubRL;
			if (SubRL)
				SubRL->_parent = parent;

			Node* parentParent = parent->_parent;
			parent->_parent = SubR;
			SubR->_left = parent;
			//parent为根节点的情况
			if (parentParent == nullptr)
			{
				_root = SubR;
				_root->_parent = nullptr;
			}
			else
			{
				SubR->_parent = parentParent;
				if (parentParent->_left == parent)
					parentParent->_left = SubR;
				else
					parentParent->_right = SubR;
			}
			SubR->_bf = parent->_bf = 0;
		}

		//right reverse
		void ReverseR(Node* parent)
		{
			Node* SubL = parent->_left;
			Node* SubLR = SubL->_right;
			parent->_left = SubLR;
			if (SubLR)
				SubLR->_parent = parent;

			Node* parentParent = parent->_parent;
			SubL->_right = parent;
			parent->_parent = SubL;
			if (parentParent == nullptr)
			{
				_root = SubL;
				_root->_parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
					parentParent->_left = SubL;
				else
					parentParent->_right = SubL;
				SubL->_parent = parentParent;
			}
			parent->_bf = SubL->_bf = 0;
		}

		void ReverseLR(Node* parent)
		{
			Node* SubL = parent->_left;
			Node* SubLR = SubL->_right;
			int pbf = parent->_bf;
			int lbf = SubL->_bf;
			int lrbf = SubLR->_bf;

			ReverseL(SubL);
			ReverseR(parent);

			if (lrbf == 0)
			{
				parent->_bf = 0;
				SubL->_bf = 0;
				SubLR->_bf = 0;
			}
			else if (lrbf == -1)
			{
				parent->_bf = 1;
				SubL->_bf = 0;
				SubLR->_bf = 0;
			}
			else if (lrbf == 1)
			{
				SubL->_bf = -1;
				parent->_bf = 0;
				SubLR->_bf = 0;
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
			ReverseR(SubR);
			ReverseL(parent);

			if (RLbf == 0)
			{
				parent->_bf = 0;
				SubR->_bf = 0;
				SubRL->_bf = 0;
			}
			else if (RLbf == 1)
			{
				parent->_bf = -1;
				SubR->_bf = 0;
				SubRL->_bf = 0;
			}
			else if (RLbf == -1)
			{
				parent->_bf = 0;
				SubR->_bf = 0;
				SubRL->_bf = -1;
			}
			else
				assert(false);
		}

		bool Erase(const K& key)
		{
			Node* cru = _root;
			Node* parent = nullptr;

			while (cru)
			{
				if (cru->_kv._first > key)
				{
					parent = cru;
					cru = cru->_left;
				}
				else if (cru->_kv._first < key)
				{
					parent = cru;
					cru = cru->_right;
				}
				else
					break;
			}
			if (cru == nullptr)
			{
				//没找到
				return false;
			}
			//找到之后
			Node* min = nullptr;
			Node* minparent = nullptr;
			if (cru->_right)
			{
				min = cru->_right;
				minparent = cru;
			}
			else
			{
				min = cru;
				minparent = min->_parent;
			}
			
			while (min->_left)
			{
				minparent = min;
				min = min->_left;
			}
			//R左节点为空时,和cru交换
			swap(cru->_kv, min->_kv);
			Node* minR = min->_right;

			if (minR)
				minR->_parent = minparent;

	
			if (minparent->_bf == 0 )
			{
				if (minparent->_left == min)
				{
					minparent->_bf++;
					minparent->_left = minR;
				}
				else
				{
					minparent->_bf--;
					minparent->_right = minR;
				}
				delete min;

				//Node* mpp = minparent->_paremt;
		/*		if (mpp->_right == minparent)
				{
					mpp->_bf
					if (mpp->_bf == 2 && minparent == )
						ReverseL(minparent);
					else if (minparent->_bf == -2)
						ReverseR(minparent);
				}*/

				return true;
			}
			minparent->_left = minR;
			delete min;
			//minparent->_bf = 0;
			Node* cru2 = minparent;
			minparent = minparent->_parent;
			while (minparent)
			{
				
				if (cru2 == minparent->_right)
					minparent->_bf--;
				else
					minparent->_bf++;

				if (minparent->_bf == 0)
				{
					cru = minparent;
					minparent = minparent->_parent;
				}
				else if (minparent->_bf == 1 || minparent->_bf == -1)
				{
					 break;
				}
				else if (minparent->_bf == 2 || minparent->_bf == -2)
				{
					cout << minparent->_bf << "  cru:" << cru->_bf << endl;
					if (minparent->_bf == 2 )
						ReverseL(minparent);
					else if (minparent->_bf == -2 )
						ReverseR(minparent);
					else if (minparent->_bf == 2 && cru->_bf == -1)
						ReverseRL(minparent);
					else if (minparent->_bf == -2 && cru->_bf == 1)
						ReverseLR(minparent);
					else
						assert(false);
				}
				else
					assert(false);

			}
			return true;
		}

		bool Isbalance()
		{
			return _Isbalance(_root);
		}
		bool _Isbalance(Node* root)
		{
			if (root == nullptr)
				return true;

			int LeftH = Height(root->_left);
			int RightH = Height(root->_right);
			if (root->_bf != RightH - LeftH)
			{
				cout << root->_kv._first << "现在是平衡因子是:" << root->_bf << endl;
				cout << root->_kv._first << "平衡因子应该是:" << RightH - LeftH << endl;
			}
			return abs(LeftH - RightH) < 2
				&&_Isbalance(root->_left)
				&&_Isbalance(root->_right);
		}
		int Height(Node* root)
		{
			if (root == nullptr)
				return 0;

			int leftH = Height(root->_left);
			int rightH = Height(root->_right);
			return leftH > rightH ? leftH + 1 : rightH + 1;
		}

		//层序遍历
		void Order()
		{
			queue<Node*> q;
			q.push(_root);
			while (!q.empty())
			{
				Node* front = q.front();
				q.pop();
				if (front == nullptr)
					cout << "N ";
				else
				{
					q.push(front->_left);
					q.push(front->_right);
					cout << front->_kv._first << " ";
				}
			}
		}


	private:
		Node* _root;
	};


	void AVLTest1()
	{
		//int arr[] = { 1,2,3,4,5 };
		int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		//int arr[] = { 10,9,12,3,7,6};
		AVLTree<int, int> avl;
		pair<int, int> p;
		for (auto& e : arr)
		{
			avl.insert(p.make_pair(e, e));
		}
		for (int i = 0; i < 9; i++)
		{
			avl.Erase(arr[i]);
			avl.Order();
			cout << endl;
			avl.Isbalance();
		}
	}
}