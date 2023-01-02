/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraystack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:16:52 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/16 09:28:48 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraystack.h"

Stack	*createStack(int maxElementCount)
{
	Stack	*array;

	array = (Stack *)malloc(sizeof(Stack));
	if (!array)
		return (FALSE);
	array->currentElementCount = 0;
	array->maxElementCount = maxElementCount;
	array->pElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (!array->pElement)
		return (FALSE);
	memset(array->pElement, 0, sizeof(StackNode) * maxElementCount);
	return (array);
}

int	push(Stack *pStack, StackNode element)
{
	if (isStackFull(pStack))
		return (FALSE);
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode	*pop(Stack *pStack)
{
	if (isStackEmpty(pStack))
		return (FALSE);
	pStack->currentElementCount--;
	return (&pStack->pElement[pStack->currentElementCount]);
}

StackNode	*peek(Stack *pStack)
{
	if (isStackEmpty(pStack))
		return (FALSE);
	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void	deleteStack(Stack *pStack)
{
	free(pStack->pElement);
	free(pStack);
}

int	isStackFull(Stack *pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int	isStackEmpty(Stack *pStack)
{
	return (pStack->currentElementCount == 0);
}