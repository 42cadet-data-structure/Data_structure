#include "circularlist.h"

List *createList()
{
	List *pList;

	pList = malloc(sizeof(List));
	if (!pList)
		return (FALSE);
	pList->currentElementCount = 0;
	pList->pLink = 0;
	return (pList);
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}

int addElement(List *pList, int position, ListNode node)
{
	ListNode	*preNode, *pNode;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	pNode = malloc(sizeof(ListNode));
	if (!pNode)
		return (FALSE);
	*pNode = node;
	if (position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			pList->pLink = pNode;
			pNode->pLink = pList->pLink;
		}
		else
		{
			preNode = pList->pLink;
			while (preNode->pLink != pList->pLink)
				preNode = preNode->pLink;
			preNode->pLink = pNode;
			pNode->pLink = pList->pLink;
			pList->pLink = pNode;
		}
	}
	else
	{
		preNode = (ListNode *)pList;
		while (position--)
			preNode = preNode->pLink;
		pNode->pLink = preNode->pLink;
		preNode->pLink = pNode;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	ListNode	*rmNode, *target_prev, *end_node;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	if (position == 0)
	{
		rmNode = pList->pLink;
		end_node = pList->pLink;
		while (end_node->pLink != pList->pLink)
			end_node = end_node->pLink;
		end_node->pLink = rmNode->pLink;
		pList->pLink = rmNode->pLink;
		if (pList->currentElementCount == 1)
			pList->pLink = NULL;
	}
	else
	{
		target_prev = (ListNode *)pList;
		while (position--)
			target_prev = target_prev->pLink;
		rmNode = target_prev->pLink;
		target_prev->pLink = rmNode->pLink;
	}
	free(rmNode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	ListNode	*pNode;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	pNode = pList->pLink;
	while (position--)
		pNode = pNode->pLink;
	return (pNode);
}

int getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void displayList(List *pList)
{
	ListNode	*to_display;
	int			i = -1;

	if (!pList->currentElementCount)
		return ;
	to_display = pList->pLink;
	while (++i < pList->currentElementCount)
	{
		printf("%d ", to_display->data);
		to_display = to_display->pLink;
	}
	printf("\n");
}

void clearList(List *pList)
{
	ListNode	*pNode, *to_free;

	if (!pList->pLink)
		return ;
	pNode = pList->pLink;
	while (pNode->pLink != pList->pLink)
	{
		to_free = pNode;
		pNode = pNode->pLink;
		free(to_free);
	}
	pList->pLink = NULL;
	pList->currentElementCount = 0;
}