#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

#include "queue.h"


//创建二叉树的节点
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
//创建二叉树
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
//销毁二叉树
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
//层序遍历
void BTLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Queue queue;
	Queue* que = &queue;
	QueueInit(que);
	QueuePush(que, root);
	while (!QueueEmpty(que))
	{
		BTNode* front = QueueTop(que);
		QueuePop(que);
		printf("%d ", front->data);

		if (front->left)
		{
			QueuePush(que, front->left);
		}

		if (front->right)
		{
			QueuePush(que, front->right);
		}
	}
	printf("\n");
	QueueDestroy(que);
}
int main()
{
	BTNode* root = BTCreate();
	BTLevelOrder(root);

	BTDestroy(root);
	return 0;
}