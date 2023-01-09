#include "linkedlist.h"
#include "polylist.h"

int main() {
    List *pListA = createList(), *pListB = createList(), *pListC = NULL;

    if (pListA != NULL && pListB != NULL){
        addPolyNodeLast(pListA, 3, 15);
        addPolyNodeLast(pListA, 2, 8);
        addPolyNodeLast(pListA, 17, 7);
        addPolyNodeLast(pListA, 2, 0);


        displayPolyList(pListA);

        addPolyNodeLast(pListB, 10, 15);
        addPolyNodeLast(pListB, 9, 9);
        addPolyNodeLast(pListB, 7, 5);
        addPolyNodeLast(pListB, 6, 3);
        addPolyNodeLast(pListB, 9, 2);

        displayPolyList(pListB);

        pListC = polyAdd(pListA, pListB);

        displayPolyList(pListC);


    }

    return 0;
}