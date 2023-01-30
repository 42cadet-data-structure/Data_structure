#include "statichashing.h"

HashTable *createHashTable(int bucketSize)
{
}

int addSHT(HashTable *pHashTable, HashElement element)
{
}

int deleteElementHT(HashTable *pHashTable, char *key)
{
}

int hashFunction(char *pKey, int bucketSize)
{
}

unsigned int stringToInt(char *pKey)
{
}

HashElement *searchHT(HashTable *pHashTable, char *key)
{
}

LinkedList *searchBucket(HashTable *pHashTable, char *key)
{
}

HashElement *searchSlot(LinkedList *pList, char *key, int *pPostion)
{
}

void deleteHashTable(HashTable *pHashTable)
{
}

void displayHashTable(HashTable *pHashTable)
{
}
