#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int DLListDataType;

typedef struct DLList
{
	struct DLList* next;
	struct DLList* prev;
	DLListDataType data;
}DLList;

DLList* DLListInit();
void DLListDestroy(DLList* phead);
void DLListPrint(const DLList* phead);
void DLListPushBack(DLList* pphead, DLListDataType x);
void DLListPushFront(DLList* pphead,DLListDataType x);
void DLListPopBack(DLList* pphead);
void DLListPopFront(DLList* pphead);
DLList* DLListFind(const DLList* phead,DLListDataType x);
void DLListInsert(DLList* pos, DLListDataType x);
void DLListErase(DLList* pos);
size_t DLListSize(DLList* phead);
bool DLListEmpty(DLList* phead);