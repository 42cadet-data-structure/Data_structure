#include "linkedlist.h"

List *createList()
{
	List	*link;

	link = (List *)malloc(sizeof(List));
	if (!link)
		return (NULL);
	link->currentElementCount = 0;
	link->headerNode.data = 0;
	link->headerNode.next = NULL;
	return (link);
}

void deleteList(List *pList)
{
	if (pList)
	{
		clearList(pList);
		free(pList);
	}
}

int addElement(List *pList, int position, ListNode node)
{
	int		i;
	ListNode *pre_node;
	ListNode *new_node;

	i = 0;
	if (pList)
	{
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
	if (pList)
	{
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
	if (pList)
	{
		while (pList->currentElementCount > 0)
			removeElement(pList, 0);
	}
}

int getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void displayList(List *pList)
{
	int			i;
	ListNode	*node;

	i = 0;
	if (pList)
	{
		printf("vurrent element count : %d\n", pList->currentElementCount);
		while (i < pList->currentElementCount)
		{
			node = getElement(pList, i);
			if (node)
				printf("link[%d] : %d\n", i, node->data);
			i++;
		}
	}
	else
		printf("nothing\n");
}