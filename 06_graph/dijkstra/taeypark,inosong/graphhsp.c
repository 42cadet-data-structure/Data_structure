#include "graphhsp.h"
#include "linkedqueue.h"

static void	make_dijkstra(LinkedGraph *pGraph, int *dist, int startID)
{
	Queue		*q;
	QueueNode	to_enqueue, *curID;
	ListNode	*linked_node;

	for (int i = 0; i < pGraph->maxVertexCount; i++)
		dist[i] = INT_MAX;
	dist[startID] = 0;
	q = createQueue();
	to_enqueue.data = startID;
	enqueue(q, to_enqueue);
	while (!isQueueEmpty(q))
	{
		curID = dequeue(q);
		linked_node = pGraph->ppEdge[curID->data]->headerNode.pLink;
		while (linked_node)
		{
			to_enqueue.data = linked_node->data.vertexID;
			if (dist[to_enqueue.data] >= dist[curID->data] + linked_node->data.weight)
			{
				dist[to_enqueue.data] = dist[curID->data] + linked_node->data.weight;
				enqueue(q, to_enqueue);
			}
			linked_node = linked_node->pLink;
		}
		free(curID);
	}
	deleteQueue(q);
}

/* Dijkstra Algorithm에 의해 최단 경로를 찾는 함수,
입력 인자로 받은 startVertexID부터 다른 모든 노드 사이들의 최단 거리를 구한 다음에 반환한다. */
int *shortestPathDijkstra(LinkedGraph *pGraph, int startVertexID)
{
	int	*dist;

	dist = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	if (dist == NULL)
		return (NULL);
	make_dijkstra(pGraph, dist, startVertexID);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		printf("%d-%d : %d\n", startVertexID, i, dist[i]);
	return (dist);
}
