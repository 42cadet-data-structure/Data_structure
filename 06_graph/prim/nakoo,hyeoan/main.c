#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"

int main() 
{

    int i = 0;
    LinkedGraph *pG1 = NULL;
    LinkedGraph *pMST1 = NULL;

    pG1 = createLinkedGraph(6);
    if (pG1 != NULL) {

        for(i = 0; i < 6; i++) {
            addVertex(pG1, i);
        }

        addEdgeWithWeight(pG1, 0, 1, 4);
        addEdgeWithWeight(pG1, 0, 2, 3);
        addEdgeWithWeight(pG1, 1, 2, 2);
        addEdgeWithWeight(pG1, 2, 3, 1);
        addEdgeWithWeight(pG1, 3, 4, 1);
        addEdgeWithWeight(pG1, 3, 5, 5);
        addEdgeWithWeight(pG1, 4, 5, 6);

        printf("G1:\n");
        displayLinkedGraph(pG1);

        printf("\nPrim MST:\n");
        pMST1 = mstPrim(pG1, 1);
		printf("\n");
        displayLinkedGraph(pMST1);

        deleteLinkedGraph(pG1);
        deleteLinkedGraph(pMST1);
    }
    return 0;
}