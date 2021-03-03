#include <stdlib.h>
#include <string.h>
#include "list.h"


int next_exist(List **list)
{
    if (*list && (*list)->next && (*list)->next != *list)
        return (1);
    else
        return (0);
}


List *find_last(List **list)
{
    List **current = NULL;

    while (next_exist(list))
    {
        *current = (*list)->next;
    }
    if (current)
        return (*current);
    else
        return (NULL);
}

List *create_node(char *str)
{
    List *new_node;

    new_node = (List *)malloc(sizeof(List));

    if (new_node == NULL)
        return NULL;
    new_node->str = strdup(str);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

List *add_node_end(List **list, char *str)
{
    List *new_node = create_node(str);
    List *last = find_last(list);

    if (*list == NULL)
        return new_node;
    else
    {
        new_node->next = *list;
        (*list)->prev = new_node;
        *list = new_node;
        (*list)->prev = last;
        last->next = *list;
    }
    free(new_node);
    return *list;
}
List *add_node_begin(List **list, char *str)
{
    List *new_node = create_node(str);
    List *last = find_last(list);

    if (*list == NULL)
        return new_node;
    else
    {
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
        (*list)->prev = last;
        last->next = *list;
    }
    free(new_node);
    return *list;
}