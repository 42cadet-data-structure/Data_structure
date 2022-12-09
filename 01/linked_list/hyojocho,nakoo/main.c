#include <stdio.h>
#include "linkedlist.h"

int main() {
    printf("Hello, World!\n");
    List *pList = NULL;
    ListNode node;

    pList = createList();

    if (pList!=NULL){
        node.data = 1;
        addElement(pList, 0, node);
        node.data = 2;
        addElement(pList, 1, node);
        node.data = 3;
        addElement(pList, 2, node);
        node.data = 4;
        addElement(pList, 3, node);
        node.data = 5;
        addElement(pList, 4, node);

        displayList(pList);

        node.data = 0;
        addElement(pList, 0, node);
        node.data = 9;
        addElement(pList, 5, node);
        node.data = 8;
        addElement(pList, 5, node);
        displayList(pList);

        removeElement(pList, 0);
        displayList(pList);

        removeElement(pList, 3);
        displayList(pList);
        printf("%d\n", getListLength(pList));
        clearList(pList);
        displayList(pList);

        deleteList(pList);
    }

    return 0;
}