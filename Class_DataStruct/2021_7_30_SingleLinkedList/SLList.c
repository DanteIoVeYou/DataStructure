#define _CRT_SECURE_NO_WARNINGS 1
#include "SLList.h"

SLList* SLListBuyNewCode(SLListDataType x)
{
	SLList* ret = (SLList*)malloc(sizeof(SLList));
	
	if(!ret)
	{
		printf("Malloc Failed!\n");
		exit(-1);
	}

	ret->data = x;
	ret->next = NULL;

	return ret;
}
void SLListPrint(const SLList* phead)
{
	if (phead == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		SLList* cur = phead;
		while (cur->next != NULL)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("%d->NULL\n",cur->data);
	}
}
void SLListPushBack(SLList** pphead, SLListDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		// node == 0
		//Create the first node
		SLList* newnode = SLListBuyNewCode(x);
		*pphead = newnode;
	}
	else
	{
		SLList* cur = *pphead;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		SLList* newnode = SLListBuyNewCode(x);
		cur->next = newnode;
	}
}
void SLListPushFront(SLList** pphead, SLListDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		*pphead = SLListBuyNewCode(x);
	}
	else
	{
		SLList* prev = SLListBuyNewCode(x);
		prev->next = *pphead;
		*pphead = prev;
	}
}
void SLListPopBack(SLList** pphead)
{
	//Method 1
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{

		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLList* cur = *pphead;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}

	//Method 2
	//SLList* cur = *pphead;
	//if (cur->next == NULL)// only one node
	//{
	//	free(cur);
	//	cur = NULL;
	//}
	//else // >= 2 nodes
	//{
	//	SLList* prev = NULL;
	//	while (cur->next != NULL)
	//	{
	//		prev = cur;
	//		cur = cur->next;
	//	}
	//	free(cur);
	//	prev->next = NULL;
	//}
}


void SLListPopFront(SLList** pphead)
{
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL) // only 1 node
	{
		free(*pphead);
		*pphead = NULL;
	}
	else // >= 2 nodes
	{
		SLList* cur = *pphead;
		*pphead = (*pphead)->next;
		free(cur);
		cur = NULL;
	}
}

SLList* SLListFind(SLList* phead, SLListDataType x)
{
	SLList* cur = phead;
	while (cur->next)
	{
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return cur->next;
}

void SLListInsertAfter(SLList* phead, SLListDataType x)
{
	assert(phead);
	SLList* tail = phead->next;
	phead->next = SLListBuyNewCode(x);
	phead->next->next = tail;
}


void SLListEraseAfter(SLList* phead)
{
	assert(phead);
	if (!phead->next)
	{
		printf("No data after\n");
		return;
	}
	else
	{
		SLList* tmp = phead->next;
		phead->next = tmp->next;
		free(tmp);
		tmp = NULL;
	}
}
void SLListDestroy(SLList** pphead)
{
	assert(pphead);
	SLList* cur = *pphead;
	while (cur)
	{
		SLList* tmp = cur->next;
		free(cur);
		cur = tmp;
		tmp = NULL;
	}
	*pphead = NULL;
}

