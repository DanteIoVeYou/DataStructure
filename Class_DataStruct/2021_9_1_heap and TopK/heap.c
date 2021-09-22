#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

void Swap(HeapDataType* x, HeapDataType* y)
{
	HeapDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDownMin(HeapDataType* a, size_t sz, int parent)
{
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child + 1 < sz && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustDownMax(HeapDataType* a, size_t sz, int parent)
{
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child + 1 < sz && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUpMin(HeapDataType* a, size_t sz, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustUpMax(HeapDataType* a, size_t sz, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapInitMin(Heap* phead, HeapDataType* arr, size_t sz)
{
	// It is a process of buliding heap
	assert(phead);
	HeapDataType* tmp = (HeapDataType*)malloc(sizeof(HeapDataType) * sz);
	if (tmp == NULL)
	{
		printf("Malloc Failed!\n");
		return;
	}
	phead->data = tmp;
	phead->capacity = sz;
	phead->size = sz;
	memcpy(phead->data, arr, sizeof(HeapDataType) * sz);

	int parent = (sz - 1 - 1) / 2;

	while (parent >= 0)
	{
		AdjustDownMin(phead->data, sz, parent);
		parent--;
	}
}

void HeapInitMax(Heap* phead, HeapDataType* arr, size_t sz)
{
	// It is a process of buliding heap
	assert(phead);
	HeapDataType* tmp = (HeapDataType*)malloc(sizeof(HeapDataType) * sz);
	if (tmp == NULL)
	{
		printf("Malloc Failed!\n");
		return;
	}
	phead->data = tmp;
	phead->capacity = sz;
	phead->size = sz;
	memcpy(phead->data, arr, sizeof(HeapDataType) * sz);

	int parent = (sz - 1 - 1) / 2;

	while (parent >= 0)
	{
		AdjustDownMax(phead->data, sz, parent);
		parent--;
	}
}

void HeapDestroy(Heap* phead)
{
	assert(phead);
	free(phead->data);
	phead->data = NULL;
	phead->size = 0;
	phead->capacity = 0;
}

void HeapPrint(Heap* phead)
{
	assert(phead);
	int i = 0;
	for (i = 0; i < phead->size; i++)
	{
		printf("%d ", phead->data[i]);
	}
	printf("\n");
}

void HeapPushMin(Heap* phead, HeapDataType x)
{
	assert(phead);
	if (phead->capacity == phead->size)
	{
		HeapDataType* tmp = (HeapDataType*)realloc(phead->data,sizeof(HeapDataType) * phead->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			return;
		}
		phead->data = tmp;
		phead->capacity = 2 * phead->capacity;
	}
	phead->data[phead->size] = x;
	phead->size++;
	AdjustUpMin(phead->data, phead->size, phead->size - 1);
}

void HeapPushMax(Heap* phead, HeapDataType x)
{
	assert(phead);
	if (phead->capacity == phead->size)
	{
		HeapDataType* tmp = (HeapDataType*)realloc(phead->data, sizeof(HeapDataType) * phead->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc failed\n");
			return;
		}
		phead->data = tmp;
		phead->capacity = 2 * phead->capacity;
	}
	phead->data[phead->size] = x;
	phead->size++;
	AdjustUpMax(phead->data, phead->size, phead->size - 1);
}

void HeapPopMin(Heap* phead)
{
	assert(phead);
	assert(!HeapEmpty(phead));
	Swap(&phead->data[0], &phead->data[phead->size - 1]);
	phead->size--;
	AdjustDownMin(phead->data, phead->size, 0);
}

void HeapPopMax(Heap* phead)
{
	assert(phead);
	assert(!HeapEmpty(phead));
	Swap(&phead->data[0], &phead->data[phead->size - 1]);
	phead->size--;
	AdjustDownMax(phead->data, phead->size, 0);
}
HeapDataType HeapTop(Heap* phead)
{
	assert(phead);
	assert(!HeapEmpty(phead));
	return phead->data[0];
}
bool HeapEmpty(Heap* phead)
{
	assert(phead);
	return phead->size == 0;
}
size_t HeapSize(Heap* phead)
{
	assert(phead);
	return phead->size;
}


void PrintTopK2(int* a, size_t sz, int k)
{
	Heap hp;
	Heap* php = &hp;
	HeapInitMax(php, a, sz);
	while (k-- && !HeapEmpty(php))
	{
		printf("%d ", HeapTop(php));
		//Swap(php->data[0], php->data[php->size - 1]);
		HeapPopMax(php);
	}
	printf("\n");
	HeapDestroy(&hp);
}

void PrintTopK(int* a, int sz, int k)
{
	Heap hp;
	HeapInitMin(&hp, a, k);
	int i = 0;

	/*printf("================\n");
	for (i = 0; i < k; i++)
	{
		printf("%d ", hp.data[i]);
	}
	printf("\n");
	printf("================\n");*/

	for (i = k; i < sz; i++)
	{
		if (a[i] > HeapTop(&hp))
		{
			HeapPopMin(&hp);
			HeapPushMin(&hp, a[i]);
		}
		
	}
	HeapPrint(&hp);
	HeapDestroy(&hp);
}