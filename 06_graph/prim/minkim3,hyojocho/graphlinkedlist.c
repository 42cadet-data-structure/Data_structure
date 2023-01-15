#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"

LinkedList *createLinkedList() 
{
    LinkedList *pResult = NULL;
    pResult = (LinkedList *) malloc(sizeof(LinkedList));
    if (pResult == NULL) 
        return NULL;
    memset(pResult, 0, sizeof(LinkedList));
    return pResult;
}

int addElement(LinkedList *pList, int position, LinkedListNode node) 
{
    int i = 0;
    LinkedListNode *pNewNode = NULL, *pPreNode = NULL;
    if (pList == NULL) 
        return FALSE;
    if (position < 0 || position > pList->currentElementCount)
        return FALSE;
    pNewNode = (LinkedListNode *) malloc(sizeof(LinkedListNode));
    if (pNewNode == NULL) 
        return FALSE;
    *pNewNode = node;
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++) 
        pPreNode = pPreNode->pLink;
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    return TRUE;
}

int removeElement(LinkedList *pList, int position) 
{
    int i = 0;
    LinkedListNode *pDelNode = NULL, *pPreNode = NULL;
    if (pList == NULL) 
        return FALSE;
    if (position < 0 || position >= pList->currentElementCount) 
        return FALSE;
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++) 
        pPreNode = pPreNode->pLink;
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    pDelNode->pLink = NULL;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

LinkedListNode *getElement(LinkedList *pList, int position) 
{
    int i = 0;
    LinkedListNode *pNode = NULL;
    if (pList == NULL) 
        return NULL;
    if (position < 0 || position >= pList->currentElementCount) 
        return NULL;
    pNode = &(pList->headerNode);
    for (i = 0; i <= position; i++) 
        pNode = pNode->pLink;
    return pNode;
}

int isListEmpty(LinkedList *pList) 
{
    if (pList == NULL) 
        return FALSE;
    if (pList->currentElementCount == 0) 
        return TRUE;
    return FALSE;
}

void deleteLinkedList(LinkedList *pList) 
{
    if (pList == NULL) 
        return;
    while (isListEmpty(pList) == FALSE) 
        removeElement(pList, 0);
    free(pList);
}
