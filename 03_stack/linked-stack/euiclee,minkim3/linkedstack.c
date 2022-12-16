/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euiclee <euiclee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:28:47 by euiclee           #+#    #+#             */
/*   Updated: 2022/12/16 10:01:02 by euiclee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedstack.h"

Stack	*createStack()
{
	Stack	*list;

	list = (Stack *)malloc(sizeof(Stack));
	if (!list)
		return (FALSE);
	memset(list, 0, sizeof(Stack));
	return (list);
}

int	push(Stack *pStack, StackNode node)
{
	StackNode	*new_node;

	new_node = (StackNode *)malloc(sizeof(StackNode));
	if (!new_node)
		return (FALSE);
	*new_node = node;
	if (isEmptyStack(pStack))
	{
		pStack->pTopElement = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = pStack->pTopElement;
		pStack->pTopElement = new_node;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode	*pop(Stack *pStack)
{
	StackNode	*top;

	top = pStack->pTopElement;
	pStack->pTopElement = top->next;
	top->next = NULL;
	pStack->currentElementCount--;
	return (top);
}

StackNode	*peek(Stack *pStack)
{
	return (pStack->pTopElement);
}

int	isEmptyStack(Stack *pStack)
{
	return (pStack->currentElementCount == 0);
}

void deleteStack(Stack *pStack)
{
	while (pStack->currentElementCount > 0)
		free(pop(pStack));
	free(pStack);
}