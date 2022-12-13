#include <stdio.h>
#include "linkedlist.h"
#include "polylist.h"

int main() {
    List *pListA = createList(), *pListB = createList(), *pListC = NULL;

    if (pListA != NULL && pListB != NULL){
        addPolyNodeLast(pListA, 3, 3);
        addPolyNodeLast(pListA, 2, 2);
        addPolyNodeLast(pListA, 7, 2);
        addPolyNodeLast(pListA, 3, 0);


        displayPolyList(pListA);

        addPolyNodeLast(pListB, 10, 5);
        addPolyNodeLast(pListB, 9, 4);
        addPolyNodeLast(pListB, 7, 3);
        addPolyNodeLast(pListB, 6, 2);
        addPolyNodeLast(pListB, 9, 1);

        displayPolyList(pListB);

        pListC = polyAdd(pListA, pListB);

        displayPolyList(pListC);


    }

    return 0;
}