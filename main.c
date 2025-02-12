#include <stdio.h>
#include "header.h"

int main()
{
    node* pointer1_1 = add_value(NULL, 1);
    node* pointer1_2 = add_value(pointer1_1, 2);
    printf("Singly-linked list:\n");
    printf("1: %d\n", pointer1_1 -> value);
    printf("2: %d\n", pointer1_2 -> value);
    printf("1->2: %d\n", pointer1_1 -> next -> value);

    free(pointer1_1);
    free(pointer1_2);

    node2* pointer2_1 = add_value2(NULL, 1);
    node2* pointer2_2 = add_value2(pointer2_1, 2);
    printf("Doubly-linked list:\n");
    printf("1: %d\n", pointer2_1 -> value);
    printf("2: %d\n", pointer2_2 -> value);
    printf("1->2: %d\n", pointer2_1 -> next -> value);
    printf("2->1: %d\n", pointer2_2 -> prev -> value);

    free(pointer2_1);
    free(pointer2_2);

    binaryTree* root = NULL;

    int elements[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < n; i++) {
        root = insert_node(root, elements[i]);
    }

    // Обход дерева (inorder)
    printf("Inorder traversal of the tree: ");
    inorder_traversal(root);
    printf("\n");
    
    return 0;
}
