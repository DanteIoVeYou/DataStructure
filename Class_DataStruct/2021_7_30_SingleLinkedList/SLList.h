#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLListDataType;

typedef struct SLList {
	SLListDataType data;
	struct SLList* next;
}SLList;

// ADD
void SLListPushBack(SLList** pphead, SLListDataType x);
void SLListPushFront(SLList** pphead, SLListDataType x);
// DELETE
void SLListPopBack(SLList** pphead);
void SLListPopFront(SLList** pphead);
// FIND
SLList* SLListFind(SLList* phead, SLListDataType x);
// MODIFY
void SLListInsertAfter(SLList* phead, SLListDataType x);
void SLListEraseAfter(SLList* phead);
// PRINT
void SLListPrint(const SLList* phead);

void SLListDestroy(SLList** pphead);
