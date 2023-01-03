/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bintreetraversal_ours.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:34:11 by hyojocho          #+#    #+#             */
/*   Updated: 2023/01/03 12:29:47 by hyojocho         ###   ########.fr       */
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
	LinkedStack *stack = NULL;
	StackNode	*stack_node = NULL;
	BinTreeNode	*root_node = NULL;

	stack = createLinkedStack();
	if (stack == NULL)
		return ;

	pushLSBinTreeNode(stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(stack) == FALSE)
	{
		stack_node = popLS(stack);
		root_node = stack_node->data;
		printf("%c ", root_node->data);
		if (root_node->pRightChild != NULL)
			pushLSBinTreeNode(stack, root_node->pRightChild);
		if (root_node->pLeftChild != NULL)
			pushLSBinTreeNode(stack, root_node->pLeftChild);
		free(stack_node);
	}
	deleteLinkedStack(stack);
}

void inorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack *stack = NULL;
	StackNode	*stack_node = NULL;
	BinTreeNode	*root_node = NULL;
	int			first = 1;
	stack = createLinkedStack();
	if (stack == NULL)
		return ;

	root_node = getRootNodeBT(pBinTree);
	pushLSBinTreeNode(stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(stack) == FALSE)
	{
		while (root_node != NULL)
		{
			pushLSBinTreeNode(stack, root_node);
			root_node = getLeftChildNodeBT(root_node);
		}
		stack_node = popLS(stack);
		root_node = stack_node->data;
		printf("%c ", root_node->data);
		root_node = getRightChildNodeBT(root_node);
		free(stack_node);
	}
	deleteLinkedStack(stack);
}

void postorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack *stack = NULL;
	StackNode	*stack_node = NULL;
	BinTreeNode	*root_node = NULL;

	stack = createLinkedStack();
	if (stack == NULL)
		return ;

	pushLSBinTreeNode(stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(stack) == FALSE)
	{
		stack_node = peekLS(stack);
        if (stack_node != NULL) {
            root_node = stack_node->data;
            root_node->pLeftChild = getLeftChildNodeBT(root_node);
            if (root_node->pLeftChild != NULL && root_node->pLeftChild->visited == FALSE) {
                pushLSBinTreeNode(stack, root_node->pLeftChild);
            } else {
                root_node->pRightChild = getRightChildNodeBT(root_node);
                if (root_node->pRightChild != NULL && root_node->pRightChild->visited == FALSE) {
                    pushLSBinTreeNode(stack, root_node->pRightChild);
                } else {
                    root_node->visited = TRUE;
                    printf("%c ", root_node->data);
                    free(popLS(stack));
                }
            }
        }
	}
	deleteLinkedStack(stack);	
}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{
	LinkedQueue *queue = NULL;
	QueueNode	*queue_node = NULL;
	BinTreeNode	*root_node = NULL;

	queue = createLinkedQueue();
	if (queue == NULL)
		return ;
	root_node = getRootNodeBT(pBinTree);

	enqueueLQBinTreeNode(queue, root_node);
	while (isLinkedQueueEmpty(queue) == FALSE)
	{
		queue_node = dequeueLQ(queue);
		root_node = queue_node->data;
		printf("%c ", root_node->data);
		if (root_node->pLeftChild != NULL) {
            enqueueLQBinTreeNode(queue, root_node->pLeftChild);
        }
        if (root_node->pRightChild != NULL) {
            enqueueLQBinTreeNode(queue, root_node->pRightChild);
        }
        free(queue_node);
	}
	    deleteLinkedQueue(queue);
}