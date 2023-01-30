#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "statichashing.h"

HashTable* createHashTable(int bucketSize)
{
    HashTable   *hash;

    hash = (HashTable *)malloc(sizeof(HashTable));
    if (hash == NULL)
        return (NULL);
    hash->pElement = (HashElement *)calloc(bucketSize, sizeof(HashElement));
    if (hash->pElement == NULL)
        return (free(hash), NULL);
    hash->bucketSize = bucketSize;
    hash->currentElementCount = 0;
    return (hash);
}

int addElementSHT(HashTable* pHashTable, HashElement element)
{
    int add_idx;
    int check_idx;

    if (pHashTable->currentElementCount >= pHashTable->bucketSize)
        return (0);
    add_idx = hashFunction(element.key, pHashTable->bucketSize);
    while (1)
    {
        if (isEmptyBucket(&pHashTable->pElement[check_idx])
            && strcmp(pHashTable->pElement[check_idx].key, element.key) != 0)
        {
            element.status = USED;
            pHashTable->pElement[check_idx] = element;
            break ;
        }
        check_idx = (check_idx + 1) % pHashTable->bucketSize;
        if (check_idx == add_idx)
            return (0);
    }
    pHashTable->currentElementCount++;
    return (1);
}

int deleteElementHT(HashTable* pHashTable, char* key)
{
    HashElement *del_node;

    del_node = searchHT(pHashTable, key);
    if (del_node == NULL)
        return (0);
    del_node->status = EMPTY;
    pHashTable->currentElementCount--;
    return (1);
}

int hashFunction(char *pKey, int bucketSize)
{
    return (stringToInt(pKey) % bucketSize);
}

unsigned int stringToInt(char *pKey)
{
    int ret;
    int cur_pid;

    cur_pid = getpid();
    ret = 0;
    while (*pKey)
    {
        ret += cur_pid / *pKey;
        pKey++;
    }
    return (ret);
}

int isEmptyBucket(HashElement* pElement)
{
    return (pElement->status == EMPTY);
}

int isEmptyOrDeletedBucket(HashElement* pElement)
{
    return (pElement->status == EMPTY || pElement->status == DELETED);
}

HashElement* searchHT(HashTable* pHashTable, char* key)
{
    int key_idx;
    int check_idx;

    if (pHashTable->currentElementCount <= 0)
        return (0);
    key_idx = hashFunction(key, pHashTable->bucketSize);
    check_idx = key_idx;
    while (1)
    {
        if (pHashTable->pElement[check_idx].status == USED
            && strcmp(pHashTable->pElement[check_idx].key, key) == 0)
            break ;
        check_idx = (check_idx + 1) % pHashTable->bucketSize;
        if (check_idx == key_idx)
            return (0);
    }
    return (&pHashTable->pElement[check_idx]);
}

void displayHashTable(HashTable *pHashTable)
{
    int         print_idx;
    HashElement print_node;

    printf("------------------------------------------\n");
    print_idx = 0;
    while (print_idx < pHashTable->bucketSize)
    {
        print_node = pHashTable->pElement[print_idx];
        if (isEmptyBucket(&print_node))
            printf("[%d],Empty\n", print_idx);
        else
            printf("[%d],%s, \n\thash : %d, value : %d\n",
                print_idx, print_node.key,
                    hashFunction(print_node.key, pHashTable->bucketSize),
                        print_node.value);
        print_idx++;
    }
    printf("------------------------------------------\n");
}

int getElementCountHT(HashTable *pHashTable)
{
    return (pHashTable->currentElementCount);
}

void deleteHashTable(HashTable *pHashTable)
{
    free(pHashTable->pElement);
    pHashTable->pElement = NULL;
    free(pHashTable);
}

// hashtable[10];
// "abc" -> 1;
// hashtable[1] = "abc";
// "qwe" -> 1;
// "  "   -> [0 ~ hashtablesize)
// hashtable[2] = "qwe";
// O(1)
// O(n)
