#define _CRT_SECURE_NO_WARNINGS 1
#include "DLList.h"
DLList* DLListBuyNode(DLListDataType x)
{
	DLList* ret = (DLList*)malloc(sizeof(DLList));
	if (ret == NULL)
	{
		return NULL;
	}
	ret->data = x;
	ret->next = NULL;
	ret->prev = NULL;
	 
	return ret;
}
DLList* DLListInit()
{
	DLList* phead = DLListBuyNode(0);
	if (phead == NULL)
	{
		printf("Init Fail!\n");
		return NULL;
	}
	phead->data = 0;
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void DLListDestroy(DLList* phead)
{
	assert(phead);
	DLList* cur = phead->next;
	while (cur != phead)
	{
		DLList* tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = NULL;
	}
}
void DLListPrint(const DLList* phead)
{
	assert(phead);
	DLList* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
	cur = NULL;
}
void DLListPushBack(DLList* phead, DLListDataType x)
{
	/*assert(phead);
	DLList* newnode= DLListBuyNode(x);
	if (newnode == NULL)
	{
		printf("pushback fail\n");
		exit(-1);
	}
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev->next = newnode;
	phead->prev = newnode;*/
	DLListInsert(phead, x);
}
void DLListPushFront(DLList* phead, DLListDataType x)
{
	/*assert(phead);
	DLList* newnode = DLListBuyNode(x);
	if (newnode == NULL)
	{
		printf("push front fai\n");
		exit(-1);
	}
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;*/
	DLListInsert(phead->next, x);
}
void DLListPopBack(DLList* phead)
{

	//assert(phead);
	//if (phead == phead->prev)
	//{
	//	return;
	//}
	//DLList* tail = phead->prev->prev;
	//free(phead->prev);
	//phead->prev = NULL;
	//tail->next = phead;
	//phead->prev = tail;
	if (phead == phead->next)
		return;
	DLListErase(phead->prev);

}
void DLListPopFront(DLList* phead)
{

	/*assert(phead);
	if (phead == phead->prev)
	{
		return;
	}
	DLList* next = phead->next->next;
	free(phead->next);
	phead->next = NULL;
	phead->next = next;
	next->prev = phead;*/

	if (phead == phead->next)
		return;
	DLListErase(phead->next);

}
DLList* DLListFind(const DLList* phead, DLListDataType x)
{
	assert(phead);
	DLList* cur = phead->next;
	while (cur!=phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void DLListInsert(DLList* pos , DLListDataType x) // insert before
{
	assert(pos);
	DLList* newnode = DLListBuyNode(x);
	if (newnode == NULL)
	{
		printf("newnode create failded\n");
		exit(-1);
	}
	newnode->next = pos;
	newnode->prev = pos->prev;
	pos->prev->next = newnode;
	pos->prev = newnode;
}
void DLListErase(DLList* pos)
{
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

size_t DLListSize(DLList* phead)
{
	assert(phead);
	DLList* cur = phead->prev;
	size_t count = 0;
	while (cur != phead)
	{
		++count;
		cur = cur->prev;
	}
	return count;
}

bool DLListEmpty(DLList* phead)
{
	assert(phead);
	return phead == phead->prev;
}