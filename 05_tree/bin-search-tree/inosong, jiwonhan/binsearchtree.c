#include "binsearchtree.h"

BinSearchTree *createBinSearchTree()
{
	BinSearchTree *tree;

	tree = calloc(1, sizeof(BinSearchTree));
	if (!tree)
		return (NULL);
	return (tree);
}

int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode *node;
	BinSearchTreeNode *search;

	if (pBinSearchTree == NULL)
		return (FALSE);
	node = calloc(1, sizeof(BinSearchTreeNode));
	if (!node)
		return (FALSE);
	*node = element;
	search = pBinSearchTree->pRootNode; 
	if (pBinSearchTree->pRootNode == NULL)
	{
		pBinSearchTree->pRootNode = node;
		return (TRUE);
	}
	while (search)
	{
		if (search->key == node->key)
		{
			free(node);
			return (FALSE);
		}
		else if (search->key > node->key)
		{
			if (search->pLeftChild == NULL)
			{
				search->pLeftChild = node;
				break ;
			}
			search = search->pLeftChild;
		}
		else
		{
			if (search->pRightChild == NULL)
			{
				search->pRightChild = node;
				break;
			}
			search = search->pRightChild;
		}
	}
	return (TRUE);
}

int deleteElementBST(BinSearchTree *pBinSearchTree, int key)
{
	BinSearchTreeNode *parent = NULL, *del_node;

	if (!pBinSearchTree)
		return (FALSE);
	del_node = pBinSearchTree->pRootNode;
	while (del_node)
	{
		if (del_node->key == key)
			break ;
		parent = del_node;
		if (del_node->key > key)
			del_node = del_node->pLeftChild;
		else
			del_node = del_node->pRightChild;
	}
	if (!del_node)
		return (FALSE);
	if (!del_node->pLeftChild && !del_node->pRightChild)
	{
		if (!parent)
			pBinSearchTree->pRootNode = NULL;
		else if (parent->pLeftChild->key == del_node->key)
			parent->pLeftChild = NULL;
		else	//parent->right == del_node
			parent->pRightChild = NULL;
	}
	else if (!del_node->pLeftChild)
	{
		if (!parent)
			pBinSearchTree->pRootNode = del_node->pRightChild;
		else if (parent->pLeftChild->key == del_node->key)
			parent->pLeftChild = del_node->pRightChild;
		else
			parent->pRightChild = del_node->pRightChild;
	}
	else if (!del_node->pRightChild)
	{
		if (!parent)
			pBinSearchTree->pRootNode = del_node->pLeftChild;
		else if (parent->pLeftChild->key == del_node->key)
			parent->pLeftChild = del_node->pLeftChild;
		else
			parent->pRightChild = del_node->pLeftChild;
	}
	else
	{
		BinSearchTreeNode *search, *pre_search;
		pre_search = del_node;
		search = del_node->pLeftChild;
		while (search->pRightChild)
		{
			pre_search = search;
			search = search->pRightChild;
		}
		pre_search->pRightChild = search->pLeftChild;
		search->pLeftChild = del_node->pLeftChild;
		search->pRightChild = del_node->pRightChild;
		if (!parent)
			pBinSearchTree->pRootNode = search;
		else if (parent->pLeftChild->key == del_node->key)
			parent->pLeftChild = search;
		else	//parent->right
			parent->pRightChild = search;
	}
	free(del_node);
	return (TRUE);
}

BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key)
{
	if (!pBinSearchTree)
		return (NULL);
	return (searchInternalRecursiveBST(pBinSearchTree->pRootNode, key));
}

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key)
{
	if (!pTreeNode)
		return (NULL);
	if (pTreeNode->key == key)
		return (pTreeNode);
	else if (pTreeNode->key > key)
		return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key));
	else
		return (searchInternalRecursiveBST(pTreeNode->pRightChild, key));
	
}

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key)
{
	BinSearchTreeNode	*search;

	if (pBinSearchTree == NULL)
		return (NULL);
	search = pBinSearchTree->pRootNode;
	
	while (search)
	{
		if (search->key == key)
			return (search);
		else if (search->key > key)
			search = search->pLeftChild;
		else
			search = search->pRightChild;
	}
	return (NULL);
}

void deleteBinSearchTree(BinSearchTree *pBinSearchTree)
{
	if (!pBinSearchTree)
		return ;
	deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
	free(pBinSearchTree);
}

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode)
{
	if (!pTreeNode->pLeftChild && !pTreeNode->pRightChild)
	{
		free(pTreeNode);
		pTreeNode = NULL;
		return ;
	}
	if (pTreeNode->pLeftChild)
		deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
	if (pTreeNode->pRightChild)
		deleteBinSearchTreeInternal(pTreeNode->pRightChild);
}
