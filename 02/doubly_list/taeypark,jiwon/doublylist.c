#include "doublylist.h"

List *createLink()
{
	List	*pList;

	pList = calloc(sizeof(List), 1);
	if (!pList)
		return (0);
	return (pList);
}

int addElement(List *pList, int position, ListNode node)
{
	int			pos = position;
	ListNode	*target, *target_prev;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	target = calloc(sizeof(ListNode), 1);
	if (!target)
		return (FALSE);
	*target = node;
	target_prev = &pList->headerNode;
	while (position--)
		target_prev = target_prev->pRightLink;
	target->pRightLink = target_prev->pRightLink;
	target->pLeftLink = target_prev;
	if (pos != pList->currentElementCount)
		target_prev->pRightLink->pLeftLink = target;
	target_prev->pRightLink = target;
	pList->currentElementCount++;
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	int			pos = position;
	ListNode	*target, *target_prev, *target_next;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	target = pList->headerNode.pRightLink;
	while (position--)
		target = target->pRightLink;
	target_prev = target->pLeftLink;
	target_next = target->pRightLink;
	target_prev->pRightLink = target_next;
	if (pos != pList->currentElementCount - 1)
		target_next->pLeftLink = target_prev;
	free(target);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	ListNode	*pNode;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	pNode = pList->headerNode.pRightLink;
	while (position--)
		pNode = pNode->pRightLink;
	return (pNode);
}

int getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void displayList(List *pList)
{
	ListNode	*pNode;

	pNode = pList->headerNode.pRightLink;
	while (pNode)
	{
		printf("%d ", pNode->data);
		pNode = pNode->pRightLink;
	}
	printf("\n");
}

void clearList(List *pList)
{
	ListNode	*pNode, *to_free;

	pNode = pList->headerNode.pRightLink;
	while (pNode)
	{
		to_free = pNode;
		pNode = pNode->pRightLink;
		free(to_free);
	}
	pList->headerNode.pRightLink = NULL;
	pList->currentElementCount = 0;
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}