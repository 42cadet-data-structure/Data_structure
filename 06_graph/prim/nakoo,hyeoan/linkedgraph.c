#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount) 
{
    int i = 0, j = 0;
    LinkedGraph *pReturn = NULL;
    pReturn = (LinkedGraph *) malloc(sizeof(LinkedGraph));
    if (pReturn == NULL) 
        return NULL ;
    memset(pReturn, 0, sizeof(LinkedGraph));
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->graphType = GRAPH_UNDIRECTED;
    pReturn->pVertex = (int *) malloc(sizeof(int) * maxVertexCount);
    if (pReturn->pVertex == NULL)
    {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    pReturn->ppEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
    if (pReturn->ppEdge == NULL) 
    {
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }
    for (i = 0; i < maxVertexCount; i++) 
    {
        pReturn->ppEdge[i] = createLinkedList();
        if (pReturn->ppEdge[i] == NULL) 
        {
            for (j = 0; j < i; j++) 
                free(pReturn->ppEdge[j]);
            free(pReturn->ppEdge);
            free(pReturn->pVertex);
            free(pReturn);
            return NULL;
        }
    }
    return pReturn;
}

LinkedGraph *createDirectedLinkedGraph(int maxVertexCount) 
{
    LinkedGraph *pReturn = createLinkedGraph(maxVertexCount);
    if (pReturn != NULL) 
        pReturn->graphType = GRAPH_DIRECTED;
    return pReturn;
}

int addVertex(LinkedGraph *pGraph, int vertexID) 
{
    if (pGraph == NULL) 
        return FAIL;
    if (checkVertexValid(pGraph, vertexID) == TRUE) 
        return FAIL;
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return SUCCESS;
}

int removeVertex(LinkedGraph *pGraph, int vertexID){
    if (pGraph == NULL) 
        return FAIL;
    if (checkVertexValid(pGraph, vertexID) == FALSE) 
        return FAIL;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        removeEdge(pGraph, vertexID, i);
        removeEdge(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return SUCCESS;
}

int addEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID) 
{
    return addEdgeWithWeight(pGraph, fromVertexID, toVertexID, USED);
}

int addElementForVertex(LinkedList *pList, GraphNode vertex)
{
    LinkedListNode node = {0,};
    node.data = vertex;
    return addElement(pList, 0, node);
}

int addEdgeWithWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight) 
{
    GraphNode toVertex = {0,};
    if (pGraph == NULL) 
        return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FALSE) 
        return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FALSE) 
        return FAIL;
    toVertex.vertexID = toVertexID;
    toVertex.weight = weight;
    addElementForVertex(pGraph->ppEdge[fromVertexID], toVertex);
    pGraph->currentEdgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED) 
    {
        GraphNode fromVertex = {0,};
        fromVertex.vertexID = fromVertexID;
        fromVertex.weight = weight;
        addElementForVertex(pGraph->ppEdge[toVertexID], fromVertex);
        pGraph->currentEdgeCount++;
    }
    return SUCCESS;
}

int removeEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL) 
        return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FALSE) 
        return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FALSE)
        return FAIL;
    deleteGraphNode(pGraph->ppEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        deleteGraphNode(pGraph->ppEdge[toVertexID], fromVertexID);
    return SUCCESS;
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID) 
{
    if (pGraph == NULL) 
        return FALSE;
    if (pGraph->pVertex[vertexID] == USED) 
        return TRUE;
    return FALSE;
}

int deleteGraphNode(LinkedList *pList, int delVertexID)
{
    int position = 0;
    if (pList == NULL) 
        return FAIL;
    position = findGraphNodePosition(pList, delVertexID);
    if (position < 0) 
        return FAIL;
    removeElement(pList, position);
    return SUCCESS;
}

int findGraphNodePosition(LinkedList *pList, int vertexID)
{
    int ret = -1, position = 0;
    LinkedListNode *pNode = NULL;
    if (pList == NULL) 
        return ret;
    pNode = pList->headerNode.pLink;
    while(pNode != NULL)
    {
        if (pNode->data.vertexID == vertexID)
            return position;
        pNode = pNode->pLink;
        position++;
    }
    return ret;
}

void deleteLinkedGraph(LinkedGraph *pGraph){
    if (pGraph == NULL) 
        return ;
    for (int i = 0; i < pGraph->currentVertexCount; i++)
        deleteLinkedList(pGraph->ppEdge[i]);
    free(pGraph->ppEdge);
    free(pGraph->pVertex);
    free(pGraph);
    return;
}

void displayLinkedGraph(LinkedGraph *pGraph)
{
    int i = 0, j = 0, position = 0;
    if (pGraph == NULL) 
        return ;
    LinkedListNode* pNode = NULL;
    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        for (j = 0; j < pGraph->maxVertexCount; j++)
        {
            position = findGraphNodePosition(pGraph->ppEdge[i], j);
            if (position >= 0)
            {
                pNode = getElement(pGraph->ppEdge[i], position);
                printf("%d ", pNode->data.weight);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}