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

void inorder_traversal(binaryTree* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

binaryTree* find_minimum(binaryTree* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

binaryTree* delete_node(binaryTree* root, int node_data) {
    if (root == NULL) {
        return root;
    }

    if (node_data < root->data) {
        root->left = delete_node(root->left, node_data);
    } else if (node_data > root->data) {
        root->right = delete_node(root->right, node_data);
    } else {
        // Узел найден
        if (root->left == NULL) {
            // Узел не имеет левого поддерева
            binaryTree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Узел не имеет правого поддерева
            binaryTree* temp = root->left;
            free(root);
            return temp;
        } else {
            // Узел имеет оба поддерева
            binaryTree* temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}