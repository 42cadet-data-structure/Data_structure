#include "linkedlist.h"
#include "polylist.h"
#include <stdlib.h>

int addPolyNodeLast(List *pList, float coef, int degree)
{
    if (pList == NULL) 
		return FALSE;
    ListNode *pNewNode = (ListNode *)malloc(sizeof(ListNode));
    if (pNewNode == NULL) 
		return FALSE;
    pNewNode->coef = coef;
	pNewNode->degree = degree;
	pNewNode->pLink = pList->headerNode.pLink;
	pList->headerNode.pLink = pNewNode;
    pList->currentElementCount++;
	return (TRUE);
}

List *polyAdd(List *pListA, List *pListB)
{
	List		*new_list = createList();
	ListNode	*move;

	if (!new_list)
		return (FALSE);
	move = &pListA->headerNode;
	while (move->pLink)
	{
		addPolyNodeLast(new_list, move->coef, move->degree);
		move = move->pLink;
	}
	move = &pListB->headerNode;
	while (move->pLink)
	{
		addPolyNodeLast(new_list, move->coef, move->degree);
		move = move->pLink;
	}
	return (new_list);
}

void displayPolyList(List *pList)
{
	ListNode	*move;

	move = &pList->headerNode;
	while (move->pLink)
	{
		printf("(%f, %d) ", move->coef, move->degree);
		move = move->pLink;
	}
	printf("\n");
}
