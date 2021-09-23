#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
void test1()
{
	//创建一棵二叉树
	BTNode* root = BTCreate();
	//前序遍历
	BTPrevOrder(root);

	printf("第3层有%d个节点\n", BTLevelKSize(root, 3));
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

}
int main()
{
	test1();
	return 0;
}