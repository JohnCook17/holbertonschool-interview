#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int possition_node(heap_t *head, heap_t *new_node, int value, int left_or_right)
{
    heap_t *new_head;
    new_head = head;
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
            new_head = new_node->parent;
            left_or_right = 1;
            printf("\nleft");
            return (left_or_right);
            
        }
        else if (new_head->right == NULL)
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
            printf("\nright");
            new_head = new_node->parent->left;
            left_or_right = 0;
            return (left_or_right);
        }
        else
        {
            if (new_head->parent)
            {
                if (new_head->right->left)
                    return (possition_node(new_head->left, new_node, value, left_or_right));
                else
                {
                    while (new_head->parent)
                    {
                        new_head = new_head->parent;
                    }
                    return (possition_node(new_head->right, new_node, value, left_or_right));
                }
            }
            else
                return (possition_node(new_head->left, new_node, value, left_or_right));
        }
        
    return (1);
}

heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node;
    heap_t *head;
    int left_or_right;

    /* left_or_right: 0 for left 1 for right */
    left_or_right = 0;
    head = *root;

    /* Step 0: make a new node if no memory avaliable return NULL */
    new_node = binary_tree_node(head, value);
    
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
        left_or_right = possition_node(head, new_node, value, left_or_right);
        return new_node;
    }
    /* Step 2: heapify the heap with max stack
    heapify();
    */
   
}