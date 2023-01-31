#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashingdef.h"
#include "hashinglinkedlist.h"
#include "statichashing.h"

HashTable *createHashTable(int bucketSize)
{
    HashTable *ret;

    ret = malloc(sizeof(HashTable));
    if (!ret || bucketSize < 1)
        return (free(ret), NULL);
    if (ret)
        memset(ret, 0, sizeof(HashTable));
    ret->ppElement = (LinkedList **)calloc(bucketSize, sizeof(LinkedList *));
    if (!ret->ppElement)
        return (free(ret), NULL);
    ret->bucketSize = bucketSize;
	for(int i=0;i<bucketSize;i++)
	{
		ret->ppElement[i] = createLinkedList();
		if (!ret->ppElement[i])
		{
			for(int j=0;j<i - 1;j++)
				free(ret->ppElement[j]);
			free(ret->ppElement);
			free(ret);
			return (NULL);
		}
	}
    return (ret);
}

int addSHT(HashTable *pHashTable, HashElement element)
{
	ListNode    *node = NULL;
	ListNode	new = {0, };
    int         i;

    i = hashFunction(element.key, pHashTable->bucketSize);
    new.data = element;
    addLLElement(pHashTable->ppElement[i], 0, new);
    pHashTable->currentElementCount++;
    return (1);
}

int deleteElementHT(HashTable *pHashTable, char *key)
{
	int         delete_i;
    int         delete_position = 0;
    ListNode    *node;

    delete_i = hashFunction(key, pHashTable->bucketSize);
    node = pHashTable->ppElement[delete_i]->headerNode.pLink;
    while (node && strcmp(node->data.key, key) != 0)
    {
        delete_position++;
        node = node->pLink;
    }
    if (node)
    	removeLLElement(pHashTable->ppElement[delete_i], delete_position);
    return (0);
}

int hashFunction(char *pKey, int bucketSize)
{
    int ret = -1;

    if (!pKey || bucketSize <= 0)
        return (ret);
    ret = stringToInt(pKey);
    ret %= bucketSize;
    return (ret);
}

unsigned int stringToInt(char *pKey)
{
    int ret = 0;

    while (*pKey != '\0')
        ret = (ret * 31) + *pKey++;
    if (ret < 0)
        ret *= -1;
    return (ret);
}

HashElement *searchHT(HashTable *pHashTable, char *key)
{
	LinkedList *bucket = NULL;

	if (!pHashTable)
		return (NULL);
	bucket = searchBucket(pHashTable, key);
	if (bucket)
		return (searchSlot(bucket, key, 0));
	return (NULL);
}

LinkedList *searchBucket(HashTable *pHashTable, char *key)
{
	int bucket_i = 0;
	if (pHashTable == NULL)
		return (NULL);
	bucket_i = hashFunction(key, pHashTable->bucketSize);
	if (bucket_i >= 0)
		return pHashTable->ppElement[bucket_i];
	return (NULL);
}

HashElement *searchSlot(LinkedList *pList, char *key, int *pPostion)
{
	ListNode *node = NULL;

	if (!pList || !pPostion)
		return (NULL);
	node = getLLElement(pList, 0);
	while (node)
	{
		if (strcmp(node->data.key, key) == 0)
			return (&(node->data));
		node = node->pLink;
		++pPostion;
	}
	return (NULL);
}

void deleteHashTable(HashTable *pHashTable)
{
	int i = 0;

    while (i < pHashTable->bucketSize)
        deleteLinkedList(pHashTable->ppElement[i++]);
    free(pHashTable->ppElement);
    pHashTable->ppElement = NULL;
    free(pHashTable);
}

void displayHashTable(HashTable *pHashTable)
{
	LinkedList *pList = NULL;
	ListNode	*pNode = NULL;
	int j;

	if (!pHashTable)
		return ;
	printf("------------------------------------------\n");
	for(int i=0;i<pHashTable->bucketSize;i++)
	{
		printf("[%d] ", i);
		pList = pHashTable->ppElement[i];
		if (!getLinkedListLength(pList))
			printf("Empty");
		else
		{
			for (j = 0;j < getLinkedListLength(pList);j++)
			{
				pNode = getLLElement(pList, j);
				if (pNode)
					printf("(%s %d)\t", pNode->data.key, pNode->data.value);
			}
		}
		printf("\n");
	}
    printf("------------------------------------------\n");
}