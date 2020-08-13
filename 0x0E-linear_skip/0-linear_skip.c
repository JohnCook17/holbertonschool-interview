#include <stdlib.h>
#include <stdio.h>
#include "search.h"

/**
 * linear_skip - a linear express lane search
 * @list: a list to search
 * @value: a value to search for
 * Return: NULL on failure, else pointer to node with value
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current;
	skiplist_t *last_e;
	skiplist_t *currentp;

	if (list == NULL)
	{
		return (NULL);
	}
	current = list;
	while (current->express && current->express->n < value)
	{
		printf("Value checked at index [%zu] = [%d]\n",
		       current->express->index, current->express->n);
		current = current->express;
	}
	if (current->express)
	{
		printf("Value found between indexes [%zu] and [%zu]\n",
			   current->index, current->express->index);
	}
	else
	{
		last_e = current;
		currentp = current;
		while (currentp->next)
		{
			currentp = currentp->next;
		}
		printf("Value found between indexes [%zu] and [%zu]\n",
			   last_e->index, currentp->index);
	}
	while (current->next && current->next->n < value)
	{
		printf("Value checked at index [%zu] = [%d]\n",
		       current->index, current->n);
		current = current->next;
	}

	printf("Value checked at index [%zu] = [%d]\n",
		   current->index, current->n);

	if (current && current->next && current->next->n == value)
	{
		printf("Value checked at index [%zu] = [%d]\n",
		       current->next->index, current->next->n);
		return (current->next);
	}
	else
		return (NULL);
}
