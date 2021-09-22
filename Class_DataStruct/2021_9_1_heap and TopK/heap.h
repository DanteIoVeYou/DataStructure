#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* data;
	size_t size;
	size_t capacity;
}Heap;


void Swap(HeapDataType* x, HeapDataType* y);
void AdjustDownMin(HeapDataType* a, size_t sz, int parent);

void AdjustDownMax(HeapDataType* a, size_t sz, int parent);
void AdjustUpMin(HeapDataType* a, size_t sz, int child);
void AdjustUpMax(HeapDataType* a, size_t sz, int child);


void HeapInitMin(Heap* phead, HeapDataType* arr, size_t sz);
void HeapInitMax(Heap* phead, HeapDataType* arr, size_t sz);

void HeapDestroy(Heap* phead);
void HeapPrint(Heap* phead);

void HeapPushMin(Heap* phead, HeapDataType x);
void HeapPushMax(Heap* phead, HeapDataType x);

void HeapPopMin(Heap* phead);
void HeapPopMax(Heap* phead);

HeapDataType HeapTop(Heap* phead);
bool HeapEmpty(Heap* phead);
size_t HeapSize(Heap* phead);

void PrintTopK(int* a, int sz, int k);
void PrintTopK2(int* a, size_t sz, int k);

void TestTopk();