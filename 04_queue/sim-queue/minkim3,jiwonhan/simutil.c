#include "simutil.h"

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	QueueNode	node;

	if (!pQueue || arrivalTime < 0 || processTime < 0)
		return ;
	node.data.arrivalTime = arrivalTime;
	node.data.serviceTime = processTime;
	node.data.startTime = 0;
	node.data.endTime = 0;
	enqueueLQ(pQueue, node);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	QueueNode	*wait;

	if (!pArrivalQueue || !pWaitQueue)
		return ;
	while (isLinkedQueueEmpty(pArrivalQueue) == FALSE)
	{
		if (peekLQ(pArrivalQueue)->data.arrivalTime == currentTime)
		{
			wait = dequeueLQ(pArrivalQueue);
			wait->data.status = arrival;
			enqueueLQ(pWaitQueue, *wait);
			printSimCustomer(currentTime, wait->data);
		}
		else
			break;
	}
}

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode	*node;

	if (!pWaitQueue || isLinkedQueueEmpty(pWaitQueue))
		return (NULL);
	node = dequeueLQ(pWaitQueue);
	node->data.status = start;
	node->data.startTime = currentTime;
	printSimCustomer(currentTime, node->data);
	return (node);
}

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	int	endTime = 0, waitTime = 0;

	if (!pServiceNode || !pServiceUserCount || !pTotalWaitTime)
		return (NULL);
	endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
	if (endTime <= currentTime)
	{
		waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
		(*pTotalWaitTime) += waitTime;
		pServiceNode->data.endTime = endTime;
		pServiceNode->data.status = end;
		(*pServiceUserCount)++;
		printSimCustomer(currentTime, pServiceNode->data);
		free(pServiceNode);
		pServiceNode = NULL;
	}
	return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("[%d],", currentTime);
	switch (customer.status)
	{
	case arrival :
		printf("arrival)\n");
		break;
	case start :
		printf("start) arrivalTime: %d, waitTime: %d\n", customer.arrivalTime, customer.startTime - customer.arrivalTime);
		break;
	case end :
		printf("end) arrivalTime: %d, start: %d, waitTime: %d, totalTime: %d\n", \
				customer.arrivalTime, customer.startTime, customer.startTime - customer.arrivalTime,
				customer.endTime - customer.startTime);
		break;
	}
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	printf("[%d],WaitQueueStatus: %d\n", currentTime, pWaitQueue->currentElementCount);
}

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
	printf("REPORT\nserviceUserCount: %d\n", serviceUserCount);
	if (serviceUserCount)
		printf("Avg WaitTime: %f\n", (float)totalWaitTime / (float)serviceUserCount);
	printf("WaitQueueStatus: %d\n", pWaitQueue->currentElementCount);
}
