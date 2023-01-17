#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

/* Prim Algorithm */
Graph *mstPrim(Graph *pGraph, int vertexID)
{
	// Graph	*ret;
	// GraphEdge	minWeightEdge;
	// int			mstNodeCount = 0;

	// if (!pGraph)
	// 	return (NULL);
	// if (!(ret = createGraph(pGraph->maxVertexCount)))
	// 	return (NULL);
	// addVertex(ret, vertexID);
	// while (ret->currentEdgeCount < pGraph->currentVertexCount)
	// {
	// 	minWeightEdge.vertexIDFrom = 0;
	// 	minWeightEdge.vertexIDTo = 0;
	// 	minWeightEdge.weight = INT_MAX;
	// 	for (int i = 0; i < pGraph->maxVertexCount; i++)
	// 	{
	// 		if (ret->pVertex[i] == TRUE)
	// 			getMinWeightEdge(pGraph, ret, i, &minWeightEdge);
	// 	}
	// 	printf("[%d] %d->%d (%d)\n", mstNodeCount, minWeightEdge.vertexIDFrom, minWeightEdge.vertexIDTo, minWeightEdge.weight);
	// 	addVertex(ret, minWeightEdge.vertexIDTo);
	// 	addEdgeWithWeight(ret, minWeightEdge.vertexIDFrom, minWeightEdge.vertexIDTo, minWeightEdge.weight);
	// 	mstNodeCount++;
	// }
	// return (ret);
	Graph	*ret = createGraph(pGraph->maxVertexCount);
	int		selected[pGraph->maxVertexCount];
	ListNode	*node;
	int			i = 0;
	int			min;
	int			id;
	int			INF = 1e9;
	for (int j = 0; j < pGraph->maxVertexCount; j++)
		selected[j] = TRUE;
	while (i < pGraph->maxVertexCount)
	{
		min = INF;
		id = node->data.vertexID;
		for (node = pGraph->ppEdge[i]->headerNode.pLink; node; node = node->pLink)
		{
			if (selected[i] && min > node->data.weight)
			{
				min = node->data.weight;
				id = node->data.vertexID;
			}
		}
		if (selected[i] && min != INF)
		{
			addVertex(ret, id);
			addVertex(ret, i);
			addEdgeWithWeight(ret, i, id, min);
			selected[i] = FALSE;
		}
		i++;
	}
	return (ret);
}

/* mstVertexID와 부속된 간선 중 가중치가 가장 작으면서 순환을 발생시키지 않는 간선을 선택 */
void getMinWeightEdge(Graph *pGraph, Graph *pMST, int mstVertexID, GraphEdge *pMinWeightEdge)
{
	ListNode	*node;
	int			isCycle;
	int			isAlready;

	for (node = pGraph->ppEdge[mstVertexID]->headerNode.pLink; node; node = node->pLink)
	{
		if (node->data.weight < pMinWeightEdge->weight)
		{
			isAlready = checkEdge(pMST, mstVertexID, node->data.vertexID);
			if (isAlready == -1)
				isCycle = checkCycle(pMST, mstVertexID, node->data.vertexID);
			if (isAlready == -1 && isCycle != TRUE)
			{
				pMinWeightEdge->vertexIDFrom = mstVertexID;
				pMinWeightEdge->vertexIDTo = node->data.vertexID;
				pMinWeightEdge->weight = node->data.weight;
			}
		}
	}
}

/* 기존의 신장 트리에 특정 간선이 존재하는지를 점검하는 함수로 getMinWeightEdge()에서 호출한다. */
int checkEdge(Graph *pGraph, int fromVertexID, int toVertexID)
{
	return (findGraphNodePosition(pGraph->ppEdge[fromVertexID], toVertexID));
}

int checkCycle(Graph *pGraph, int fromVertexID, int toVertexID)
{
	Stack *stack;
	StackNode *stackNode;
	StackNode newStackNode;
	ListNode *listNode;

	stack = createStack();
	if (!stack)
		return (FALSE);
	int	visited[pGraph->maxVertexCount];
	for(int i=0;i<pGraph->maxVertexCount;i++)
		visited[i] = NOT_USED;

	newStackNode.data = fromVertexID;
	newStackNode.pLink = NULL;
	push(stack, newStackNode);
	visited[fromVertexID] = USED;
	while (!isStackEmpty(stack))
	{
		stackNode = pop(stack);
		if (stackNode && stackNode->data == toVertexID)
			return (TRUE);
		for (listNode = pGraph->ppEdge[stackNode->data]->headerNode.pLink; listNode; listNode = listNode->pLink)
		{
			if (!visited[listNode->data.vertexID])
			{
				visited[listNode->data.vertexID] = USED;
				newStackNode.data = listNode->data.vertexID;
				push(stack, newStackNode);
			}
		}
		free(stackNode);
	}
	deleteStack(stack);
	return (FALSE);
}
