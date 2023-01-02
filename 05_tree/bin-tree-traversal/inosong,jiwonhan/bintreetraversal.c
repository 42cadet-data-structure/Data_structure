#include "bintreetraversal.h"
#include "bintree.h"

static void preorderTraversalBinTreeNode(BinTreeNode *pNode)
{
	printf("%c ", pNode->data);
	if (pNode->pLeftChild != NULL)
		preorderTraversalBinTreeNode(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		preorderTraversalBinTreeNode(pNode->pRightChild);
}

void preorderTraversalBinTree(BinTree *pBinTree)
{
	printf("1. 재귀: ");
	preorderTraversalBinTreeNode(pBinTree->pRootNode);

	printf("\n2. 반복: ");
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
}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{
	printf("1. 재귀: 안됨");
	printf("\n2. 반복: ");
}
