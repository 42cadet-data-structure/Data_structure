#include "arrayqueue.h"

Queue *createQueue(int maxElementCount)
{
	Queue	*cqueue;

	cqueue = (Queue *)malloc(sizeof(Queue));
	if (!cqueue)
		return (NULL);
	memset(cqueue, 0, sizeof(Queue));
	cqueue->pElement = (QueueNode *)malloc(sizeof(QueueNode) * maxElementCount);
	if (!cqueue->pElement)
	{
		free(cqueue);
		return (NULL);
	}
	cqueue->maxElementCount = maxElementCount;
	return (cqueue);
}

int enqueue(Queue *pQueue, QueueNode element)
{
	if (isQueueFull(pQueue))
		return (FALSE);
	if (!isQueueFull(pQueue) && pQueue->rear == pQueue->maxElementCount - 1)
		pQueue->rear = 0;
	if (!isQueueEmpty(pQueue))
		pQueue->rear++;
	pQueue->pElement[pQueue->rear] = element;
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
	QueueNode	*retnode;

	retnode = &pQueue->pElement[pQueue->front];
	if (isQueueEmpty(pQueue))
		return (NULL);
	pQueue->front++;
	pQueue->currentElementCount--;
	if (isQueueEmpty(pQueue) && pQueue->front == pQueue->maxElementCount)
		pQueue->front = 0;
	return (retnode);
}

QueueNode *peek(Queue *pQueue)
{
	if (isQueueEmpty(pQueue))
		return (NULL);
	return (&pQueue->pElement[pQueue->front]);
}

void deleteQueue(Queue *pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

int isQueueFull(Queue *pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentElementCount == 0);
}
