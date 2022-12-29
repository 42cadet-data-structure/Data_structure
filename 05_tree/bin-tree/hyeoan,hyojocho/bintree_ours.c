/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintree_ours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeoan <hyeoan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:33:56 by hyojocho          #+#    #+#             */
/*   Updated: 2022/12/29 21:08:23 by hyeoan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree		*tree;

	tree = (BinTree *)malloc(sizeof(BinTree));
	if (tree == NULL)
		return (NULL);
	tree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (tree->pRootNode == NULL)
	{
		free(tree);
		return(NULL);
	}
	*tree->pRootNode = rootNode;

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
	BinTreeNode	*left_child_node;

	left_child_node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (left_child_node == NULL)
		return (NULL);
	*left_child_node = element;
	if (pParentNode->pLeftChild == NULL)
	{
		pParentNode->pLeftChild = left_child_node;
		return (pParentNode);
	}
	return (NULL);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode	*right_child_node;

	right_child_node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (right_child_node == NULL)
		return (NULL);
	*right_child_node = element;
	if (pParentNode->pRightChild == NULL)
	{
		pParentNode->pRightChild = right_child_node;
		return (pParentNode);
	}
	return (NULL);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return (NULL);
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (pNode == NULL)
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

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return ;
	if (pNode->pLeftChild != NULL)
		deleteBinTreeNode(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
	pNode = NULL;
}