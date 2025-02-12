#include <stdio.h>
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

void inorder_traversal(binaryTree* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}