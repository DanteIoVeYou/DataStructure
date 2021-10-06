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
void MergeSortNoRe(int* arr, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc failed!\n");
		return;
	}
	int GroupNum = 1;
	while (GroupNum < n)
	{
		int i = 0;
		for (i = 0; i < n; i += 2 * GroupNum)
		{
			int begin1 = i;
			int end1 = begin1 + GroupNum - 1;
			int begin2 = begin1 + GroupNum;
			int end2 = begin2 + GroupNum - 1;
			int index = begin1;
			//begin不存在时，[begin2,end2]区间当然不存在，将[begin2,end2]修正成一个不存在的区间，避免进去下面的while循环，去非法读取内存
			if (begin2 > n - 1)
			{
				begin2 = n + 1;
				end2 = n;
			}
			//end2越界
			if (end2 > n - 1)
			{
				end2 = n - 1;
			}
			//end1越界
			if (end1 > n - 1)
			{
				end1 = n - 1;
			}
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
		}
		//把tmp数组的值拷回arr数组,注意：这边得等一排的全部数都排完一次之后才能拷贝！否则堆溢出？
		int k = 0;
		for (k = 0; k < n; k++)
		{
			arr[k] = tmp[k];
		}
		GroupNum *= 2;
	}
	free(tmp);
}











//
//void MergeSortNoRe(int* arr, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		printf("malloc failed!\n");
//		return;
//	}
//	int GroupNum = 1;
//	while (GroupNum < n)
//	{
//		int i = 0;
//		for (i = 0; i < n; i += 2 * GroupNum)
//		{
//			int begin1 = i;
//			int end1 = begin1 + GroupNum - 1;
//			int begin2 = begin1 + GroupNum;
//			int end2 = begin2 + GroupNum - 1;
//			int index = begin1;
//			/*int begin = begin1;
//			int end = end2;*/
//		
//
//
//			if (end1 > n - 1)
//			{
//				end1 = n - 1;
//			}
//			if (end2 > n - 1)
//			{
//				end2 = n - 1;
//			}
//			//begin不存在时，[begin2,end2]区间当然不存在，将[begin2,end2]修正成一个不存在的区间，避免进去下面的while循环，去非法读取内存
//			if (begin2 > n - 1)
//			{
//				begin2 = n;
//				end2 = n - 1;
//			}
//			
//
//		
//
//
//			//挑小的数插入
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (arr[begin1] < arr[begin2])
//					tmp[index++] = arr[begin1++];
//				else
//					tmp[index++] = arr[begin2++];
//			}
//			//把剩下来一段区间的数依次拷到tmp
//			while (begin1 <= end1)
//				tmp[index++] = arr[begin1++];
//			while (begin2 <= end2)
//				tmp[index++] = arr[begin2++];
//			//把tmp数组的值拷回arr数组
//			//while (begin <= end)
//			//{
//			//	arr[begin] = tmp[begin];//别写成arr[begin++] = tmp[begin++]; 不然++两次！！！哈哈哈
//			//	begin++;
//			//}
//			int i = 0;
//			for (i = 0; i < n; i++)
//			{
//				arr[i] = tmp[i];
//			}
//		}
//		GroupNum *= 2;
//	}
//	free(tmp);
//}


//// 1、[begin2,end2] 不存在, 修正为一个不存在的区间
//if (begin2 >= n)
//{
//	begin2 = n + 1;
//	end2 = n;
//}
//
//// 2、end1越界,修正一下
//if (end1 >= n)
//{
//	end1 = n - 1;
//}
//
//// 3、end2越界，需要修正后归并
//if (end2 >= n)
//{
//	end2 = n - 1;
//}