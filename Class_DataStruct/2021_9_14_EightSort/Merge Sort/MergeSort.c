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
	//��С��������
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	//��ʣ����һ������������ο���tmp
	while (begin1 <= end1)
		tmp[index++] = arr[begin1++];
	while (begin2 <= end2)
		tmp[index++] = arr[begin2++];

	//��tmp�����ֵ����arr����
	while (begin <= end)
	{
		arr[begin] = tmp[begin];//��д��arr[begin++] = tmp[begin++]; ��Ȼ++���Σ�����������
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