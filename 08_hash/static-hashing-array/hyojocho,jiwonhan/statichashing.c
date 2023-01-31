#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statichashing.h"

HashTable* createHashTable(int bucketSize)
{
    HashTable *ret;

    ret = malloc(sizeof(HashTable));
    if (!ret || bucketSize < 1)
        return (free(ret), NULL);
    if (ret)
        memset(ret, 0, sizeof(HashTable));
    ret->pElement = malloc(sizeof(HashElement) * bucketSize);
    if (!ret->pElement)
        return (free(ret), NULL);
    ret->bucketSize = bucketSize;
    memset(ret->pElement, 0, sizeof(HashElement) * bucketSize);
    return (ret);
}

int addElementSHT(HashTable* pHashTable, HashElement element)
{
    int i, tmp;

    if (!pHashTable)
        return (FALSE);
    i = hashFunction(element.key, pHashTable->bucketSize);
    if (i < 0 || i >= pHashTable->bucketSize)
        return (FALSE);
    tmp = i;
    do
    {
        if (isEmptyOrDeletedBucket(&(pHashTable->pElement[tmp])))
        {
            pHashTable->pElement[tmp] = element;
            pHashTable->pElement[tmp].status = USED;
            pHashTable->currentElementCount++;
            return (TRUE);
        }
        else
            tmp = (tmp + 1) % pHashTable->bucketSize;

    } while (tmp != i);
    return (FALSE);
}

int deleteElementHT(HashTable* pHashTable, char* key)
{
    HashElement *del = NULL;

    if (!pHashTable)
        return (FALSE);
    del = searchHT(pHashTable, key);
    if (del)
    {
        del->status = DELETED;
        del->key[0] = '\0';
        del->value = 0;
        pHashTable->currentElementCount--;
        return (TRUE);
    }
    return (FALSE);
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

int isEmptyBucket(HashElement* pElement)
{
    if (!pElement)
        return (FALSE);
    return (pElement->status == EMPTY);
}

int isEmptyOrDeletedBucket(HashElement* pElement)
{
    if (!pElement)
        return (FALSE);
    return (pElement->status == EMPTY || pElement->status == DELETED);
}

HashElement* searchHT(HashTable* pHashTable, char* key)
{
    int i, tmp;

    if (!pHashTable)
        return (NULL);
    i = hashFunction(key, pHashTable->bucketSize);
    if (i < 0)
        return (NULL);
    tmp = i;
    do
    {
        if (isEmptyBucket(&(pHashTable->pElement[tmp])))
            return (NULL);
        if (pHashTable->pElement[tmp].status == USED && \
            strcmp(pHashTable->pElement[tmp].key, key) == 0)
            return (&(pHashTable->pElement[tmp]));
        else
            tmp = (tmp + 1) % pHashTable->bucketSize;
    } while (tmp != i);
    return (NULL);
}

void displayHashTable(HashTable *pHashTable)
{
    if (!pHashTable)
        return ;
    printf("-----------------------------------------\n");
    for (int i=0;i<pHashTable->bucketSize;i++)
    {
        printf("[%d] ", i);
        if (pHashTable->pElement[i].key[0])
            printf("%s (%d->%d): %d\n", pHashTable->pElement[i].key, hashFunction(pHashTable->pElement[i].key, pHashTable->bucketSize), \
            i, pHashTable->pElement[i].value);
        else
            printf("Empty\n");
    }
    printf("-----------------------------------------\n");
}

int getElementCountHT(HashTable *pHashTable)
{
    return (pHashTable->currentElementCount);
}

void deleteHashTable(HashTable *pHashTable)
{
    if (!pHashTable)
        return ;
    if (pHashTable->pElement)
        free(pHashTable->pElement);
    free(pHashTable);
}
