#include <stdio.h>
#include <stdlib.h>
#include "header.h"



node* add_value(node* prev, int num)
{
    node* pointer = (node*)malloc(sizeof(node*));
    pointer -> value = num;
    pointer -> next = NULL;
    if (prev != NULL) prev -> next = pointer;
    return pointer;
}

node2* add_value2(node2* prev, int num)
{
    node2* pointer = (node2*)malloc(sizeof(node2*));
    pointer->value = num;
    pointer->next = NULL;
    pointer->prev = prev;
    if (prev != NULL) prev->next = pointer;
    return pointer;
}

binaryTree* create_node(int node_data) 
{
    binaryTree* new_node = (binaryTree*)malloc(sizeof(binaryTree));
    new_node->data = node_data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

binaryTree* insert_node(binaryTree* root, int node_data) 
{
    if (root == NULL) 
    {
        root = create_node(node_data);
        return root;
    }

    binaryTree* curr = root;
    if (node_data < curr->data) 
    {
        if (curr->left == NULL) 
        {
            curr->left = create_node(node_data);
        } else 
        {
            insert_node(curr->left, node_data);
        }
    } 
    else 
    {
        if (curr->right == NULL) 
        {
            curr->right = create_node(node_data);
        } 
        else 
        {
            insert_node(curr->right, node_data);
        }
    }

    return root;
}

void inorder_traversal(binaryTree* root) 
{
    if (root != NULL) 
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int enque(queue* que, int new)
{
    if (que->back == MAX_SIZE)
    {
        return 1;
    }

    
    que->array[que->back] = new;
    que->back++;
    return 0;
}

void output_queue(queue* que)
{
    printf("Queue:\t");
    for (int i = que->front; i < que->back; i++)
    {
        printf("%d\t", que->array[i]);
    }
    printf("\n");
}

int deque(queue* que)
{
    if (que->back == que->front)
    {
        return 1;
    }
    int temp = que->array[que->front];
    for (int i = 0; i < que->back; i++)
    {
        que->array[i] = que->array[i+1];
    }
    que->back--;
    return temp;
}

int is_full(queue* que)
{
    if (que->back == MAX_SIZE) return 1;
    return 0;
}

int is_empty(queue* que)
{
    if (que->back == que->front) return 1;
    return 0;
}