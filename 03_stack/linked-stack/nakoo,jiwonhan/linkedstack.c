/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwonhan <jiwonhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:05:26 by jiwonhan          #+#    #+#             */
/*   Updated: 2022/12/15 15:28:28 by jiwonhan         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

Stack *createStack()
{
	Stack	*stack = (Stack *)malloc(sizeof(Stack));
	if (!stack)
		return (NULL);
	memset(stack, 0, sizeof(Stack));
	return (stack);
}

int push(Stack *pStack, StackNode node)
{
	StackNode	*pNode;

	if (!pStack)
		return (FALSE);
	pNode = (StackNode *)malloc(sizeof(StackNode));
	if (!pNode)
		return (FALSE);
	*pNode = node;
	pNode->pLink = pStack->pTopElement;
	pStack->pTopElement = pNode;
	pStack->currentElementCount++;
	return (TRUE);
}

void	pop(Stack *pStack)
{
	StackNode	*delNode;

	if (!pStack || pStack->currentElementCount == 0)
		return ;
	delNode = pStack->pTopElement;
	pStack->pTopElement = delNode->pLink;
	delNode->pLink = NULL;
	free(delNode);
	pStack->currentElementCount--;
}

StackNode *peek(Stack *pStack)
{
	if (!pStack || pStack->currentElementCount == 0)
		return (NULL);
	return (pStack->pTopElement);
}

int isEmptyStack(Stack *pStack)
{
	if (!pStack)
		return (FALSE);
	return (!pStack->currentElementCount);
}

void deleteStack(Stack *pStack)
{
	StackNode	*delNode;
	StackNode	*prevNode;

	if (!pStack)
		return ;
	delNode = pStack->pTopElement;
	while (delNode != NULL)
	{
		prevNode = delNode;
		delNode = delNode->pLink;
		free(prevNode);
	}
	free(pStack);
}