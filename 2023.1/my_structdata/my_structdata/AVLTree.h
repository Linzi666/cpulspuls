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
		int _bf; //ƽ�����ӣ���¼�߶Ȳ�
		pair<K, V> _kv; //�洢��һ������
		//���캯��
		AVLNode(const pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _bf(0) //�����ڵ�϶���Ҷ�ӽڵ㣬���Ը߶�Ĭ��0
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
			//����ǵ�һ�β���
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* cur = _root; //�����ڵ�Ĳ���λ��
			Node* parent = nullptr; //����λ�õĸ��׽ڵ�
			while (cur)
			{
				parent = cur;
				if (cur->_kv.first > kv.first)//�²�ڵ��ֵ�ȵ�ǰ�ڵ�С������������
					cur = cur->_left;
				else if (cur->_kv.first < kv.first)
					cur = cur->_right;
				else
					return false; //����������ظ�ֵ�Ľڵ�
			}
			cur = new Node(kv); //�����½ڵ�
			cur->_parent = parent; //���Ӹ���
			if (cur->_kv.first > parent->_kv.first)
				parent->_right = cur;
			else
				parent->_left = cur;

			//�ڵ����ɹ�������ƽ������,����Ϊ�գ���˵�����������ڵ���
			while (parent)
			{
				if (cur == parent->_right) //����ڵ��ڸ��׽ڵ���ұ�
					parent->_bf++; //���ұ�++�������--
				else
					parent->_bf--;

				if (parent->_bf == 0)
				{
					//ƽ������Ϊ0��˵�������֮ǰ��ƽ��������-1����1��Ҳ����˵�����½ڵ���ƽ����
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					//���׵�ƽ��������1����-1��˵������֮ǰ��0��Ҳ����˵����֮ǰ��ƽ���
					//����֮��߶ȷ����˱仯��������Ҫ�������ϸ���ƽ������
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2)
				{
					//ƽ������Ϊ2����-2��˵�����������������ƽ���ˣ���ô���������
					if (parent->_bf == 2 && cur->_bf == 1)//�ұ�һ�߸�
						RotateL(parent);
					else if (parent->_bf == -2 && cur->_bf == -1)//���һ�߸�
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
		// ����
		void RotateL(Node* parent)
		{
			Node* grandparent = parent->_parent;
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//��������subRL
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;

			//subR���������parent
			subR->_left = parent;
			parent->_parent = subR;
			//grandparent����subR
			if (grandparent == nullptr)
			{
				//grandparentΪ�գ�˵��parentһ��ʼ�Ǹ��ڵ�
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				//���parentһ����grandparent������������grandparent������������subR
				if (parent == grandparent->_left)
					grandparent->_left = subR;
				else
					grandparent->_right = subR;
				subR->_parent = grandparent;
			}
			//����ƽ������
			parent->_bf = subR->_bf = 0;
		}

		//�ҵ���
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
		//����˫��
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int lrbf = subLR->_bf;

			//������subL
			RotateL(subL);
			//����parent
			RotateR(parent);
			//����LR��ƽ������
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
		//����˫��
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

		//����
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
				cout << root->_kv.first << "������ƽ��������:" << root->_bf << endl;
				cout << root->_kv.first << "ƽ������Ӧ����:" << RightHeight - LeftHeight << endl;
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
		Node* _root;//AVL���ĸ�
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