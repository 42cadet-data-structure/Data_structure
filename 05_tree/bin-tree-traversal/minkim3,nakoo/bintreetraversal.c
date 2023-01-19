#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"
#include "bintreelinkedstack.h"
#include "bintreelinkedqueue.h"
#include "bintreetraversal.h"

int pushLSBinTreeNode(LinkedStack *linked_stack, BinTreeNode *rootnode)
{
	StackNode node;
	memset(&node, 0, sizeof(StackNode));
	node.data = rootnode;
	return (pushLS(linked_stack, node));
}

int enqueueLQBinTreeNode(LinkedQueue *pQueue, BinTreeNode *rootnode)
{
	QueueNode node;
	memset(&node, 0, sizeof(QueueNode));
	node.data = rootnode;
	return (enqueueLQ(pQueue, node));
}

void preorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack *linked_stack;
	StackNode *stack_node;
	BinTreeNode *rootnode = NULL, *leftnode = NULL, *rightnode = NULL;

	if (!pBinTree)
		return ;
	linked_stack = createLinkedStack();
	if (!linked_stack)
		return ;
	pushLSBinTreeNode(linked_stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(linked_stack) == FALSE)
	{
		stack_node = popLS(linked_stack);
		rootnode = stack_node->data;
		printf("%c ",rootnode->data);
		leftnode =  getLeftChildNodeBT(rootnode);
		rightnode = getRightChildNodeBT(rootnode);
		if (rightnode != NULL)
			pushLSBinTreeNode(linked_stack, rightnode);
		if (leftnode != NULL)
			pushLSBinTreeNode(linked_stack, leftnode);
		free(stack_node);
	}
	deleteLinkedStack(linked_stack);
}

void inorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack *linked_stack;
	StackNode *stack_node = NULL;
	BinTreeNode *pnode = NULL;

	if (!pBinTree)
		return ;
	linked_stack = createLinkedStack();
	if (!linked_stack)
		return ;
	pnode = getRootNodeBT(pBinTree);
	while (TRUE)
	{
		/* 무조건 왼쪽 아래까지 내려간다 */
		while (pnode != NULL)
		{
			pushLSBinTreeNode(linked_stack, pnode);
			pnode = getLeftChildNodeBT(pnode);
		}
		if (isLinkedStackEmpty(linked_stack) == TRUE)
			break ;
		else
		{
			stack_node = popLS(linked_stack);
			if (stack_node != NULL)
			{
				pnode = stack_node->data;
				printf("%c ", pnode->data);
				pnode = getRightChildNodeBT(pnode);
				free(stack_node);
			}
		}
	}
	deleteLinkedStack(linked_stack);
}

void postorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack *linked_stack;
	StackNode *stack_node = NULL;
	BinTreeNode *rootnode = NULL, *leftnode = NULL, *rightnode = NULL;

	if (!pBinTree)
		return ;
	linked_stack = createLinkedStack();
	if (!linked_stack)
		return ;
	pushLSBinTreeNode(linked_stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(linked_stack) == FALSE)
	{
		stack_node = peekLS(linked_stack);
		if (stack_node != NULL)
		{
			rootnode = stack_node->data;
			leftnode = getLeftChildNodeBT(rootnode);
			if (leftnode != NULL && leftnode->visited == NOT_VISITED)
				pushLSBinTreeNode(linked_stack, leftnode);
			else
			{
				rightnode = getRightChildNodeBT(rootnode);
				if (rightnode != NULL && rightnode->visited == NOT_VISITED)
					pushLSBinTreeNode(linked_stack, rightnode);
				else
				{
					rootnode->visited = VISITED;
					printf("%c ", rootnode->data);
					free(popLS(linked_stack));
				}
			}
		}
	}
	deleteLinkedStack(linked_stack);
}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{
	LinkedQueue *linked_queue = NULL;
	QueueNode *queue_node = NULL;
	BinTreeNode *rootnode = NULL, *leftnode = NULL, *rightnode = NULL;

	if (!pBinTree)
		return ;
	linked_queue = createLinkedQueue();
	rootnode = getRootNodeBT(pBinTree);
	enqueueLQBinTreeNode(linked_queue, rootnode);

	while (isLinkedQueueEmpty(linked_queue) == FALSE)
	{
		queue_node = dequeueLQ(linked_queue);
		rootnode = queue_node->data;
		printf("%c ", rootnode->data);
		leftnode = getLeftChildNodeBT(rootnode);
		rightnode = getRightChildNodeBT(rootnode);
		if (leftnode != NULL)
			enqueueLQBinTreeNode(linked_queue, leftnode);
		if (rightnode != NULL)
			enqueueLQBinTreeNode(linked_queue, rightnode);
		free(queue_node);
	}
	deleteLinkedQueue(linked_queue);
}
