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

//创建节点
BTNode* BuyBTNode(BTDataType x);

//创建二叉树
BTNode* BTCreate();

//销毁二叉树
void BTDestroy(BTNode* root);

//前序遍历
void BTPrevOrder(BTNode* root);

// 二叉树第k层节点个数
int BTLevelKSize(BTNode* root, int k);

//求二叉树的深度
int BTDepth(BTNode* root);

// 二叉树查找值为x的节点
BTNode* BTFind(BTNode* root, BTDataType x);