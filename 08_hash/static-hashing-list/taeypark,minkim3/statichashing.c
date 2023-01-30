#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "hashingdef.h"
#include "hashinglinkedlist.h"
#include "statichashing.h"

HashTable* createHashTable(int bucketSize)
{
    HashTable   *hash;

    hash = (HashTable *)malloc(sizeof(HashTable));
    if (hash == NULL)
        return (NULL);
    hash->ppElement = (LinkedList **)calloc(bucketSize, sizeof(LinkedList *));
    if (hash->ppElement == NULL)
        return (free(hash), NULL);
    hash->bucketSize = bucketSize;
    hash->currentElementCount = 0;
    return (hash);
}

int addSHT(HashTable* pHashTable, HashElement element)
{
    ListNode    *move;
    ListNode    to_add = {0, };
    int         add_idx;

    add_idx = hashFunction(element.key, pHashTable->bucketSize);
    to_add.data = element;
    addLLElement(pHashTable->ppElement[add_idx], 0, to_add);
    pHashTable->currentElementCount++;
    return (1);
}

int deleteElementHT(HashTable* pHashTable, char* key)
{
    int         del_idx;
    int         del_pos;
    ListNode    *move;

    del_pos = 0;
    del_idx = hashFunction(key, pHashTable->bucketSize);
    move = pHashTable->ppElement[del_idx]->headerNode.pLink;
    while (move && strcmp(move->data.key, key) != 0)
    {
        del_pos++;
        move = move->pLink;
    }
    if (move == NULL)
        return (0);
    removeLLElement(pHashTable->ppElement[del_idx], del_pos);
    return (0);
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

HashElement* searchHT(HashTable* pHashTable, char* key)
{
    int         idx;
    ListNode    *move;

    idx = hashFunction(key, pHashTable->bucketSize);
    move = pHashTable->ppElement[idx]->headerNode.pLink;
    while (move && strcmp(move->data.key, key) != 0)
        move = move->pLink;
    return (&move->data);
}

void displayHashTable(HashTable *pHashTable)
{
    int         print_idx;
    HashElement print_node;
    ListNode    *move;

    printf("------------------------------------------\n");
    print_idx = 0;
    while(print_idx < pHashTable->bucketSize)
    {
        printf("[%d],", print_idx);
        move = pHashTable->ppElement[print_idx]->headerNode.pLink;
        if (move == NULL)
            printf("Empty");
        else
        {
            while (move)
            {
                printf("\n\t%s, value : %d",
                    move->data.key, move->data.value);
                move = move->pLink;
            }
        }
        printf("\n");
        print_idx++;
    }
    printf("------------------------------------------\n");
}

void deleteHashTable(HashTable *pHashTable)
{
    int del_idx;

    del_idx = 0;
    while (del_idx < pHashTable->bucketSize)
    {
        deleteLinkedList(pHashTable->ppElement[del_idx]);
        del_idx++;
    }
    free(pHashTable->ppElement);
    pHashTable->ppElement = NULL;
    free(pHashTable);
}

