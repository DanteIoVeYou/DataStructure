#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
void Test1()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);

	printf("%d\n", QueueSize(&q));

	printf("%d\n", QueueTop(&q));

	QueuePop(&q);
	printf("%d\n", QueueTop(&q));

	QueuePop(&q);
	printf("%d\n", QueueTop(&q));

	QueuePop(&q);
	printf("%d\n", QueueTop(&q));

	QueuePop(&q);

	printf("%d\n", QueueSize(&q));

	QueueDestroy(&q);
}

int main()
{
	Test1();
	return 0;
}