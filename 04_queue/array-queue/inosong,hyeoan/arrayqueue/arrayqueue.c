
#include "arrayqueue.h"

Queue *createQueue(int maxElementCount)
{
	Queue	*queue;

	queue = (Queue *)malloc(sizeof(Queue));
	if (queue == NULL)
		return (NULL);
	memset(queue, 0, sizeof(Queue));
	queue->pElement = (QueueNode *)malloc(sizeof(QueueNode) * maxElementCount);
	if (queue->pElement == NULL)
	{
		free (queue);
		return (NULL);
	}	
	memset(queue->pElement, 0, sizeof(QueueNode) * maxElementCount);
	queue->maxElementCount = maxElementCount;
	queue->front = 0;
	queue->rear = 0;
	return (queue);
}

int isQueueFull(Queue *pQueue)
{
	return (pQueue->currentElementCount >= pQueue->maxElementCount);
}

int enqueue(Queue *pQueue, QueueNode node)
{
	if (isQueueFull(pQueue) == FALSE)
	{
		pQueue->pElement[pQueue->currentElementCount] = node;
		pQueue->currentElementCount++;
		pQueue->rear = pQueue->currentElementCount - 1;
	}
	return (FALSE);
}
 
int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentElementCount == 0);
}

QueueNode *dequeue(Queue *pQueue)
{

	int			i;
	QueueNode	*ret;
	QueueNode	first;

	i = 0;
	first = pQueue->pElement[0];
	ret = &first;
	if (isQueueEmpty(pQueue) == FALSE)
	{
		while(i < pQueue->rear)
		{
			pQueue->pElement[i] = pQueue->pElement[i + 1];
			i++;
		}
			pQueue->currentElementCount--;
			pQueue->rear--;
	}
	return(ret);
}

QueueNode *peek(Queue *pQueue)
{
	return (pQueue->pElement);
}

void deleteQueue(Queue *pQueue)
{
	free(pQueue->pElement);
	pQueue->pElement = NULL;
	free(pQueue);
}
