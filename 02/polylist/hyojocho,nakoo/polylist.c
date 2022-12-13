/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   our_polylist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:23:18 by nakoo             #+#    #+#             */
/*   Updated: 2022/12/13 17:35:06 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include "polylist.h"
#include <stdio.h>
#include <stdlib.h>

int	addPolyNodeLast(List *pList, float coef, int degree)
{
	ListNode	newNode;
	
	newNode.coef = coef;
	newNode.degree = degree;
	addElement(pList, pList->currentElementCount, newNode);
	return (TRUE);
}

List	*polyAdd(List *pListA, List *pListB)
{
	List		*pListC;
	ListNode	*pNodeA;
	ListNode	*pNodeB;
	
	pListC = createList();
	pNodeA = pListA->headerNode.pLink;
	pNodeB = pListB->headerNode.pLink;
	while (pNodeA != NULL && pNodeB != NULL)
	{
		if (pNodeA->degree > pNodeB->degree)
		{
			addPolyNodeLast(pListC, pNodeA->coef, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}
		else if (pNodeA->degree == pNodeB->degree)
		{
			addPolyNodeLast(pListC, pNodeA->coef + pNodeB->coef, pNodeA->degree);
			pNodeA = pNodeA->pLink;
			pNodeB = pNodeB->pLink;
		}
		else
		{
			addPolyNodeLast(pListC, pNodeB->coef, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
	}
	while (pNodeA != NULL)
	{
		addPolyNodeLast(pListC, pNodeA->coef, pNodeA->degree);
		pNodeA = pNodeA->pLink;
	}
	while (pNodeB != NULL)
	{
		addPolyNodeLast(pListC, pNodeB->coef, pNodeB->degree);
		pNodeB = pNodeB->pLink;
	}
	return (pListC);
}

void	displayPolyList(List *pList)
{
	ListNode	*referNode;

	referNode = pList->headerNode.pLink;
	printf("displayPolyList\n");
	while (referNode != NULL)
	{
		printf("%.1fx^%d ", referNode->coef, referNode->degree);
		referNode = referNode->pLink;
	}
	printf("\n");
}
