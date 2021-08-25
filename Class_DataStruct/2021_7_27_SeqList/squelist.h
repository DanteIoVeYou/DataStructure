#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SeqListDataType;
#define INIT_SZ 4
typedef struct SeqList {
	SeqListDataType* ptr;
	int capacity;
	int sz;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListPushBack(SeqList* ps, SeqListDataType x);
void SeqListPushFront(SeqList* ps, SeqListDataType x);
void SeqListPrint(const SeqList* ps);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);
void SeqListDestroy(SeqList* ps);
int SeqListFind(const SeqList* ps, SeqListDataType x);
void SeqListInsert(SeqList* ps, size_t pos, SeqListDataType x);
void SeqListErase(SeqList* ps, size_t pos);
void SeqListSortUp(SeqList* ps);
void SeqListSortDown(SeqList* ps);



