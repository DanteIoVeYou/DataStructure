#define _CRT_SECURE_NO_WARNINGS 1
#include "DLList.h"

void Test1()
{
	DLList* plist = DLListInit();

	printf("empty = %d\n", DLListEmpty(plist));

	DLListPushBack(plist, 1);
	DLListPrint(plist);
	printf("empty = %d\n", DLListEmpty(plist));

	DLListPushBack(plist, 2);
	DLListPrint(plist);

	DLListPushFront(plist, 3);
	DLListPrint(plist);

	DLListPushFront(plist, 4);
	DLListPrint(plist);

	DLListPopFront(plist);
	DLListPrint(plist);

	printf("count = %d\n", DLListSize(plist));

	if (DLListFind(plist, 3))
	{
		DLListInsert(DLListFind(plist, 3), 9);
	}
	if (DLListFind(plist, 2))
	{

		DLListInsert(DLListFind(plist, 2), 9);
	}
	DLListPrint(plist);
	DLListPopBack(plist);
	DLListPopBack(plist);

	DLListPopBack(plist);

	DLListPopBack(plist);
	DLListPrint(plist);

	DLListPopBack(plist);
	DLListPrint(plist);

	DLListPrint(plist);
	DLListPopBack(plist);

	DLListPopBack(plist);
	DLListPopBack(plist);

	DLListPopBack(plist);
	DLListPrint(plist);

	DLListPrint(plist);
	DLListDestroy(plist);
	return 0;
}
int main()
{
	Test1();
	
}