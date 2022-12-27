#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"
#include <string.h>
#include <stdio.h>

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	/* 도착 큐에 도착 시간과 서비스 시간 데이터를 가진 고객들을 차곡차곡 넣는다. */
	QueueNode	newnode;

	memset(&newnode, 0, sizeof(QueueNode));
	newnode.data.arrivalTime = arrivalTime;
	newnode.data.serviceTime = processTime;
	enqueueLQ(pQueue, newnode);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	/* 현재 시각과 도착 시각과 비교하여 도착 큐에서 dequeue하여 대기 큐에 enqueue 한다. */
	QueueNode	*tmpnode;

	while (isLinkedQueueEmpty(pArrivalQueue) == FALSE && currentTime == peekLQ(pArrivalQueue)->data.arrivalTime)
	{
		tmpnode = dequeueLQ(pArrivalQueue);
		enqueueLQ(pWaitQueue, *tmpnode);
		printSimCustomer(currentTime, pArrivalQueue->pRearNode->data);
	}
}

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	/* 새로운 고객 서비스를 시작하는 함수로 현재 서비스 중인 고객 노드가 없다면,
	고객 대기 큐에서 dequeue하여 서비스 노드에 대입한다*/
	printf("[%d] - 시작 arrivalTime : %d, waitTime : %d\n",
	currentTime, pWaitQueue->pFrontNode->data.arrivalTime, currentTime - pWaitQueue->pFrontNode->data.arrivalTime);
	return (dequeueLQ(pWaitQueue));
}

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime)
{
	/* 서비스 중인 고객 노드가 존재한다면, 해당 고객의 서비스 종료 시점과 비교하여 종료 시점이면 NULL을 반환한다.*/ 
	if (currentTime == pServiceNode->data.endTime + (*pTotalWaitTime))
	{
		(*pServiceUserCount)++;
		(*pTotalWaitTime) += pServiceNode->data.serviceTime;
		printf("[%d] - 종료 arrivalTime : %d, startTime : %d, waitTime : %d, totalTime : %d\n",
		currentTime, pServiceNode->data.arrivalTime, pServiceNode->data.startTime, pServiceNode->data.startTime - pServiceNode->data.arrivalTime, pServiceNode->data.serviceTime);
		return (NULL);
	}
	pServiceNode->data.endTime = pServiceNode->data.arrivalTime + pServiceNode->data.serviceTime;
	return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	char	*str[3] = {"도착", "시작", "종료"};

	printf("[%d] - %s\n", currentTime, str[customer.status]);
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	printf("[%d] - WaitQueueStatus : %d\n", currentTime, pWaitQueue->currentElementCount);
}

void printReport(LinkedQueue *pWaitQueue,
                 int serviceUserCount,
                 int totalWaitTime)
{
	printf("REPORT\n");
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("Avg WaitTime : %d\n", totalWaitTime / serviceUserCount);
	printf("WaitQueueStatus : %d\n", pWaitQueue->currentElementCount);
}