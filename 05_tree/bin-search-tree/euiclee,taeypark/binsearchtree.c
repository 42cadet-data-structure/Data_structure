#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binsearchtree.h"

BinSearchTree *createBinSearchTree() {
    BinSearchTree *pReturn = NULL;
    pReturn = (BinSearchTree *) malloc(sizeof(BinSearchTree));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(BinSearchTree));
    pReturn->pRootNode = NULL;
    return pReturn;
}

int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode *node;
	BinSearchTreeNode **search;

	if (pBinSearchTree == NULL)
		return (FALSE);
	node = calloc(1, sizeof(BinSearchTreeNode));
	if (!node)
		return (FALSE);
	*node = element;
	search = &pBinSearchTree->pRootNode; 
	if (pBinSearchTree->pRootNode == NULL)
	{
		pBinSearchTree->pRootNode = node;
		return (TRUE);
	}
	while (*search)
	{
		if ((*search)->key == node->key)
		{
			free(node);
			return (FALSE);
		}
		else if ((*search)->key > node->key)
			search = &(*search)->pLeftChild;
		else
			search = &(*search)->pRightChild;
	}
	(*search) = node;
	return (TRUE);
}

int deleteElementBST(BinSearchTree *pBinSearchTree, int key) {
    BinSearchTreeNode *pDelNode = NULL, *pParentNode = NULL;
    BinSearchTreeNode *pPredecessor = NULL, *pSuccessor = NULL;
    BinSearchTreeNode *pChildNode = NULL;
    if (pBinSearchTree == NULL) return FALSE;
    pDelNode = pBinSearchTree->pRootNode;
    while (pDelNode != NULL) {
        if (pDelNode->key == key) {
            break;
        }
        pParentNode = pDelNode;
        if (pDelNode->key < key) {
            pDelNode = pDelNode->pRightChild;
        } else {
            pDelNode = pDelNode->pLeftChild;
        }
    }
    if (pDelNode == NULL) return FALSE;
    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = NULL;
            } else {
                pParentNode->pRightChild = NULL;
            }
        } else {
            pBinSearchTree->pRootNode = NULL;
        }
    } else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
        pPredecessor = pDelNode;
        pSuccessor = pDelNode->pLeftChild;
        while (pSuccessor->pRightChild != NULL) {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
        }

        pPredecessor->pRightChild = pSuccessor->pLeftChild;
        pSuccessor->pLeftChild = pDelNode->pLeftChild;
        pSuccessor->pRightChild = pDelNode->pRightChild;

        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pSuccessor;
            } else {
                pParentNode->pRightChild = pSuccessor;
            }
        } else {
            pBinSearchTree->pRootNode = pSuccessor;
        }
    } else {
        if (pDelNode->pLeftChild != NULL) {
            pChildNode = pDelNode->pLeftChild;
        } else {
            pChildNode = pDelNode->pRightChild;
        }

        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pChildNode;
            } else {
                pParentNode->pRightChild = pChildNode;
            }
        } else {
            pBinSearchTree->pRootNode = pChildNode;
        }
    }
    free(pDelNode);

    return TRUE;
}

BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key) {
    BinSearchTreeNode *pReturn = NULL;
    if (pBinSearchTree == NULL) return NULL;
    pReturn = searchInternalRecursiveBST(pBinSearchTree->pRootNode, key);
    return pReturn;
}

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key) {
    BinSearchTreeNode *pReturn = NULL;
    if (pTreeNode == NULL) return NULL;
    if (pTreeNode->key == key) pReturn = pTreeNode;
    else if (pTreeNode->key < key) pReturn = searchInternalRecursiveBST(pTreeNode->pRightChild, key);
    else pReturn = searchInternalRecursiveBST(pTreeNode->pLeftChild, key);
    return pReturn;
}

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key) {
    BinSearchTreeNode *pReturn = NULL;
    if (pBinSearchTree == NULL) return NULL;
    pReturn = pBinSearchTree->pRootNode;
    while (pReturn != NULL) {
        if (pReturn->key == key) {
            break;
        }
        if (pReturn->key < key) {
            pReturn = pReturn->pRightChild;
        } else {
            pReturn = pReturn->pLeftChild;
        }
    }
    return pReturn;
}

void deleteBinSearchTree(BinSearchTree *pBinSearchTree) {
    if (pBinSearchTree == NULL) return;
    deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
    free(pBinSearchTree);
}

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode) {
    if (pTreeNode == NULL) return;
    deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
    deleteBinSearchTreeInternal(pTreeNode->pRightChild);
    free(pTreeNode);
}