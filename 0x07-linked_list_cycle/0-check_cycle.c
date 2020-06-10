#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: the list to check
 * Return: 0 if no cycle is found 1 if it is
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise = list;
	listint_t *hare = list;

	while (tortoise->next && hare->next->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise->n == hare->n)
			return (1);
	}
	return (0);
}
