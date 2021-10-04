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

//����һ��Hoare��
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

//���������ڿӷ�
int Partion_Hole(int* arr, int left, int right)
{
	//1.�����ڿ�
	int hole = left;//һ��ʼ����ߵ����ǿ�λ
	int key = arr[left];//ѡ���Ĺؼ���������ߵ���
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

	//�����ڿ�
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

//��������ǰ��ָ�뷨
int Partion_Prev_After_pointer(int* arr, int left, int right)
{
	//prevһ��ʼָ��left-1��curһ��ʼָ��left��
	//keyΪ����ߵ���
	//curָ���ֵ��>key��cur++
	//curָ���ֵ��<=key��prev++������prev��cur��ֵ
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

//�ݹ�
//���ǰ��������arr�����������
void QuickSort(int* arr, int left, int right)
{
	//����left��right��������ֻ��1��Ԫ��
	if (right - left < 1)
		return;
	//������2��������Ԫ�أ���������һ�ε�����ʹkey��ߵ�ֵȫС��key���ұߵ�ֵȫ����key
	//����ѡ�������һ��������key
	//int mid = Partion_Hoare(arr, left, right);

	int mid = Partion_Hole(arr, left, right);
	//int mid = Partion_Prev_After_pointer(arr, left, right);

	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);


}

//�ǵݹ�
//����׼����ջ+ѭ���ķ�ʽʵ�ַǵݹ�Ŀ�������
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
