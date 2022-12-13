#ifndef DOUBLY_LIST_DOUBLYLIST_H
#define DOUBLY_LIST_DOUBLYLIST_H

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNodeType {
    int data;
    struct ListNodeType *r_next;
    struct ListNodeType *l_next;

} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;

List *createLink();

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

void displayList(List *pList);

void clearList(List *pList);

void deleteList(List *pList);


#endif