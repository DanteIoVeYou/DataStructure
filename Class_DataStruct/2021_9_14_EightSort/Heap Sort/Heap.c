#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"
void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void ArrayPrint(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}


void AdjustDown(int* arr, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1< n && arr[child] < arr[child + 1])
		{
			child++;
		}
		if (arr[parent] < arr[child])
		{
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	int parent = (n - 1 - 1) / 2;
	while (parent >= 0)
	{
		AdjustDown(arr, n, parent);
		parent--;
	}
	while (n>1)
	{
		Swap(&arr[0], &arr[--n]);
		AdjustDown(arr, n, 0);
	}
}