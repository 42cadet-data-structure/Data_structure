/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintreetraversal_ours.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:34:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/02 20:44:23 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bintreetraversal.h"
#include "bintreelinkedqueue.h"
#include "bintreelinkedstack.h"
#include "bintree.h"

int pushLSBinTreeNode(LinkedStack *pStack, BinTreeNode *pNode)
{
    StackNode node = {0,};
    node.data = pNode;
    return pushLS(pStack, node);
}

int enqueueLQBinTreeNode(LinkedQueue *pQueue, BinTreeNode *pNode)
{
    QueueNode node = {0,};
    node.data = pNode;
    return enqueueLQ(pQueue, node);
}

void preorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack *stack;
	StackNode	*stack_node;
	BinTreeNode	*root;

	memset(root, 0, sizeof(BinTreeNode));
	memset(stack_node, 0, sizeof(StackNode));

	stack = createLinkedStack();
	if (stack == NULL)
		return ;

	pushLSBinTreeNode(stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(stack) == FALSE)
	{
		stack_node = popLS(stack);
		root = stack_node->data;
		printf("%c ", root->data);
		if (root->pRightChild != NULL)
			pushLSBinTreeNode(stack, root->pRightChild);
		if (root->pLeftChild != NULL)
			pushLSBinTreeNode(stack, root->pLeftChild);
		free(stack_node);
	}
}

void inorderTraversalBinTree(BinTree *pBinTree);

void postorderTraversalBinTree(BinTree *pBinTree);

void levelOrderTraversalBinTree(BinTree *pBinTree);