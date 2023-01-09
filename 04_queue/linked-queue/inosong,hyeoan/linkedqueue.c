
#include "linkedqueue.h"

Queue *createQueue()
{
	Queue	*	queue;

	queue  = (Queue *)malloc(sizeof(Queue));
	memset(queue, 0, sizeof(Queue));
	if (queue == NULL)
		return (NULL);
	return (queue);	
}

int enqueue(Queue *pQueue, QueueNode element)
{
	QueueNode	*queue_node;

	queue_node	= (QueueNode *)malloc(sizeof(QueueNode));
	if (queue_node == NULL)
		return (FALSE);
	*queue_node = element;
	if (pQueue->currentQueueCount == 0)
	{
		pQueue->pFrontNode = queue_node;
		pQueue->pRearNode = queue_node;
		queue_node->pLink = NULL;
	}
	queue_node->pLink = pQueue->pRearNode->pLink;
	pQueue->pRearNode->pLink = queue_node;
	pQueue->pRearNode = queue_node;
	pQueue->currentQueueCount++;
	return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
	QueueNode *del_node;

	if (isQueueEmpty(pQueue) == FALSE)
	{
		del_node = pQueue->pFrontNode;
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		del_node->pLink = NULL;
		pQueue->currentQueueCount--;
		return (del_node);
	}
	return (NULL);
}

QueueNode *peek(Queue *pQueue)
{
	if (isQueueEmpty(pQueue) == FALSE)
	{
		return(pQueue->pFrontNode);
	}
	return (NULL);
}

void deleteQueue(Queue *pQueue)
{
	QueueNode	*del_node;
	
	for(int i = 0; i < pQueue->currentQueueCount; i++)
	{
		del_node = pQueue->pFrontNode;
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		free (del_node);
	}
	free (pQueue);
}

int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentQueueCount == 0);
}