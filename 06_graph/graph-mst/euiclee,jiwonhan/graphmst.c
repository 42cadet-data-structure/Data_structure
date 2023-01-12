#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

Graph *mstKruskal(Graph* pGraph)
{
	Graph			*graph;
	ArrayMinHeap	*heap;

	if (!pGraph)
		return (NULL);
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		graph = createGraph(pGraph->maxVertexCount);
	else if (pGraph->graphType == GRAPH_DIRECTED)
		graph = createDirectedGraph(pGraph->maxVertexCount);
	if (graph)
		return (NULL);
	heap = orderEdges(pGraph);
}

ArrayMinHeap *orderEdges(Graph* pGraph)
{
	ArrayMinHeap	*heap;
	HeapNode		heapnode;
	ListNode		*ListNode;

	heap = createArrayMinHeap(pGraph->maxVertexCount);
	if (!heap)
		return (NULL);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppEdge[i] = USED)
		{
			for(ListNode = pGraph->ppEdge[i]->headerNode.pLink; ListNode; ListNode = ListNode->pLink)
			{
				heapnode.fromVertexID = pGraph->ppEdge[i];
				heapnode.key = ListNode->data.weight;
				heapnode.toVertexID = ListNode->data.vertexID;
				insertMinHeapAH(heap, heapnode);
			}
		}
	}
	return (heap);
}

int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID)
{
}
Graph *mstKruskal(Graph *pGraph) {
    Graph *pReturn = NULL;
    int i = 0, maxNodeCount = 0, currentNodeCount = 0, edgeCount = 0, isCycle = 0;
    ArrayMinHeap *pMinHeap = NULL;
    HeapNode *pHeapNode = NULL;

    maxNodeCount = pGraph->maxVertexCount;
    currentNodeCount = pGraph->currentVertexCount;
    edgeCount = pGraph->currentEdgeCount;
    pReturn = createGraph(maxNodeCount);
    if (pReturn == NULL) return NULL;
    pMinHeap = orderEdges(pGraph);
    if (pMinHeap == NULL) return NULL;
    for (i = 0; i < edgeCount; i++) {
        pHeapNode = deleteMinHeapAH(pMinHeap);
        if (pHeapNode != NULL) {
            isCycle = checkCycle(pReturn, pHeapNode->fromVertexID,
                                 pHeapNode->toVertexID);
            if (isCycle == FALSE) {
                if (pReturn->pVertex[pHeapNode->fromVertexID] != USED) {
                    addVertex(pReturn, pHeapNode->fromVertexID);
                }
                if (pReturn->pVertex[pHeapNode->toVertexID] != USED) {
                    addVertex(pReturn, pHeapNode->toVertexID);
                }
                addEdgeWithWeight(pReturn, pHeapNode->fromVertexID,
                                    pHeapNode->toVertexID, pHeapNode->key);
                printf("[%d], : (%d,%d)->%d\n",
                       i, pHeapNode->fromVertexID, pHeapNode->toVertexID,
                       pHeapNode->key);
            }
            free(pHeapNode);

            if (pReturn->currentVertexCount == currentNodeCount) {
                break;
            }
        }
    }
    return pReturn;
}

int pushLSForDFS(Stack* pStack, int nodeID)
{
    StackNode node = {0,};
    node.data = nodeID;
    return push(pStack, node);
}

int checkCycle(Graph *pGraph, int fromVertexID, int toVertexID) {
    int pReturn = FALSE;

    int i = 0;
    int vertextID = 0;
    Stack* pStack = NULL;
    StackNode* pStackNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited = NULL;

    if (pGraph == NULL) {
        return pReturn;
    }

    pStack = createStack();
    if (pStack == NULL) {
        return pReturn;
    }

    pVisited = (int*) malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL) {
        printf("Error, malloc() in traversalDFS()\n");
        deleteStack(pStack);
        return pReturn;
    }

    for(i = 0; i < pGraph->maxVertexCount; i++) {
        pVisited[i] = FALSE;
    }

    pVisited[fromVertexID] = TRUE;
    pushLSForDFS(pStack, fromVertexID);

    while(isStackEmpty(pStack) == FALSE) {
        pStackNode = pop(pStack);
        if (pStackNode != NULL) {
            vertextID = pStackNode->data;
            if (vertextID == toVertexID) {
                printf("(%d,%d)-������ ���ΰ� �����մϴ�.\n",
                       fromVertexID, toVertexID);
                pReturn = TRUE;
                break;
            }

            pListNode = pGraph->ppEdge[vertextID]->headerNode.pLink;
            while(pListNode != NULL) {
                int vertexID = pListNode->data.vertexID;
                if (pVisited[vertexID] == FALSE) {
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