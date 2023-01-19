#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraygraph.h"

static void free_all(ArrayGraph *graph, int fail_idx)
{
    for (int i = 0; i < fail_idx; i++)
        free(graph->ppAdjEdge[i]), graph->ppAdjEdge[i] = NULL;
    free(graph->ppAdjEdge);
    free(graph->pVertex);
    graph->ppAdjEdge = NULL;
    graph->pVertex = NULL;
    free(graph);
}

ArrayGraph *createArrayGraph(int maxVertexCount)
{
    ArrayGraph  *graph;

    graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
    if (graph == NULL)
        return (NULL);
    graph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    graph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
    if (graph->pVertex == NULL || graph->ppAdjEdge == NULL)
        return (free(graph->pVertex), free(graph->ppAdjEdge), free(graph), NULL);
    for (int i = 0; i < maxVertexCount; i++)
    {
        graph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
        if (graph->ppAdjEdge[i] == NULL)
            return (free_all(graph, i), NULL);
    }
    graph->currentVertexCount = 0;
    graph->maxVertexCount = maxVertexCount;
    graph->graphType = GRAPH_UNDIRECTED;
    return (graph);
}

ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph  *graph;

    graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
    if (graph == NULL)
        return (NULL);
    graph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    graph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
    if (graph->pVertex == NULL || graph->ppAdjEdge == NULL)
        return (free(graph->pVertex), free(graph->ppAdjEdge), free(graph), NULL);
    for (int i = 0; i < maxVertexCount; i++)
    {
        graph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
        if (graph->ppAdjEdge[i] == NULL)
            return (free_all(graph, i), NULL);
    }
    graph->currentVertexCount = 0;
    graph->maxVertexCount = maxVertexCount;
    graph->graphType = GRAPH_DIRECTED;
    return (graph);
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
    free_all(pGraph, pGraph->maxVertexCount);
}

int isEmptyAG(ArrayGraph *pGraph)
{
    return (pGraph->currentVertexCount <= 0);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (!(0 <= vertexID && vertexID < pGraph->maxVertexCount)
        || pGraph->pVertex[vertexID] == USED)
        return (FALSE);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return (TRUE);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (checkVertexValid(pGraph, fromVertexID) == FALSE
        || checkVertexValid(pGraph, toVertexID) == FALSE)
        return (FALSE);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
    return (TRUE);
}

int addEdgeWithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (checkVertexValid(pGraph, fromVertexID) == FALSE
        || checkVertexValid(pGraph, toVertexID) == FALSE)
        return (FALSE);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (TRUE);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
    return ((0 <= vertexID && vertexID < pGraph->maxVertexCount)
            && pGraph->pVertex[vertexID] == USED);
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (checkVertexValid(pGraph, vertexID) == FALSE)
        return (FALSE);
    for(int i = 0; i < pGraph->maxVertexCount; i++)
        pGraph->ppAdjEdge[vertexID][i] = pGraph->ppAdjEdge[i][vertexID] = 0;
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return (TRUE);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (checkVertexValid(pGraph, fromVertexID) == FALSE
        || checkVertexValid(pGraph, toVertexID) == FALSE
        || pGraph->ppAdjEdge[fromVertexID][toVertexID] == NOT_USED)
        return (FALSE);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    return (TRUE);
}

void displayArrayGraph(ArrayGraph *pGraph)
{
    int y, x;

    for (y = 0; y < pGraph->maxVertexCount; y++)
    {
        if (pGraph->pVertex[y] == NOT_USED && printf("\n"))
            continue ;
        for (x = 0; x < pGraph->maxVertexCount; x++)
        {
            if (pGraph->pVertex[x] == NOT_USED)
                printf("  ");
            else
               printf("%d ", pGraph->ppAdjEdge[y][x]);
        }
        printf("\n");
    }
}
