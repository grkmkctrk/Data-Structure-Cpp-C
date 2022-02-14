#ifndef __NODE_H_
#define __NODE_H_

#include "main.h"

#define MAXDATA 5
#define LIMIT 3

typedef enum {
    MIN,
    MAX
} sort_t;

typedef struct node_t {
    ui32 sizeData;
    ui32 data[MAXDATA];
    struct node_t* next;
} node_t;

// begin initialization
node_t* initNode();
// end initialization

// begin deletion
void deleteNode(node_t** head, ui32 data);
// end deletion

// begin insetion
void insertAfter(node_t**, ui32);
void insertBefore(node_t**, ui32);
// end insertion


// begin print
void print(node_t*);
// end print


// begin sort
void sort(node_t**, sort_t);
// end sort


#endif // __NODE_H_