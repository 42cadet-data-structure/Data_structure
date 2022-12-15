#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

Stack *createStack(int maxElementCount)
{
	Stack *stack;
	
	stack = (Stack *)malloc(sizeof(Stack));
	if (!stack)
		return (NULL);
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stack->pElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (!stack->pElement)
		return (NULL);
	return (stack);
}

int push(Stack *pStack, StackNode element)
{
	if (pStack == NULL)
		return (FALSE);
	if (pStack->maxElementCount <= pStack->currentElementCount)
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode *pop(Stack *pStack)
{
	StackNode *tmp;

	if (pStack == NULL || pStack->currentElementCount <= 0)
		return (FALSE);
	tmp = &(pStack->pElement[pStack->currentElementCount - 1]);
	pStack->currentElementCount--;
	return (tmp);
}

StackNode *peek(Stack *pStack)
{
	if (pStack == NULL || pStack->currentElementCount <= 0)
		return (FALSE);
	return (&(pStack->pElement[pStack->currentElementCount - 1]));
}

void deleteStack(Stack *pStack)
{
	if (pStack == NULL)
		return ;
	free(pStack->pElement);
	free(pStack);
}

int isStackFull(Stack *pStack)
{
	if (pStack == NULL)
		return (FALSE);
	return (pStack->maxElementCount == pStack->currentElementCount);
}

int isStackEmpty(Stack *pStack)
{
	if (pStack == NULL)
		return (FALSE);
	return (pStack->currentElementCount == 0);
}