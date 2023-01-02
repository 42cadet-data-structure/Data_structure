//
// Created by sanguk on 11/08/2017.
//

#import <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"


void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
    QueueNode   node;

    memset(&node, 0, sizeof(QueueNode));
    memset(&node.data, 0, sizeof(SimCustomer));

    node.data.arrivalTime = arrivalTime;
    node.data.serviceTime = processTime;
    enqueueLQ(pQueue, node);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
    QueueNode   *delnode;
    while (isLinkedQueueEmpty(pArrivalQueue) == FALSE)
    {
        if (currentTime == pArrivalQueue->pFrontNode->data.arrivalTime)
        {
            delnode = dequeueLQ(pArrivalQueue);
            enqueueLQ(pWaitQueue, *delnode);
            printSimCustomer(currentTime, delnode->data);
            free(delnode);
        }
        else
            break ;
    }
}

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    if (isLinkedQueueEmpty(pWaitQueue) == FALSE)
    {
        pWaitQueue->pFrontNode->data.status = start;
        pWaitQueue->pFrontNode->data.startTime = currentTime;
        printSimCustomer(currentTime, pWaitQueue->pFrontNode->data);
        return (dequeueLQ(pWaitQueue));
    }
    return (NULL);
}

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime)
{
    int end_service;
    int wait_time;

    end_service = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
    wait_time = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
    if (currentTime == end_service)
    {
        pServiceNode->data.status = end;
        pServiceNode->data.endTime = currentTime;
        (*pServiceUserCount)++;
        (*pTotalWaitTime) += wait_time;
        printSimCustomer(currentTime, pServiceNode->data);
        free (pServiceNode);
        return (NULL);
    }
    return (pServiceNode);
}

void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("[%d],", currentTime);

    if (customer.status == arrival)
    {
        printf("도착\n");
    }
    else if(customer.status == start)
    {
        printf("시작 ");
        printf("arrivalTime : %d, waitTime : %d\n", customer.arrivalTime, (customer.startTime - customer.arrivalTime));

    }
    else if (customer.status == end)
    {
        printf("종료 ");
        printf("arrivalTime : %d, startTime : %d, waitTime : %d, totalTime : %d\n",
        customer.arrivalTime, customer.startTime,
        customer.startTime - customer.arrivalTime,
        customer.endTime - customer.startTime);
    }
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    printf("[%d],WaitQueueStatus: %d\n",currentTime, pWaitQueue->currentElementCount);   
}

void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
    printf("REPORT\n");
    printf("serviceUserCount : %d\n", serviceUserCount);
    if (serviceUserCount > 0)
    {
        printf("Avg WaitTime : %f\n", ((float)totalWaitTime / (float)serviceUserCount));
    }
    printf("WaitQueueStatus : %d\n", pWaitQueue->currentElementCount);
}
