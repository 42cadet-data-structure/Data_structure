#ifndef GRAPH_MST_GRAPHMST_H
#define GRAPH_MST_GRAPHMST_H

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

/* Prim 알고리즘 구현에 필요한 구조체 */
typedef struct GraphEdgeType
{
	int vertexIDFrom; /* Tail Node ID */
	int vertexIDTo;   /* Head Node ID */
	int weight;       /* 가중치 */
} GraphEdge;

/* Prim Algorithm */
LinkedGraph *mstPrim(LinkedGraph *pGraph, int vertexID);

/* mstVertexID와 부속된 간선 중 가중치가 가장 작으면서 순환을 발생시키지 않는 간선을 선택 */
void getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph *pMST, int mstVertexID, GraphEdge *pMinWeightEdge);

/* 기존의 신장 트리에 특정 간선이 존재하는지를 점검하는 함수로 getMinWeightEdge()에서 호출한다. */
int checkEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

/* 순환 검사 */
int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID);

#endif //GRAPH_MST_GRAPHMST_H
