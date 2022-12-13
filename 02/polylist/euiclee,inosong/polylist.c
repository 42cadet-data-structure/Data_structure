#include "linkedlist.h"
#include "polylist.h"

int addPolyNodeLast(List *pList, float coef, int degree)
{
    ListNode    node;

    node.coef = coef;
    node.degree = degree;
    addElement(pList, pList->currentElementCount, node);
    return (TRUE);
}

List *polyAdd(List *pListA, List *pListB)
{
	ListNode	*node_A;
	ListNode	*node_B;
	List		*list_c;

	list_c = createList();
	node_A = pListA->headerNode.next;
	node_B = pListB->headerNode.next;
	while (node_A != NULL && node_B != NULL)
	{
		if (node_A->degree > node_B->degree)
		{
			addPolyNodeLast(list_c, node_A->coef, node_A->degree);
			node_A = node_A->next;
		}
		else if (node_A->degree == node_B->degree)
		{
			addPolyNodeLast(list_c, node_A->coef + node_B->coef, node_A->degree);
			node_A = node_A->next;
			node_B = node_B->next;
		}
		else if (node_A->degree < node_B->degree)
		{
			addPolyNodeLast(list_c, node_B->coef, node_B->degree);
			node_B = node_B->next;
		}
	}
	while (node_A != NULL)
	{
		addPolyNodeLast(list_c, node_A->coef, node_A->degree);
		node_A = node_A->next;
	}
	while (node_B != NULL)
	{
		addPolyNodeLast(list_c, node_B->coef, node_B->degree);
		node_B = node_B->next;
	}
	return (list_c);
}

void displayPolyList(List *pList)
{
    int	i;

	i = 0;
	printf("displayPoluList\n");
    while (i < pList->currentElementCount)
	{
		printf("%.1fx^%d ", getElement(pList, i)->coef, getElement(pList, i)->degree);
		i++;
	}
	printf("\n");
}