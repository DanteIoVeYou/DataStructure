#define _CRT_SECURE_NO_WARNINGS 1
#include"squelist.h"


void SeqListCheckCap(SeqList* ps)
{
	assert(ps);
	if (ps->sz == ps->capacity)
	{
		SeqListDataType* tmp = realloc(ps->ptr, 2 * ps->capacity * sizeof(SeqListDataType));
		ps->capacity *= 2;
		if (tmp)
		{
			ps->ptr = tmp;
		}
	}
	if (ps->capacity > 4 * ps->sz && ps->sz != 0 )
	{
		SeqListDataType* tmp = realloc(ps->ptr, (ps->capacity / 2) * sizeof(SeqListDataType));
		ps->capacity /= 2;
		if (tmp)
		{
			ps->ptr = tmp;
		}
	}

}

int SortDown(SeqListDataType* e1, SeqListDataType* e2)
{
	return *e2 - *e1;
}

int SortUp(SeqListDataType* e1,SeqListDataType* e2)
{
	return *e1 - *e2;
}
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->ptr = (SeqListDataType*)malloc(INIT_SZ * sizeof(SeqListDataType));
	if (ps->ptr)
	{
		ps->capacity = INIT_SZ;
		ps->sz = 0;
	}	
}

void SeqListDestroy(SeqList* ps)
{
	ps->sz = 0;
	ps->capacity = 0;
	free(ps->ptr);
	ps->ptr = NULL;
}

void SeqListPushBack(SeqList* ps, SeqListDataType x)
{
	assert(ps);
	SeqListCheckCap(ps);
	ps->ptr[ps->sz] = x;
	ps->sz++;
}

void SeqListPushFront(SeqList* ps, SeqListDataType x)
{
	assert(ps);
	SeqListCheckCap(ps);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		ps->ptr[ps->sz - i] = ps->ptr[ps->sz - i - 1];
	}
	ps->ptr[0] = x;
	ps->sz++;
}

void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->ptr[i]);
	}
	printf("\n");
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	SeqListCheckCap(ps);
	SeqListCheckCap(ps);
	ps->sz--;
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	SeqListCheckCap(ps);
	int i = 0;
	for (i = 0; i < ps->sz - 1; i++)
	{
		ps->ptr[i] = ps->ptr[i - 1];
	}
	ps->sz--;
}

int SeqListFind(const SeqList* ps,SeqListDataType x)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (x == ps->ptr[i])
		{
			return 1;
		}
	}
	return 0;
}

void SeqListInsert(SeqList* ps, size_t pos, SeqListDataType x)
{
	assert(ps);
	SeqListCheckCap(ps);
	SeqListCheckCap(ps);
	int i = 0;
	for (i = 0; i < ps->sz - pos + 1; i++)
	{
		ps->ptr[ps->sz - i] = ps->ptr[ps->sz - i - 1];
	}
	ps->ptr[pos - 1] = x;
	ps->sz++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	SeqListCheckCap(ps);	
	int i = 0;
	for (i = 0; i < ps->sz - pos; i++)
	{
		ps->ptr[pos + i - 1] = ps->ptr[pos + i];
	}
	ps->sz--;
}

void SeqListSortUp(SeqList* ps)
{
	assert(ps);
	qsort(ps->ptr, ps->sz, sizeof(SeqListDataType), SortUp);

}

void SeqListSortDown(SeqList* ps)
{
	assert(ps);
	qsort(ps->ptr, ps->sz, sizeof(SeqListDataType), SortDown);
}






