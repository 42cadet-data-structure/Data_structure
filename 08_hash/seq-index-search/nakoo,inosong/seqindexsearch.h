#ifndef SEQ_INDEX_SEARCH_SEQINDEXSEARCH_H
#define SEQ_INDEX_SEARCH_SEQINDEXSEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL -1
#define FALSE 0
#define TRUE 1

typedef struct IndexTableType {
    int position;
    int key;
} IndexTable;

int sequentialIndexSearch(int value[], int size,
                          IndexTable index[], int indexSize, int key);

int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key);

IndexTable *createIndexTable(int value[], int size, int indexSize);

void showIndexTable(IndexTable *pIndexTable, int indexSize);

#endif