#ifndef GRAPH_MST_LINKEDGRAPH_H
#define GRAPH_MST_LINKEDGRAPH_H

#include "graphlinkedlist.h"

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAIL 0

#define USED 1
#define NOT_USED 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

typedef struct GraphType {
    int maxVertexCount;
    int currentVertexCount;
    int currentEdgeCount;
    int graphType;
    int *pVertex;
    List **ppEdge;
} Graph, LinkedGraph;

LinkedGraph *createLinkedGraph(int maxVertexCount);

LinkedGraph *createDirectedLinkedGraph(int maxVertexCount);

int addVertex(LinkedGraph *pGraph, int vertexID);

int removeVertex(LinkedGraph *pGraph, int vertexID);

int addEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

int addEdgeWithWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int removeEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

int checkVertexValid(LinkedGraph *pGraph, int vertexID);

int deleteGraphNode(LinkedList *pList, int delVertexID);

int findGraphNodePosition(LinkedList *pList, int vertexID);

void deleteLinkedGraph(LinkedGraph *pGraph);

void displayLinkedGraph(LinkedGraph *pGraph);

#endif