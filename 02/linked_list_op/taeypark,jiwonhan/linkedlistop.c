#include "linkedlist.h"
#include "linkedlistop.h"

void reverseLinkedList(List *pList)
{
	int			i = 0;
	ListNode	*pNode, *preNode, *firstNode;
	if (pList->currentElementCount <= 1)
		return ;
	firstNode = getElement(pList, pList->currentElementCount - 1);
	while (++i < pList->currentElementCount)
	{
		pNode = getElement(pList, pList->currentElementCount - i);
		preNode = getElement(pList, pList->currentElementCount - i - 1);
		pNode->pLink = preNode;
	}
	pNode = getElement(pList, 0);
	pNode->pLink = NULL;
	pList->headerNode.pLink = firstNode;
}