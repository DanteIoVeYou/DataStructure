#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
void test1()
{
	//创建一棵二叉树
	BTNode* root = BTCreate();
	//前序遍历
	BTPrevOrder(root);
	printf("\n");
	//中序遍历
	BTInOrder(root);
	printf("\n");
	//后序遍历
	BTPostOrder(root);
	printf("\n");
	//层序遍历
	//BTLevelOrder(root);
	printf("第3层有%d个节点\n", BTLevelKSize(root, 3));
	printf("二叉树节点个数是%d\n", BTSize(root));
	printf("二叉树叶子节点个数是%d\n", BTLeafSize(root));

	printf("树的深度为%d\n", BTDepth(root));
	BTNode* ret = BTFind(root, 8);
	if (ret == NULL)
	{
		printf("no\n");
	}
	else
	{
		printf("%d\n", ret->data);
	}
	BTDestroy(root);
	root = NULL;
}
int main()
{
	test1();
	return 0;
}