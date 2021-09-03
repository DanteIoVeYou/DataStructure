#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

# define INIT_NUM 4
typedef int StackDataType;
typedef struct Stack {
	StackDataType* data;
	size_t size;
	size_t capacity;
}Stack;


void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPrint(const Stack* ps);
void StackPush(Stack* ps, StackDataType x);
void StackPop(Stack* ps);
int StackEmpty(Stack* ps);
size_t StackSize(const Stack* ps);