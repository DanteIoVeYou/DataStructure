#define _CRT_SECURE_NO_WARNINGS 1
#include "MergeSort.h"

void ArrayPrint(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void _MergeSort(int* arr, int* tmp, int left, int right)
{
	if (right <= left)
		return;
	int mid = (right - left) / 2 + left;
	_MergeSort(arr, tmp, left, mid);
	_MergeSort(arr, tmp, mid + 1, right);
	int index = left;
	int begin = left;
	int end = right;
	int begin1 = left;
	int end1 = mid;;
	int begin2 = mid + 1;
	int end2 = right;
	//挑小的数插入
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	//把剩下来一段区间的数依次拷到tmp
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];

	//把tmp数组的值拷回arr数组
	while (begin <= end)
	{
		arr[begin] = tmp[begin];//别写成arr[begin++] = tmp[begin++]; 不然++两次！！！哈哈哈
		begin++;
	}
}
void MergeSort(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc failed!\n");
		return;
	}
	_MergeSort(arr, tmp, 0, n - 1);
	free(tmp);
	tmp = NULL;
}