
#include "linkeddeque.h"

Deque *createDeque()
{
    Deque   *deque;

    deque = (Deque *)malloc(sizeof(Deque));
    if (deque == NULL)
        return (NULL);
    memset(deque, 0, sizeof(Deque));

    return (deque);
}

int insertFront(Deque *pDeque, DequeNode element)
{
    DequeNode   *deque_node;
    deque_node = (DequeNode *)malloc(sizeof(DequeNode));
    if (deque_node == NULL)
        return (FALSE);
    *deque_node = element;
    if (pDeque->currentElementCount == 0)
    {
        pDeque->pRearNode = deque_node;
        deque_node->pLLink = NULL;
        deque_node->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = deque_node;
    }
    else
    {
        deque_node->pLLink = NULL;
        deque_node->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode->pLLink = deque_node;
        pDeque->pFrontNode = deque_node;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

int insertRear(Deque *pDeque, DequeNode element)
{
    DequeNode   *deque_node;
    deque_node = (DequeNode *)malloc(sizeof(DequeNode));
    if (deque_node == NULL)
        return (FALSE);
    *deque_node = element;
    if (pDeque->currentElementCount == 0)
    {
        pDeque->pFrontNode = deque_node;
        deque_node->pRLink = NULL;
        deque_node->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = deque_node;
    }
    else
    {
        deque_node->pRLink = NULL;
        deque_node->pLLink = pDeque->pRearNode;
        pDeque->pRearNode->pRLink = deque_node;
        pDeque->pRearNode = deque_node;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

DequeNode *deleteFront(Deque *pDeque)
{
    DequeNode   *Del_node;

    if (isDequeEmpty(pDeque) == FALSE)
    {
        if (pDeque->currentElementCount == 1)
        {
            Del_node = pDeque->pFrontNode;
            Del_node->pRLink = NULL;
            pDeque->pFrontNode = NULL;
            pDeque->pRearNode = NULL;
        }
        else
        {
            Del_node = pDeque->pFrontNode;
            pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
            pDeque->pFrontNode->pLLink = NULL;
            Del_node->pRLink = NULL;
        }
        pDeque->currentElementCount--;
        return (Del_node);
    }
    return (NULL);
}

DequeNode *deleteRear(Deque *pDeque)
{
    DequeNode   *Del_node;

    if (isDequeEmpty(pDeque) == FALSE)
    {
        if (pDeque->currentElementCount == 1)
        {
            Del_node = pDeque->pRearNode;
            Del_node->pLLink = NULL;
            pDeque->pFrontNode = NULL;
            pDeque->pRearNode = NULL;
        }
        else
        {
            Del_node = pDeque->pRearNode;
            pDeque->pRearNode = pDeque->pRearNode->pLLink;
            pDeque->pRearNode->pRLink = NULL;
            Del_node->pLLink = NULL;
        }
        pDeque->currentElementCount--;
        return (Del_node);
    }
    return (NULL);
}

DequeNode *peekFront(Deque *pDeque)
{
    if (pDeque->currentElementCount > 0)
        return (pDeque->pFrontNode);
    return (NULL);
}

DequeNode *peekRear(Deque *pDeque)
{
    if (pDeque->currentElementCount > 0)
        return (pDeque->pRearNode);
    return (NULL);
}

void deleteDeque(Deque *pDeque)
{
    int i;
    DequeNode   *del_node;

    i = 0;
    while (i < pDeque->currentElementCount)
    {
        del_node = pDeque->pFrontNode;
        pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
        free (del_node);
        i++;
    }
    free (pDeque);
}

int isDequeEmpty(Deque *pDeque)
{
    return (pDeque->currentElementCount == 0);
}
