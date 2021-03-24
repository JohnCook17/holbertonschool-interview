#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>
#define bool int
/**
 * max - gets max of two ints
 * @a: int a
 * @b: int b
 * Return the bigger of the two
 */
int max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
/**
 * height - gets the height of the binary tree
 * @node: the node of the tree to check height of
 * Return the height of the tree
 */
int height(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return (1 + max(height(node->left), height(node->right)));
}
/**
 * isBalanced - checks if tree is avl
 * @root: the root of the tree to check
 * Return 0 if not 1 if so
 */
bool isBalanced(const binary_tree_t *root)
{
	int lh;
	int rh;

	if (root == NULL)
		return (1);
	lh = height(root->left);
	rh = height(root->right);
	if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return (1);
	return (0);
}
/**
 * binary_tree_is_avl - checks if tree exist and if avl
 * @tree: the tree to check
 * Return 0 if not 1 if so
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (isBalanced(tree))
		return (1);
	else
		return (0);
}
