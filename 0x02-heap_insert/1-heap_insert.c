#include <stdlib.h>
#include "binary_trees.h"

heap_t *make_heap(heap_t *head, heap_t *new_node, int value)
{
	if (value > head->n)
		{
			new_node->n = head->n;
			head->n = value;
			return head;
		}
	else
	{
		new_node->n = value;
		return new_node;
	}
}

void possition_node(heap_t *head, heap_t *new_node, int value)
{
	heap_t *new_head;

	new_head = head;
	
	if (new_head->left == NULL)
	{
		new_head->left = new_node;
		
		new_node->parent = new_head;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	else if (new_head->right == NULL)
	{
		new_head->right = new_node;
		new_node->parent = new_head;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	else
	{
		if (new_head->parent)
			new_head = new_head->parent->left;
		if (!new_head->left->right)
			possition_node(new_head->left, new_node, value);
		else
			possition_node(new_head->right, new_node, value);
	}
}

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *head;
	heap_t *pointer_to_node;

	/* left_or_right: 0 for left 1 for right */
	head = *root;

	/* Step 0: make a new node if no memory avaliable return NULL */
	new_node = binary_tree_node(head, value);

	/* Step 1: position the new node */
	if (head == NULL)
	{
		*root = new_node;
		head = new_node;
		new_node->n = value;
		new_node->parent = NULL;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	else
		possition_node(head, new_node, value);
	pointer_to_node = make_heap(head, new_node, value);
	return (pointer_to_node);
}