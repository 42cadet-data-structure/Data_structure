#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
	/* 도착 큐에 도착 시간과 서비스 시간 데이터를 가진 고객들을 차곡차곡 넣는다. */
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	/* 현재 시각과 도착 시각과 비교하여 도착 큐에서 dequeue하여 대기 큐에 enqueue 한다.

	printSimCustomer(currentTime, pArrivalQueue->data.status); */
}

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	/* 새로운 고객 서비스를 시작하는 함수로 현재 서비스 중인 고객 노드가 없다면,
	고객 대기 큐에서 dequeue하여 서비스 노드에 대입한다

	printf("[%d],%d arrivalTime : %d, waitTime : %d\n",
	currentTime, pWaitQueue->data.status, pWaitQueue->data.arrivalTime, pWaitQueue->data.waitTime); */
}

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime)
{
	/* 서비스 중인 고객 노드가 존재한다면, 해당 고객의 서비스 종료 시점과 비교하여 종료 시점이면 NULL을 반환한다.

	printf("[%d],%d arrivalTime : %d, startTime : %d, waitTime : %d, totalTime : %d\n",
	currentTime, pServiceNode->data.status, pServiceNode->data.startTime, pServiceNode->data.waitTime, pTotalWaitTime); */
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
	/* printf("[%d],%d\n", currentTime, customer.status); */
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	/* 대기 큐 상태를 출력한다.
	
	printf("[%d],WaitQueueStatus : %d", currentTime, pWaitQueue->currentElementCount); */
}

void printReport(LinkedQueue *pWaitQueue,
                 int serviceUserCount,
                 int totalWaitTime)
{
	/* printf("REPORT\n");
	printf("serviceUserCount : %d\n", serviceUserCount);
	printf("Avg WaitTime : %f\n", totalWaitTime / servieceUserCount);
	printf("WaitQueueStatus : %d\n", pWaitQueue->currentElementCount); */
}