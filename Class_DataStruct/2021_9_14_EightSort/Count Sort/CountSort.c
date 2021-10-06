#define _CRT_SECURE_NO_WARNINGS 1
#include "CountSort.h"

void ArrayPrint(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//非比较排序：计数排序
void CountSort(int* arr, int n)
{
	int max = arr[0];
	int min = arr[0];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		if (arr[i] < min)
			min = arr[i];
	}
	int size = max - min + 1;
	int* tmp = (int*)calloc(size, sizeof(int));
	if (tmp == NULL)
	{
		printf("calloc failed!\n");
		return;
	}
	//统计arr里面各个数的相对映射下的个数
	for (i = 0; i < n; i++)
	{
		tmp[arr[i] - min]++;
	}
	//排序，把tmp统计到的各个数从大到小返回到arr中去
	int j = 0;
	for (i = 0; i < size; i++)
	{
		while (tmp[i]--)
		{
			arr[j++] = min + i;
		}
	}
}