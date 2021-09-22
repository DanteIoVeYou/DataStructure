#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
//
//void test1()
//{
//	Heap hp;
//	int arr[] = { 12,43,56,4,43,78123,4,3455,45,38939,3,4,5,65 };
//	HeapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
//	HeapPrint(&hp);
//
//	HeapPush(&hp, 100);
//	HeapPush(&hp, 102);
//	HeapPush(&hp, 13);
//	HeapPush(&hp, 160);
//
//
//	HeapPrint(&hp);
//
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//	printf("%d\n", HeapTop(&hp));
//	printf("%d\n", HeapSize(&hp));
//	printf("%d\n", HeapEmpty(&hp));
//
//	PrintTopK(arr, sizeof(arr) / sizeof(arr[0]), 5);
//
//	HeapDestroy(&hp);
//}

TestTopK()
{
	int arr[] = { 435,3,4,523,5,235,1,2,3,4,5,3,424,324,5345,656,7,57,56,75,68678,45,34,53,5,535,5,6,54,67,454,34345,554,99,9987,5345,67,345,345,345,345,3,52,42,34,234234235,456,34,53,412,3,1,232,34,3233 };
	int sizearr = sizeof(arr) / sizeof(arr[0]);
	srand(time(0));
	int max = 30000000;
	HeapDataType* a1 = (HeapDataType*)malloc(sizeof(HeapDataType) * max);
	HeapDataType* a2 = (HeapDataType*)malloc(sizeof(HeapDataType) * max);

	int i = 0;
	for (i = 0; i < max; i++)
	{
		a1[i] = rand()%23453;
		a2[i] = a1[i];
	}

	//for (i = 0; i < max; i++)
	//{
	//	printf("%d ", a1[i]);
	//}
	//printf("\n");

	//for (i = 0; i < max; i++)
	//{
	//	printf("%d ", a2[i]);
	//}
	//printf("\n");
	int begin1 = clock();
	PrintTopK(a1, max, 20);
	//PrintTopK(arr, sizearr, 10);

	int end1 = clock();

	int begin2 = clock();
	PrintTopK2(a2, max, 20);
	//PrintTopK2(arr, sizearr, 10);

	int end2 = clock();

	printf("TopK = %d\n", end1 - begin1);
	printf("TopK2 = %d\n", end2 - begin2);

	

}
int main()
{
	TestTopK();
	return 0;
}