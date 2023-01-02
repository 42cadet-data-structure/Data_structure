#include "linkeddeque.h"

Deque *createDeque()
{
    Deque   *deque;
    deque = (Deque *)malloc(sizeof(Deque));
    if (!deque)
        return (NULL);
    memset(deque, 0, sizeof(Deque));
    return (deque);
}

int insertFront(Deque *pDeque, DequeNode element)
{
    DequeNode   *new;

    if (!pDeque)
        return (FALSE);
    new = (DequeNode *)malloc(sizeof(DequeNode));
    if (!new)
        return (FALSE);
    *new = element;
    if (isDequeEmpty(pDeque))
    {
        pDeque->pRearNode = new;
        new->pRLink = NULL;
    }
    else
    {
        new->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode->pLLink = new;
    }
    new->pLLink = NULL;
    pDeque->pFrontNode = new;
    pDeque->currentElementCount++;
    return (TRUE);
}

int insertRear(Deque *pDeque, DequeNode element)
{
    DequeNode   *new;

    if (!pDeque)
        return (FALSE);
    new = (DequeNode *)malloc(sizeof(DequeNode));
    if (!new)
        return (FALSE);
    *new = element;
    if (pDeque->currentElementCount == 0)
    {
        pDeque->pFrontNode = new;
        new->pLLink = NULL;
    }
    else
    {
        new->pLLink = pDeque->pRearNode;
        pDeque->pRearNode->pRLink = new;
    }
    new->pRLink = NULL;
    pDeque->pRearNode = new;
    pDeque->currentElementCount++;
    return (TRUE);
}

DequeNode *deleteFront(Deque *pDeque)
{
    DequeNode   *node;

    if (!pDeque || isDequeEmpty(pDeque))
        return (NULL);
    node = pDeque->pFrontNode;
	if (pDeque->currentElementCount != 1)
		node->pRLink->pLLink = NULL;
    pDeque->pFrontNode = node->pRLink;
    node->pRLink = NULL;
    pDeque->currentElementCount--;
    return (node);
}

DequeNode *deleteRear(Deque *pDeque)
{
    DequeNode   *node;

    if (!pDeque || isDequeEmpty(pDeque))
        return (NULL);
    node = pDeque->pRearNode;
	if (pDeque->currentElementCount != 1)
		node->pLLink->pRLink = NULL;
    pDeque->pRearNode = node->pLLink;
    node->pRLink = NULL;
    pDeque->currentElementCount--;
    return (node);
}

DequeNode *peekFront(Deque *pDeque)
{
	if (!pDeque || isDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pFrontNode);
}

DequeNode *peekRear(Deque *pDeque)
{
	if (!pDeque || isDequeEmpty(pDeque))
		return (NULL);
	return (pDeque->pRearNode);
}
void deleteDeque(Deque *pDeque)
{
	while (pDeque->currentElementCount)
		free(deleteRear(pDeque));
	free(pDeque);
}

int isDequeEmpty(Deque *pDeque)
{
	return (pDeque->currentElementCount == 0);
}