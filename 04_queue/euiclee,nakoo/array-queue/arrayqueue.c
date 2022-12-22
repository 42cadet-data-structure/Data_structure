#include "arrayqueue.h"

Queue *createQueue(int maxElementCount)
{
	Queue		*queue;

	queue = (Queue *)malloc(sizeof(Queue));
	if (!queue)
		return (NULL);
	memset(queue, 0, sizeof(Queue));
	queue->pElement = (QueueNode *)malloc(sizeof(QueueNode) * maxElementCount);
	if (!queue->pElement)
	{
		free(queue);
		return (NULL);
	}
	queue->maxElementCount = maxElementCount;
	return (queue);
}

int enqueue(Queue *pQueue, QueueNode node)
{
	if (isQueueFull(pQueue) == 1)
		return (FALSE);
	pQueue->pElement[pQueue->rear] = node;
	pQueue->rear++;
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
	pQueue->front++;
	pQueue->currentElementCount--;
	return (&pQueue->pElement[pQueue->front - 1]);
}

QueueNode *peek(Queue *pQueue)
{
	return (&pQueue->pElement[pQueue->front]);
}

void deleteQueue(Queue *pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

int isQueueFull(Queue *pQueue)
{
	return (pQueue->rear == pQueue->maxElementCount - 1);
}

int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentElementCount == 0);
}
