/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_linkedlist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:12:34 by nakoo             #+#    #+#             */
/*   Updated: 2022/12/08 20:42:57 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

List	*createList(void)
{
	List	*lst;
	
	lst = (List *)malloc(sizeof(List));
	if (!lst)
		return (NULL);
	lst->headerNode.pLink = NULL;
	lst->currentElementCount = 0;
	return (lst);
}

void	deleteList(List *pList)
{
	free(pList);
	pList = NULL;
}

int	addElement(List *pList, int position, ListNode node)
{
	ListNode	*newNode;
	ListNode	*tmp;

	if (pList == NULL || position < 0 || pList->currentElementCount < position)
		return (FALSE);
	newNode = (ListNode *)malloc(sizeof(ListNode));
	if (!newNode)
		return (FALSE);
	newNode->data = node.data;
	tmp = &pList->headerNode;
	while (position > 0)
	{
		tmp = tmp->pLink;
		position--;
	}
	newNode->pLink = tmp->pLink;
	tmp->pLink = newNode;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeElement(List *pList, int position)
{
	ListNode	*prevPlist;
	ListNode	*removeNode;
	
	if (pList == NULL || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	prevPlist = &pList->headerNode;
	while (position > 0)
	{
		prevPlist = prevPlist->pLink;
		position--;
	}
	removeNode = prevPlist->pLink;
	prevPlist->pLink = prevPlist->pLink->pLink;
	free(removeNode);
	removeNode = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

ListNode	*getElement(List *pList, int position)
{
	ListNode	*tmp;
	
	tmp = &pList->headerNode;
	while (position >= 0)
	{
		tmp = tmp->pLink;
		position--;
	}
	return (tmp);
}

void	clearList(List *pList)
{
	ListNode	*tmp;
	ListNode	*deleteNode;

	tmp = pList->headerNode.pLink;
	while (tmp)
	{
		deleteNode = tmp;
		tmp = tmp->pLink;
		free(deleteNode);
		deleteNode = NULL;
	}
	pList->headerNode.pLink = NULL;
}

int	getListLength(List *pList)
{
	return (pList->currentElementCount);
}

void displayList(List *pList)
{
	ListNode	*tmp;
	
	tmp = pList->headerNode.pLink;
	printf("displayList\n");
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->pLink;
	}
	printf("\n");
}