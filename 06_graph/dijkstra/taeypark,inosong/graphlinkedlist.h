#ifndef GRAPH_MST_GRAPHLINKEDLIST_H
#define GRAPH_MST_GRAPHLINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef struct GraphNodeType {
    int vertexID;
    int weight;
} GraphNode;

typedef struct ListNodeType {
    GraphNode data;
    struct ListNodeType *pLink;
} ListNode, LinkedListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List, LinkedList;

LinkedList *createLinkedList();

int addElement(LinkedList *pList, int position, LinkedListNode node);

int removeElement(LinkedList *pList, int position);

LinkedListNode *getElement(LinkedList *pList, int position);

int isListEmpty(LinkedList *pList);

void deleteLinkedList(LinkedList *pList);

#endif