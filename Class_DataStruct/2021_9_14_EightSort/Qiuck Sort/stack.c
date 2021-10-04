#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"

void StackBuy(Stack* ps)
{
	assert(ps);
	ps->capacity = ps->capacity == 0 ? INIT_NUM : 2 * ps->capacity;
	
	StackDataType* tmp = (StackDataType*)realloc(ps->data, ps->capacity * sizeof(StackDataType));
	if (tmp == NULL)
	{
		printf("realloc failed\n");
		return;
	}
	ps->data = tmp;
}

void StackCheck(Stack* ps)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
 		StackBuy(ps);
	}
}
void StackInit(Stack* ps)
{
	assert(ps);
	ps->capacity = 0;
	ps->size = 0;
	ps->data = NULL;
	StackBuy(ps);
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	ps->capacity = 0;
	ps->size = 0;
	free(ps->data);
	ps->data = NULL;
}

void StackPush(Stack* ps, StackDataType x)
{
	assert(ps);
	StackCheck(ps);
	ps->data[ps->size] = x;
	ps->size++;
}

void StackPrint(const Stack* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->size == 0)
		return;
	else
		--ps->size;
}

int StackEmpty(Stack* ps)
{
	return ps->size == 0;
}

size_t StackSize(const Stack* ps)
{
	return ps->size;
}

StackDataType StackTop(const Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->size - 1];
}