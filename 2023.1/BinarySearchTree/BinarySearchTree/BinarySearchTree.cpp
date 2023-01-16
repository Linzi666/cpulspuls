#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

namespace wyl
{
	//树节点
	template<class K>
	struct BSTNode
	{
		BSTNode* _left;
		BSTNode* _right;
		K _key;
		//构造函数
		BSTNode(const K& val)
			:_left(nullptr),
			_right(nullptr),
			_key(val) {}
	};

	//搜索二叉树类
	template<class K>
	class BinarySearchTree
	{
		typedef BSTNode<K> Node;

	public:
		BinarySearchTree() :_root(nullptr) {	}

		bool Insert(const K& key)
		{
			//如果是第一次插入
			if (_root == nullptr)
			{
				_root = new Node(key);
				_root->_left = nullptr;
				_root->_right = nullptr;
				return true;
			}


			Node* parent = nullptr;
			Node* cru = _root;
			while (cru)
			{
				if (cru->_key < key)
				{
					parent = cru;
					cru = cru->_right;
				}
				else if (cru->_key > key)
				{
					parent = cru;
					cru = cru->_left;
				}
				else
				{
					return false;
				}
			}
			//链接
			cru = new Node(key);
			cru->_left = nullptr;
			cru->_right = nullptr;
			if (cru->_key < parent->_key)
			{
				parent->_left = cru;
			}
			else
			{
				parent->_right = cru;
			}
			return true;
		}
		//中序遍历
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
		//查找
		bool Find(const K& key)
		{
			Node* cru = _root;
			while (cru)
			{
				if (cru->_key > key)
				{
					cru = cru->_left;
				}
				else if (cru->_key < key)
				{
					cru = cru->_right;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		bool Erase(const K& key)
		{
			//查找节点
			Node* parent = nullptr;
			Node* cru = _root;
			while (cru)
			{
				if (key < cru->_key)
				{
					parent = cru;
					cru = cru->_left;
				}
				else if (key > cru->_key)
				{
					parent = cru;
					cru = cru->_right;
				}
				else
				{
					//如果左节点为空
					if (cru->_left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cru->_right;
						}
						else
						{
							if (cru == parent->_left)
							{
								parent->_left = cru->_right;
							}
							else
							{
								parent->_right = cru->_right;
							}
						}
						delete cru;
						return true;
					}
					else if (cru->_right == nullptr)
					{
						if (parent == nullptr)
							_root = cru->_left;
						else
						{
							if (cru == parent->_left)
								parent->_left = cru->_left;
							else
								parent->_right = cru->_left;
						}
						delete cru;
						return true;

					}
					else
					{
						Node* MinParent = cru;
						Node* MinNode = cru->_right;
						while (MinNode->_left)
						{
							parent = MinNode;
							MinNode = MinNode->_left;
						}
						cru->_key = MinNode->_key;
						
						if (MinNode == MinParent->_left)
						{
							MinParent->_left = MinNode->_right;
						}
						else
						{
							MinParent->_right = MinNode->_right;
						}
						delete cru;
						return true;
					}
				}
			}
			return false;
		}
		/////////////////////////////////////////////////////////////////////////////
		//递归查找
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}

		//递归插入
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}

		//递归删除
		bool EraseR(const K& key)
		{
			return _EraseR(_root, key);
		}
		

	private:
		//中序遍历子函数
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}

		//递归查找子函数
		bool _FindR(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
				return _FindR(root->_right,key);
			else if (root->_key > key)
				return _FindR(root->_left,key);
			else
				return true;
		}

		//递归插入子函数
		bool _InsertR(Node*& root ,const K& key)
		{
			if (root == nullptr)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key > key)
				return _InsertR(root->_left, key);
			else if (root->_key < key)
				return _InsertR(root->_right, key);
			else
				return false;
		}

		//递归删除子函数
		bool _EraseR(Node*& root,const K& key)
		{
			if (root == nullptr)
				return false;
			//先查找
			if (root->_key > key)
				return _EraseR(root->_left, key);
			else if (root->_key < key)
				return _EraseR(root->_right, key);
			else
			{
				//保存root指向的空间
				Node* del = root;
				//如果左孩子为空
				if (root->_left == nullptr)
					root = root->_right; // root是上一个节点的子节点别名，可以直接替换
				else if (root->_right == nullptr)
					root = root->_left;
				else
				{
					//删除有2个孩子的节点
					Node* Min = root->_right; 
					//找root右子树中最小的节点
					while (Min->_left)
					{
						Min = Min->_left;
					}
					//min和root 进行交换
					swap(Min->_key, root->_key);
					//从Min节点开始递归删除
					return _EraseR(Min, Min->_key);			
				}
			}
		}

	private:
		Node* _root;
	};

	void BSTTest()
	{
		BinarySearchTree<int> BST;
		int arr[] = { 8,7,6,5,4,1,3,2,9};
		for (auto e : arr)
		{
			BST.Insert(e);
		}
		for (int i = 0; i < 9; i++)
		{
			BST.Erase(i+1);
			BST.InOrder();
		}
	}

	void BSTTest_FindR()
	{
		BinarySearchTree<int> BST;
		int arr[] = { 8,7,6,5,4,1,3,2,9 };
		for (auto e : arr)
		{
			BST.Insert(e);
		}
		if (BST.FindR(5))
			cout << "yes" << endl;
		else
			cout << "NO" << endl;
	}

	void BSTTest_InsertR()
	{
		BinarySearchTree<int> BST;
		int arr[] = { 8,7,6,5,4,1,3,2,9 };
		for (auto e : arr)
		{
			BST.InsertR(e);
		}
		BST.InOrder();

	}

	void BSTTest_EraseR()
	{
		BinarySearchTree<int> BST;
		int arr[] = { 5,3,7,1,4,6,8,2,9 };
		for (auto e : arr)
		{
			BST.InsertR(e);
		}
		for (int i = 1; i <= 9; i++)
		{
			BST.EraseR(i);
			BST.InOrder();
		}


	}

}


int main()
{
	wyl::BSTTest_EraseR();
	//wyl::BSTTest_InsertR();
	//cout << sizeof(a);
	return 0;
}