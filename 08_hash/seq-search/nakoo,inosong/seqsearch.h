#ifndef SEQ_SEARCH_SEQSEARCH_H
#define SEQ_SEARCH_SEQSEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define FAIL -1

int sequentialSearchNotSorted(int *value, int size, int key);

int sequentialSearchAsendingSorted(int *value, int size, int key);

void showArray(int *value, int size);

#endif