#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		printf("malloc failed!\n");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//����������
BTNode* BTCreate()
{
	BTNode* node1 = BuyBTNode(1);
	BTNode* node2 = BuyBTNode(2);
	BTNode* node3 = BuyBTNode(3);
	BTNode* node4 = BuyBTNode(4);
	BTNode* node5 = BuyBTNode(5);
	BTNode* node6 = BuyBTNode(6);
	BTNode* node7 = BuyBTNode(7);



	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = node6;
	node3->right = node7;

	return node1;
}

//���ٶ�����
void BTDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	
	BTDestroy(root->left);
	BTDestroy(root->right);
	free(root);
	
}

//ǰ�����
void BTPrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ", root->data);
		BTPrevOrder(root->left);
		BTPrevOrder(root->right);
	}
}

//��k��Ľڵ����
int BTLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	else
	{
		return BTLevelKSize(root->left, k - 1) + BTLevelKSize(root->right, k - 1);
	}
}


//int Max(int x, int y)
//{
//	return x > y ? x : y;
//}

//������� -> ����Ƚ���ɸѡ
int BTDepth(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + max(BTDepth(root->left), BTDepth(root->right));//ʹ����stdlib.h�еĺ�max
	}
}

// ����������ֵΪx�Ľڵ�
BTNode* ret = NULL;
BTNode* BTFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return  root;
	}
	else
	{
		BTNode* retLeft = BTFind(root->left, x);
		if (retLeft != NULL)
		{
			return retLeft;
		}
		BTNode* retRight = BTFind(root->right, x);
		if (retRight != NULL)
		{
			return retRight;
		}
		return NULL;
	}
}