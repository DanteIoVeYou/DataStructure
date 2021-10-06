#define _CRT_SECURE_NO_WARNINGS 1
#include "MergeSort.h"
int main()
{
	//int arr[] = { 4};

	//int arr[] = { 4,3,2,1 };
	//int arr[] = { 5,4,3,2,1 };
	int arr[] = { 12,23,54,6,45,34,344,34,87,7,90 };
	ArrayPrint(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	ArrayPrint(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}