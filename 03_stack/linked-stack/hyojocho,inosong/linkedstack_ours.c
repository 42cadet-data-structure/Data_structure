/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedstack_ours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:38:05 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/15 15:29:21 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedstack.h"

Stack *createStack()
{
	Stack		*stack;
	StackNode	*stacknode;
	
	stack = (Stack *)malloc(sizeof(Stack));
	stack->currentElementCount = 0;
	stacknode = (StackNode *)malloc(sizeof(StackNode));
	stacknode->data = 0;
	stacknode->pLink = NULL;
	stack->pTopElement = stacknode;
	return (stack);
}

int push(Stack *pStack, StackNode node)
{
	StackNode	*stacknode;
	
	stacknode = (StackNode *)malloc(sizeof(StackNode));
	stacknode->data = node.data;
	if (isEmptyStack(pStack))
		pStack->pTopElement = stacknode;
	else
	{
		stacknode->pLink = pStack->pTopElement;
		pStack->pTopElement = stacknode;
	}
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode *pop(Stack *pStack)
{
	StackNode	*tmp;
	
	if (isEmptyStack(pStack))
		return (FALSE);
	tmp = pStack->pTopElement;
	pStack->pTopElement = pStack->pTopElement->pLink;
	pStack->currentElementCount--;
	free (tmp);
	return (tmp);
}

StackNode *peek(Stack *pStack)
{
	return (pStack->pTopElement);
}

int isEmptyStack(Stack *pStack)
{
	if (pStack->currentElementCount == 0)
		return (TRUE);
	return (FALSE);
}

void deleteStack(Stack *pStack)
{
	StackNode	*tmp;

	while(pStack->pTopElement)
	{
		tmp = pStack->pTopElement->pLink;
		free(pStack->pTopElement);
		pStack->pTopElement = tmp;
	}
}