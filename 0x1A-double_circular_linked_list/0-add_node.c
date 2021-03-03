#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * next_exist - Determines if list exist and next node in list exist
 * @list: the list
 * Return: 0 not exist 1 on exist
 */
int next_exist(List **list)
{
	if (*list && (*list)->next && (*list)->next != *list)
		return (1);
	return (0);
}
/**
* find_last - finds the last node in the list
* @list: the list to find the last node of
* Return: the last node in list
*/
List *find_last(List **list)
{
	List **current = NULL;

	while (next_exist(list))
	{
		*current = (*list)->next;
	}
	if (current)
		return (*current);
	return (NULL);
}
/**
 * create_node - creates a node
 * @str: the str to put into the node
 * Return: the node
 */
List *create_node(char *str)
{
	List *new_node;

	new_node = (List *)malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
/**
 * add_node_end - adds a node to the end
 * @list: the list to add node to
 * @str: the str to add to the list
 * Return: the list with the new node
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = create_node(str);
	List *last = find_last(list);

	if (*list == NULL)
		return (new_node);
	new_node->next = *list;
	(*list)->prev = new_node;
	*list = new_node;
	(*list)->prev = last;
	last->next = *list;
	free(new_node);
	return (*list);
}
/**
 *add_node_end - adds a node to the start
 * @list: the list to add node to
 * @str: the str to add to the list
 * Return: the list with the new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = create_node(str);
	List *last = find_last(list);

	if (*list == NULL)
		return (new_node);
	last->next = new_node;
	new_node->prev = last;
	last = new_node;
	(*list)->prev = last;
	last->next = *list;
	free(new_node);
	return (*list);
}
