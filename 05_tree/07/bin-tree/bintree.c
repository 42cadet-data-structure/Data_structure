#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree		*tree;

	if (!(tree = (BinTree *)malloc(sizeof(BinTree))))
		return (NULL);
	if (!(tree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (free(tree), NULL);
	*tree->pRootNode = rootNode;
	tree->pRootNode->pLeftChild = NULL;
	tree->pRootNode->pRightChild = NULL;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode	*node;

	if (!(node = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
	*node = element;
	pParentNode->pLeftChild = node;
	return (node);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode	*node;

	if (!(node = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
		return (NULL);
	*node = element;
	pParentNode->pRightChild = node;
	return (node);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	deleteBinTreeNode(pBinTree->pRootNode);
	pBinTree->pRootNode = NULL;
	free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode != NULL)
	{
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}