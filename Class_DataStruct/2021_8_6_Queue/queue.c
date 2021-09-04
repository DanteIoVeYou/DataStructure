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



