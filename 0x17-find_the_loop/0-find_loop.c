#include "lists.h"
/**
 * find_listint_loop - finds the start of a loop in a linked list
 * @head: The head of the linked list
 * Return: the pointer to the start of the loop or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
			break;
	}

	slow = head;

	while (slow && fast)
	{
		slow = slow->next;
		fast = fast->next;

		if (slow == fast)
			return (slow);
	}

	return (NULL);
}
