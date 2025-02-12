#ifndef MY_HEADER
#define MY_HEADER
#define MAX_SIZE 10

typedef struct Node {
    int value;
    struct Node* next;
} node;

typedef struct Node2 {
    int value;
    struct Node2* next;
    struct Node2* prev;
} node2;

typedef struct Queue {
    int array[MAX_SIZE];
    int front;
    int back;
} queue;

typedef struct BinaryTree {
    int data;
    struct BinTree* right;
    struct BinTree* left;
} binaryTree;



node* add_value(node* prev, int num);
node2* add_value2(node2* prev, int num);

binaryTree* create_node(int node_data);
binaryTree* insert_node(binaryTree* root, int node_data);
void inorder_traversal(binaryTree* root);
#endif