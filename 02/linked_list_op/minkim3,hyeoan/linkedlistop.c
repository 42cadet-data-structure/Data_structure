#include <stdio.h>
#include "linkedlist.h"
#include "linkedlistop.h"

void iterateLinkedList(List *pList)
{
	ListNode	*dummy;
	int			i;
	
	i = 0;
	if(pList == NULL)
		return ;
	dummy = pList->headerNode.pLink;
	while(i < pList->currentElementCount)
	{
		printf("[%d]- %d ", i, dummy->data);
		dummy = dummy->pLink;
		i++;
	}
	printf("\n");

}

void concatLinkedList(List *pListA, List *pListB)
{
	ListNode	*dummy;

	dummy = pListA->headerNode.pLink;
	while (dummy != NULL && dummy->pLink != NULL)
		dummy = dummy->pLink;
	dummy->pLink = pListB->headerNode.pLink;
	pListA->currentElementCount += pListB->currentElementCount;
	pListB->headerNode.pLink = NULL;
	pListB->currentElementCount = 0;
}

void reverseLinkedList(List *pList)
{
	ListNode	*dummy;
	ListNode	*before;
	ListNode	*current;

	if (pList == NULL)
		return ;
	before = NULL;
	current = NULL;
	dummy = pList->headerNode.pLink;
	while (dummy != NULL)
	{
		before = current;
		current = dummy;
		dummy = dummy->pLink;
		current->pLink = before;
	}
	pList->headerNode.pLink = current;
}