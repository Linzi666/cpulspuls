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

	//������ڵ�
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
	
	//�����ʵ��
	template<class K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	public:
		RBTree():_root(nullptr){}
		bool insert(const pair<K,V> kv)
		{
			//��һ�β���
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = BLACK;
				return true;
			}
			//�Ȳ���ֵ��λ��
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
			//���cur��Ϊ��˵�����ظ���ֵ
			if (cur)
				return false;
			

			//�����½ڵ�
			cur = new Node(kv);
			cur->_parent = parent;
			if (cur->_kv.first > parent->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;

			cur->_col = RED;
			//�������ĺ�ڵ�,��Ҫ����
			while (parent && parent->_col == RED)
			{
				Node* grandparent = parent->_parent;//�游�ڵ�
				//parent�����ӵ����
				if (parent == grandparent->_left)
				{
					// ����ڵ�
					Node* uncle = grandparent->_right;
					//������������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						//���׺�������
						parent->_col = uncle->_col = BLACK;
						grandparent->_col = RED;
						//����
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//����Ϊ�ڻ������岻����
						if (cur == parent->_left)
						{
							//�ҵ���
							RotateR(grandparent); //��ת�游
							parent->_col = BLACK;
							grandparent->_col = cur->_col = RED;
						}
						else
						{
							//����˫��
							RotateL(parent);
							RotateR(grandparent);
							cur->_col = BLACK;
							parent->_col = grandparent->_col = RED;
						}	
					}
				}
				else
				{
					//parent���Һ��ӵ����
					Node* uncle = grandparent->_left;
					//���������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						uncle->_col = parent->_col = BLACK;
						grandparent->_col = RED;
						cur = grandparent;
						parent = cur->_parent;
					}
					else
					{
						//���岻���ڻ�Ϊ��
						if (cur = parent->_right)
						{
							//����
							RotateL(grandparent);
							grandparent->_col = cur->_col = RED;
							parent->_col = BLACK;
						}
						else
						{
							//����˫��
							RotateR(parent);
							RotateL(grandparent);
							cur->_col = BLACK;
							parent->_col = grandparent->_col = RED;
						}
					}
	
				}
			}
			_root->_col = BLACK;	//������Σ����ڵ����ɫһ��Ϊ��
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


		//��������Ƿ�����
		bool IsBalance()
		{
			if (_root->_col == RED)
			{
				cout << "���ڵ�Ϊ��ɫ" << endl;
				return false;
			}

			//�һ�׼ֵ
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
		//�ҵ���
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
		//����
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
					cout << "·���кڽڵ����������" << endl;
					return false;
				}
				return true;
			}
			if (root->_col == RED && root->_parent->_col == RED)
			{
				cout << "����������ڵ�"<<endl;
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

	//�����Ǻ�����Ĳ��Դ���
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