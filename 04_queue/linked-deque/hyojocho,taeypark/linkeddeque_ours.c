/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkeddeque_ours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:23:42 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/26 12:57:17 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkeddeque.h"

Deque *createDeque()
{
	Deque	*deque;

	deque = malloc(sizeof(Deque));
	if (!deque)
		return (NULL);
	deque->currentElementCount = 0;
	deque->pFrontNode = deque->pRearNode = NULL;
	return (deque);
}

int insertFront(Deque *pDeque, DequeNode element)
{
	DequeNode	*deque_node;

	deque_node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!deque_node)
		return (FALSE);
	*deque_node = element;
	if (isDequeEmpty(pDeque))
		pDeque->pRearNode = deque_node;
	else
		pDeque->pFrontNode->pLLink = deque_node;
	deque_node->pRLink = pDeque->pFrontNode;
	pDeque->pFrontNode = deque_node;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRear(Deque *pDeque, DequeNode element)
{
	DequeNode	*deque_node;

	deque_node = (DequeNode *)malloc(sizeof(DequeNode));
	if (!deque_node)
		return (FALSE);
	*deque_node = element;
	if (isDequeEmpty(pDeque))
		pDeque->pFrontNode = deque_node;
	else
		pDeque->pRearNode->pRLink = deque_node;
	deque_node->pLLink = pDeque->pRearNode;
	pDeque->pRearNode = deque_node;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode *deleteFront(Deque *pDeque)
{
	DequeNode	*to_delete;

	if (isDequeEmpty(pDeque))
		return (FALSE);
	to_delete = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	to_delete->pLLink = to_delete->pRLink = NULL;
	if (pDeque->pFrontNode)
		pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	return (to_delete);
}


DequeNode *deleteRear(Deque *pDeque)
{
	DequeNode	*to_delete;

	if (isDequeEmpty(pDeque))
		return (FALSE);
	to_delete = pDeque->pRearNode;
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	to_delete->pLLink = to_delete->pRLink = NULL;
	if (pDeque->pRearNode)
		pDeque->pRearNode->pRLink = NULL;
	pDeque->currentElementCount--;
	return (to_delete);
}

DequeNode *peekFront(Deque *pDeque)
{
	if (isDequeEmpty(pDeque))
		return (FALSE);
	return (pDeque->pFrontNode);
}

DequeNode *peekRear(Deque *pDeque)
{
	if (isDequeEmpty(pDeque))
		return (FALSE);
	return (pDeque->pRearNode);	
}

void deleteDeque(Deque *pDeque)
{
	DequeNode	*to_free;

	to_free = pDeque->pFrontNode;
	while (to_free != NULL)
	{
		free(to_free);
		to_free = to_free->pRLink;
	}
	pDeque->currentElementCount = 0;
	pDeque->pFrontNode = pDeque->pRearNode = NULL;
	free(pDeque);
}

int isDequeEmpty(Deque *pDeque)
{
	return (pDeque->currentElementCount <= 0);
}