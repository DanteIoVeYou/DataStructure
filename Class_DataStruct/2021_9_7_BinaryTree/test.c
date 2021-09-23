#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
void test1()
{
	//����һ�ö�����
	BTNode* root = BTCreate();
	//ǰ�����
	BTPrevOrder(root);
	printf("\n");
	//�������
	BTInOrder(root);
	printf("\n");
	//�������
	BTPostOrder(root);
	printf("\n");
	//�������
	//BTLevelOrder(root);
	printf("��3����%d���ڵ�\n", BTLevelKSize(root, 3));
	printf("�������ڵ������%d\n", BTSize(root));
	printf("������Ҷ�ӽڵ������%d\n", BTLeafSize(root));

	printf("�������Ϊ%d\n", BTDepth(root));
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