#include "graphhsp.h"
#include "priority_queue.h"

static void dijkstra(int *costTable, int **graph, int start, int max)
{
    PriorityQueue *pq;
	pq = createQueuPriorityQueue();

    QueueNode node;
    node.cost = 0; node.toVertex = start;
    enqueue(pq, node);
    costTable[start] = 0;

    int dist, now, cost;
    while (!isQueueEmpty(pq))
    {
        dist = -pq->pFrontNode->cost;
        now = pq->pFrontNode->toVertex;
        dequeue(pq);

        if (costTable[now] < dist)
            continue;
        for(int i = 0;i < max;i++)
        {
            if (graph[now][i] == 0)
                continue;
            cost = dist + graph[now][i];
            if (cost < costTable[i])
            {
                costTable[i] = cost;
                node.cost = -cost;node.toVertex = i;
                enqueue(pq, node);
            }
        }
    }
}

void    shortestPathDijkstra(ArrayGraph *pGraph, int startVertexID)
{
    int *costTable;
    costTable = malloc(sizeof(int) * pGraph->maxVertexCount);
    for(int i=0;i<pGraph->maxVertexCount;i++)costTable[i] = INF;
    //memset(costTable, INF, sizeof(int) * pGraph->maxVertexCount);
    /*int **graph;
    graph = malloc(sizeof(int *) * pGraph->maxVertexCount);
    memcpy(graph, pGraph->ppAdjEdge, sizeof(int) * pGraph->maxVertexCount * pGraph->maxVertexCount);
    */dijkstra(costTable, pGraph->ppAdjEdge, startVertexID, pGraph->maxVertexCount);
    for (int i = 0;i<pGraph->maxVertexCount;i++)
    {
        if (costTable[i] != INF)
            printf("%-4d ", costTable[i]);
        else 
            printf("INF  ");
    }
    printf("\n");
}
