/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublylist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:23:46 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/13 20:11:42 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"

List	*createLink()
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

int	addElement(List *pList, int position, ListNode node)
{
	ListNode	*newNode;
	ListNode	*prevNode;
	
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (!newNode)
		return (FALSE);
	*newNode = node;
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

void	displayList(List *pList)
{
	int			count;
	ListNode	*curNode;

	count = pList->currentElementCount;
	curNode = pList->headerNode.pRightLink;
	printf("displayList\n");
	while(count > 0)
	{
		printf("%d ", curNode->data);
		curNode = curNode->pRightLink;
		count--;
	}
	printf("\n");
}

int	removeElement(List *pList, int position)
{
	ListNode	*prevNode;
	ListNode	*delNode;
	
	if (position < 0 || position >= pList->currentElementCount)
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

ListNode	*getElement(List *pList, int position)
{
	ListNode	*curNode;
	
	if (position < 0 || position >= pList->currentElementCount)
	return (FALSE);
	curNode = pList->headerNode.pRightLink;
	while (position > 0)
	{
		curNode = curNode->pRightLink;
		position--;
	}
	return (curNode);
}

int	getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void	clearList(List *pList)
{
	ListNode	*curNode, *delNode;

	if (pList->headerNode.pRightLink == NULL)
		return ;
	curNode = pList->headerNode.pRightLink;
	while (curNode->pRightLink != &pList->headerNode)
	{
		delNode = curNode;
		curNode = curNode->pRightLink;
		free(delNode);
	}
	memset(pList, 0, sizeof(List));
}

void	deleteList(List *pList)
{
	clearList(pList);
	free(pList);
}
