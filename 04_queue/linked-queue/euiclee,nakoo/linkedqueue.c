#include "linkedqueue.h"

Queue *createQueue()
{
	Queue	*linkedqueue;

	linkedqueue = (Queue *)malloc(sizeof(Queue));
	if (!linkedqueue)
		return (NULL);
	memset(linkedqueue, 0, sizeof(Queue));
	return (linkedqueue);
}

int enqueue(Queue *pQueue, QueueNode element)
{
	QueueNode	*newnode;

	newnode = (QueueNode *)malloc(sizeof(QueueNode));
	if (!newnode)
		return (FALSE);
	*newnode = element;
	if (isQueueEmpty(pQueue))
		pQueue->pFrontNode = newnode;
	else
	{
		pQueue->pRearNode->pLink = newnode;
		newnode->pLink = NULL;
	}
	pQueue->pRearNode = newnode;
	pQueue->currentQueueCount++;
	return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
	QueueNode	*delnode;

	if (isQueueEmpty(pQueue))
		return (NULL);
	delnode = pQueue->pFrontNode;
	pQueue->pFrontNode = delnode->pLink;
	delnode->pLink = NULL;
	pQueue->currentQueueCount--;
	return (delnode);
}

QueueNode *peek(Queue *pQueue)
{
	return (pQueue->pFrontNode);
}

void deleteQueue(Queue *pQueue)
{
	while (pQueue->currentQueueCount)
		free(dequeue(pQueue));
	free(pQueue);
	pQueue->pFrontNode = NULL;
	pQueue->pRearNode = NULL;
}

int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentQueueCount == 0);
}