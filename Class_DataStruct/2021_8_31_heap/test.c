#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//������->Ч�ʸ���
int main()
{
	return 0;
}

void AdjustUp(int* a, int child)
{
	while (child >= 0)
	{
		if (a[child] > a[(child - 1) / 2])
		{
			Swap(&a[child], &a[(child - 1) / 2]);
			child = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}