#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount)
{
    LinkedGraph  *graph;

    graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
    if (graph == NULL)
        return (NULL);
    graph->pVertex = (int *)calloc(sizeof(int), maxVertexCount);
    graph->ppEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
    if (graph->pVertex == NULL || graph->ppEdge == NULL)
        return (free(graph->pVertex), free(graph->ppEdge), free(graph), NULL);
    graph->currentEdgeCount = 0;
    graph->currentVertexCount = 0;
    graph->maxVertexCount = maxVertexCount;
    graph->graphType = GRAPH_UNDIRECTED;
    return (graph);
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph  *graph;

    graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
    if (graph == NULL)
        return (NULL);
    graph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    graph->ppEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
    if (graph->pVertex == NULL || graph->ppEdge == NULL)
        return (free(graph->pVertex), free(graph->ppEdge), free(graph), NULL);
    graph->currentEdgeCount = 0;
    graph->currentVertexCount = 0;
    graph->maxVertexCount = maxVertexCount;
    graph->graphType = GRAPH_DIRECTED;
    return (graph);
}

void deleteLinkedGraph(LinkedGraph *pGraph)
{
    int i;

    for (i = 0; i < pGraph->maxVertexCount; i++)
        if (pGraph->pVertex[i] == USED)
            deleteLinkedList(pGraph->ppEdge[i]), pGraph->ppEdge[i] = NULL;
    free(pGraph->pVertex);
    free(pGraph->ppEdge);
    pGraph->pVertex = NULL;
    pGraph->ppEdge = NULL;
    free(pGraph);
}

int isEmpty(LinkedGraph *pGraph)
{
    return (pGraph->currentEdgeCount <= 0);
}

int addVertex(LinkedGraph *pGraph, int vertexID)
{
    if (!(0 <= vertexID && vertexID < pGraph->maxVertexCount)
        || pGraph->pVertex[vertexID] == USED)
        return (FALSE);
    pGraph->ppEdge[vertexID] = createLinkedList();
    pGraph->ppEdge[vertexID]->headerNode.data.vertexID = vertexID;
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return (TRUE);
}

int addEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    int         add_pos;
    ListNode    to_add = {0, };

    if (checkVertexValid(pGraph, fromVertexID) == FALSE
        || checkVertexValid(pGraph, toVertexID) == FALSE)
        return (FALSE);
    to_add.data.weight = 1;
    to_add.data.vertexID = toVertexID;
    add_pos = findGraphNodePosition(pGraph->ppEdge[fromVertexID], toVertexID);
    if (add_pos != -1)
    {
        addLLElement(pGraph->ppEdge[fromVertexID], add_pos, to_add);
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            add_pos = findGraphNodePosition(pGraph->ppEdge[toVertexID], fromVertexID);
            to_add.data.vertexID = fromVertexID;
            to_add.data.weight = 1;
            addLLElement(pGraph->ppEdge[toVertexID], add_pos, to_add);
        }
        pGraph->currentEdgeCount++;
    }
    return (TRUE);
}

int addEdgeWithWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    int         add_pos;
    ListNode    to_add = {0, };

    if (checkVertexValid(pGraph, fromVertexID) == FALSE
        || checkVertexValid(pGraph, toVertexID) == FALSE)
        return (FALSE);
    to_add.data.weight = weight;
    to_add.data.vertexID = toVertexID;
    add_pos = findGraphNodePosition(pGraph->ppEdge[fromVertexID], toVertexID);
    if (add_pos != -1)
    {
        addLLElement(pGraph->ppEdge[fromVertexID], add_pos, to_add);
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            add_pos = findGraphNodePosition(pGraph->ppEdge[toVertexID], fromVertexID);
            to_add.data.vertexID = fromVertexID;
            to_add.data.weight = weight;
            addLLElement(pGraph->ppEdge[toVertexID], add_pos, to_add);
        }
        pGraph->currentEdgeCount++;
    }
    return (TRUE);
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{ 
    return ((0 <= vertexID && vertexID < pGraph->maxVertexCount)
            && pGraph->pVertex[vertexID] == USED);
}

int removeVertex(LinkedGraph *pGraph, int vertexID)
{
    if (checkVertexValid(pGraph, vertexID) == FALSE)
        return (FALSE);
    deleteLinkedList(pGraph->ppEdge[vertexID]);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
        if (pGraph->pVertex[i] == USED)
            deleteGraphNode(pGraph->ppEdge[i], vertexID);
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return (TRUE);
}

int removeEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (checkVertexValid(pGraph, fromVertexID) == FALSE
        || checkVertexValid(pGraph, toVertexID) == FALSE)
        return (FALSE);
    deleteGraphNode(pGraph->ppEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        deleteGraphNode(pGraph->ppEdge[toVertexID], fromVertexID);
    pGraph->currentEdgeCount--;
    return (TRUE);
}

void deleteGraphNode(LinkedList *pList, int delVertexID)
{
    int         del_idx;
    ListNode    *move;

    del_idx = 0;
    move = pList->headerNode.pLink;
    while (move && move->data.vertexID != delVertexID)
    {
        move = move->pLink;
        del_idx++;
    }
    if (move == NULL)
        return ;
    removeLLElement(pList, del_idx);
}

//만약에 vertexID가 있다면, -1 반환
int findGraphNodePosition(LinkedList *pList, int vertexID)
{
    ListNode    *move;
    int         idx = 0;

    move = pList->headerNode.pLink;
    while (move && move->data.vertexID < vertexID)
    {
        move = move->pLink;
        idx++;
    }
    if (move && move->data.vertexID == vertexID)
        return (-1);
    return (idx);
}

int getEdgeCount(LinkedGraph *pGraph)
{
    return (pGraph->currentEdgeCount);
}

int getVertexCount(LinkedGraph *pGraph)
{ 
    return (pGraph->currentVertexCount);
}

int getMaxVertexCount(LinkedGraph *pGraph)
{
    return (pGraph->maxVertexCount);
}

int getGraphType(LinkedGraph *pGraph)
{
    return (pGraph->graphType);
}

void displayLinkedGraph(LinkedGraph *pGraph)
{
    int y, x, i = 0;
    ListNode    *move;
    ListNode    *next_move;

    for (y = 0; y < pGraph->maxVertexCount; y++)
    {
        if (pGraph->pVertex[y] == NOT_USED && printf("\n"))
            continue ;
        i = 0;
        move = pGraph->ppEdge[y]->headerNode.pLink;
        while (i < pGraph->maxVertexCount)
        {
            if (move && move->data.vertexID == i)
            {
                printf("%d ",move->data.weight);
                move = move->pLink;
            }
            else
            {
                if (pGraph->pVertex[i] == NOT_USED)
                    printf("  ");
                else
                    printf("0 ");
            }
            i++;
        }
        printf("\n");
    }
}
