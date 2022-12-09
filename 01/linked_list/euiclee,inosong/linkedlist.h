#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct ListNodeType ListNode;

struct ListNodeType {
    int data;
    ListNode *next;
};

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;

List *createList();

void deleteList(List *pList);

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

void clearList(List *pList);

int getListLength(List *pList);

void displayList(List *pList);

#endif //LINKED_LIST_LINKEDLIST_H