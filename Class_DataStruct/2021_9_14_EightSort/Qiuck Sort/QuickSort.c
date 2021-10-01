#define _CRT_SECURE_NO_WARNINGS 1
#include "QuickSort.h"
void PrintArray(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
int Partion_Hoare(int* arr, int left, int right)
{
	int first = left;
	int key = arr[left];
	while (left < right)
	{
		while (arr[right] >= key && right > left)
		{
			right--;
		}
		while (arr[left] <= key && left < right)
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[first], &arr[left]);
	return left;
}
//我们按照升序对arr数组进行排序
void QuickSort(int* arr, int left, int right)
{
	//传错left，right或者数组只有1个元素
	if (right - left < 1)
		return;
	//数组有2个及以上元素，按规则做一次调整，使key左边的值全小于key，右边的值全大于key
	//我们选择数组第一个数当作key
	int mid = Partion_Hoare(arr, left, right);

	//int mid = Partion_Hole(arr, left, right);
	//int mid = Partion_Prev_After_pointer(arr, left, right);

	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);


}