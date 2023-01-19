#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		return (NULL);
	tree->pRootNode = calloc(1, sizeof(BinTreeNode));
	if (!tree->pRootNode)
	{
		free(tree);
		return (NULL);
	}
	tree->pRootNode->data = rootNode.data;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	*node = element;
	pParentNode->pLeftChild = node;
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	*node = element;
	pParentNode->pRightChild = node;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode->pLeftChild == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode->pRightChild == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	deleteBinTreeNode(pBinTree->pRootNode);
	free (pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode->pLeftChild != NULL)
	{
		free(pNode->pLeftChild);
		pNode->pLeftChild = NULL;
	}
	if (pNode->pRightChild != NULL)
	{
		free(pNode->pRightChild);
		pNode->pRightChild = NULL;
	}
	free (pNode);
	pNode = NULL;
}
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		return (NULL);
	tree->pRootNode = calloc(1, sizeof(BinTreeNode));
	if (!tree->pRootNode)
	{
		free(tree);
		return (NULL);
	}
	tree->pRootNode->data = rootNode.data;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	*node = element;
	pParentNode->pLeftChild = node;
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	*node = element;
	pParentNode->pRightChild = node;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode->pLeftChild == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode->pRightChild == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	deleteBinTreeNode(pBinTree->pRootNode);
	free (pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode->pLeftChild != NULL)
	{
		free(pNode->pLeftChild);
		pNode->pLeftChild = NULL;
	}
	if (pNode->pRightChild != NULL)
	{
		free(pNode->pRightChild);
		pNode->pRightChild = NULL;
	}
	free (pNode);
	pNode = NULL;
}
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
		return (NULL);
	tree->pRootNode = calloc(1, sizeof(BinTreeNode));
	if (!tree->pRootNode)
	{
		free(tree);
		return (NULL);
	}
	tree->pRootNode->data = rootNode.data;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	*node = element;
	pParentNode->pLeftChild = node;
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *node;

	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node)
		return (NULL);
	*node = element;
	pParentNode->pRightChild = node;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode->pLeftChild == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode->pRightChild == NULL)
		return (NULL);
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	deleteBinTreeNode(pBinTree->pRootNode);
	free (pBinTree);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode->pLeftChild != NULL)
	{
		free(pNode->pLeftChild);
		pNode->pLeftChild = NULL;
	}
	if (pNode->pRightChild != NULL)
	{
		free(pNode->pRightChild);
		pNode->pRightChild = NULL;
	}
	free (pNode);
	pNode = NULL;
}
