#define _CRT_SECURE_NO_WARNINGS 1
#include "BubbleSort.h"
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
void BubbleSort(int* arr, int n)
{
	int i = 0;
	int end = 0;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (end = n - 1; end >= i; end--)
		{
			if (arr[end] < arr[end - 1])
			{
				Swap(&arr[end], &arr[end - 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}