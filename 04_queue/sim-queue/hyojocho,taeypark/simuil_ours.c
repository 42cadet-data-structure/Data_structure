/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simuil_ours.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:51:08 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/27 12:09:35 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simutil.h"
#include "simlinkedqueue.h"
#include "simdef.h"
#include <stdlib.h>
#include <stdio.h>

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	QueueNode	to_enqueue;

	to_enqueue.data.arrivalTime = arrivalTime;
	to_enqueue.data.serviceTime = processTime;
	to_enqueue.pLink = NULL;
	enqueueLQ(pQueue, to_enqueue);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	QueueNode	*queue_node;
	
	while (!isLinkedQueueEmpty(pArrivalQueue))
	{
		queue_node = peekLQ(pArrivalQueue);
		if (queue_node->data.arrivalTime == currentTime)
		{
			dequeueLQ(pArrivalQueue);
			queue_node->data.status = arrival;
			enqueueLQ(pWaitQueue, *queue_node);
			printSimCustomer(currentTime, queue_node->data);
			free(queue_node);
		}
		else
			break ;
	}
}

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	peekLQ(pWaitQueue)->data.startTime = currentTime;
	peekLQ(pWaitQueue)->data.status = start;
	printSimCustomer(currentTime, peekLQ(pWaitQueue)->data);
	return (dequeueLQ(pWaitQueue));
}

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime)
{
	if (currentTime == pServiceNode->data.startTime + pServiceNode->data.serviceTime)
	{
		pServiceNode->data.status = end;
		pServiceNode->data.endTime = currentTime;
		printSimCustomer(currentTime, pServiceNode->data);
		(*pTotalWaitTime) += (pServiceNode->data.endTime - pServiceNode->data.startTime);
		(*pServiceUserCount)++;
		return (NULL);
	}
	return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("[%d],", currentTime);
	if (customer.status == arrival)
		printf("도착\n");
	else if (customer.status == start)
		printf("시작 arrivalTime : %d, waitTime : %d\n", customer.arrivalTime, customer.startTime - customer.arrivalTime);
	else
		printf("종료 arrivalTime : %d, startTime : %d, waitTime : %d, totalTime : %d\n", \
			customer.arrivalTime, customer.startTime, customer.startTime - customer.arrivalTime, customer.endTime - customer.startTime);
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	printf("[%d], WaitQueueStatus: %d\n", currentTime, pWaitQueue->currentElementCount);
}

void printReport(LinkedQueue *pWaitQueue,
                 int serviceUserCount,
                 int totalWaitTime)
{
	printf("REPORT\n");
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("Avg WaitTime : %lf\n", (double)totalWaitTime / pWaitQueue->currentElementCount);
	printf("WaitQueueStatus : %d\n", pWaitQueue->currentElementCount);
}