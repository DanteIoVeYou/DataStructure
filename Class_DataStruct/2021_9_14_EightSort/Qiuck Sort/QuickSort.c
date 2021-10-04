#define _CRT_SECURE_NO_WARNINGS 1
#include "QuickSort.h"
#include "stack.h"

void PrintArray(int* arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//方法一：Hoare法
int Partion_Hoare(int* arr, int left, int right)
{
	int first = left;
	int key = arr[left];
	while (left < right)
	{
		while (arr[right] >= key && right > left)
		{
			right--;
		}
		while (arr[left] <= key && left < right)
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[first], &arr[left]);
	return left;
}

//方法二：挖坑法
int Partion_Hole(int* arr, int left, int right)
{
	//1.正常挖坑
	int hole = left;//一开始最左边的数是坑位
	int key = arr[left];//选出的关键字是最左边的数
	while (left<right)
	{
		while (arr[right] >= key && right > left)
		{
			right--;
		}
		arr[hole] = arr[right];
		hole = right;
		while (arr[left] <= key && left < right)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	return hole;

	//交换挖坑
	/*int tmp = arr[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && arr[right] >= tmp)
		{
			right--;
		}
		Swap(&arr[right], &arr[hole]);
		hole = right;

		while (left < right && arr[left]  <= tmp)
		{
			left++;
		}
		Swap(&arr[left], &arr[hole]);
		hole = left;
	}*/

}

//方法三：前后指针法
int Partion_Prev_After_pointer(int* arr, int left, int right)
{
	//prev一开始指向left-1，cur一开始指向left。
	//key为最左边的数
	//cur指向的值若>key，cur++
	//cur指向的值若<=key，prev++，交换prev和cur的值
	int prev = left;
	int cur = left + 1;
	int key = arr[left];
	while (cur <= right)
	{
		if (arr[cur] < key && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[left], &arr[prev]);
	return prev;
}

//递归
//我们按照升序对arr数组进行排序
void QuickSort(int* arr, int left, int right)
{
	//传错left，right或者数组只有1个元素
	if (right - left < 1)
		return;
	//数组有2个及以上元素，按规则做一次调整，使key左边的值全小于key，右边的值全大于key
	//我们选择数组第一个数当作key
	//int mid = Partion_Hoare(arr, left, right);

	int mid = Partion_Hole(arr, left, right);
	//int mid = Partion_Prev_After_pointer(arr, left, right);

	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);


}

//非递归
//我们准备用栈+循环的方式实现非递归的快速排序
void No_Recursion_QuickSort(int* arr, int left, int right)
{
	if (right - left < 1)
		return;
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, right);
	StackPush(&stack, left);
	while (!StackEmpty(&stack))
	{
		int tmpleft = StackTop(&stack);
		StackPop(&stack);
		int tmpright = StackTop(&stack);
		StackPop(&stack);
		if (tmpleft < tmpright)
		{
			int mid = Partion_Hole(arr, tmpleft, tmpright);
			StackPush(&stack, mid - 1);
			StackPush(&stack, tmpleft);
			StackPush(&stack, tmpright);
			StackPush(&stack, mid + 1);
		}
	}
	StackDestroy(&stack);
}
