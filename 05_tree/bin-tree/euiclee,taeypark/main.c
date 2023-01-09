#include <stdio.h>
#include "bintree.h"

void    leaks(void)
{
    system("leaks a.out | grep total");
}

int main() {
    BinTree *pBinTree = NULL;
    BinTreeNode node = {0,};
    BinTreeNode *pRootNode = NULL;
    BinTreeNode *parentNodeB, *parentNodeC;

    node.data = 'a';
    pBinTree = makeBinTree(node);

    atexit(leaks);
    if (pBinTree != NULL){
        pRootNode = getRootNodeBT(pBinTree);
        printf("%c ", pRootNode->data);
        node.data = 'b';
        parentNodeB = insertLeftChildNodeBT(pRootNode, node);
        node.data = '1';
        insertLeftChildNodeBT(parentNodeB, node);
        node.data = '2';
        insertRightChildNodeBT(parentNodeB, node);
        node.data = 'c';
        parentNodeC = insertRightChildNodeBT(pRootNode, node);
        node.data = '3';
        insertLeftChildNodeBT(parentNodeC, node);
        node.data = '4';
        insertRightChildNodeBT(parentNodeC, node);

        printf("%c ", getLeftChildNodeBT(pRootNode)->data);
        printf("%c ", getRightChildNodeBT(pRootNode)->data);

        printf("%c ", getLeftChildNodeBT(parentNodeB)->data);
        printf("%c ", getRightChildNodeBT(parentNodeB)->data);
        printf("%c ", getLeftChildNodeBT(parentNodeC)->data);
        printf("%c\n", getRightChildNodeBT(parentNodeC)->data);
        deleteBinTree(pBinTree);
    }
    return 0;
}