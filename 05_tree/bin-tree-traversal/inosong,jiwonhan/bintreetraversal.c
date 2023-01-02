#include "bintreetraversal.h"
#include "bintree.h"
#include "bintreelinkedqueue.h"
#include "bintreelinkedstack.h"

static void preorderTraversalBinTreeNode(BinTreeNode *pNode)
{
	printf("%c ", pNode->data);
	if (pNode->pLeftChild != NULL)
		preorderTraversalBinTreeNode(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		preorderTraversalBinTreeNode(pNode->pRightChild);
}

static void pushStackNode(LinkedStack *stack, BinTreeNode *treeNode)
{
	StackNode stackNode = {0, };
	stackNode.data = treeNode;
	pushLS(stack, stackNode);
}

void preorderTraversalBinTree(BinTree *pBinTree)
{
	printf("1. 재귀: ");
	preorderTraversalBinTreeNode(pBinTree->pRootNode);

	printf("\n2. 반복: ");
	LinkedStack	*stack = createLinkedStack();
	StackNode	*del_node;
	BinTreeNode	*left;
	BinTreeNode	*right;

	pushStackNode(stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(stack) == FALSE)
	{
		del_node =	popLS(stack);
		printf("%c ",del_node->data->data);
		left = getLeftChildNodeBT(del_node->data);
		right = getRightChildNodeBT(del_node->data);
		if (right != NULL)
			pushStackNode(stack, right);
		if (left != NULL)
			pushStackNode(stack, left);
		free (del_node);	
	}
	deleteLinkedStack(stack);
}

static void	inorderTraversalBinTreeNode(BinTreeNode *pNode)
{
	if (pNode->pLeftChild != NULL)
		inorderTraversalBinTreeNode(pNode->pLeftChild);
	printf("%c ", pNode->data);
	if (pNode->pRightChild != NULL)
		inorderTraversalBinTreeNode(pNode->pRightChild);
}

void inorderTraversalBinTree(BinTree *pBinTree)
{
	printf("1. 재귀: ");
	inorderTraversalBinTreeNode(pBinTree->pRootNode);

	printf("\n2. 반복: ");
	LinkedStack	*stack = createLinkedStack();
	BinTreeNode	*node;
	StackNode	*del_node;

	pushStackNode(stack, getRootNodeBT(pBinTree));
	node = getLeftChildNodeBT(pBinTree->pRootNode);
	while (TRUE)
	{
		while(node != NULL)
		{
			pushStackNode(stack, node);
			node = getLeftChildNodeBT(node);
		}
		if (isLinkedStackEmpty(stack))
			break;
		else
		{
			del_node = popLS(stack);
			printf("%c ", del_node->data->data);
			node = getRightChildNodeBT(del_node->data);
			free(del_node);
		}
	}
	deleteLinkedStack(stack);
}

static void postorderTraversalBinTreeNode(BinTreeNode *pNode)
{
	if (pNode->pLeftChild != NULL)
		postorderTraversalBinTreeNode(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		postorderTraversalBinTreeNode(pNode->pRightChild);
	printf("%c ", pNode->data);
}

void postorderTraversalBinTree(BinTree *pBinTree)
{
	printf("1. 재귀: ");
	postorderTraversalBinTreeNode(pBinTree->pRootNode);

	printf("\n2. 반복: ");
	LinkedStack	*stack = createLinkedStack();
	BinTreeNode	*left, *right, *root;

	pushStackNode(stack, getRootNodeBT(pBinTree));
	while (isLinkedStackEmpty(stack) == FALSE)
	{
		root = peekLS(stack)->data;
		left = getLeftChildNodeBT(root);
		if (left != NULL && !left->visited)
			pushStackNode(stack, left);
		else
		{
			right = getRightChildNodeBT(root);
			if (right != NULL && !right->visited)
				pushStackNode(stack, right);
			else
			{
				printf("%c ", root->data);
				root->visited = TRUE;
				free(popLS(stack));
			}
		}
	}
	deleteLinkedStack(stack);
}

static void	pushQueueNode(LinkedQueue *queue, BinTreeNode *treeNode)
{
	QueueNode queueNode = {0,};
	queueNode.data = treeNode;
	enqueueLQ(queue, queueNode);
}
void levelOrderTraversalBinTree(BinTree *pBinTree)
{
	printf("1. 재귀: 안됨");
	printf("\n2. 반복: ");
	LinkedQueue *queue = createLinkedQueue();
	QueueNode	*del_node;
	BinTreeNode	*left, *right;

	pushQueueNode(queue, pBinTree->pRootNode);
	while (isLinkedQueueEmpty(queue) == FALSE)
	{
		del_node = dequeueLQ(queue);
		printf("%c ", del_node->data->data);
		left = getLeftChildNodeBT(del_node->data);
		right = getRightChildNodeBT(del_node->data);
		if (left != NULL)
			pushQueueNode(queue, left);
		if (right != NULL)
			pushQueueNode(queue, right);
		free(del_node);
	}
	deleteLinkedQueue(queue);
}
