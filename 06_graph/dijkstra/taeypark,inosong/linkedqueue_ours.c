/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedqueue_ours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:39:05 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/22 13:13:42 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedqueue.h"

Queue *createQueue()
{
	Queue	*queue;

	queue = (Queue *)malloc(sizeof(Queue));
	if (!queue)
		return (NULL);
	queue->currentQueueCount = 0;
	queue->pRearNode = queue->pFrontNode = NULL;
	return (queue);
}

int enqueue(Queue *pQueue, QueueNode element)
{
	QueueNode	*queue_node;

	queue_node = (QueueNode *)malloc(sizeof(QueueNode));
	if (!queue_node)
		return (FALSE);
	*queue_node = element;
	if (isQueueEmpty(pQueue))
		pQueue->pFrontNode = queue_node;
	else
		pQueue->pRearNode->pLink = queue_node;
	pQueue->pRearNode = queue_node;
	pQueue->currentQueueCount++;
	return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
	QueueNode	*for_dequeue;

	if (isQueueEmpty(pQueue))
		return (FALSE);
	for_dequeue = pQueue->pFrontNode;
	pQueue->pFrontNode = pQueue->pFrontNode->pLink;
	for_dequeue->pLink = NULL;
	pQueue->currentQueueCount--;
	return (for_dequeue);
}

QueueNode *peek(Queue *pQueue)
{
	return (pQueue->pFrontNode);
}

void deleteQueue(Queue *pQueue)
{
	QueueNode	*to_free;

	while (pQueue->pFrontNode != NULL)
	{
		to_free = pQueue->pFrontNode;
		pQueue->pFrontNode = pQueue->pFrontNode->pLink;
		free(to_free);
	}
	pQueue->currentQueueCount = 0;
	pQueue->pFrontNode = pQueue->pRearNode = NULL;
	free(pQueue);
}

int isQueueEmpty(Queue *pQueue)
{
	return (pQueue->currentQueueCount <= 0);
}