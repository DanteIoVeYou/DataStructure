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
//���ǰ��������arr�����������
void QuickSort(int* arr, int left, int right)
{
	//����left��right��������ֻ��1��Ԫ��
	if (right - left < 1)
		return;
	//������2��������Ԫ�أ���������һ�ε�����ʹkey��ߵ�ֵȫС��key���ұߵ�ֵȫ����key
	//����ѡ�������һ��������key
	int mid = Partion_Hoare(arr, left, right);

	//int mid = Partion_Hole(arr, left, right);
	//int mid = Partion_Prev_After_pointer(arr, left, right);

	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);


}