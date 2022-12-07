#include "linkedlist.h"

List *createList()
{
	List *pList;
	
	pList = malloc(sizeof(List));
	if (!pList)
		return (FALSE);
	pList->currentElementCount = 0;
	//pList->headerNode.pLink = 0;
	return (pList);
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}

int addElement(List *pList, int position, ListNode node)
{
	int			i;
	ListNode	*pNode;
	ListNode	*target_prev;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (pList->currentElementCount == 0)
	{
		pList->headerNode = node;
		pList->currentElementCount++;
		return (TRUE);
	}
	pNode = malloc(sizeof(ListNode));
	if (!pNode)
		return (FALSE);
	*pNode = node;
	if (position != 0)
	{
		target_prev = getElement(pList, position - 1);
		target_prev->pLink = pNode;
	}
	if (position == 0)
	{
	
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	int			i;
	ListNode	*target;
	ListNode	*target_prev;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	target = getElement(pList, position);
	if (position != 0)
	{
		target_prev = getElement(pList, position - 1);
		target_prev->pLink = target->pLink;
	}
	if (position == 0)
		pList->headerNode.pLink = target->pLink;
	free(target);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	int			i;
	ListNode	*target;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	target = &pList->headerNode;
	i = -1;
	while (++i < position)
		target = target->pLink;
	return (target);
}

void clearList(List *pList)
{
	ListNode	*tmp;

	while (pList->headerNode.pLink)
	{
		tmp = pList->headerNode.pLink;
		pList->headerNode.pLink = pList->headerNode.pLink->pLink;
		free(tmp);
	}
	pList->currentElementCount = 0;
}

int getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void displayList(List *pList)
{
	ListNode	*tmp;

	tmp = &pList->headerNode;
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->pLink;
	}
	printf("\n");
}