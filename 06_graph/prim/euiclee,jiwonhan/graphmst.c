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
}

/* mstVertexID와 부속된 간선 중 가중치가 가장 작으면서 순환을 발생시키지 않는 간선을 선택 */
void getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph *pMST, int mstVertexID, GraphEdge *pMinWeightEdge)
{
}

/* 기존의 신장 트리에 특정 간선이 존재하는지를 점검하는 함수로 getMinWeightEdge()에서 호출한다. */
int checkEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
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
