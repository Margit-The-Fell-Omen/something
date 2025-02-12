#include <stdio.h>
#include "header.h"



node* add_value(node* prev, int num)
{
    node* pointer = malloc(sizeof(int));
    pointer -> value = num;
    pointer -> next = NULL;
    if (prev != NULL) prev -> next = pointer;
    return pointer;
}

node2* add_value2(node2* prev, int num)
{
    node2* pointer = malloc(sizeof(int));
    pointer -> value = num;
    pointer -> next = NULL;
    pointer -> prev = prev;
    if (prev != NULL) prev -> next = pointer;
    return pointer;
}