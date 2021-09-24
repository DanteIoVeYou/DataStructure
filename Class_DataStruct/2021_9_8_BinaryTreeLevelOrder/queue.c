#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

void QueueInit(Queue* que)
{
	assert(que);
	que->head = NULL;
	que->tail = NULL;
}
void QueueDestroy(Queue* que)
{
	assert(que);
	QueueNode* cur = que->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	que->tail = NULL;
}
void QueuePush(Queue* que, QueueDataType x)
{
	assert(que);
	if (que->head == NULL)
	{
		que->head = que->tail = (QueueNode*)malloc(sizeof(QueueNode));
		que->head->data = x;
		que->head->next = NULL;
	}
	else
	{
		que->tail->next = (QueueNode*)malloc(sizeof(QueueNode));
		que->tail = que->tail->next;
		que->tail->data = x;
		que->tail->next = NULL;
	}
}
void QueuePop(Queue* que)
{
	assert(que);
	assert(!QueueEmpty(que));
	QueueNode* next = que->head->next;
	free(que->head);
	que->head = next;
}
QueueDataType QueueTop(Queue* que)
{
	assert(que);
	assert(!QueueEmpty(que));
	return que->head->data;
}
int QueueEmpty(Queue* que)
{
	return que->head == NULL;
}
size_t QueueSize(Queue* que)
{
	assert(que);
	QueueNode* cur = que->head;
	size_t count = 0;
	while(cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}





//struct ListNode* cur = head;
//struct ListNode* tmp = head;
//
//struct ListNode* next = NULL;
//struct ListNode* nnext = NULL;
//if (head && (head)->next)
//{
//	next = cur->next;
//	nnext = next->next;
//}
//while (cur && cur->next)
//{
//	next->next = cur;
//	cur = next;
//	next = nnext;
//	if (nnext)
//		nnext = nnext->next;
//}
//if (tmp)
//tmp->next = NULL;
//return cur;
//
//
//
//if (root != NULL)
//	return  (root->left == NULL && root->right == NULL) && ? 1 : 0 + BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
//else
//	eturn 0;
//
//
//
//
//
//
//int BinaryTreeLevelKSize(BTNode* root, int k)
//{
//	if (!root)
//		return 0;
//	if (k == 1)
//		return 1;
//	else 
//	{
//		return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
//	}
//
//}
//
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return;
//	if(BinaryTreeFind(root->left, x)->data == x)
//		return BinaryTreeFind(root->left, x)
//	else
//		return BinaryTreeFind(root->right, x);
//
//}
//
//
//BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//	if (root->data == x)
//		return root;
//	BTNode* left = BinaryTreeFind(root->left, x);
//	if (left)
//		return left;
//	BTNode* right = BinaryTreeFind(root->right, x);
//	return right;
//}		
//
//
//bool isSymmetric(struct TreeNode* root) {
//	if (root == NULL)
//		return true;
//	if(root->left->data != )
//	
//
//	return isSymmetric
//
//}