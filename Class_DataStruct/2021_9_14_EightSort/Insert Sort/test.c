#define _CRT_SECURE_NO_WARNINGS 1
#include "insertsort.h"
int main()
{
	int arr[] = { 12,23,54,6,45,34,344,34,87,7 };
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	ArrayPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}