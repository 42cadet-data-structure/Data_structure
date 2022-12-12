/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ours_doubly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:46 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/12 17:39:17 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"

List *createLink()
{
	List	*pList;
	
	pList = (List *)malloc(sizeof(List));
	if (!pList)
		return (FALSE);
	memset(pList, 0, sizeof(List));
	pList->headerNode.pRightLink = &pList->headerNode;
	pList->headerNode.pLeftLink = &pList->headerNode;
	return (pList);
}

int addElement(List *pList, int position, ListNode node)
{
	ListNode	*newNode;
	ListNode	*prevNode;
	
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (!newNode)
		return (FALSE);
	newNode->data = node.data;
	prevNode = &pList->headerNode;
	while (position > 0)
	{
		prevNode = prevNode->pRightLink;
		position--;
	}
	newNode->pRightLink = prevNode->pRightLink;
	prevNode->pRightLink = newNode;
	newNode->pLeftLink = prevNode;
	newNode->pRightLink->pLeftLink = newNode;
	pList->currentElementCount++;
	return (TRUE);
}

void displayList(List *pList)
{
	int			count;
	ListNode	*tmp;

	count = pList->currentElementCount;
	tmp = pList->headerNode.pRightLink;
	printf("displayList\n");
	while(count > 0)
	{
		printf("%d ", tmp->data);
		tmp = tmp->pRightLink;
		count--;
	}
	printf("\n");
}

int removeElement(List *pList, int position)
{
	ListNode	*prevNode;
	ListNode	*delNode;
	
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	prevNode = &pList->headerNode;
	while (position > 0)
	{
		prevNode = prevNode->pRightLink;
		position--;
	}
	delNode = prevNode->pRightLink;
	prevNode->pRightLink = delNode->pRightLink;
	delNode->pRightLink->pLeftLink = prevNode;
	free(delNode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode *getElement(List *pList, int position)
{
	ListNode	*tmp;
	
	if (position < 0 || position > pList->currentElementCount)
	return (FALSE);
	tmp = pList->headerNode.pRightLink;
	while (position > 0)
	{
		tmp = tmp->pRightLink;
		position--;
	}
	return (tmp);
}

int	getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void	clearList(List *pList)
{
	while (pList->currentElementCount > 0)
	{
		removeElement(pList, 0);
	}
}

void	deleteList(List *pList)
{
	free(pList);
	pList = NULL;
}
