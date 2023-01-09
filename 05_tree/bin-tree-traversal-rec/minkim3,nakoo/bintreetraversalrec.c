#include <stdio.h>
#include "bintree.h"
#include "bintreetraversalrec.h"

void preorderTraversalRecursiveBinTree(BinTree *pBinTree) 
{
    preorderTraversalRecursiveBinTreeNode(pBinTree->rootnode);
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *rootnode) 
{
    if (rootnode == NULL) 
        return ;
    printf("%c ", rootnode->data);
    preorderTraversalRecursiveBinTreeNode(rootnode->leftnode);
    preorderTraversalRecursiveBinTreeNode(rootnode->rightnode);
}

void inorderTraversalRecursiveBinTree(BinTree *pBinTree) 
{
    inorderTraversalRecursiveBinTreeNode(pBinTree->rootnode);
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *rootnode) 
{
    if (rootnode == NULL) 
        return ;
    inorderTraversalRecursiveBinTreeNode(rootnode->leftnode);
    printf("%c ", rootnode->data);
    inorderTraversalRecursiveBinTreeNode(rootnode->rightnode);
}

void postorderTraversalRecursiveBinTree(BinTree *pBinTree) 
{
    postorderTraversalRecursiveBinTreeNode(pBinTree->rootnode);
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *rootnode) 
{
    if (rootnode == NULL) 
        return ;
    postorderTraversalRecursiveBinTreeNode(rootnode->leftnode);
    postorderTraversalRecursiveBinTreeNode(rootnode->rightnode);
    printf("%c ", rootnode->data);
}