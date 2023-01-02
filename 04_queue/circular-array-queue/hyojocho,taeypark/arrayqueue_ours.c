/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayqueue_ours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:11:48 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/22 12:28:57 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayqueue.h"
#include <stdio.h>

Queue *createQueue(int maxElementCount)
{
	Queue	*queue;

	queue = (Queue *)malloc(sizeof(Queue));
	if (queue == NULL)
		return (NULL);
	queue->pElement = (QueueNode *)malloc(sizeof(QueueNode) * maxElementCount);
	if (queue->pElement == NULL)
		return (free(queue), NULL);
	queue->currentElementCount = 0;
	queue->front = queue->rear = 0;
	queue->maxElementCount = maxElementCount;
	return (queue);
}

int enqueue(Queue *pQueue, QueueNode node)
{
	if (isQueueFull(pQueue))
		return (FALSE);
	pQueue->currentElementCount++;
	pQueue->pElement[pQueue->rear] = node;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	return (TRUE);
}

QueueNode *dequeue(Queue *pQueue)
{
	QueueNode	*ret;

	if (isQueueEmpty(pQueue))
		return (FALSE);
	pQueue->currentElementCount--;
	ret = &pQueue->pElement[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	return (ret);
}

QueueNode *peek(Queue *pQueue)
{
	if (isQueueEmpty(pQueue))
		return (FALSE);
	return (&pQueue->pElement[pQueue->front]);
}

void deleteQueue(Queue *pQueue)
{
	free(pQueue->pElement);
	pQueue->pElement = NULL;
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
