#ifndef CIRCULARLIST_CIRCULARLIST_H
#define CIRCULARLIST_CIRCULARLIST_H

#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNodeType {
    int data;
    struct ListNodeType *next;
} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode *next;
} List;

List *createList();

void deleteList(List *pList);

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

void displayList(List *pList);

void clearList(List *pList);


#endif