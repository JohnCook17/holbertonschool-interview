#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "search.h"

/**
 * linear_skip - a linear skip search
 * @list: the list to search
 * @value: the value to search for
 * Return: a pointer the the node in the list
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;

	if (current)
	{
		/* express loop */
		while (current && current->express)
		{
			printf("Value checked at index [%li] = [%i]\n", current->index, current->n);
			if (current->express->n > value)
			{
				printf("Value found between indexes [%li] and [%li]\n",
				       current->index, current->express->index);
				break;
			}
			if (current && current->express)
				current = current->express;
		}
	}

	if (current)
	{
		/* list loop */
		while (current && current->next)
		{
			if (current->next->n > value)
				break;
			printf("Value checked at index [%li] = [%i]\n", current->index, current->n);
			if (current && current->next)
				current = current->next;
		}
		printf("Value checked at index [%li] = [%i]\n", current->index, current->n);
		return (current);
	}
	return (NULL);
}
