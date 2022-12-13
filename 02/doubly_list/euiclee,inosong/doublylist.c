#include "doublylist.h"

List *createLink()
{
	List	*list;

	list = (List *)malloc(sizeof(List));
	memset(list, 0, sizeof(List));
	list->headerNode.r_next = &(list->headerNode);
	list->headerNode.l_next = &(list->headerNode);
	return (list);
}

int addElement(List *pList, int position, ListNode node)
{
	int			i = 0;
	ListNode	*new_node;
	ListNode	*pre_node;

	if (position >= 0 && position <= pList->currentElementCount)
	{
		new_node = (ListNode *)malloc(sizeof(ListNode));
		new_node->data = node.data;
		pre_node = &(pList->headerNode);
		while (i < position)
		{
			pre_node = pre_node->r_next;
			i++;
		}
		new_node->l_next = pre_node;
		new_node->r_next = pre_node->r_next;
		pre_node->r_next = new_node;
		new_node->r_next->l_next = new_node;
		pList->currentElementCount++;
	}
	else
		return (FALSE);
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	int			i = 0;
	ListNode	*del_node;
	ListNode	*pre_node;

	if (position >= 0 && position <= pList->currentElementCount)
	{
		pre_node = &(pList->headerNode);
		while (i <= position)
		{
			pre_node = pre_node->r_next;
			i++;
		}
		del_node = pre_node;
		pre_node->r_next->l_next = del_node->l_next;
		pre_node->l_next->r_next = del_node->r_next;
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
	node = &(pList->headerNode);
	while (i <= position)
	{
		node = node->r_next;
		i++;
	}
	return (node);
}

void displayList(List *pList)
{
	int	i;

	i = 0;
	printf("current element count : %d\n", pList->currentElementCount);
	while (i < pList->currentElementCount)
	{
		printf("link[%d] : %d\n", i, getElement(pList, i)->data);
		i++;
	}
}

void clearList(List *pList)
{
	while (pList->currentElementCount > 0)
		removeElement(pList, 0);
}

void deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}