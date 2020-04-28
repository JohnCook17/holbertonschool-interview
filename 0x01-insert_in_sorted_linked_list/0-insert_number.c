#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a node into a linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: int to be added into list
 * Return: address of node inserted or NULL on malloc fail
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node;
	listint_t *current;

	current = *head;
	

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = number;
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
	}
	else
	{
		if (current->n > number)
		{
			new_node->next = current;
			*head = new_node;
			return *head;
		}
		while (current->next != NULL && current->next->n < number)
		{
			current = current->next;
		}
		if (current->next && current->next->next)
		{
			new_node->next = current->next;
		}
		else
		{
			new_node->next = NULL;
		}
		current->next = new_node;
		while (current->next != NULL)
		{
			current = current->next;
		}
		if (new_node->n > current->n)
		{
			current->next = new_node;
			new_node->next = NULL;
		}
	}

	return (new_node);
}
