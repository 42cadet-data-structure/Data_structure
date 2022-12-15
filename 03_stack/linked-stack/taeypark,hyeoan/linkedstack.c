//
// Created by sanguk on 07/08/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"


Stack *createStack()
{
	Stack	*stack;

	stack = (Stack *)malloc(sizeof(Stack));
	if (stack == NULL)
		return (FALSE);
	stack->currentElementCount = 0;
	stack->pTopElement = NULL;
	return (stack);
}

int push(Stack *pStack, StackNode node)
{
	StackNode	*new_node;
	new_node = (StackNode *)malloc(sizeof(StackNode));
	if (new_node == NULL)
		return (FALSE);
	*new_node = node;
	new_node->pLink = pStack->pTopElement;
	pStack->pTopElement = new_node;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode *pop(Stack *pStack)
{
	StackNode	*to_pop;

	if (isEmptyStack(pStack))
		return (NULL);
	to_pop = pStack->pTopElement;
	pStack->pTopElement = to_pop->pLink;
	to_pop->pLink = NULL;
	pStack->currentElementCount--;
	return (to_pop);
}

StackNode *peek(Stack *pStack)
{
	if (isEmptyStack(pStack))
		return (NULL);
	return (pStack->pTopElement);
}

int isEmptyStack(Stack *pStack)
{
	return (pStack->currentElementCount <= 0);
}

void deleteStack(Stack *pStack)
{
}