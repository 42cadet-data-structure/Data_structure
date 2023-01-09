#ifndef STACK_MAP_MAPSTACK_H
#define STACK_MAP_MAPSTACK_H
#include "mapdef.h"
#define TRUE        1
#define FALSE        0

typedef struct StackNodeType {
    MapPosition data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct StackType {
    int currentElementCount;
    StackNode *pTopElement;
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode element);

void pop(Stack *pStack);

StackNode *peek(Stack *pStack);

void deleteStack(Stack *pStack);

void	clearStack(Stack *pStack);

int isStackEmpty(Stack *pStack);

#endif