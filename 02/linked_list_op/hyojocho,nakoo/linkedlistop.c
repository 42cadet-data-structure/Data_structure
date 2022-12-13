/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_ours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:08:15 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/12 19:38:45 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "linkedlistop.h"

void iterateLinkedList(List *pList)
{
	ListNode	*tmp;
	int			count;

	count = 0;
	tmp = pList->headerNode.pLink;
	printf("iterateLinkedList\n");
	while (tmp != NULL)
	{
		printf("[%d] - %d ", count, tmp->data);
		tmp = tmp->pLink;
		count++;
	}
	printf("\n");
}

void concatLinkedList(List *pListA, List *pListB)
{
	ListNode	*tmp;

	tmp = pListA->headerNode.pLink;
	printf("concatLinkedList\n");
	while (tmp->pLink != NULL)
		tmp = tmp->pLink;
	tmp->pLink = pListB->headerNode.pLink;
	memset(pListB, 0, sizeof(List));
}

void	reverseLinkedList(List *pList)
{
	ListNode	*curNode = NULL;
	ListNode	*prevNode = NULL;
	ListNode	*tmp = NULL;

	tmp = pList->headerNode.pLink;
	curNode = NULL;
	prevNode = NULL;
	printf("reverseLinkedList\n");
	while (tmp != NULL)
	{
		prevNode = curNode;
		curNode = tmp;
		tmp = tmp->pLink;
		curNode->pLink = prevNode;
	}
	pList->headerNode.pLink = curNode;
}
