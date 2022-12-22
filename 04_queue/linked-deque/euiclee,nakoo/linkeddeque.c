#include "linkeddeque.h"

Deque *createDeque()
{
	Deque	*deque;

	deque = (Deque *)malloc(sizeof(Deque));
	if (!deque)
		return (NULL);
	memset(deque, 0, sizeof(Deque));
	return (deque);
}

int insertFront(Deque *pDeque, DequeNode element)
{
	DequeNode	*newnode;

	newnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!newnode)
		return (FALSE);
	*newnode = element;
	if (isDequeEmpty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = newnode;
		pDeque->pRearNode = newnode;
		newnode->pLLink = NULL;
		newnode->pRLink = NULL;
		pDeque->currentElementCount++;
		return (TRUE);
	}
	newnode->pRLink = pDeque->pFrontNode;
	pDeque->pFrontNode->pLLink = newnode;
	newnode->pLLink = NULL;
	pDeque->pFrontNode = newnode;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRear(Deque *pDeque, DequeNode element)
{
	DequeNode	*newnode;

	newnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!newnode)
		return (FALSE);
	*newnode = element;
	if (isDequeEmpty(pDeque) == TRUE)
	{
		pDeque->pFrontNode = newnode;
		pDeque->pRearNode = newnode;
		newnode->pLLink = NULL;
		newnode->pRLink = NULL;
		pDeque->currentElementCount++;
		return (TRUE);
	}
	newnode->pLLink = pDeque->pRearNode;
	pDeque->pRearNode->pRLink = newnode;
	newnode->pRLink = NULL;
	pDeque->pRearNode = newnode;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode *deleteFront(Deque *pDeque)
{
	DequeNode	*retnode;

	if (isDequeEmpty(pDeque) == TRUE)
		return (NULL);
	retnode = pDeque->pFrontNode;
	if (pDeque->currentElementCount != 1)
		retnode->pRLink->pLLink = NULL;
	pDeque->pFrontNode = retnode->pRLink;
	retnode->pRLink = NULL;
	pDeque->currentElementCount--;
	return (retnode);
}

DequeNode *deleteRear(Deque *pDeque)
{
	DequeNode	*retnode;

	if (isDequeEmpty(pDeque) == TRUE)
		return (NULL);
	retnode = pDeque->pRearNode;
	if (pDeque->currentElementCount != 1)
		retnode->pLLink->pRLink = NULL;
	pDeque->pRearNode = retnode->pLLink;
	retnode->pRLink = NULL;
	pDeque->currentElementCount--;
	return (retnode);
}

DequeNode *peekFront(Deque *pDeque)
{
	if (isDequeEmpty(pDeque) == TRUE)
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode *peekRear(Deque *pDeque)
{
	if (isDequeEmpty(pDeque) == TRUE)
		return (NULL);
	return (pDeque->pRearNode);
}

void deleteDeque(Deque *pDeque)
{
	while (pDeque->currentElementCount > 0)
		free(deleteRear(pDeque));
	free(pDeque);
}

int isDequeEmpty(Deque *pDeque)
{
	return (pDeque->currentElementCount == 0);
}