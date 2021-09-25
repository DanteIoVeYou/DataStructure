#define _CRT_SECURE_NO_WARNINGS 1
#include "ShellSort.h"

void ArrayPrint(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		int i = 0;
		gap = gap / 3 + 1;
		for (i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end = end - gap;
				}
				else
				{
					break;
				}
				arr[end + gap] = tmp;
			}
		}
	}
}
