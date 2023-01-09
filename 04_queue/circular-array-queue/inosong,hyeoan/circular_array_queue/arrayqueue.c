
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
	queue->front = -1;
	queue->rear = -1;
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
        pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
        pQueue->pElement[pQueue->rear] = node;
        pQueue->currentElementCount++;
    } 
    return (TRUE);
}
 
int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentElementCount == 0);
}

QueueNode *dequeue(Queue *pQueue)
{
    
	if (isQueueEmpty(pQueue) == FALSE)
    {
        pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
        pQueue->currentElementCount--;
    	return (&(pQueue->pElement[pQueue->front]));
    }
}

QueueNode *peek(Queue *pQueue)
{
	return (&pQueue->pElement[(pQueue->front + 1) % pQueue->maxElementCount]);
}

void deleteQueue(Queue *pQueue)
{
	free(pQueue->pElement);
	pQueue->pElement = NULL;
	free(pQueue);
}
