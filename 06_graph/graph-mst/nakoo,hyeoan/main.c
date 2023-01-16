#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"
#include <unistd.h>

int main() {

    int i = 0;
    Graph *pG1 = NULL;
    Graph *pG2 = NULL;
    Graph *pMST1 = NULL;
    Graph *pMST2 = NULL;

    pG1 = createGraph(6);
    pG2 = createGraph(6);

    if (pG1 != NULL) {

        for(i = 0; i < 6; i++)
            addVertex(pG1, i);

        addEdgeWithWeight(pG1, 0, 1, 1);
        addEdgeWithWeight(pG1, 2, 3, 2);
        addEdgeWithWeight(pG1, 4, 5, 3);
        addEdgeWithWeight(pG1, 0, 2, 4);
        addEdgeWithWeight(pG1, 1, 3, 4);
        addEdgeWithWeight(pG1, 2, 4, 4);
        addEdgeWithWeight(pG1, 3, 5, 4);

        for(i = 0; i < 6; i++) 
            addVertex(pG2, i);

        addEdgeWithWeight(pG2, 0, 1, 4);
        addEdgeWithWeight(pG2, 0, 2, 3);
        addEdgeWithWeight(pG2, 1, 2, 2);
        addEdgeWithWeight(pG2, 2, 3, 1);
        addEdgeWithWeight(pG2, 3, 4, 1);
        addEdgeWithWeight(pG2, 3, 5, 5);
        addEdgeWithWeight(pG2, 4, 5, 6);

        printf("G1:\n");
        displayGraph(pG1);

        printf("\nG1 - Kruskal MST:\n");
        pMST1 = mstKruskal(pG1);
        printf("\n");
        displayGraph(pMST1);
        printf("\n");

        printf("G2:\n");
        displayGraph(pG2);

        printf("\nG2 - Kruskal MST:\n");
        pMST2 = mstKruskal(pG2);
        printf("\n"),
        displayGraph(pMST2);
        printf("\n");

        deleteGraph(pG1);
        deleteGraph(pMST1);
        deleteGraph(pG2);
        deleteGraph(pMST2);
    }

    return 0;
}