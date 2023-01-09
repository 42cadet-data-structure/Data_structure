#include "bintree.h"
#include <stdlib.h>
#include <string.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree	*tree;
	BinTreeNode *root;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		return (NULL);
	root = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!root)
		return (NULL);
	memset(root, 0, sizeof(BinTreeNode));
	*root = rootNode;
	tree->pRootNode = root;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (pBinTree == NULL)
		return (NULL);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;
	
	if (pParentNode == NULL || pParentNode->pLeftChild != NULL)
		return (NULL);
	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		return (NULL);
	memset(new, 0, sizeof(BinTreeNode));
	*new = element;
	pParentNode->pLeftChild = new;
	return (new);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new;

	if (pParentNode == NULL || pParentNode->pRightChild != NULL)
		return (NULL);
	new = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!new)
		return (NULL);
	memset(new, 0, sizeof(BinTreeNode));
	*new = element;
	pParentNode->pRightChild = new;
	return (new);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree == NULL)
		return ;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode *pNode)
{
	if (pNode == NULL)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}
