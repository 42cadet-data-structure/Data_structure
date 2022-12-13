#include "linkedlist.h"
#include "linkedlistop.h"

void iterateLinkedList(List *pList)
{
	ListNode	*node;
	int			i;

	i = 0;
	node = pList->headerNode.next;
	printf("iterateLinkedList\n");
	while (node != NULL)
	{
		printf("[%d]%d ", i, node->data);
		i++;
		node = node->next;
	}
	printf("\n");
}

void concatLinkedList(List *pListA, List *pListB)
{
	ListNode	*last_node;

	last_node = pListA->headerNode.next;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = pListB->headerNode.next;
	pListA->currentElementCount += pListB->currentElementCount;

	pListB->headerNode.next = NULL;
	pListB->currentElementCount = 0;
}

void reverseLinkedList(List *pList)
{
	ListNode	*node;
	ListNode	*curent_node;
	ListNode	*pre_node;

	node = NULL;
	curent_node = NULL;
	pre_node = NULL;
	node = pList->headerNode.next;
	while (node != NULL)
	{
		pre_node = curent_node;
		curent_node = node;
		node = node->next;
		curent_node->next = pre_node;
	}
	pList->headerNode.next = curent_node;
}