/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyo_koo_circularlist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:23:54 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/11 15:25:06 by hyojocho         ###   ########.fr       */
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

int removeElement(List *pList, int position)
{
}