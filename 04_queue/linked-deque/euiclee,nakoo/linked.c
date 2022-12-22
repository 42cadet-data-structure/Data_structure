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
	DequeNode	*frontnode;

	frontnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!frontnode)
		return (FALSE);
	*frontnode = element;
	if (isDequeEmpty(pDeque) == 1)
	{
		pDeque->pRearNode = frontnode;
		pDeque->pFrontNode = frontnode;
		pDeque->pFrontNode->pLLink = NULL;
		pDeque->pFrontNode->pRLink = NULL;
		pDeque->currentElementCount++;
		return (TRUE);
	}
	pDeque->pFrontNode->pLLink = frontnode;
	frontnode->pRLink = pDeque->pFrontNode;
	frontnode->pLLink = NULL;
	pDeque->pFrontNode = frontnode;
	pDeque->currentElementCount++;
	return (TRUE);
}

int insertRear(Deque *pDeque, DequeNode element)
{
	DequeNode	*rearnode;

	rearnode = (DequeNode *)malloc(sizeof(DequeNode));
	if (!rearnode)
		return (FALSE);
	*rearnode = element;
	pDeque->pRearNode->pRLink = rearnode;
	rearnode->pLLink = pDeque->pRearNode;
	rearnode->pRLink = NULL;
	pDeque->pRearNode = rearnode;
	if (isDequeEmpty(pDeque) == 1)
		pDeque->pFrontNode = rearnode;
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode *deleteFront(Deque *pDeque)
{
	DequeNode	*retnode;

	if (isDequeEmpty(pDeque) == 1)
		return (NULL);
	retnode = pDeque->pFrontNode;
	pDeque->pFrontNode = retnode->pRLink;
	retnode->pRLink = NULL;
	pDeque->pFrontNode->pLLink = NULL;
	pDeque->currentElementCount--;
	return (retnode);
}

DequeNode *deleteRear(Deque *pDeque)
{
	DequeNode	*retnode;

	if (isDequeEmpty(pDeque) == 1)
		return (NULL);
	retnode = pDeque->pRearNode;
	pDeque->pRearNode = retnode->pLLink;
	retnode->pLLink = NULL;
	pDeque->pRearNode->pRLink = NULL;
	pDeque->currentElementCount--;
	return (retnode);
}

DequeNode *peekFront(Deque *pDeque)
{
	if (isDequeEmpty(pDeque) == 1)
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode *peekRear(Deque *pDeque)
{
	if (isDequeEmpty(pDeque) == 1)
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