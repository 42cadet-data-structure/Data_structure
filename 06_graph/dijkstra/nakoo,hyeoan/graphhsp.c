#include "graphhsp.h"

/* Dijkstra Algorithm에 의해 최단 경로를 찾는 함수,
입력 인자로 받은 startVertexID부터 다른 모든 노드 사이들의 최단 거리를 구한 다음에 반환한다. */
int *shortestPathDijkstra(LinkedGraph *pGraph, int startVertexID)
{
	int	*pReturn = NULL;
	int	*pSelected = NULL;
	int	nodeCount = 0, maxNodeCount = 0;
	int	i = 0, j = 0, weight = 0;
	int	vertexID = 0, y_w = 0, y_v = 0;
	ListNode	*pListNode = NULL;
	LinkedList	*pEdgeList = NULL;

	if (pGraph == NULL)
		return (NULL);

	maxNodeCount = getMaxVertexCountLG(pGraph);
	nodeCount = getVertexCountLG(pGraph);
	pReturn = (int *)malloc(sizeof(int) * maxNodeCount);
	pSelected = (int *)malloc(sizeof(int) * maxNodeCount);

	if (pReturn == NULL || pSelected == NULL)
	{
		if (pReturn != NULL)
			return (free(pReturn), NULL);
	}
	for (i = 0; i < maxNodeCount; i++)
	{
		if (i == startVertexID)
			pReturn[i] = 0;
		else
		{
			if (pGraph->pVertex[i] == USED)
			{
				pSelected[i] = TRUE;
				pReturn[i] = getEdgeWeight(pGraph, startVertexID, i);
			}
			else
			{
				pSelected[i] = FALSE;
				pReturn[i] = INT_MAX;
			}
		}
	}
	for (i = 0; i < maxNodeCount; i++)
		printf(" (%d, %d) -> %d\n", startVertexID, i, pReturn[i]);
	for (i = 0; i < nodeCount - 1; i++)
	{
		printf("[%d] - Iteration\n", i+1);
		// Step-1
		vertexID = getMinDistance(pReturn, pSelected, maxNodeCount);
		pSelected[vertexID] = FALSE;
		pEdgeList = pGraph->ppEdge[vertexID];
		pListNode = pEdgeList->headerNode.pLink;
		while (pListNode != NULL)
		{
			int	toVertexID = pListNode->data.vertexID;
			int weight = pListNode->data.weight;

			// y_v + c_v,w 와  y_w 비 교 
			y_v = pReturn[vertexID];
			y_w = pReturn[toVertexID];
			if (y_v + weight < y_w)
				pReturn[toVertexID] = y_v + weight;
			pListNode = pListNode->pLink;
		}
		for (j = 0; j < maxNodeCount; j++)
			printf("\t(%d, %d) -> %d\n", startVertexID, j, pReturn[j]);
	}
	free(pSelected);
	return (pReturn);
}

/* 특정 노드가 집합 S에 포함되었는지 저장하는 배열 변수 == isSelected,
현재 노드 집합 S 중에서 최단 거리를 가지는 노드 ID인 vertexID를 구한 다음 집합 S에서 지워준다. */
int getMinDistance(int *distance, int *pSelected, int maxNodeCount)
{
	int	pReturn = 0;
	int	min_distance = INT_MAX;
	int	i = 0;

	for (i = 0; i < maxNodeCount; i++)
	{
		if (pSelected[i] == TRUE && distance[i] < min_distance)
		{
			min_distance = distance[i];
			pReturn = i;
		}
	}
	return (pReturn);
}

/* 간선의 가중치를 반환하는 함수 */
int getEdgeWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	int	pReturn = INT_MAX;
	int	position = 0;
	LinkedList	*pEdgeList = NULL;
	ListNode	*pListNode = NULL;

	if (pGraph != NULL)
	{
		pEdgeList = pGraph->ppEdge[fromVertexID];
		if (pEdgeList != NULL)
		{
			position = findGraphNodePosition(pEdgeList, toVertexID);
			if (position >= 0)
			{
				pListNode = getElement(pEdgeList, position);
				if (pListNode != NULL)
					pReturn = pListNode->data.weight;
			}
		}
	}
	return (pReturn);
}
