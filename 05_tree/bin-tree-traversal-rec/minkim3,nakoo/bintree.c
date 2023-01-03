//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


BinTree *createBinTree(BinTreeNode node) {
    BinTree *pReturn = NULL;
    pReturn = (BinTree *) malloc(sizeof(BinTree));
    if (pReturn == NULL)return NULL;
    pReturn->rootnode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pReturn->rootnode == NULL) {
        free(pReturn);
        return NULL;
    }
    *(pReturn->rootnode) = node;
    pReturn->rootnode->leftnode = NULL;
    pReturn->rootnode->rightnode = NULL;
    return pReturn;
}

BinTreeNode *getRootNode(BinTree *pBinTree){
    if (pBinTree == NULL) return NULL;
    return pBinTree->rootnode;
}

BinTreeNode *addLeftNode(BinTreeNode *pNode, BinTreeNode node){
    BinTreeNode *pNewNode = NULL;
    if (pNode == NULL) return NULL;
    if (pNode->leftnode != NULL) return NULL;
    pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if (pNewNode == NULL) return NULL;
    *(pNewNode) = node;
    pNewNode->leftnode = NULL;
    pNewNode->rightnode = NULL;
    pNode->leftnode = pNewNode;
    return pNewNode;
}

BinTreeNode *addRightNode(BinTreeNode *pNode, BinTreeNode node){
    BinTreeNode *pNewNode = NULL;
    if (pNode == NULL) return NULL;
    if (pNode->rightnode != NULL) return NULL;
    pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if (pNewNode == NULL) return NULL;
    *(pNewNode) = node;
    pNewNode->leftnode = NULL;
    pNewNode->rightnode = NULL;
    pNode->rightnode = pNewNode;
    return pNewNode;
}

BinTreeNode *getLeftNode(BinTreeNode *pNode){
    if (pNode == NULL) return NULL;
    return pNode->leftnode;
}

BinTreeNode *getRightNode(BinTreeNode *pNode){
    if (pNode == NULL) return NULL;
    return pNode->rightnode;
}

void deleteBinTree(BinTree *pBinTree){
    if (pBinTree == NULL) return;
    deleteBinTreeNode(pBinTree->rootnode);
    free(pBinTree);

}

void deleteBinTreeNode(BinTreeNode *pNode)
{
    if (pNode == NULL)
        return ;
    deleteBinTreeNode(pNode->leftnode);
    deleteBinTreeNode(pNode->rightnode);
    free(pNode);
}