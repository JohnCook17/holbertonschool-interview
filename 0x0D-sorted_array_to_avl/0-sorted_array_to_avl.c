#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * balance - checks balance of avl tree
 * @current: the current node
 * Return: the balance of tree
 */
int balance(avl_t *current)
{
	int left = 0;
	int right = 0;

	if (current == NULL)
		return (0);
	if (current->parent)
		current = current->parent;
	while (current->left)
	{
		left += 1;
		current = current->left;
	}
	while (current->right)
	{
		right += 1;
		current = current->right;
	}
	return (left - right);
}
/**
 * insert - inserts into avl tree
 * @array: the array
 * @i: the number of inserts
 * @size: the size of array
 * @tree: the tree root
 * @current: the current node
 * @left: left index
 * @right: right index
 * Return: the tree
 */
avl_t *insert(int *array, size_t i, size_t size,
			  avl_t *tree, avl_t *current, int left, int right)
{
	int b;
	int s = size;

	b = balance(current);
	if (b == 0 && left >= 0)
	{
		current->left = malloc(sizeof(avl_t));
		if (current->left == NULL)
			return (NULL);
		current->left->n = array[left];
		current->left->parent = current;
		current->left->left = NULL;
		current->left->right = NULL;
		return (insert(array, i + 1, size, tree, current->left, left - 1, right));
	}
	else if (b > 0 && right <= s)
	{
		current->right = malloc(sizeof(avl_t));
		if (current->right == NULL)
			return (NULL);
		current->right->n = array[right];
		current->right->parent = current;
		current->right->left = NULL;
		current->right->right = NULL;
		return (insert(array, i + 1, size, tree, current->right, left, right + 1));
	}
	else if (b < 0 && left >= 0)
	{
		current->left = malloc(sizeof(avl_t));
		if (current->left == NULL)
			return (NULL);
		current->left->n = array[left];
		current->left->parent = current;
		current->left->left = NULL;
		current->left->right = NULL;
		return (insert(array, i + 1, size, tree, current->left, left - 1, right));
	}
	return (tree);
}
/**
 * sorted_array_to_avl - sorted array to avl tree
 * @array: the array
 * @size: size of array
 * Return: the tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int mid = size / 2;
	avl_t *tree;

	tree = malloc(sizeof(avl_t));
	if (tree == NULL)
		return (NULL);
	tree->left = NULL;
	tree->n = array[mid];
	tree->parent = NULL;
	tree->right = NULL;
	tree = insert(array, 0, size, tree, tree, mid - 1, mid + 1);
	return (tree);
}
