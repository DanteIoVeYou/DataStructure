#define _CRT_SECURE_NO_WARNINGS 1
#include "BinaryTree.h"
void test1()
{
	//����һ�ö�����
	BTNode* root = BTCreate();
	//ǰ�����
	BTPrevOrder(root);

	printf("��3����%d���ڵ�\n", BTLevelKSize(root, 3));
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

}
int main()
{
	test1();
	return 0;
}