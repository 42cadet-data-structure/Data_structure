#include "linkedlist.h"
#include "polylist.h"
#include <stdio.h>

int addPolyNodeLast(List *pList, float coef, int degree) {
    ListNode node;
    node.coef = coef;
    node.degree = degree;
    addElement(pList, getListLength(pList), node);
    return FALSE;
}

List *polyAdd(List *pListA, List *pListB)
{
	List		*pList;
    ListNode	*pListANode;
	ListNode	*pListBNode;

	pList = createList();
	if (pListA == NULL || pListB == NULL || pList == NULL)
		return NULL;
    pListANode = pListA->headerNode.pLink;
    pListBNode = pListB->headerNode.pLink;
	while (pListANode != NULL && pListBNode != NULL)
	{
		if ((pListANode->degree) == (pListBNode->degree))
		{
			addPolyNodeLast(pList, (pListANode->coef + pListBNode->coef), pListANode->degree);
			pListANode = pListANode->pLink;
			pListBNode = pListBNode->pLink;
		}
		else
		{
			if ((pListANode->degree) > (pListBNode->degree))
			{
				addPolyNodeLast(pList, pListANode->coef, pListANode->degree);
				pListANode = pListANode->pLink;
			}
			else
			{
				addPolyNodeLast(pList, pListBNode->coef, pListBNode->degree);
				pListBNode = pListBNode->pLink;
			}
		}
	}
	while (pListBNode != NULL) 
	{
		addPolyNodeLast(pList, pListBNode->coef, pListBNode->degree);
		pListBNode = pListBNode->pLink;
    }
    while (pListANode != NULL) 
	{
		addPolyNodeLast(pList, pListANode->coef, pListANode->degree);
		pListANode = pListANode->pLink;
    }
	return(pList);
}

void displayPolyList(List *pList)
{
    ListNode *dummy;
	int	i;

    if (pList == NULL)
		return ;
	dummy = pList->headerNode.pLink;
	i = 0;
	while (i < pList->currentElementCount)
	{
		if (dummy != NULL)
			printf("%5.1fx^%d", dummy->coef, dummy->degree);
		dummy = dummy->pLink;
		i++;
	}
    printf("\n");
}