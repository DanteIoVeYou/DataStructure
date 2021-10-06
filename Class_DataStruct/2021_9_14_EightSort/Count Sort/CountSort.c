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

//�ǱȽ����򣺼�������
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
	//ͳ��arr��������������ӳ���µĸ���
	for (i = 0; i < n; i++)
	{
		tmp[arr[i] - min]++;
	}
	//���򣬰�tmpͳ�Ƶ��ĸ������Ӵ�С���ص�arr��ȥ
	int j = 0;
	for (i = 0; i < size; i++)
	{
		while (tmp[i]--)
		{
			arr[j++] = min + i;
		}
	}
}