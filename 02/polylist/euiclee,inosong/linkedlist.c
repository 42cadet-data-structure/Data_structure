#include "linkedlist.h"

List *createList()
{
	List	*link;

	link = (List *)malloc(sizeof(List));
	if (!link)
		return (NULL);
	memset(link, 0, sizeof(List));
	return (link);
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}

int addElement(List *pList, int position, ListNode node)
{
	int		i;
	ListNode *pre_node;
	ListNode *new_node;

	i = 0;
	if (position >= 0 && position <= pList->currentElementCount)
	{
		new_node = (ListNode *)malloc(sizeof(ListNode));
		if (!new_node)
			return (FALSE);
		*new_node = node;
		new_node->next = NULL;
		pre_node = &(pList->headerNode);
		while (i < position)
		{
			pre_node = pre_node->next;
			i++;
		}
		new_node->next = pre_node->next;
		pre_node->next = new_node;
		pList->currentElementCount++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	int			i;
	ListNode	*pre_node;
	ListNode	*del_node;

	i = 0;
	if (position >= 0 && position < pList->currentElementCount)
	{
		pre_node = &(pList->headerNode);
		while (i < position)
		{
			pre_node = pre_node->next;
			i++;
		}
		del_node = pre_node->next;
		pre_node->next = del_node->next;
		free(del_node);
		pList->currentElementCount--;
	}
	else
		return (FALSE);
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	int			i;
	ListNode	*pre_node;
	
	i = 0;
	pre_node = NULL;
	pre_node = &(pList->headerNode);
	while (i <= position)
	{
		pre_node = pre_node->next;
		i++;
	}
	return (pre_node);
}

void clearList(List *pList)
{
	while (pList->currentElementCount > 0)
		removeElement(pList, 0);
}

void displayList(List *pList)
{
	int	i;

	i = 0;
	printf("current element count : %d\n", pList->currentElementCount);
	while (i < pList->currentElementCount)
	{
		printf("link[%d] : %d\n", i, getElement(pList, i)->degree);
		i++;
	}
}