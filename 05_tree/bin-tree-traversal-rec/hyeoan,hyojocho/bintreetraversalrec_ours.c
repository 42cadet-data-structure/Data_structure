/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintreetraversalrec_ours.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:24:28 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/03 12:25:45 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bintree.h"
#include "bintreetraversalrec.h"

void preorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
    preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode)
{
    if (pRootNode == NULL) return;
    printf("%c ", pRootNode->data);
    preorderTraversalRecursiveBinTreeNode(pRootNode->pLeftNode);
    preorderTraversalRecursiveBinTreeNode(pRootNode->pRightNode);
}

void inorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
    inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode)
{
    if (pRootNode == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pRootNode->pLeftNode);
    printf("%c ", pRootNode->data);
    inorderTraversalRecursiveBinTreeNode(pRootNode->pRightNode);
}

void postorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
    postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode)
{
    if (pRootNode == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pRootNode->pLeftNode);
    postorderTraversalRecursiveBinTreeNode(pRootNode->pRightNode);
    printf("%c ", pRootNode->data);
}
