#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
int main()
{
	int a[] = { 23,43,349,32,4,56,1,234,55,6,568,33,4,44,4 };
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
	return 0;
}