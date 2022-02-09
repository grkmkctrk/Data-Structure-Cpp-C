#ifndef __XORLL_LIST_H__
#define __XORLL_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// Define the node structure
typedef struct Node{
    int data;
    struct Node* npx;
}Node;

// type of print kind
typedef enum{
    PRINT_HEAD,
    PRINT_TAIL
}print_t;

// npx finder
Node* npx(Node*, Node*);

// insert node
void insert(Node**, int);

// print list
void print(Node*);


#endif
