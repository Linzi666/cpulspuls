#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType val;

}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* Node = (BTNode*)malloc(sizeof(BTNode));
	if(Node == NULL)
	{
		printf("malloc fail\n");
	}

	Node->val = x;
	Node->left = Node->right = NULL;

	return Node;
}


BTNode* BinaryCreate()
{
	BTNode* BTNodeA = BuyNode('A');
	BTNode* BTNodeB = BuyNode('B');
	BTNode* BTNodeC = BuyNode('C');
	BTNode* BTNodeD = BuyNode('D');
	BTNode* BTNodeE = BuyNode('E');
	BTNode* BTNodeF = BuyNode('F');
	//BTNode* BTNodeG = BuyNode('G');


	BTNodeA->left = BTNodeB;
	BTNodeA->right = BTNodeC;
	BTNodeB->left = BTNodeD;
	//����G��ô������ȫ�������ˣ�����������
	//BTNodeB->right = BTNodeG;
	BTNodeC->left = BTNodeE;
	BTNodeC->right = BTNodeF;

	return BTNodeA;
}

//ǰ�����
void PreOrder(BTNode* root)
{
	//�����ΪNULL��ֱ�ӷ���
	if (root == NULL)
		return;

	//ǰ��������ȴ�ӡ��
	printf("%c ", root->val);
	//��������
	PreOrder(root->left);
	//�����Һ���
	PreOrder(root->right);
}

//�������
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

//�������
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);

}

//ͳ�ƽڵ����
size_t BinaryTreeSize(BTNode* root)
{
	return root == NULL ? 0 : 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

//ͳ��Ҷ�Ӹ���
size_t BinaryLeafSize(BTNode* root)
{
	//��Ϊ�գ�����0
	if (root == NULL)
		return 0;

	//���Ӻ��Һ��Ӷ�Ϊ�գ���Ҷ�ӽڵ㣬����1
	if (root->left == NULL && root->right == NULL)
		return 1;

	//�ݹ����
	return BinaryLeafSize(root->left) + BinaryLeafSize(root->right);

}

//��K��Ľڵ����
size_t BinaryLevelKSize(BTNode* root, int k)
{
	//��Ϊ�գ�����0
	if (root == NULL)
		return 0;

	//���k����1��˵���ڵ�k��,����1
	if (k == 1)
		return 1;

	return BinaryLevelKSize(root->left, k - 1) + BinaryLevelKSize(root->right, k - 1);
}

//�����������
int BinaryTreeDepth(BTNode* root)
{
	//��Ϊ�գ�����0
	if (root == NULL)
		return 0;

	//�������ӵ����
	int leftRet = BinaryTreeDepth(root->left);
	//�����Һ������
	int rightRet = BinaryTreeDepth(root->right);

	//�������Һ��ӽϴ����һ��
	return leftRet < rightRet ? rightRet + 1 : leftRet + 1;

}

//����ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	//��Ϊ�գ�����NULL
	if (root == NULL)
		return NULL;
	
	//root��ֵ����val������root
	if (root->val == x)
		return root;

	//����������x
	BTNode* left = BinaryTreeFind(root->left, x);
	//���ֵ����x�����ص�ǰ�ڵ�
	if (left->val == x)
		return left;

	//�����Һ�����x
	BTNode* right = BinaryTreeFind(root->right, x);
	//���ֵ����x�����ص�ǰ�ڵ�
	if (right->val == x)
		return right;

	//���Һ��Ӷ�û�ҵ�������null
	return NULL;
}

//�������
void LevelOrder(BTNode* root)
{
	//���rootΪ�գ�����
	if (root == NULL)
		return;

	//����һ������
	Queue q;
	//��ʼ������
	QueueInto(&q);

	//���ڵ����
	QueuePush(&q, root);

	//ѭ����ӳ���
	while (!QueueIsEmpty(&q))
	{
		//�����ͷ�ڵ�
		BTNode* Front = QueueGetFront(&q);
		//��ͷ�ڵ㣬Ҳ���Ǹ��ڵ����
		QueuePop(&q);

		//�����������,��ȷ���ýڵ㲻��Ϊ��
		if (Front != NULL)
		{
			//��ӡ
			printf("%c ", Front->val);
			//���������
			QueuePush(&q, Front->left);
			QueuePush(&q, Front->right);

		}
		else
			printf("NULL "); //��Ҫ�ɲ�Ҫ
	}
	printf("\n");

}

// �ж϶������Ƿ�����ȫ������
bool BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
		return true;


	//����һ������
	Queue q;
	//��ʼ������
	QueueInto(&q);
	//�����
	QueuePush(&q, root);
	while (!QueueIsEmpty(&q))
	{
		BTNode* Front = QueueGetFront(&q);
		QueuePop(&q);
		//�����ͷ��NULL����ô˵���������ĺ�һ���ڵ�
		if (Front == NULL)
			break;

		//Front��Ϊ�գ�2���������
		QueuePush(&q, Front->left);
		QueuePush(&q, Front->right);
	}

	while (!QueueIsEmpty(&q))
	{
		//�������ϲ�����������������Front����ȫΪ�գ�����Ͳ�����ȫ������
		BTNode* Front = QueueGetFront(&q);
		QueuePop(&q);

		if (Front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	//ѭ������˵�����涼��NULL����������ȫ������
	QueueDestroy(&q);
	return true;
}


int main()
{
	BTNode* root = BinaryCreate();
	printf("ǰ�����:");
	PreOrder(root);
	printf("\n");

	printf("�������:");
	InOrder(root);
	printf("\n");

	printf("�������:");
	PostOrder(root);
	printf("\n");

	printf("�����ܽڵ����:");
	printf("%d",BinaryTreeSize(root));
	printf("\n");

	printf("����Ҷ�ӽڵ����");
	printf("%d", BinaryLeafSize(root));
	printf("\n");

	printf("�ҵ��Ľڵ�ֵΪ��");
	BTNode* BT = BinaryTreeFind(root,'B');
	printf("%c ",BT->val);
	printf("\n");

	printf("��������ǣ�");
	printf("%d ", BinaryTreeDepth(root)); 
	printf("\n");

	int i = 3;
	printf("���ĵ�%d��Ľڵ���:",i);
	printf("%d ", BinaryLevelKSize(root,i));
	printf("\n");

	printf("�������:");
	LevelOrder(root);

	bool a = BinaryTreeComplete(root);
	if (a)
		printf("����ȫ������\n");
	else
		printf("������ȫ������\n");

}