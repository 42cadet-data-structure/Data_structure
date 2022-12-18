#ifndef STACK_MAP_MAPSTACK_H
#define STACK_MAP_MAPSTACK_H

#define TRUE        1
#define FALSE        0

typedef struct StackNodeType {
    MapPosition data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct StackType {
    int currentElementCount;    // ���� ������ ����
    StackNode *pTopElement;        // Top ������ ������
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode element);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

void deleteStack(Stack *pStack);

int isEmptyStack(Stack *pStack);

#endif