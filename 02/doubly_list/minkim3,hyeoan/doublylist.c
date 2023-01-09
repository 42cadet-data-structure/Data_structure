#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"

List *createLink()
{
	List		*lst;

	lst = (List *)malloc(sizeof(List));
	if (lst == NULL)
		return (NULL);

	lst->currentElementCount = 0;
	lst->headerNode.pLeftLink = &(lst->headerNode);
	lst->headerNode.pRightLink = &(lst->headerNode);
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
	int			i;

	i = 0;
	if (pList == NULL || position > pList->currentElementCount || position < 0)
		return (FALSE);
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
		return (FALSE);
	
	*new_node = node;

	dummy = &(pList->headerNode);
	while (i < position)
	{
		dummy = dummy->pRightLink;
		i++;
	}

	new_node->pRightLink = dummy->pRightLink;
	new_node->pLeftLink = dummy;
	dummy->pRightLink->pLeftLink = new_node;
	dummy->pRightLink = new_node;

	pList->currentElementCount++;
	return (TRUE);
}

int removeElement(List *pList, int position)
{
	ListNode	*dummy;
	ListNode	*del_node;
	int	i;

	i = 0;
	if (pList == NULL || position >= pList->currentElementCount || position < 0)
		return (FALSE);
	dummy = &(pList->headerNode);
	while (i < position)
	{
		dummy = dummy->pRightLink;
		i++;
	}
	del_node = dummy->pRightLink;
	dummy->pRightLink = del_node->pRightLink;
	del_node->pLeftLink = dummy;
	free(del_node);
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
	dummy = &(pList->headerNode);
	while (i < position)
	{
		dummy = dummy->pRightLink;
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
	dummy = pList->headerNode.pRightLink;
	while(i < pList->currentElementCount)
	{
		printf("%d ", dummy->data);
		dummy = dummy->pRightLink;
		i++;
	}
	printf("\n");

}