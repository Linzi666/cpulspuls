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

	//������
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

		//����
		~RBTree()
		{
			Destroy(_root);
		}
		//��������
		RBTree(const RBTree<K, T, VlueOfT>& rbt)
		{
			_root = copy(rbt._root);
		}

		//��ֵ����
		self& operator=(self rbt)
		{
			swap(rbt._root,_root);
			return *this;
		}

		typedef RBTreeIterator<T, T&, T*> iterator;
		//������
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

		//����
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
			//��������λ��
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
				//�游�ڵ�
				Node* GrandFather = parent->_parent;
				//������ڵ�����
				if (parent == GrandFather->_left)
				{
					Node* uncle = GrandFather->_right; //����ڵ�����
					//�������ڵ�Ϊ��ɫ�в�Ϊ��
					if (uncle && uncle->_col == Red)
					{
						//���׺�����ڵ㶼���
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
							// ���һ�߸ߣ��ҵ���
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
						//unlceΪ�� ���� Ϊ�ڵ����
						if (parent->_right == cur)
						{
							//����ұ�һ�߸ߣ�����
							ReverseL(GrandFather);
							parent->_col = Black;
							GrandFather->_col = Red;
						}
						else
						{
							//cru ��parent�����
							
							ReverseR(parent);//�ҵ���
							ReverseL(GrandFather);//����
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

		//��ת
				//����
		void ReverseL(Node* parent)
		{
			//�Һ���
			Node* SubR = parent->_right;
			//�Һ��ӵ�����
			Node* SubRL = SubR->_left;
			parent->_right = SubRL;
			if (SubRL)
				SubRL->_parent = parent;

			//�游�ڵ�
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

		//�ҵ���
		void ReverseR(Node* parent)
		{
			//����
			Node* SubL = parent->_left;
			//���ӵ��Һ���
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
		//����
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