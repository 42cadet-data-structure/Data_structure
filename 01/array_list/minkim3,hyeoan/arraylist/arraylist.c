#include "arraylist.h"

List	*createList(int maxElementCount)
{
	List	*array;

	array = (List *)malloc(sizeof(List));
	if (array == NULL)
		return (NULL);
	array->pElement = (ListNode *)malloc(sizeof(ListNode) * maxElementCount);
	if ((array->pElement) == NULL)
		return (NULL);
	array->maxElementCount = maxElementCount;
	array->currentElementCount = 0;
	return (array);
}

void	deleteList(List *pList)
{
	free(pList->pElement);
	free(pList);
}

int	isFull(List *pList)
{
	if (pList != NULL)
		if ((pList->currentElementCount) == (pList->maxElementCount))
			return (TRUE);
	return (FALSE);
}

int addElement(List *pList, int position, ListNode element)
{
	int	i;

	i = (pList->currentElementCount);
	if ((pList == NULL || position < 0 || ((pList->currentElementCount) < position) || isFull(pList)))
		return (FALSE);
	while (position < i)
	{
		pList->pElement[i] = pList->pElement[i - 1];
		i--;
	}
	(pList->currentElementCount) += 1;
	pList->pElement[position] = element;
	return (TRUE); 
}

int removeElement(List *pList, int position)
{
	int	i;
	i = (pList->maxElementCount) - 1;	
	if (pList == NULL || position < 0 || ((pList->currentElementCount) <= position))
		return (FALSE);
	while (position < i)
	{
		pList->pElement[position] = pList->pElement[position + 1];
		position++;
	}
	pList->pElement[i].data = 0;
	(pList->currentElementCount) -= 1;
	return (TRUE);
}

ListNode* getElement(List *pList, int position)
{
	if (pList == NULL || position < 0 || ((pList->currentElementCount) <= position))
		return (NULL);
	return (&(pList->pElement[position]));
}

void displayList(List *pList)
{
	int	i;

	i = 0;
	if (pList == NULL)
		return ;
	while(i < pList->currentElementCount)
	{
		printf("%d\n", pList->pElement[i].data);
		i++;	
	}	
}

void clearList(List *pList)
{	
	int	i;

	i = 0;
	if (pList == NULL)
		return ;
	while (i < (pList->maxElementCount))
	{
		pList->pElement[i].data = 0;
		i++;
	}
	pList->currentElementCount = 0;
}

int getListLength(List *pList)
{
	if (pList == NULL)
		return FALSE;
	return (pList->currentElementCount);
}
