#ifndef __XORLL_LIST_H__
#define __XORLL_LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

// print type
typedef enum{
    pf,
    pb
}print_t;

// Define the node structure
typedef struct List{
    struct Node{
        int data;
        struct Node* npx;
    }head;

    struct P{
        struct Node* head;
        struct Node* tail;
    }loc;

}* List;

// new list
List newList(List);

// npx finder
struct Node* npx(struct Node*, struct Node*);

// ptr next
void nexT(struct Node**, struct Node**, struct Node**);

// insert node
void insert(List*, int);

// print list
void print(List, print_t);

#endif
