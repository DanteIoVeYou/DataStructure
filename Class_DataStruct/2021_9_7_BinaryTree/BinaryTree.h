#pragma once
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
//�����ڵ�
BTNode* BuyBTNode(BTDataType x);
//����������
BTNode* BTCreate();
//���ٶ�����
void BTDestroy(BTNode* root);
//ǰ�����
void BTPrevOrder(BTNode* root);
//�������
void BTInOrder(BTNode* root);
//�������
void BTPostOrder(BTNode* root);
//�������
void BTLevelOrder(BTNode* root);
// �������ڵ����
int BTSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BTLeafSize(BTNode* root);
// ��������k��ڵ����
int BTLevelKSize(BTNode* root, int k);
//������������
int BTDepth(BTNode* root);
// ����������ֵΪx�Ľڵ�
BTNode* BTFind(BTNode* root, BTDataType x);