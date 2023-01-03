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
	BinTreeNode *pnode = NULL;

	if (!pBinTree)
		return ;
	linked_stack = createLinkedStack();
	if (!linked_stack)
		return ;
	pushLSBinTreeNode(linked_stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(linked_stack) == FALSE)
	{
		while (pnode != NULL && pnode->visited == NOT_VISITED)
		{
			pnode->visited = VISITED;
			pushLSBinTreeNode(linked_stack, pnode);
			pnode = getRightChildNodeBT(pnode);
		}
		if
		{
			stack_node = popLS(linked_stack);
			if (stack_node != NULL)
			{
				pnode = getLeftChildNodeBT(pnode);
				pnode->visited = VISITED;
				pushLSBinTreeNode(linked_stack, pnode);
				free(stack_node);
			}
		}
	}
	deleteLinkedStack(linked_stack);
}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{
}
