#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


List *createList()
{
	List		*lst;

	lst = (List *)malloc(sizeof(List));
	if (lst == NULL)
		return (NULL);

	lst->currentElementCount = 0;
	lst->headerNode = NULL;
	return (lst);
}

void deleteList(List *pList)
{
	free(pList);
}

int addElement(List *pList, int position, ListNode node)
{
	ListNode	*dummy;
	ListNode	*new_node;
	ListNode	*last_node;
	int			i;

	i = 0;
	if (pList == NULL || position > pList->currentElementCount || position < 0)
		return (FALSE);
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
		return (FALSE);
	
	*new_node = node;
	if (position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			pList->headerNode = new_node;
			new_node->pLink = new_node; 
		}
		else
		{
			last_node = pList->headerNode;
			while (last_node->pLink != pList->headerNode)
				last_node = last_node->pLink;
			pList->headerNode = new_node;
			new_node->pLink = last_node->pLink;
			last_node->pLink = new_node;
		}
	}
	else
	{
		dummy = pList->headerNode;
		while (i < position -1)
		{
			dummy = dummy->pLink;
			i++;
		}
		new_node->pLink = dummy->pLink;
		dummy->pLink = new_node;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	ListNode	*dummy;
	ListNode	*del_node;
	ListNode	*last_node;
	int			i;

	i = 0;
	if (pList == NULL || position >= pList->currentElementCount || position < 0)
		return (FALSE);
	del_node = pList->headerNode;
	if (position == 0)
	{
		if (pList->currentElementCount == 1)
		{
			free(del_node);
			pList->headerNode = NULL; 
		}
		else
		{
			last_node = pList->headerNode;
			while (last_node->pLink != pList->headerNode)
				last_node = last_node->pLink;
			last_node->pLink = del_node->pLink;
			pList->headerNode = del_node->pLink;
			free(del_node);
		}
	}
	else
	{
		dummy = pList->headerNode;
		while (i < position - 1)
		{
			dummy = dummy->pLink;
			i++;
		}
		del_node = dummy->pLink;
		dummy->pLink = del_node->pLink;
		free(del_node);
	}
	pList->currentElementCount--;
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	ListNode	*dummy;
	int	i;

	i = 0;
	if (pList == NULL || position >= pList->currentElementCount || position < 0)
		return (FALSE);
	dummy = pList->headerNode;
	while (i < position)
	{
		dummy = dummy->pLink;
		i++;
	}
	return (dummy);	
}

void clearList(List *pList)
{	
	if(pList == NULL)
		return ;
	while(pList->currentElementCount)
		removeElement(pList, 0);
}

int getListLength(List *pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

void displayList(List *pList)
{
	ListNode	*dummy;
	int			i;
	
	i = 0;
	if(pList == NULL)
		return ;
	dummy = pList->headerNode;
	while(i < pList->currentElementCount)
	{
		printf("%d\n", dummy->data);
		dummy = dummy->pLink;
		i++;
	}
}