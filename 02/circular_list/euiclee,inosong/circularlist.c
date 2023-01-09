#include "circularlist.h"

List *createList()
{
	List	*list;

	list = (List *)malloc(sizeof(List));
	memset(list, 0, sizeof(List));
	// list->currentElementCount = 0;
	// list->next = NULL;
	return (list);
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}

int addElement(List *pList, int position, ListNode node)
{
	int			i = 0;
	ListNode	*pre_node;
	ListNode	*new_node;
	ListNode	*last_node;

	if (pList->currentElementCount == 0 && position == 0)
	{
		new_node = (ListNode *)malloc(sizeof(ListNode));
		*new_node = node;
		pList->next = new_node;
		new_node->next = new_node;
		pList->currentElementCount++;
	}
	else if (pList->currentElementCount != 0 && position == 0)
	{
		new_node = (ListNode *)malloc(sizeof(ListNode));
		*new_node = node;
		last_node = pList->next;
		while (last_node->next != pList->next)
			last_node = last_node->next;
		new_node->next = pList->next;
		pList->next = new_node;
		last_node->next = new_node;
		pList->currentElementCount++;
	}
	else if (position <= pList->currentElementCount)
	{
		new_node = (ListNode *)malloc(sizeof(ListNode));
		*new_node = node;
		pre_node = pList->next;
		while (i < position - 1)
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
	int			i = 0;
	ListNode	*pre_node;
	ListNode	*del_node;
	ListNode	*last_node;

	if (pList->currentElementCount == 1 && position == 0)
	{
		del_node = pList->next;
		free(del_node);
		pList->next = NULL;
		pList->currentElementCount--;
	}
	else if (pList->currentElementCount != 0 && position == 0)
	{
		last_node = pList->next;
		while (last_node->next != pList->next)
			last_node = last_node->next;
		del_node = pList->next;
		last_node->next = del_node->next;
		pList->next = del_node->next;
		free(del_node);
		pList->currentElementCount--;
	}
	else if (position <= pList->currentElementCount)
	{
		pre_node = pList->next;
		while (i < position - 1)
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
	ListNode	*node;

	i = 0;
	node = NULL;
	node = pList->next;
	while (i++ < position)
		node = node->next;
	return (node);
}

void displayList(List *pList)
{
	int	i;

	i = -1;
	printf("current count : %d\n", pList->currentElementCount);
	while (++i < pList->currentElementCount)
		printf("idx[%d] : %d\n", i, getElement(pList, i)->data);
}

void clearList(List *pList)
{
	int	i;

	i = pList->currentElementCount;
	while (i-- > 0)
		removeElement(pList, 0);
}