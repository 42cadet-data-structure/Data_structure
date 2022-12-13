#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

List *createList()
{
	List		*lst;

	lst = (List *)malloc(sizeof(List));
	if (lst == NULL)
		return (NULL);

	lst->currentElementCount = 0;
	lst->headerNode.pLink = NULL;
	return (lst);
}

void deleteList(List *pList)
{
	free(pList);
}

int addElement(List *pList, int position, ListNode node)
{
	ListNode	*dummy;
	ListNode	*pNode;
	int			i;

	i = 0;
	if (pList == NULL || position > pList->currentElementCount || position < 0)
		return (FALSE);
	pNode = (ListNode *)malloc(sizeof(ListNode));
	if (pNode == NULL)
		return (FALSE);
	
	*pNode = node;

	dummy = &pList->headerNode;
	while (i < position)
	{
		dummy = dummy->pLink;
		i++;
	}
	pNode->pLink = dummy->pLink;
	dummy->pLink = pNode;
	(pList->currentElementCount)++;
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	ListNode	*dummy;
	ListNode	*tmp;
	int	i;

	i = 0;
	if (pList == NULL || position >= pList->currentElementCount || position < 0)
		return (FALSE);
	dummy = &pList->headerNode;
	while (i < position)
	{
		dummy = dummy->pLink;
		i++;
	}
	tmp = dummy->pLink;
	dummy->pLink = dummy->pLink->pLink;
	free(tmp);
	(pList->currentElementCount)--;
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	ListNode	*dummy;
	int	i;

	i = 0;
	if (pList == NULL || position >= pList->currentElementCount || position < 0)
		return (FALSE);
	dummy = pList->headerNode.pLink;
	while (i < position)
	{
		dummy = dummy->pLink;
		i++;
	}
	return (dummy);	
}

void clearList(List *pList)
{
	ListNode *dummy;
	
	if(pList == NULL)
		return ;
	while(pList->currentElementCount)
	{
		dummy = pList->headerNode.pLink;
		pList->headerNode.pLink = pList->headerNode.pLink->pLink;
		free(dummy);
		(pList->currentElementCount)--;
	}
}

int getListLength(List *pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}