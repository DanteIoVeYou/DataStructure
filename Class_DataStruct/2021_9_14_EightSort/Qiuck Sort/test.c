#define _CRT_SECURE_NO_WARNINGS 1
#include "QuickSort.h"
int main()
{
	int arr[] = { 12,34,2,43,2,321,4,5,222,4565,46,223,3434,1223,5553,32,4,4454,99 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	//Partion_Hoare(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}

