/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:08:50 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/15 14:46:34 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraystack.h"

Stack *createStack(int maxElementCount)
{
	Stack		*stack;
	StackNode	*stackarray;
	
	stack = (Stack *)malloc(sizeof(Stack));
	stack->maxElementCount = maxElementCount;
	stack->currentElementCount = 0;
	stackarray = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	memset(stackarray, 0, sizeof(maxElementCount));
	stack->pElement = stackarray;
	return (stack);
}

int push(Stack *pStack, StackNode element)
{
	if (isStackFull(pStack))
	{
		printf("error : stack is full\n");
		return (FALSE);
	}
	pStack->pElement[pStack->currentElementCount].data = element.data;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode *pop(Stack *pStack)
{
	if (isStackEmpty(pStack))
	{
		printf("error : stack is empty\n");
		return (FALSE);
	}
	pStack->currentElementCount--;
	return (&pStack->pElement[pStack->currentElementCount]);
}

StackNode *peek(Stack *pStack)
{
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

int isStackFull(Stack *pStack)
{
	if (pStack->currentElementCount < pStack->maxElementCount)
		return (FALSE);
	return (TRUE);
}

int isStackEmpty(Stack *pStack)
{
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void deleteStack(Stack *pStack)
{
	free(pStack->pElement);
	pStack->pElement = NULL;
	pStack->currentElementCount = 0;
	free(pStack);
}