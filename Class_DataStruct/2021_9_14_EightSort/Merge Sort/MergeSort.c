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
			//begin������ʱ��[begin2,end2]���䵱Ȼ�����ڣ���[begin2,end2]������һ�������ڵ����䣬�����ȥ�����whileѭ����ȥ�Ƿ���ȡ�ڴ�
			if (begin2 > n - 1)
			{
				begin2 = n + 1;
				end2 = n;
			}
			//end2Խ��
			if (end2 > n - 1)
			{
				end2 = n - 1;
			}
			//end1Խ��
			if (end1 > n - 1)
			{
				end1 = n - 1;
			}
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
		}
		//��tmp�����ֵ����arr����,ע�⣺��ߵõ�һ�ŵ�ȫ����������һ��֮����ܿ���������������
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
//			//begin������ʱ��[begin2,end2]���䵱Ȼ�����ڣ���[begin2,end2]������һ�������ڵ����䣬�����ȥ�����whileѭ����ȥ�Ƿ���ȡ�ڴ�
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
//			//��С��������
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (arr[begin1] < arr[begin2])
//					tmp[index++] = arr[begin1++];
//				else
//					tmp[index++] = arr[begin2++];
//			}
//			//��ʣ����һ������������ο���tmp
//			while (begin1 <= end1)
//				tmp[index++] = arr[begin1++];
//			while (begin2 <= end2)
//				tmp[index++] = arr[begin2++];
//			//��tmp�����ֵ����arr����
//			//while (begin <= end)
//			//{
//			//	arr[begin] = tmp[begin];//��д��arr[begin++] = tmp[begin++]; ��Ȼ++���Σ�����������
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


//// 1��[begin2,end2] ������, ����Ϊһ�������ڵ�����
//if (begin2 >= n)
//{
//	begin2 = n + 1;
//	end2 = n;
//}
//
//// 2��end1Խ��,����һ��
//if (end1 >= n)
//{
//	end1 = n - 1;
//}
//
//// 3��end2Խ�磬��Ҫ������鲢
//if (end2 >= n)
//{
//	end2 = n - 1;
//}