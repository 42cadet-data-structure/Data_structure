#ifndef BIN_SEARCH_BINSEARCH_H
#define BIN_SEARCH_BINSEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL -1
#define FALSE 0
#define TRUE 1

int binarySearchRecursive(int *value, int start, int end, int key);

int binarySearch(int *value, int start, int end, int key);

#endif