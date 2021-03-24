#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#define bool int

int max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int height(const binary_tree_t *node)
{
	if (node == NULL)
		return 0;

	return 1 + max(height(node->left), height(node->right));
}

bool isBalanced(const binary_tree_t *root)
{
	int lh;
	int rh;

	if (root == NULL)
		return 1;
	lh = height(root->left);
	rh = height(root->right);
	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return 1;
	return 0;
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (isBalanced(tree))
		return (1);
	else
		return (0);
}