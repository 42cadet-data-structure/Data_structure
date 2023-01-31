#ifndef AVL_TREE_AVLDEF_H
#define AVL_TREE_AVLDEF_H

#include "avllinkedstack.h"
#include "avltree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define VALUE_SIZE 100

typedef struct AVLTreeNodeDataType {
    int key;
    char value[VALUE_SIZE + 1];
} AVLTreeNodeData;

typedef struct AVLTreeNodeType {
    AVLTreeNodeData data;
    int balance;
    int height;
    struct AVLTreeNodeType *pLeftChild;
    struct AVLTreeNodeType *pRightChild;
} AVLTreeNode;

#endif