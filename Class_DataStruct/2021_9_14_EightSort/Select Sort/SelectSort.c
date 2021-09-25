#define _CRT_SECURE_NO_WARNINGS 1
#include "SelectSort.h"
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
void SelectSort(int* arr, int n)
{
	////1.单向选择
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < n - 1; i++)
	//{
	//	int begin = i;
	//	int end = n - i;
	//	int mini = i;
	//	int maxi = i;
	//	for (j = i; j < n; j++)
	//	{
	//		if (arr[j] < arr[mini])
	//		{
	//			mini = j;
	//		}
	//	}
	//	Swap(&arr[begin], &arr[mini]);
	//	begin++;
	//}
	
	//2.双向同时选择
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		int i = 0;
		for (i = begin; i <= end; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		Swap(&arr[end], &arr[maxi]);
		if (mini == end)// 处理end是mini的情况，此情况下，由于（end == mini）和maxi交换，mini到了maxi的位置，并不是预期中的end的位置
		{
			mini = maxi;
		}
		Swap(&arr[begin], &arr[mini]);
		begin++;
		end--;
	}
}