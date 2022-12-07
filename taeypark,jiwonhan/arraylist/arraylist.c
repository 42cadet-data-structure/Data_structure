#include "arraylist.h"

List *createList(int maxElementCount)
{
	List *list;
	list = malloc(sizeof(List));
	if (!list)
		return (0);
	list->pElement = calloc(sizeof(ListNode), maxElementCount);
	if (!list->pElement)
		return (free(list), (List *)0);
	list->maxElementCount = maxElementCount;
	list->currentElementCount = 0;
	return (list);
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}

int isFull(List *pList)
{
	return (pList->currentElementCount == pList->maxElementCount);
}

int addElement(List *pList, int position, ListNode element)
{
	int			i;
	ListNode	*to_free;
	ListNode	*position_element;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (isFull(pList) == TRUE)
	{
		to_free = pList->pElement;
		pList->pElement = calloc(sizeof(ListNode), pList->maxElementCount * 1.5);
		if (!pList)
			return (FALSE);
		memcpy(pList->pElement, to_free, sizeof(ListNode) * pList->maxElementCount);
		pList->maxElementCount = pList->maxElementCount * 1.5;
		free(to_free);
	}
	position_element = getElement(pList, position);
	i = pList->currentElementCount;
	while (i > position)
	{
		*getElement(pList, i) = *getElement(pList, i - 1);
		i--;
	}
	*position_element = element;
	pList->currentElementCount++;
	return (TRUE);
}


int removeElement(List *pList, int position)
{
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	while (pList->currentElementCount >= position)
	{
		*getElement(pList, position) = *getElement(pList, position + 1);
		++position;
	}
	(*getElement(pList, position)).data = 0;
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getElement(List *pList, int position)
{
	if (position < 0 || pList->maxElementCount < position)
	{
		write(2, "invalid position!\n", 19);
		return (FALSE);
	}
	return (pList->pElement + position);
}

void displayList(List *pList)
{
	int	i;
	ListNode *node;

	i = -1;
	while (++i < pList->currentElementCount)
		printf("%d ", getElement(pList, i)->data);
	printf("\n");
}

void clearList(List *pList)
{
	if (!pList->pElement)
		return ;
	free(pList->pElement);
	pList->pElement = 0;
	pList->currentElementCount = 0;
}

int getListLength(List *pList)
{
	return (pList->currentElementCount);
}