#define _CRT_SECURE_NO_WARNINGS 1
#include"squelist.h"

void Test()
{
	SeqList sl;
	SeqList* p = &sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPrint(&sl);
	SeqListPushBack(&sl, 2);
	SeqListPrint(&sl);
	SeqListPushFront(&sl,3);
	SeqListPrint(&sl);
	SeqListPushFront(&sl, 3);
	SeqListPrint(&sl);
	SeqListPushFront(&sl, 3);
	SeqListPrint(&sl);
	SeqListInsert(&sl, 4, 9);
	SeqListPrint(&sl);
	SeqListErase(&sl, 4);
	SeqListPrint(&sl);

	SeqListSortUp(&sl);
	SeqListPrint(&sl);

	SeqListSortDown(&sl);
	SeqListPrint(&sl);

	if (SeqListFind(&sl, 3) == 1)
		printf("3 yes\n");
	else
		printf("3 no\n");

	if (SeqListFind(&sl, 9) == 1)
		printf("9 yes\n");
	else
		printf("9 no\n");

	SeqListDestroy(&sl);
}


int main()
{
	Test();
	return 0;
}