#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

heap_t *possition_node(heap_t *head, heap_t *new_node, int value)
{
    heap_t *new_head;
    new_head = head;
    do{
        if (new_head->left == NULL)
        {
            new_head->left = new_node;
            if (value > new_head->n)
            {
                new_node->n = head->n;
                new_head->n = value;
            }
            else
                new_node->n = value;
            new_node->parent = new_head;
            new_node->left = NULL;
            new_node->right = NULL;
            printf("left\n");
        }
        else
        {
            new_head->right = new_node;
            if (value > new_head->n)
            {
                new_node->n = head->n;
                new_head->n = value;
            }
            else
                new_node->n = value;
            new_node->parent = new_head;
            new_node->left = NULL;
            new_node->right = NULL;
            printf("right\n");
            new_head = new_head->left;
        }
        
    }while (new_head->left);
    return new_head;
}

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;
    heap_t *head;

    head = *root;

    /* Step 0: make a new node if no memory avaliable return NULL */
    new_node = malloc(sizeof(heap_t));
    if (new_node == NULL)
        return (NULL);
    
    /* Step 1: position the new node */
    if (head == NULL)
    {
        *root = new_node;
        new_node->n = value;
        new_node->parent = NULL;
        new_node->left = NULL;
        new_node->right = NULL;
        printf("No head found\n");
        return new_node;
    }
    else
    {
        possition_node(head, new_node, value);
        return new_node;
    }
    /* Step 2: heapify the heap with max stack
    heapify();
    */
   
}