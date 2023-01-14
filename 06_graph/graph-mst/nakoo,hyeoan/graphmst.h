#ifndef GRAPH_MST_GRAPHMST_H
#define GRAPH_MST_GRAPHMST_H

/* Prim 알고리즘 구현에 필요한 구조체 */
typedef struct GraphEdgeType
{
	int vertexIDFrom; /* Tail Node ID */
	int vertexIDTo;   /* Head Node ID */
	int weight;       /* 가중치 */
} GraphEdge;

/* Kruskal Algorithm */
Graph *mstKruskal(Graph* pGraph);
ArrayMinHeap *orderEdges(Graph* pGraph);
int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID);

/* Prim Algorithm */
Graph *mstPrim(Graph *pGraph, int vertexID);
void getMinWeightEdge(Graph *pGraph, Graph *pMST, \
					int mstVertexID, GraphEdge *pMinWeightEdge);
int checkEdge(Graph *pGraph, int fromVertexID, int toVertexID);

#endif