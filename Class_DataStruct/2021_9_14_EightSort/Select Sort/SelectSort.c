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
	////1.����ѡ��
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
	
	//2.˫��ͬʱѡ��
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
		if (mini == end)// ����end��mini�������������£����ڣ�end == mini����maxi������mini����maxi��λ�ã�������Ԥ���е�end��λ��
		{
			mini = maxi;
		}
		Swap(&arr[begin], &arr[mini]);
		begin++;
		end--;
	}
}