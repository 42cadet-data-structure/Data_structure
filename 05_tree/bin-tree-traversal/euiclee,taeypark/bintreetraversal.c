#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreelinkedstack.h"
#include "bintreelinkedqueue.h"
#include "bintreetraversal.h"

void preorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack	*stack;
	StackNode	*cur_node;
	StackNode	node;

	stack = createLinkedStack();
	node.data = pBinTree->pRootNode;
	pushLS(stack, node);
	while (!isLinkedStackEmpty(stack))
	{
		cur_node = popLS(stack);
		printf("%c ", cur_node->data->data);
		node.data = cur_node->data->pRightChild;
		if (node.data != NULL)
			pushLS(stack, node);
		node.data = cur_node->data->pLeftChild;
		if (node.data != NULL)
			pushLS(stack, node);
		free(cur_node);
	}
	deleteLinkedStack(stack);
	printf("\n");
}

void inorderTraversalBinTree(BinTree *pBinTree)
{
	LinkedStack	*stack;
	StackNode	*cur_node;
	StackNode	node;

	stack = createLinkedStack();
	node.data = pBinTree->pRootNode;
	pushLS(stack, node);
	while (!isLinkedStackEmpty(stack))
	{
		cur_node = peekLS(stack);
		while (cur_node)
		{
			pushLS(stack, *cur_node);
			cur_node->data = cur_node->data->pLeftChild;
		}
		cur_node = popLS(stack);
		printf("%c ", cur_node->data->data);
		free(cur_node);
		cur_node = popLS(stack);
		printf("%c ", cur_node->data->data);
		node.data = cur_node->data->pRightChild;
		if (node.data != NULL)
			pushLS(stack, node);
		free(cur_node);
	}
	deleteLinkedStack(stack);
	printf("\n");
}

void postorderTraversalBinTree(BinTree *pBinTree)
{

}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{

}