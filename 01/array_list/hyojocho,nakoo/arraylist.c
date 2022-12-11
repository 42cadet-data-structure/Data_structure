/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoo <nakoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:24:18 by nakoo             #+#    #+#             */
/*   Updated: 2022/12/07 20:24:19 by nakoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "arraylist.h"

List	*createList(int maxElementCount)
{
	List	*pList;

	pList = (List *)malloc(sizeof(List));
	if (!pList)
		return (0);
	pList->pElement = (ListNode *)malloc(sizeof(ListNode) * maxElementCount);
	if (!pList->pElement)
		return (0);
	pList->currentElementCount = 0;
	pList->maxElementCount = maxElementCount;
	return (pList);
}

int	isFull(List *pList)
{
	if (pList->currentElementCount == pList->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int	addElement(List *pList, int position, ListNode element)
{
	int	tmp;

	if (isFull(pList) || position < 0 || pList->currentElementCount < position)
		return (FALSE);
	tmp = pList->currentElementCount - 1;
	while (position <= tmp)
	{
		pList->pElement[tmp + 1].data = pList->pElement[tmp].data;
		tmp--;
	}
	pList->pElement[position].data = element.data;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeElement(List *pList, int position)
{
	int	tmp;

	if (pList->currentElementCount == 0 || position < 0 || pList->currentElementCount <= position)
		return (FALSE);
	tmp = position;
	while ((pList->currentElementCount) - 1 > tmp)
	{
		pList->pElement[tmp].data = pList->pElement[tmp + 1].data;
		tmp++;
	}
	pList->pElement[pList->currentElementCount - 1].data = 0;
	(pList->currentElementCount)--;
	return (TRUE);
}

void	clearList(List *pList)
{
	pList->currentElementCount = 0;
}

void	deleteList(List *pList)
{
	free(pList->pElement);
	pList->pElement = NULL;
	free(pList);
	pList = NULL;
}

void	displayList(List *pList)
{
	int	i;

	i = 0;
	printf("dispalyList\n");
	while (i < pList->currentElementCount)
	{
		printf("%d ", pList->pElement[i].data);
		i++;
	}
	printf("\n");
}

ListNode	*getElement(List *pList, int position)
{
	return (&pList->pElement[position]);
}

int	getListLength(List *pList)
{
	return (pList->currentElementCount);
}
