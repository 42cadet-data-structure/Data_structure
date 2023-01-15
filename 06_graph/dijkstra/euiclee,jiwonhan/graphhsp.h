#ifndef GRAPHHSP_H
#define GRAPHHSP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

// 1. 출발노드 설정
// 2. 출발노드를 기준으로 각 노드의 최소비용을 저장
// 3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택
// 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소비용을 갱신
// 5. 위의 3 ~ 4 과정을 반복
// euiclee, jiwonhan fighting !!


/* Dijkstra Algorithm에 의해 최단 경로를 찾는 함수,
입력 인자로 받은 startVertexID부터 다른 모든 노드 사이들의 최단 거리를 구한 다음에 반환한다. */
int *shortestPathDijkstra(LinkedGraph *pGraph, int startVertexID);

/* 특정 노드가 집합 S에 포함되었는지 저장하는 배열 변수 == isSelected,
현재 노드 집합 S 중에서 최단 거리를 가지는 노드 ID인 vertexID를 구한 다음 집합 S에서 지워준다. */
int getMinDistance(int *distance, int *isSelected, int maxNodeCount);

/* 간선의 가중치를 반환하는 함수 */
int getEdgeWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

#endif