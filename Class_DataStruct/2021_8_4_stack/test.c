#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"


Test1()
{
	Stack st;
	Stack* pstack = &st;
	StackInit(pstack);


	StackPush(pstack, 1);

	StackPush(pstack, 2);

	StackPush(pstack, 3);

	StackPush(pstack, 4);

	StackPop(pstack);
	StackPop(pstack);

	StackPop(pstack);

	StackPop(pstack);



	printf("%d\n", StackEmpty(pstack));
	printf("%d\n", StackSize(pstack));

	StackDestroy(pstack);
	
}
int main()
{
	Test1();
	return 0;
}