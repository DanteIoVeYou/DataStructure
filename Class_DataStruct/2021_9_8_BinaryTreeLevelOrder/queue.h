#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct BinaryTreeNode* QueueDataType;
typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

void QueueInit(Queue* que);
void QueueDestroy(Queue* que);
void QueuePush(Queue* que, QueueDataType x);
void QueuePop(Queue* que);
QueueDataType QueueTop(Queue* que);
int QueueEmpty(Queue* que);
size_t QueueSize(Queue* que);



