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
LinkedGraph *mstPrim(LinkedGraph *pGraph, int vertexID)
{
	LinkedGraph	*mst;
	GraphEdge	min_edge;

	if (pGraph == NULL || vertexID < 0)
		return (NULL);
	mst = createLinkedGraph(pGraph->maxVertexCount);
	if (mst == NULL)
		return (NULL);

	addVertex(mst, vertexID);
	while (mst->currentVertexCount < pGraph->maxVertexCount)
	{
		min_edge.vertexIDFrom = 0;
		min_edge.vertexIDTo = 0;
		min_edge.weight = INT_MAX;
		for (int v = 0; v < pGraph->maxVertexCount; v++)
		{
			if (mst->pVertex[v] == TRUE)
				getMinWeightEdge(pGraph, mst, v, &min_edge);
		}
		printf("%d, min weight: (%d, %d) -> %d\n", mst->currentVertexCount, min_edge.vertexIDFrom, min_edge.vertexIDTo, min_edge.weight);
		addVertex(mst, min_edge.vertexIDTo);
		addEdgeWithWeight(mst, min_edge.vertexIDFrom, min_edge.vertexIDTo, min_edge.weight);
	}
	return (mst);
}

/* mstVertexID와  부 속 된   간 선  중  가 중 치 가   가 장 작 으 면 서  순 환  을  발 생  시 키 지   않 는 간 선   을 선 택 */
void getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph *pMST, int fromVertexID, GraphEdge *pMinWeightEdge)
{
	LinkedList		*edge_list = pGraph->ppEdge[fromVertexID];
	LinkedListNode	*edge_node = NULL;

	edge_node = edge_list->headerNode.pLink;
	while (edge_node != NULL)
	{
		if (edge_node->data.weight < pMinWeightEdge->weight)
		{
			if (checkEdge(pMST, fromVertexID, edge_node->data.vertexID) == NOT_FOUND && \
				checkCycle(pMST, fromVertexID, edge_node->data.vertexID) == FALSE)
			{
				pMinWeightEdge->vertexIDFrom = fromVertexID;
				pMinWeightEdge->vertexIDTo = edge_node->data.vertexID;
				pMinWeightEdge->weight = edge_node->data.weight;
			}
		}
		edge_node = edge_node->pLink;
	}
}

/* 기 존 의 신 장  트 리 에   특 정 간 선 이 존 재 하 는 지를  점 검 하는   함 수 로   getMinWeightEdge()에 서  호 출 한  다. */
int checkEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
	LinkedList	*edge_list = NULL;	
	int			position = 0;

	if (pGraph != NULL)
	{
		edge_list = pGraph->ppEdge[fromVertexID];
		position = findGraphNodePosition(edge_list, toVertexID);
		if (position != NOT_FOUND)
			return (TRUE);
	}
	return (NOT_FOUND);
}

int pushLSForDFS(Stack* pStack, int nodeID)
{
    StackNode node = {0,};
    node.data = nodeID;
    return push(pStack, node);
}

int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID) {
    int pReturn = FALSE;

    int i = 0;
    int vertextID = 0;
    Stack* pStack = NULL;
    StackNode* pStackNode = NULL;
    LinkedListNode *pListNode = NULL;
    int *pVisited = NULL;

    if (pGraph == NULL)
        return pReturn;
    pStack = createStack();
    if (pStack == NULL) 
        return pReturn;
    pVisited = (int*) malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL) 
    {
        printf("Error, malloc() in traversalDFS()\n");
        deleteStack(pStack);
        return pReturn;
    }
    for(i = 0; i < pGraph->maxVertexCount; i++)
        pVisited[i] = FALSE;
    pVisited[fromVertexID] = TRUE;

    pushLSForDFS(pStack, fromVertexID);

    while(isStackEmpty(pStack) == FALSE) 
    {
        pStackNode = pop(pStack);
        if (pStackNode != NULL) 
        {
            vertextID = pStackNode->data;
            if (vertextID == toVertexID) {
                printf("(%d, %d)-순환되는 구조\n",
                       fromVertexID, toVertexID);
                pReturn = TRUE;
                break;
            }
            pListNode = pGraph->ppEdge[vertextID]->headerNode.pLink;
            while(pListNode != NULL) 
            {
                int vertexID = pListNode->data.vertexID;
                if (pVisited[vertexID] == FALSE)
                {
                    pVisited[vertexID] = TRUE;
                    pushLSForDFS(pStack, vertexID);
                }
                pListNode = pListNode->pLink;
            }
        }
    }
    free(pVisited);
    deleteStack(pStack);
    return pReturn;
}
