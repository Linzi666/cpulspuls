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
		int _bf; //ƽ������
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
			//��һ�β���
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* parent = nullptr;
			Node* cru = _root;
			//�ҽڵ�
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

			//����һ���½ڵ�
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

			//ƽ�����ӿ���
			while (parent)
			{
				//���cru��parent����ߣ�ƽ������--
				if (cru == parent->_left)
					parent->_bf--;
				else
					parent->_bf++;

				//���ƽ������Ϊ0����ʾ����ƽ���
				if (parent->_bf == 0)
					break;
				else if (parent->_bf == 1 || parent->_bf == -1) //���ƽ������Ϊ1����-1
				{
					//�������ϸ���ƽ�����ӣ���Ϊ��_bf =1 ���� -1ʱ��˵���ڲ���֮ǰ��parent��û��Ԫ�ص�
					//����֮������Ԫ�أ��߶�Ҳ�����˱仯
					cru = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2) //ƽ����˵�-2˵�����������ˣ���Ҫ����
				{
					//������׵�ƽ�������� -2 ��cru��ƽ������Ϊ-1����ô��Ҫ�ҵ���һ��
					if (parent->_bf == -2 && cru->_bf == -1)
						ReverseR(parent);
					//����
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
					//���ѭ���ߵ���˵����������֮ǰ��������
					assert(false);
				}
			}
			return true;
		}
		//�ҵ���
		void ReverseR(Node* parent)
		{

			//ȡ���ҽڵ�
			Node* SubL = parent->_left;
			Node* SubLR = SubL->_right;
			parent->_left = SubLR;

			//���SubLR��Ϊ�գ���ô���ĸ���ָ��parent
			if (SubLR)
			{
				SubLR->_parent = parent;
			}
			//����үү�ڵ�
			Node* parentparent = parent->_parent;
			SubL->_right = parent;
			parent->_parent = SubL;

			//���parentparentΪ��ָ�룬˵��parent ���������ĸ�
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
			//p��������
			Node* SubR = parent->_right;
			//����SubR��������
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
		//����˫��
		void ReverseLR(Node* parent)
		{
			Node* SubL = parent->_left;
			Node* SubLR = SubL->_right;
			//���������ڵ��ƽ������
			int pbf = parent->_bf;
			int Lbf = SubL->_bf;
			int LRbf = SubLR->_bf;
			ReverseL(parent->_left);//����
			ReverseR(parent);//����

			//���������
			// ���LR�������ڵ�
			if (LRbf == 0)
			{
				SubL->_bf = 0;
				parent->_bf = 0;
				SubLR->_bf = 0;
			}
			//�����������LR���ҽڵ�
			else if (LRbf == 1)
			{
				SubL->_bf = -1;
				parent->_bf = 0;
				SubLR->_bf = 0;
			}
			//�����������LR����ڵ�
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
			ReverseR(SubR); //����ת
			ReverseL(parent); //����ת

			//���RLΪ�����ڵ�
			if (RLbf == 0)
			{
				parent->_bf = 0;
				SubR->_bf = 0;
				SubRL->_bf = 0;
			}
			//���RL��������Ϊ�����ڵ�
			else if (RLbf == 1)
			{
				SubRL->_bf = 0;
				parent->_bf = -1;
				SubR->_bf = 0;
			}
			else if (RLbf == -1) //RL������Ϊ�����ڵ�
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
				cout << root->_kv._first <<"������ƽ��������:" << root->_bf << endl;
				cout << root->_kv._first <<"ƽ������Ӧ����:" << RightHeight - LeftHeight << endl;
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

		//�������
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