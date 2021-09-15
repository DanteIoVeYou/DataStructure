#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void HeapDown(int* arr, int sz, int i){
	int parent = i;
	int child = 2 * parent + 1;
	while (child < sz)
	{
		if (child + 1 < sz && arr[child] > arr[child + 1]) {
			++child;
		}
		if (arr[parent] > arr[child]) {
			Swap(&arr[parent], &arr[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* arr, int sz){
	int i = (sz - 1) / 2;
	for (; i >= 0; --i){
		HeapDown(arr, sz, i);
	}

	for (i = sz - 1; i > 0; --i)
	{
		Swap(&arr[0], &arr[i]);
		HeapDown(arr, i, 0);
	}
}
int main(){
	int arr[] = { 23,13,23,45,67,23,223,435,89 };
	int sz = sizeof(arr)/sizeof(arr[0]);
	HeapSort(arr, sz);
	int a = 0;
	for (a = 0; a < sz; a++)
	{
		printf("%d ", arr[a]);
	}

	return 0;
}