#ifndef POLYLIST_POLYLIST_H
#define POLYLIST_POLYLIST_H

#include "linkedlist.h"

int addPolyNodeLast(List *pList, float coef, int degree);

List *polyAdd(List *pListA, List *pListB);

void displayPolyList(List *pList);


#endif
