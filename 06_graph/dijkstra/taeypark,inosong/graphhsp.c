#include "graphhsp.h"
#include "linkedqueue.h"

static void	make_dijkstra(LinkedGraph *pGraph, int *dist, int startID)
{
	Queue		*q;
	QueueNode	to_enqueue, *curID;
	ListNode	*move;
	int			*visited;

	visited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		dist[i] = INT_MAX, visited[i] = 0;
	dist[startID] = 0;
	visited[startID] = 1;
	q = createQueue();
	to_enqueue.data = startID;
	enqueue(q, to_enqueue);
	while (!isQueueEmpty(q))
	{
		curID = dequeue(q);
		visited[curID->data] = 1;
		move = pGraph->ppEdge[curID->data]->headerNode.pLink;
		while (move)
		{
			to_enqueue.data = move->data.vertexID;
			if (visited[to_enqueue.data] == 1)
				continue ;
			enqueue(to_enqueue);
			if (dist[to_enqueue.data] >= dist[curID->data] + move->data.weight)
				dist[to_enqueue.data] = dist[curID->data] + move->data.weight;
			move = move->pLink;
		}
		// free(curID);
	}
	// deleteQueue(q);
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

/* 간선의 가중치를 반환하는 함수 */
int getEdgeWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	ListNode	*move;

	move = pGraph->ppEdge[fromVertexID]->headerNode.pLink;
	while (move)
	{
		if (move->data.vertexID == toVertexID)
			break ;
		move = move->pLink;
	}
	if (move == NULL)
		return (-1);
	return (move->data.weight);
}
