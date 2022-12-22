#ifndef LINKED_DEQUE_LINKEDDEQUE_H
#define LINKED_DEQUE_LINKEDDEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct DequeNodeType {
    char data;
    struct DequeNodeType *pRLink;
    struct DequeNodeType *pLLink;
} DequeNode;

typedef struct DequeType {
    int currentElementCount;
    DequeNode *pFrontNode;
    DequeNode *pRearNode;
} Deque;

Deque *createDeque();

int insertFront(Deque *pDeque, DequeNode element);

int insertRear(Deque *pDeque, DequeNode element);

DequeNode *deleteFront(Deque *pDeque);

DequeNode *deleteRear(Deque *pDeque);

DequeNode *peekFront(Deque *pDeque);

DequeNode *peekRear(Deque *pDeque);

void deleteDeque(Deque *pDeque);

int isDequeEmpty(Deque *pDeque);

#endif //LINKED_DEQUE_LINKEDDEQUE_H
