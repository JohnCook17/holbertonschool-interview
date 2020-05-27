#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if the singly linked list is a palindrome
 * @head: The head of the singly linked list
 * Return: 0 if not palindrom 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int *list;
	int i = 0;
	int j;

	if (head == NULL)
		return (1);

	while (current)
	{
		i += 1;
		current = current->next;
	}
	list = malloc(sizeof(int) * i);
	current = *head;
	j = i;
	i = 0;
	while (current)
	{
		list[i] = current->n;
		i += 1;
		current = current->next;
	}
	i = 0;
	while (i != j)
	{
		if (list[i] != list[j - 1])
		{
			free(list);
			return (0);
		}
		i += 1;
		j -= 1;
	}
	free(list);
	return (1);
}
