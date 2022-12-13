/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:23:54 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/12 16:21:28 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circularlist.h"

List	*createList(void)
{
	List	*pList;

	pList = (List *)malloc(sizeof(List));
	if (!pList)
		return (NULL);
	memset(pList, 0, sizeof(List));
	return (pList);
}

void	deleteList(List *pList)
{
	free(pList);
}

int	addElement(List *pList, int position, ListNode node)
{
	ListNode	*new_node;
	ListNode	*tmp;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new_node = (ListNode *)malloc(sizeof(ListNode));
	if (!new_node)
		return (FALSE);
	new_node->data = node.data;
	tmp = pList->pLink;
	if (position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			pList->pLink = new_node;
			new_node->pLink = new_node;
		}
		else
		{
			while (tmp->pLink != pList->pLink)
				tmp = tmp->pLink;
			pList->pLink = new_node;
			new_node->pLink = tmp->pLink;
			tmp->pLink = new_node;
		}
	}
	else
	{
		while (position - 1 > 0)
		{
			tmp = tmp->pLink;
			position--;
		}
		new_node->pLink = tmp->pLink;
		tmp->pLink = new_node;
	}
	pList->currentElementCount++;
	return (TRUE);
}

void	displayList(List *pList)
{
	ListNode	*tmp;
	int			cnt;

	tmp = pList->pLink;
	cnt = pList->currentElementCount;
	printf("displayList\n");
	while (cnt > 0)
	{
		printf("%d ", tmp->data);
		tmp = tmp->pLink;
		cnt--;
	}
	printf("\n");
}

int	removeElement(List *pList, int position)
{
	ListNode	*tmp;
	ListNode	*removeNode;

	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	tmp = pList->pLink;
	if (position == 0)
	{
		if (pList->currentElementCount == 1)
		{
			free(pList->pLink);
			pList->pLink = NULL;
		}
		else
		{
			while (tmp->pLink != pList->pLink)
				tmp = tmp->pLink;
			tmp->pLink = pList->pLink->pLink;
			free(pList->pLink);
			pList->pLink = tmp->pLink;
		}
	}
	else
	{
		while (position - 1 > 0)
		{
			tmp = tmp->pLink;
			position--;
		}
		removeNode = tmp->pLink;
		tmp->pLink = removeNode->pLink;
		free(removeNode);
	}
	pList->currentElementCount--;
	return (TRUE);
}

ListNode	*getElement(List *pList, int position)
{
	ListNode	*tmp;

	tmp = pList->pLink;
	while (position > 0)
	{
		tmp = tmp->pLink;
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
