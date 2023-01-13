//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

// kruskal algorithm
// --> vertex간의 edge의 가중치(비용)를 비교하여, 모든 vertex를 연결하는 가장 짧은 경로를 찾는 문제
// 1. edge간의 가중치(비용) 비교: Heap을 사용하여 오름차순으로 정렬
// 2. edge에서 가장 비용이 낮은 값을 찾음: Heap에서 delete를 하면 가장 낮은 값이 나옴
// 3. 그 값이 cycle을 형성하는 지 확인
// stack data structure & DFS algorithm을 이용해서 vertex의 방문 여부를 확인하면서 check
// 만약 방문한 vertex를 또 방문하게 된다면 cycle으로 판단.
// 4. cycle이 아닌 최소 비용 edge를 result에 추가
// 이 때, edge의 개수는 vertex - 1이 되어야 함

Graph *mstKruskal(Graph *pGraph) {
    Graph *result = NULL;
    int i = 0, maxNodeCount = 0, currentNodeCount = 0, edgeCount = 0, isCycle = 0;
    ArrayMinHeap *min_heap = NULL;
    HeapNode *head_node = NULL;
    if (pGraph == NULL)
		return NULL;
    maxNodeCount = pGraph->maxVertexCount;
    currentNodeCount = pGraph->currentVertexCount;
    edgeCount = pGraph->currentEdgeCount;
    result = createGraph(maxNodeCount);
    if (result == NULL)
		return NULL;
    min_heap = orderEdges(pGraph);
    if (min_heap == NULL)
		return NULL;
    for (i = 0; i < edgeCount; i++) {
        head_node = deleteMinHeapAH(min_heap);
        if (head_node != NULL) {
            isCycle = checkCycle(result, head_node->fromVertexID, head_node->toVertexID);
            if (isCycle == FALSE) {
                if (result->pVertex[head_node->fromVertexID] != USED) {
                    addVertex(result, head_node->fromVertexID);
                }
                if (result->pVertex[head_node->toVertexID] != USED) {
                    addVertex(result, head_node->toVertexID);
                }
                addEdgeWithWeight(result, head_node->fromVertexID, head_node->toVertexID, head_node->key);
                printf("[%d], : (%d,%d)->%d\n",
                       i, head_node->fromVertexID, head_node->toVertexID, head_node->key);
            }
            free(head_node);
            if (result->currentVertexCount == currentNodeCount)
                break;
        }
    }
    return result;
}

ArrayMinHeap *orderEdges(Graph *pGraph) {
    int i = 0;
    int edgeCount = 0;
    ArrayMinHeap *result = NULL;
    ListNode *list_node = NULL;
    List *edge_list = NULL;
    if (pGraph == NULL)
		return NULL;
    edgeCount = pGraph->currentEdgeCount;
    result = createArrayMinHeap(edgeCount);
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        if (checkVertexValid(pGraph, i) == TRUE) {
            edge_list = pGraph->ppEdge[i];
            list_node = edge_list->headerNode.pLink;
            while (list_node != NULL) {
                int vertexID = list_node->data.vertexID;
                int weight = list_node->data.weight;
                if (pGraph->graphType == GRAPH_DIRECTED || (pGraph->graphType == GRAPH_UNDIRECTED && i < vertexID)) {
                    HeapNode heapNode = {0,};
                    heapNode.fromVertexID = i;
                    heapNode.toVertexID = vertexID;
                    heapNode.key = weight;
                    insertMinHeapAH(result, heapNode);
                }
                list_node = list_node->pLink;
            }
        }
    }
    return result;
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

    while(isStackEmpty(pStack) == FALSE)
	{
        pStackNode = pop(pStack);
        vertextID = pStackNode->data;
        if (vertextID == toVertexID)
		{
            printf("(%d,%d)-������ ���ΰ� �����մϴ�.\n", fromVertexID, toVertexID);
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
    free(pVisited);
    deleteStack(pStack);

    return pReturn;
}