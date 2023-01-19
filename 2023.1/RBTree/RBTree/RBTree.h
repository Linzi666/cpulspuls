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

	template<class K, class V>
	struct RBTreeNode {
		RBTreeNode<K, V>* _left;
		RBTreeNode<K, V>* _right;
		RBTreeNode<K, V>* _parent;
		pair<K, V> _kv;
		color _col;
		RBTreeNode(const pair<K, V>& kv)
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _col(Red)
			, _kv(kv) {}

	};

	template<class K, class V>
	class RBTree
	{
		typedef RBTreeNode<K, V> Node;
	public:
		RBTree() :_root(nullptr) {};

		bool insert(const pair<K, V>& kv)
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				_root->_col = Black;
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			//��������λ��
			while (cur)
			{
				parent = cur;
				if (cur->_kv.first > kv.first)
					cur = cur->_left;
				else if (cur->_kv.first < kv.first)
					cur = cur->_right;
				else
					return false;
			}

			cur = new Node(kv);
			cur->_parent = parent;
			cur->_col = Red;
			if (cur->_kv.first < parent->_kv.first)
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
		}
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

		bool Isbalance()
		{
			if (_root->_col == Red)
			{	
				cout << "����:���ڵ㲻�Ǻ�ɫ" << endl;
				return false;
			}
			int banchmark = 0;
			Node* min = _root;
			while (min)
			{
				if (min->_col == Black)
					banchmark++;
				min = min->_left;
			}
			return _Isbalance(_root, banchmark, 0);
		}

		int Height()
		{
			return _Height(_root);
		}
		
		int _Height(Node* root)
		{
			if (root == nullptr)
				return 0;
			int LH = _Height(root->_left);
			int RH = _Height(root->_right);
			return LH > RH ? LH + 1 : RH + 1;
		}

		void InOrder()
		{
			_InOrder(_root);
		}
	private:
		bool _Isbalance(Node* root, int banchmark, int blacknum)
		{
			if (root == nullptr)
			{
				if (banchmark != blacknum)
				{
					cout << "��ɫ�ڵ�·����һ��" << endl;
					return false;
				}
				return true;
			}
			if (root->_col == Red && root->_parent->_col == Red)
			{
				cout << "����ͬ���ĺ�ڵ�" << root->_kv.first << ":" << root->_parent->_kv.first << endl;
				return false;
			}
			if (root->_col == Black)
				blacknum++;

			return _Isbalance(root->_left, banchmark, blacknum)
				&& _Isbalance(root->_right, banchmark, blacknum);
		}

		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_kv.first << ":" << root->_kv.second<<"�ڵ���ɫ:"<<root->_col << endl;
			_InOrder(root->_right);

		}
	private:
		Node* _root;
	};

	void RBTest()
	{
		RBTree<int,int> r;
		int arr[] = { 1,6,9,8,5,2,3,4, };
		int N = 10000000;
		for (int i = 0; i < N; i++)
		{
			r.insert(make_pair(i, i));
		}
		r.Isbalance();
		cout << r.Height() << "��" << endl;

	}
}