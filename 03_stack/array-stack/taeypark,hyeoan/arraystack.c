#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"


Stack *createStack(int maxElementCount)
{
	Stack	*stack;

	stack = (Stack *)malloc(sizeof(Stack));
	if (stack == NULL)
		return (FALSE);
	stack->currentElementCount = 0;
	stack->maxElementCount = maxElementCount;
	stack->pElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (stack->pElement == NULL)
		return (free(stack), (Stack *)FALSE);
	return (stack);
}

int push(Stack *pStack, StackNode element)
{
	if (isStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount++] = element;
	return (TRUE);
}

StackNode *pop(Stack *pStack)
{
	if (isStackEmpty(pStack))
		return (FALSE);
	return (&pStack->pElement[--pStack->currentElementCount]);
}

StackNode *peek(Stack *pStack)
{
	if (isStackEmpty(pStack))
		return (FALSE);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void deleteStack(Stack *pStack)
{
	free(pStack->pElement);
	pStack->pElement = NULL;
	free(pStack);
}

int isStackFull(Stack *pStack)
{
	return	(pStack->currentElementCount >= pStack->maxElementCount);
}

int isStackEmpty(Stack *pStack)
{
	return (pStack->currentElementCount <= 0);
}