#define _CRT_SECURE_NO_WARNINGS 1
#include "SLList.h"


Test1()
{
	SLList* phead = NULL;
	SLListPushBack(&phead,1);
	SLListPrint(phead);

	SLListPushBack(&phead, 2);
	SLListPrint(phead);

	SLListPushBack(&phead, 3);
	SLListPrint(phead);

	SLListPushFront(&phead, 0);
	SLListPrint(phead);

	SLListPopBack(&phead);
	SLListPrint(phead);

	if (SLListFind(phead,1))
	{
		SLListInsertAfter(SLListFind(phead,1), 22);
		SLListPrint(phead);
	}

	if (SLListFind(phead, 1))
	{
		SLListEraseAfter(SLListFind(phead, 1));
		SLListPrint(phead);
	}
	SLListDestroy(&phead);

	SLListPrint(phead);
}

int main()
{
	Test1();
	return 0;
}