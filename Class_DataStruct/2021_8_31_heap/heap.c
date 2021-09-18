#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"


//Swap function
void Swap(HeapDataType* x, HeapDataType* y){
	HeapDataType tmp = *x;
	*x = *y;
	*y = tmp;
}
// Down Adjustment

//So we have adjusted the left and right trees as max-trees or min-trees before DownAdjust
//So it is a process of iteration from the bottom to the top
//Now we hypothesize we have a complete binary tree that is asjusted well
// max-heap
void AdjustDown(HeapDataType* a, int sz, int k){
	int parent = k;
	int child = 2 * parent + 1;
	while (child < sz) {
		if (a[child] < a[child + 1] && child + 1 < sz) {	//allow a[child] the bigger one between left and right child
			child++;
		}
		if (a[parent] < a[child]) {		//Swap
			Swap(&a[parent], &a[child]);
		}
		else {
			break;
		}
		parent = child;
		child = 2 * parent + 1;
	}
}

//iteration from the last parent element to the first

void HeapSort(HeapDataType* a, int sz) {
	int i = (sz - 1 - 1) / 2; //the last subscript of non-leaf node
	while (i){
		AdjustDown(a, sz, i);
		i--;
	}

	//we have a max-hwap now, so we can make a ascneding order
	//every time the root node's value is the max, so we Sawp the first and ;ast node and let sz--
	
	while (sz > 1) {
		AdjustDown(a, sz, 0);
		Swap(&a[0], &a[sz - 1]);
		sz--;
	}
}

void PrintArray(HeapDataType* a, int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}