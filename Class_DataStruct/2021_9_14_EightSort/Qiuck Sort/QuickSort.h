#pragma once
#include <stdio.h>
void PrintArray(int* arr, int n);

int Partion_Hoare(int* arr, int left, int right);

void QuickSort(int* arr, int left, int right);
//int tmp = a[left];
//int hole = left;
//while (left < right)
//{
//    while (left < right && a[right] >= tmp)
//    {
//        right--;
//    }
//    Swap(&a[right], &a[hole]);
//    hole = right;
//
//    while (left < right && a[left]  <= tmp)
//    {
//        left++;
//    }
//    Swap(&a[left], &a[hole]);
//    hole = left;
//}
//a[hole] = a[left];
//
//while(cur<=right)
//{
//    if (a[cur] < key && ++prev!=cur)
//        Swap(&a([prev], &a[cur]);
//    cur++;
//}
//Swap(&a[prev], &a[keyi]);