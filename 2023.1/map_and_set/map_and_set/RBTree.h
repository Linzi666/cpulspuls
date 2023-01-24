#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

namespace wyl
{

	enum color
	{
		Red,
		Black
	};

	template<class T>
	struct RBTreeNode {
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		T _data;
		color _col;
		RBTreeNode(const T& data)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(Red)
			, _data(data) {}

	};

	//迭代器
	template<class T,class Ref,class Ptr>
	struct RBTreeIterator
	{
		typedef RBTreeNode<T> Node;
		typedef RBTreeIterator<T, Ref, Ptr> self;
		RBTreeIterator(Node* node) 
			:_node(node) {}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}
		
		self& operator++()
		{
			if (_node->_right)
			{
				Node* min = _node->_right;
				while (min->_left)
				{
					min = min->_left;
				}
				_node = min;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_right == cur)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);
			if (_node->_right)
			{
				Node* min = _node->_right;
				while (min->_left)
				{
					min = min->_left;
				}
				_node = min;
			}
			else
			{
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_right == cur)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return tmp;
		}

		self& operator--()
		{
			assert(_node);
			if (_node->_left)
			{
				Node* max = _node->_left;
				while (max->_right)
				{
					max = max->_right;
				}
				_node = max;
			}
			else
			{
				Node* parent = _node->_parent;
				Node* cur = _node;
				while (parent && parent->_left == cur)
				{
					cur = parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		Node* _node;
	};

	template<class K, class T,class VlueOfT>
	class RBTree
	{
		typedef RBTreeNode<T> Node;
		typedef RBTree<K, T, VlueOfT> self;
	public:
		RBTree() :_root(nullptr) {}

		//析构
		~RBTree()
		{
			Destroy(_root);
		}
		//拷贝构造
		RBTree(const RBTree<K, T, VlueOfT>& rbt)
		{
			_root = copy(rbt._root);
		}

		//赋值重载
		self& operator=(self rbt)
		{
			swap(rbt._root,_root);
			return *this;
		}

		typedef RBTreeIterator<T, T&, T*> iterator;
		//迭代器
		iterator begin()
		{
			if (_root == nullptr)
				return iterator(nullptr);

			Node* left = _root;
			while (left->_left)
			{
				left = left->_left;
			}
			return iterator(left);
		}
		iterator end()
		{
			return iterator(nullptr);
		}

		//插入
		pair<iterator,bool> insert(const T& data)
		{
			VlueOfT voft;
			if (_root == nullptr)
			{
				_root = new Node(data);
				_root->_col = Black;
				return make_pair(_root,true);
			}
			Node* cur = _root;
			Node* parent = nullptr;
			//查找新增位置
			while (cur)
			{
				parent = cur;
				if (voft(cur->_data) > voft(data))
					cur = cur->_left;
				else if (voft(cur->_data) < voft(data))
					cur = cur->_right;
				else
					return make_pair(cur, false);
			}

			cur = new Node(data);
			cur->_parent = parent;
			cur->_col = Red;
			Node* ret = cur;
			if (voft(cur->_data)< voft(parent->_data))
				parent->_left = cur;
			else
				parent->_right = cur;

			while (parent && parent->_col == Red)
			{
				//祖父节点
				Node* GrandFather = parent->_parent;
				//如果父节点在左
				if (parent == GrandFather->_left)
				{
					Node* uncle = GrandFather->_right; //叔叔节点在右
					//如果叔叔节点为红色切不为空
					if (uncle && uncle->_col == Red)
					{
						//父亲和叔叔节点都变黑
						parent->_col = Black;
						uncle->_col = Black;
						GrandFather->_col = Red;
						cur = GrandFather;
						parent = cur->_parent;
					}
					else
					{
						if ( cur == parent->_left)
						{
							// 左边一边高，右单旋
							ReverseR(GrandFather);
							GrandFather->_col = Red;
							parent->_col = Black;
						}
						else
						{
							ReverseL(parent);
							ReverseR(GrandFather);
							cur->_col = Black;
							GrandFather->_col = Red;
						}
						break;
					}
				}
				else
				{
					Node* uncle = GrandFather->_left;
					if (uncle && uncle->_col == Red)
					{
						GrandFather->_col = Red;
						uncle->_col = Black;
						parent->_col = Black;
						cur = GrandFather;
						parent = cur->_parent;
					}
					else
					{
						//unlce为空 或者 为黑的情况
						if (parent->_right == cur)
						{
							//如果右边一边高，左单旋
							ReverseL(GrandFather);
							parent->_col = Black;
							GrandFather->_col = Red;
						}
						else
						{
							//cru 在parent的左边
							
							ReverseR(parent);//右单旋
							ReverseL(GrandFather);//左单旋
							GrandFather->_col = Red;
							cur->_col = Black;
						}

						break;
					}
				}
			}
			_root->_col = Black;
			return make_pair(ret, true);
		}

		//Find
		iterator Find(const K& key)
		{
			VlueOfT com;
			Node* cur = _root;
			while (cur)
			{
				if (com(cur->_data) < key)
					cur = cur->_right;
				else if (com(cur->_data) > key)
					cur = cur->_left;
				else
					return cur;
			}
			return nullptr;
		}


		void InOrder()
		{
			_InOrder(_root);
		}
	private:
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_kv.first << ":";
			_InOrder(root->_right);

		}

		//旋转
				//左单旋
		void ReverseL(Node* parent)
		{
			//右孩子
			Node* SubR = parent->_right;
			//右孩子的左孩子
			Node* SubRL = SubR->_left;
			parent->_right = SubRL;
			if (SubRL)
				SubRL->_parent = parent;

			//祖父节点
			Node* Grandparent = parent->_parent;
			SubR->_left = parent;
			parent->_parent = SubR;
			if (parent == _root)
			{
				_root = SubR;
				SubR->_parent = nullptr;
			}
			else
			{
				if (Grandparent->_left == parent)
					Grandparent->_left = SubR;
				else
					Grandparent->_right = SubR;
				SubR->_parent = Grandparent;
			}
		}

		//右单旋
		void ReverseR(Node* parent)
		{
			//左孩子
			Node* SubL = parent->_left;
			//左孩子的右孩子
			Node* SubLR = SubL->_right;
			parent->_left = SubLR;
			if (SubLR)
				SubLR->_parent = parent;

			Node* Grandparent = parent->_parent;
			SubL->_right = parent;
			parent->_parent = SubL;
			if (parent == _root)
			{
				_root = SubL;
				_root->_parent = nullptr;
			}
			else
			{
				if (Grandparent->_left == parent)
					Grandparent->_left = SubL;
				else
					Grandparent->_right = SubL;
				SubL->_parent = Grandparent;
			}
		}
		//销毁
		void Destroy(Node* root)
		{
			if (root == nullptr)
				return;

			Destroy(root->_left);
			Destroy(root->_right);
			delete root;	
			root = nullptr;
		}

		Node* copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			
			Node* newNode = new Node(root->_data);
			newNode->_col = root->_col;
			
			newNode->_left = copy(root->_left);
			newNode->_right = copy(root->_right);

			if (newNode->_left)
				newNode->_left->_parent = newNode;
			if(newNode->_right)
				newNode->_right->_parent = newNode;
			return newNode;		
		}
	private:
		Node* _root;
	};

}