/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintsearchtree_ours.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:33:49 by hyeoan            #+#    #+#             */
/*   Updated: 2023/01/05 22:00:40 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binsearchtree.h"

BinSearchTree *createBinSearchTree()
{
	BinSearchTree	*search_tree;

	search_tree = (BinSearchTree *)malloc(sizeof(BinSearchTree));
	if (search_tree == NULL)
		return (NULL);
	memset(search_tree->pRootNode, 0, sizeof(BinSearchTreeNode));
	search_tree->pRootNode = NULL;

	return (search_tree);
}

int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
	BinSearchTreeNode	*parent = NULL;
	BinSearchTreeNode	*new_node = NULL;

	if (pBinSearchTree == NULL)
		return (FALSE);
	parent = pBinSearchTree->pRootNode;
	while (parent != NULL)
	{
		if (parent->key == element.key)
			return (FALSE);
		if (parent->key < element.key)
		{
			if (parent->pRightChild == NULL)
				break ;
			else
				parent = parent->pRightChild;
		}
		else if (parent->key > element.key)
		{
			if (parent->pLeftChild == NULL)
				break ;
			else
				parent = parent->pLeftChild;
		}
	}
	new_node (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
	if (new_node == NULL)
		return (FALSE);
	memset(new_node, 0, sizeof(BinSearchTree));
	if (parent == NULL)
		pBinSearchTree->pRootNode = new_node;
	else
	{
		if (parent->key < element.key)
			parent->pRightChild = new_node;
		else if (parent->key > element.key)
			parent->pLeftChild = new_node;
	}
	return (TRUE);
}

int deleteElementBST(BinSearchTree *pBinSearchTree, int key);

BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key);

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key);

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree *pBinSearchTree);

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode);
