#include <stdlib.h>
#include "binary_trees.h"

/**
 * new_node - makes a new node
 * @parent: The parent of the new node
 * @n: the value of the new node
 * Return: new node
 */
avl_t *new_node(avl_t *parent, int n)
{
	avl_t *new_branch;

	new_branch = malloc(sizeof(avl_t));

	new_branch->parent = parent;
	new_branch->left = NULL;
	new_branch->right = NULL;
	new_branch->n = n;

	return (new_branch);
}
/**
 * left_rotate - rotates left
 * @tree: the tree node to performe the rotation on
 * Return: the tree
 */
avl_t *left_rotate(avl_t *tree)
{
	avl_t *ret_pointer = tree->right;
	avl_t *temp = ret_pointer->left;

	ret_pointer->left = tree;
	tree->right = temp;

	return (ret_pointer);
}
/**
 * right_rotate - rotates right
 * @tree: the tree to rotate right
 * Return: the tree
 */
avl_t *right_rotate(avl_t *tree)
{
	avl_t *ret_pointer = tree->left;
	avl_t *temp = ret_pointer->right;

	ret_pointer->right = tree;
	tree->left = temp;

	return (ret_pointer);
}
/**
 * insert_node - inserts a new node, does not work currently
 * @tree: the tree to insert the new node on
 * @n: the curret value to insert
 * Return: the tree
 */
avl_t *insert_node(avl_t *tree, int n)
{
	int balance = 0;

	if (tree == NULL)
	{
		return (new_node(NULL, n));
	}
	if (n < tree->n)
		tree->left = insert_node(tree->left, n);
	else if (n > tree->n)
		tree->right = insert_node(tree->right, n);
	else
		return (tree);

	/* left left */
	if (balance > 1 && n < tree->left->n)
	{
		return (right_rotate(tree));
	}
	/* right right */
	if (balance < -1 && n > tree->right->n)
	{
		return (left_rotate(tree));
	}
	/* left right */
	if (balance > 1 && n > tree->left->n)
	{
		tree->left = left_rotate(tree->left);
		return (right_rotate(tree));
	}
	/* right left */
	if (balance < -1 && n < tree->right->n)
	{
		tree->right = right_rotate(tree->right);
		return (left_rotate(tree));
	}

	return (tree);


}
/**
 * sorted_to_avl - entry point, takes an array and makes avl
 * @array: the array to make an avl
 * @size: the size of the array
 * Return: the avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	size_t i = 1;

	avl_t *tree = insert_node(NULL, array[0]);

	while (i < size)
	{
		tree = insert_node(tree, array[i]);
		i += 1;
	}
	return (tree);
}
